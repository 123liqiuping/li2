// MyDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC4_20_5.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, R(0)
	, G(0)
	, B(0)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, R);
	DDV_MinMaxInt(pDX, R, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, G);
	DDV_MinMaxInt(pDX, G, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, B);
	DDV_MinMaxInt(pDX, B, 0, 255);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
END_MESSAGE_MAP()


// MyDlg 消息处理程序
