// AddrDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "客户端.h"
#include "AddrDlg.h"
#include "afxdialogex.h"


// CAddrDlg 对话框

IMPLEMENT_DYNAMIC(CAddrDlg, CDialogEx)

CAddrDlg::CAddrDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddrDlg::IDD, pParent)
	, my_Addr(_T("zhangsheng377.wicp.net"))
	, my_ServerPort(32137)
{

}

CAddrDlg::~CAddrDlg()
{
}

void CAddrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, my_Addr);
	DDX_Text(pDX, IDC_EDIT2, my_ServerPort);
}


BEGIN_MESSAGE_MAP(CAddrDlg, CDialogEx)
END_MESSAGE_MAP()


// CAddrDlg 消息处理程序
