// MyDlg3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Zh1.h"
#include "MyDlg3.h"
#include "afxdialogex.h"


// MyDlg3 �Ի���

IMPLEMENT_DYNAMIC(MyDlg3, CDialogEx)

MyDlg3::MyDlg3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, a(_T(""))
{

}

MyDlg3::~MyDlg3()
{
}

void MyDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
}


BEGIN_MESSAGE_MAP(MyDlg3, CDialogEx)
END_MESSAGE_MAP()


// MyDlg3 ��Ϣ�������
