# -基于TCP/IP的多线程实战——多线程客户端的本地实现，通过局域网IP
## 流程
<details><summary><b>服务器</b></summary>
  <li>1.确定协议版本
  <li>2.创建socket
  <li>3.设置服务器地址簇
  <li>4.绑定
  <li>5.监听
  <li>6.接受连接
  <li>7.通信（使用for循环与多个客户端通信，当时用的是一个数组表示不同的客户端）
  <li>8.断开连接
  <li>9.清理协议版本信息
</details>
<br>
<details><summary><b>客户端</b></summary>
  <li>1.确定协议版本
  <li>2.创建socket
  <li>3.获取服务器地址簇
  <li>4.连接
  <li>5.通信
  <li>6.断开连接
  <li>7.清理协议版本信息
</details>
