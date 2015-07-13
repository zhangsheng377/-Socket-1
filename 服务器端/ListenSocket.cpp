#include "stdafx.h"
#include "ListenSocket.h"


CListenSocket::CListenSocket()
{
}


CListenSocket::~CListenSocket()
{
}


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO:  在此添加专用代码和/或调用基类
	CNewSocket *pSocket = new CNewSocket();
	if (Accept(*pSocket))
	{
		pSocket->AsyncSelect(FD_READ);						//触发Read()函数
		m_pSocket = pSocket;
	}
	else
	{
		delete pSocket;
	}

	CAsyncSocket::OnAccept(nErrorCode);
}
