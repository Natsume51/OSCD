// Dlg1.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "Dlg1.h"
#include "duoJiFanKui.h"
#include <iostream>
// Dlg1 对话框

IMPLEMENT_DYNAMIC(Dlg1, CDialogEx)

Dlg1::Dlg1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Dlg1::~Dlg1()
{
}

void Dlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list1);
	DDX_Control(pDX, IDC_LIST4, m_list2);
	DDX_Control(pDX, IDC_LIST5, m_list3);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}


BEGIN_MESSAGE_MAP(Dlg1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dlg1::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &Dlg1::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &Dlg1::OnEnChangeEdit1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST5, &Dlg1::OnLvnItemchangedList5)
END_MESSAGE_MAP()


// Dlg1 消息处理程序


BOOL Dlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = m_list1.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list1.SetExtendedStyle(dwStyle);
	m_list1.InsertColumn(0, "进程名", LVCFMT_LEFT, 100);
	m_list1.InsertColumn(1, "剩余时间", LVCFMT_LEFT, 100);
	dwStyle = m_list2.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list2.SetExtendedStyle(dwStyle);
	m_list2.InsertColumn(0, "进程名", LVCFMT_LEFT, 100);
	m_list2.InsertColumn(1, "剩余时间", LVCFMT_LEFT, 100);
	dwStyle = m_list3.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list3.SetExtendedStyle(dwStyle);
	m_list3.InsertColumn(0, "进程名", LVCFMT_LEFT, 100);
	m_list3.InsertColumn(1, "剩余时间", LVCFMT_LEFT, 100);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Dlg1::OnBnClickedButton1()
{
	duoJiFanKui djfk;
	// TODO: 在此添加控件通知处理程序代码
	djfk.CreateNewProcess(pName,pTime);

}


void Dlg1::OnEnChangeEdit2()
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


void Dlg1::OnEnChangeEdit1()
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



void Dlg1::OnLvnItemchangedList5(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
