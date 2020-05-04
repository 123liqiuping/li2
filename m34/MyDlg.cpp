// MyDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC4_21_2.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ifstream ifs(_T("F:\\abc.txt"));
	string s;
	ifs >> s;
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		CImage img;
		img.Load(CString(s.c_str()));
		CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
		img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
	}

}
