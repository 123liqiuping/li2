// UPDATE_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "z3.h"
#include "UPDATE_DLG.h"
#include "afxdialogex.h"


// UPDATE_DLG 对话框

IMPLEMENT_DYNAMIC(UPDATE_DLG, CDialogEx)

UPDATE_DLG::UPDATE_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_UPDA, pParent)
	, i2(0)
{

}

UPDATE_DLG::~UPDATE_DLG()
{
}

void UPDATE_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, i2);
}


BEGIN_MESSAGE_MAP(UPDATE_DLG, CDialogEx)
END_MESSAGE_MAP()


// UPDATE_DLG 消息处理程序
