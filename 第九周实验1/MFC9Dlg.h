
// MFC9Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC9Dlg �Ի���
class CMFC9Dlg : public CDialogEx
{
// ����
public:
	CMFC9Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC9_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox Lbox;
	CString s;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	virtual void Serialize(CArchive& ar);
};
