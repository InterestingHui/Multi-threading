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
	SOCKET cSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SOCKET_ERROR == cSocket){
		printf("创建socket失败:%d\n", GetLastError());
		//9 清理协议版本信息
		WSACleanup();
		return -1;
	}
	printf("创建socket成功\n");

	//3 获取服务器协议地址簇
	SOCKADDR_IN addr = { 0 };
	addr.sin_family = AF_INET;//必须和socket函数的第一个参数一致
	addr.sin_addr.S_un.S_addr = inet_addr("113.54.193.49");
	addr.sin_port = htons(9527);

	//4 连接
	int r = connect(cSocket, (sockaddr*)&addr, sizeof(addr));
	printf("连接成功\n");
	//5 通信
	char buf[1024];
	while (1){
		printf("请输入你想发送的数据:");
		scanf("%s", buf);
		send(cSocket, buf, strlen(buf), NULL);
	}


	//6 断开连接
	closesocket(cSocket);

	//7 清理协议版本信息
	WSACleanup();

	return 0;
}
