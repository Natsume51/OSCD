// Dlg1.cpp: 实现文件

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "Dlg1.h"
#include "duoJiFanKui.h"
#include <iostream>
#include "process.h"
#define finish_a_time_slice (WM_USER + 1)

// Dlg1 对话框
IMPLEMENT_DYNAMIC(Dlg1, CDialogEx)

Dlg1::Dlg1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	;
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
	DDX_Control(pDX, IDC_PROGRESS2, m_TotalProCtrl);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_LIST1, m_list_all);
}


BEGIN_MESSAGE_MAP(Dlg1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dlg1::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &Dlg1::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &Dlg1::OnEnChangeEdit1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST5, &Dlg1::OnLvnItemchangedList5)
	ON_EN_CHANGE(IDC_EDIT3, &Dlg1::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON2, &Dlg1::OnBnClickedButton2)
//	ON_MESSAGE(finish_a_time_slice, &Dlg1::OnFinishATimeSlice)
END_MESSAGE_MAP()


// Dlg1 消息处理程序


BOOL Dlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = m_list_all.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list_all.SetExtendedStyle(dwStyle);
	m_list_all.InsertColumn(0, "进程名", LVCFMT_LEFT, 100);
	m_list_all.InsertColumn(1, "剩余时间", LVCFMT_LEFT, 100);
	dwStyle = m_list1.GetExtendedStyle();
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

void Dlg1::TotalProgressStep(int n)
{
	m_TotalProCtrl.OffsetPos(n);
}

void Dlg1::OnBnClickedButton1()
{
	process newProcess(pName, pTime, pArrTime);
	pList.push_process(newProcess);
	UpdateQueue(pList.get_list(), 3);
	// TODO: 在此添加控件通知处理程序代码
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


void Dlg1::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString arrTime;
	m_edit3.GetWindowText(arrTime);
	pArrTime = atoi(arrTime);
	;
}


void Dlg1::OnBnClickedButton2()
{
	duojifankui djfk(this, pList, 1, 2, 4);
	djfk.scheduling();
	
}

void Dlg1::UpdateQueue(vector<process> pList,int queueNum)
{
	if (queueNum == 0)
	{
		m_list1.DeleteAllItems();
		for (int i = 0; i < pList.size(); i++)
		{
			CString str;
			str.Format(_T("%d"), pList[i].get_run_time());
			m_list1.InsertItem(i, _T(""));
			m_list1.SetItemText(i, 0, pList[i].get_process_name().c_str());
			m_list1.SetItemText(i, 1, str);
		}
	}
	else if (queueNum == 1)
	{
		m_list2.DeleteAllItems();
		for (int i = 0; i < pList.size(); i++)
		{
			CString str;
			str.Format(_T("%d"), pList[i].get_run_time());
			m_list2.InsertItem(i, _T(""));
			m_list2.SetItemText(i, 0, pList[i].get_process_name().c_str());
			m_list2.SetItemText(i, 1, str);
		}
	}
	else if (queueNum == 2)
	{
		m_list3.DeleteAllItems();
		for (int i = 0; i < pList.size(); i++)
		{
			CString str;
			str.Format(_T("%d"), pList[i].get_run_time());
			m_list3.InsertItem(i, _T(""));
			m_list3.SetItemText(i, 0, pList[i].get_process_name().c_str());
			m_list3.SetItemText(i, 1, str);
		}
	}
	else if (queueNum == 3)
	{
		m_list_all.DeleteAllItems();
		for (int i = 0; i < pList.size(); i++)
		{
			CString str;
			str.Format(_T("%d"), pList[i].get_run_time());
			m_list_all.InsertItem(i, _T(""));
			m_list_all.SetItemText(i, 0, pList[i].get_process_name().c_str());
			m_list_all.SetItemText(i, 1, str);
		}
	}
	else
		throw std::invalid_argument("queueNum should be 0,1 or 2");
}