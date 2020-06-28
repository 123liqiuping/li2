// MyDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "Zh1.h"
#include "MyDlg1.h"
#include "afxdialogex.h"


// MyDlg1 对话框

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, i1(_T(""))
	, i2(0)
	, i3(_T(""))
	, i4(_T(""))
	, i5(_T(""))
	, i6(0)
	, i7(_T(""))
	, i8(_T(""))
	, i9(_T(""))
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, i1);
	DDX_Text(pDX, IDC_EDIT11, i2);
	DDX_Text(pDX, IDC_EDIT12, i3);
	DDX_Text(pDX, IDC_EDIT13, i4);
	DDX_Text(pDX, IDC_EDIT14, i5);
	DDX_Text(pDX, IDC_EDIT15, i6);
	DDX_Text(pDX, IDC_EDIT16, i7);
	DDX_Text(pDX, IDC_EDIT17, i8);
	DDX_Text(pDX, IDC_EDIT18, i9);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT14, &MyDlg1::OnEnChangeEdit14)
	ON_EN_CHANGE(IDC_EDIT12, &MyDlg1::OnEnChangeEdit12)
	ON_EN_CHANGE(IDC_EDIT11, &MyDlg1::OnEnChangeEdit11)
END_MESSAGE_MAP()


// MyDlg1 消息处理程序


void MyDlg1::OnEnChangeEdit14()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MyDlg1::OnEnChangeEdit12()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MyDlg1::OnEnChangeEdit11()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
