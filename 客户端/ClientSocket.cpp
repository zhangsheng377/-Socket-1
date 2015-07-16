#include "stdafx.h"
#include "ClientSocket.h"

#include "客户端Dlg.h"
#include "客户端.h"


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


void CClientSocket::OnConnect(int nErrorCode)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (nErrorCode == 0)
	{
		my_bConnected = TRUE;
		C客户端App *pApp = (C客户端App*)AfxGetApp();
		C客户端Dlg *pDlg = (C客户端Dlg*)pApp->m_pMainWnd;
		CString temp = L"连接到:";
		temp += pDlg->my_ServerAddr;
		pDlg->m_MsgR.InsertString(0, temp);
		pDlg->GetDlgItem(IDC_SEND)->EnableWindow(true);
		AsyncSelect(FD_READ);
	}

	CAsyncSocket::OnConnect(nErrorCode);
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO:  在此添加专用代码和/或调用基类
	my_nLength = Receive(my_szBuffer, sizeof(my_szBuffer));
	C客户端App *pApp = (C客户端App*)AfxGetApp();
	C客户端Dlg *pDlg = (C客户端Dlg*)pApp->m_pMainWnd;
	CString temp;
	temp.Format(L"%s", CString(my_szBuffer));				//一定要把char[]用CString强制转换,否则CString temp里会有乱码
	pDlg->m_MsgR.InsertString(0, temp);
	memset(my_szBuffer, 0, sizeof(my_szBuffer));

	CAsyncSocket::OnReceive(nErrorCode);
}


void CClientSocket::OnSend(int nErrorCode)
{
	// TODO:  在此添加专用代码和/或调用基类
	Send(my_szBuffer, my_nLength, 0);
	my_nLength = 0;
	memset(my_szBuffer, 0, sizeof(my_szBuffer));
	AsyncSelect(FD_READ);

	CAsyncSocket::OnSend(nErrorCode);
}
