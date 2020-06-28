#pragma once


// MyDlg2 对话框

class MyDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg2)

public:
	MyDlg2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit11();
	CString r1;
	long r2;
	CString r3;
	CString r4;
	CString r5;
	long r6;
	CString r7;
	CString r8;
	CString r9;
};
