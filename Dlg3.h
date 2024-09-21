#pragma once
#include "pch.h"
#include "afxdialogex.h"
#include "MyProcess.h"
// Dlg3 对话框

class Dlg3 : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg3)

public:
	Dlg3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dlg3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_list1;
	int pTime;
	std::string pName;
	int pArrTime;
	int pPriority;
	void UpdateQueue(vector<MyProcess> p, int queueNum);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	vector<MyProcess> pList;
	CListCtrl m_list_all;
	afx_msg void OnBnClickedButton2();
};
