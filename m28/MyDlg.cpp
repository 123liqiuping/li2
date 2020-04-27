// MyDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC4_20_1.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "math.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, z(0)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDV_MinMaxFloat(pDX, x, 0, 1000);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDV_MinMaxFloat(pDX, y, 0, 1000);
	DDX_Text(pDX, IDC_EDIT3, z);
	DDV_MinMaxFloat(pDX, z, 0, 10000);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &MyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &MyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &MyDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &MyDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	z = x + y;
	UpdateData(false);
}


void MyDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	z = x-y;
	UpdateData(false);
}


void MyDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	z = x * y;
	UpdateData(false);
}


void MyDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	z = x / y;
	UpdateData(false);
}


void MyDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	z = sqrt(x);
	UpdateData(false);
}


void MyDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	x = 1;
	z = x / y;
	UpdateData(false);
}
