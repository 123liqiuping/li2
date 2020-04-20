// MyDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC4_14_1.h"
#include "MyDlg.h"
#include "afxdialogex.h"


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
	DDX_Control(pDX, IDC_LIST1, Lbox);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	s = " ";
	// TODO:  在此添加额外的初始化
	Lbox.AddString(_T("文件1"));
	Lbox.AddString(_T("文件2"));
	Lbox.AddString(_T("文件3"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s1;
	int n = Lbox.GetCurSel();
	Lbox.GetText(n,s);


}
