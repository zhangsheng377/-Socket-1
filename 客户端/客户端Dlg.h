
// 客户端Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#include "ClientSocket.h"
#include "AddrDlg.h"

#include "resource.h"

// C客户端Dlg 对话框
class C客户端Dlg : public CDialogEx
{
// 构造
public:
	C客户端Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	int TryCount;
	CClientSocket m_ClientSocket;
	UINT my_szPort;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_MsgR;
	CEdit m_MsgS;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedClose();

	char my_szServerAdr[256];
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	CString my_ServerAddr;
	CString my_SendData;
};
