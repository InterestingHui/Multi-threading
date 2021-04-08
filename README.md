# 基于TCP/IP的多线程实战——多线程客户端聊天室的本地实现，通过局域网IP
## 流程

<details><summary><b>要点</b></summary>
  
- 使用的是Winsock2库和windows库
</details>
<details><summary><b>服务器</b></summary>
  
- 1.通过WSAStartup函数确认版本协议号
- 2.通过socket函数创建socket变量
- 3.设置服务器协议地址簇，通过声明一个sock_address_in变量，就是大写的SOCKADDR_IN变量，然后设置网络地址就是本地的局域网IP，再设置端口号
- 4.通过bind函数绑定第二步创建的socket和第三步设置的服务器协议地址簇变量
- 5.通过listen函数让socket变量监听，同时设置最大允许连接的客户端数量
- 6.接受连接
- 7.通信（使用for循环与多个客户端通信，当时用的是一个数组表示不同的客户端）
- 8.断开连接
- 9.清理协议版本信息
</details>
<br>
<details><summary><b>客户端</b></summary>
  
- 1.确定协议版本
- 2.创建socket
- 3.获取服务器地址簇
- 4.连接
- 5.通信
- 6.断开连接
- 7.清理协议版本信息
</details>
