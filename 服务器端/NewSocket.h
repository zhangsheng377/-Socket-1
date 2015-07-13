#pragma once
#include "afxsock.h"
class CNewSocket :
	public CAsyncSocket
{
public:
	CNewSocket();
	~CNewSocket();

	UINT my_nLength;
	char my_szBuffer[4096];
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
};

