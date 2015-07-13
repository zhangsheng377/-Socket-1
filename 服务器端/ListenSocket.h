#pragma once
#include "afxsock.h"

#include "NewSocket.h"

class CListenSocket :
	public CAsyncSocket
{
public:
	CListenSocket();
	~CListenSocket();

	CNewSocket *m_pSocket;
	virtual void OnAccept(int nErrorCode);
};

