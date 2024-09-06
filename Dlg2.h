#pragma once
#include "afxdialogex.h"
#include <string>

// Dlg2 对话框

class Dlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg2)

public:
	Dlg2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
//	CListCtrl m_ListCtrl1;
	CListCtrl m_list1;
	afx_msg void OnEnChangeEdit2();
	CEdit m_edit2;
	CEdit m_edit1;
	int pTime;
	std::string pName;
};
