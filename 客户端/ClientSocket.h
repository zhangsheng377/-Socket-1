#pragma once
#include "afxsock.h"
class CClientSocket :
	public CAsyncSocket
{
public:
	CClientSocket();
	~CClientSocket();
};

