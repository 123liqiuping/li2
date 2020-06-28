// MyDlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "Zh1.h"
#include "MyDlg2.h"
#include "afxdialogex.h"


// MyDlg2 对话框

IMPLEMENT_DYNAMIC(MyDlg2, CDialogEx)

MyDlg2::MyDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, r1(_T(""))
	, r2(0)
	, r3(_T(""))
	, r4(_T(""))
	, r5(_T(""))
	, r6(0)
	, r7(_T(""))
	, r8(_T(""))
	, r9(_T(""))
{

}

MyDlg2::~MyDlg2()
{
}

void MyDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, r1);
	DDX_Text(pDX, IDC_EDIT11, r2);
	DDX_Text(pDX, IDC_EDIT12, r3);
	DDX_Text(pDX, IDC_EDIT13, r4);
	DDX_Text(pDX, IDC_EDIT14, r5);
	DDX_Text(pDX, IDC_EDIT15, r6);
	DDX_Text(pDX, IDC_EDIT16, r7);
	DDX_Text(pDX, IDC_EDIT17, r8);
	DDX_Text(pDX, IDC_EDIT18, r9);
}


BEGIN_MESSAGE_MAP(MyDlg2, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT11, &MyDlg2::OnEnChangeEdit11)
END_MESSAGE_MAP()


// MyDlg2 消息处理程序


void MyDlg2::OnEnChangeEdit11()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
