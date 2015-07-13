#include "stdafx.h"
#include "NewSocket.h"


CNewSocket::CNewSocket()
{
	my_nLength = 0;
	memset(my_szBuffer, 0, sizeof(my_szBuffer));
}


CNewSocket::~CNewSocket()
{
	if (m_hSocket != INVALID_SOCKET) Close();
}


void CNewSocket::OnReceive(int nErrorCode)
{
	// TODO:  在此添加专用代码和/或调用基类
	my_nLength = Receive(my_szBuffer, sizeof(my_szBuffer), 0);		//接收消息
	AsyncSelect(FD_WRITE);											//触发OnSend()函数,(转发接收到的消息)

	CAsyncSocket::OnReceive(nErrorCode);
}


void CNewSocket::OnSend(int nErrorCode)
{
	// TODO:  在此添加专用代码和/或调用基类
	char my_SendBuffer[4096];
	memcpy(my_SendBuffer, "服务器转发:", 24);
	strncat(my_SendBuffer, my_szBuffer, my_nLength);				//复制赋值
	Send(my_SendBuffer, sizeof(my_SendBuffer));						//发送数据
	AsyncSelect(FD_READ);											//触发OnReceive()函数

	CAsyncSocket::OnSend(nErrorCode);
}
