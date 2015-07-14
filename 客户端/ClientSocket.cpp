#include "stdafx.h"
#include "ClientSocket.h"


CClientSocket::CClientSocket()
{
	my_nLength = 0;
	memset(my_szBuffer, 0, sizeof(my_szBuffer));
	my_bConnected = FALSE;
}


CClientSocket::~CClientSocket()
{
	if (m_hSocket != INVALID_SOCKET) Close();
}
