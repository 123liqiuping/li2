#pragma once


// MyDlg1 �Ի���

class MyDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg1)

public:
	MyDlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit14();
	afx_msg void OnEnChangeEdit12();
	afx_msg void OnEnChangeEdit11();
	CString i1;
	long i2;
	CString i3;
	CString i4;
	CString i5;
	long i6;
	CString i7;
	CString i8;
	CString i9;
};
