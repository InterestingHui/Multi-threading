#include<stdio.h>
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include<Windows.h>

int main(){
	//1 确定协议版本
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (HIBYTE(wsaData.wVersion) != 2 || LOBYTE(wsaData.wVersion) != 2){
		printf("确定协议版本失败:%d\n", GetLastError());
		return -1;
	}
	printf("确定协议版本成功!\n");

	//2 创建socket
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SOCKET_ERROR == serverSocket){
		printf("创建socket失败:%d\n", GetLastError());
		//9 清理协议版本信息
		WSACleanup();
		return -1;
	}
	printf("创建socket成功\n");

	//3 设置服务器协议地址簇
	SOCKADDR_IN addr = { 0 };
	addr.sin_family = AF_INET;//必须和socket函数的第一个参数一致
	addr.sin_addr.S_un.S_addr = inet_addr("113.54.193.49");

	addr.sin_port = htons(9527);
	printf("设置服务器协议地址簇成功\n");

	//4 绑定
	int r = bind(serverSocket, (sockaddr*)&addr, sizeof(addr));//?sizeof
	if (r == -1){
		printf("绑定失败:%d\n", GetLastError());
		closesocket(serverSocket);
		WSACleanup();
		return -1;
	}
	printf("绑定成功!\n");

	//5 监听
	r = listen(serverSocket, 10);//允许连接的最大客户端数量
	printf("监听成功!\n");

	//6 接受连接
	SOCKADDR_IN cAddr = { 0 };//创建客户端
	int len = sizeof(cAddr);

	//accept是一个阻塞函数，类似于scanf、getchar
	SOCKET clientSocket = accept(serverSocket, (sockaddr*)&cAddr, &len);//接听
	if (SOCKET_ERROR == clientSocket){
		printf("服务器崩溃:%d\n", GetLastError());
		closesocket(serverSocket);
		WSACleanup();
		return -1;
	}
	printf("客户端连接服务器成功:%s\n", inet_ntoa(cAddr.sin_addr));

	//7 通信
	char buf[1024];
	while (1){
		//等待从客户端接收数据
		r = recv(clientSocket, buf, 1023, NULL);
		if (r > 0){
			buf[r] = 0;//添加结束符号
			printf("来自客户端的信息:%s\n", buf);
		}
	}



	//8 断开连接
	closesocket(serverSocket);

	//9 清理协议版本信息
	WSACleanup();
	while (1);
	return 0;
}
