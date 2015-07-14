#pragma once

#include "resource.h"

// CAddrDlg 对话框

class CAddrDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddrDlg)

public:
	CAddrDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddrDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString my_Addr;
};
