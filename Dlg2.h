#pragma once
#include "afxdialogex.h"
#include <string>
#include "NProcess.h"
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
	int pTime;
	std::string pName;
	int pArrTime;


	virtual BOOL OnInitDialog();
//	CListCtrl m_ListCtrl1;
	CListCtrl m_list1;
	afx_msg void OnEnChangeEdit2();
	CEdit m_edit2;
	CEdit m_edit1;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit3();
	void UpdateQueue(vector<process> p,int queueNum);
	process_list pList;
	afx_msg void OnBnClickedButton2();
	CListCtrl m_list_all;
	CEdit m_edit3;
};
