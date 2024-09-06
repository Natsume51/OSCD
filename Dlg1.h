#pragma once
#include "afxdialogex.h"
#include <iostream>
#include <vector>
// Dlg1 对话框

class Dlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg1)

public:
	Dlg1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dlg1();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	CListCtrl m_list1;
	CListCtrl m_list2;
	CListCtrl m_list3;
	std::string pName;
	int pTime;
	

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnLvnItemchangedList5(NMHDR* pNMHDR, LRESULT* pResult);
	void ProgressStep(int n);
	void TotalProgressStep(int n);
	CProgressCtrl m_ProCtrl;
	CProgressCtrl m_TotalProCtrl;
};
