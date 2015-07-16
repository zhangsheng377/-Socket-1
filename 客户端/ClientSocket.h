#pragma once
#include "afxsock.h"
class CClientSocket :
	public CAsyncSocket
{
public:
	CClientSocket();
	~CClientSocket();

	BOOL my_bConnected;
	UINT my_nLength;
	char my_szBuffer[4096];
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);

	CString my_SendData;
};

