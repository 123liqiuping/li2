// MyDlg2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Zh1.h"
#include "MyDlg2.h"
#include "afxdialogex.h"


// MyDlg2 �Ի���

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


// MyDlg2 ��Ϣ�������


void MyDlg2::OnEnChangeEdit11()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
