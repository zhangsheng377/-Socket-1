
// 客户端Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "客户端.h"
#include "客户端Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C客户端Dlg 对话框



C客户端Dlg::C客户端Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C客户端Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C客户端Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_MsgR);
	DDX_Control(pDX, IDC_EDIT1, m_MsgS);
}

BEGIN_MESSAGE_MAP(C客户端Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, &C客户端Dlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_SEND, &C客户端Dlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_CLOSE, &C客户端Dlg::OnBnClickedClose)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// C客户端Dlg 消息处理程序

BOOL C客户端Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C客户端Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C客户端Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C客户端Dlg::OnBnClickedConnect()
{
	// TODO:  在此添加控件通知处理程序代码
	m_ClientSocket.ShutDown(2);
	m_ClientSocket.m_hSocket = INVALID_SOCKET;
	m_ClientSocket.my_bConnected = FALSE;
	CAddrDlg m_Dlg;
	my_szPort = 5088;
	
	if (m_Dlg.DoModal() == IDOK && !m_Dlg.my_Addr.IsEmpty())
	{
		memcpy(my_szServerAdr, m_Dlg.my_Addr, sizeof(my_szServerAdr));
		my_ServerAddr = m_Dlg.my_Addr;
		SetTimer(1, 1000, NULL);
		TryCount = 0;
	}
	GetDlgItem(IDC_CONNECT)->EnableWindow(false);
}


void C客户端Dlg::OnBnClickedSend()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_ClientSocket.my_bConnected)
	{
		m_ClientSocket.my_nLength = m_MsgS.GetWindowTextLengthW();
		m_ClientSocket.AsyncSelect(FD_WRITE);
		m_MsgS.SetWindowTextW(L"");
	}
}


void C客户端Dlg::OnBnClickedClose()
{
	// TODO:  在此添加控件通知处理程序代码
	m_ClientSocket.ShutDown(2);
	EndDialog(0);
}


void C客户端Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (m_ClientSocket.m_hSocket == INVALID_SOCKET)
	{
		BOOL bFlag = m_ClientSocket.Create(0, SOCK_STREAM, FD_CONNECT);
		if (!bFlag)
		{
			AfxMessageBox(L"Socket创建错误!");
			m_ClientSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}
	m_ClientSocket.Connect(my_ServerAddr, my_szPort);
	TryCount++;
	if (TryCount >= 10 || m_ClientSocket.my_bConnected==true)
	{
		KillTimer(1);
		if (TryCount >= 10)
		{
			AfxMessageBox(L"连接失败!");
			GetDlgItem(IDC_CONNECT)->EnableWindow(true);
		}
		return;
	}

	CDialogEx::OnTimer(nIDEvent);
}
