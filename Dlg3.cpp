﻿// Dlg3.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "Dlg3.h"


// Dlg3 对话框

IMPLEMENT_DYNAMIC(Dlg3, CDialogEx)

Dlg3::Dlg3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

Dlg3::~Dlg3()
{
}

void Dlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list1);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
}


BEGIN_MESSAGE_MAP(Dlg3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dlg3::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &Dlg3::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &Dlg3::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &Dlg3::OnEnChangeEdit3)
END_MESSAGE_MAP()


// Dlg3 消息处理程序


BOOL Dlg3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = m_list1.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list1.SetExtendedStyle(dwStyle);
	m_list1.InsertColumn(0, "进程名", LVCFMT_LEFT, 125);
	m_list1.InsertColumn(1, "剩余时间", LVCFMT_LEFT, 125);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void Dlg3::UpdateQueue(vector<process> pList)
{
	for (int i = 0; i < pList.size(); i++)
	{
		CString str;
		str.Format(_T("%d"), pList[i].get_run_time());
		m_list1.InsertItem(i, _T(""));
		m_list1.SetItemText(i, 0, pList[i].get_process_name().c_str());
		m_list1.SetItemText(i, 1, str);
	}
}


void Dlg3::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	process newProcess(pName, pTime, pArrTime);
}


void Dlg3::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString name;
	m_edit1.GetWindowTextA(name);
	pName = name;
}


void Dlg3::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString time;
	m_edit2.GetWindowTextA(time);
	pTime = atoi(time);
}



void Dlg3::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString arrTime;
	m_edit2.GetWindowTextA(arrTime);
	pArrTime = atoi(arrTime);
}