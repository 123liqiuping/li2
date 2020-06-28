
// Zh1View.h : CZh1View ��Ľӿ�
//

#pragma once

class CZh1Set;

class CZh1View : public CRecordView
{
protected: // �������л�����
	CZh1View();
	DECLARE_DYNCREATE(CZh1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ZH1_FORM };
#endif
	CZh1Set* m_pSet;

// ����
public:
	CZh1Doc* GetDocument() const;
	void draw_pic(CString file);

// ����
public:
	CString path;

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CZh1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	long number;
	CString Zy;
	CString sex;
	CString birth;
	long phone;
	CString dz;
	CString pname;
	CString jname;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDele();
	afx_msg void OnAdd();
	afx_msg void OnUpdate();
	afx_msg void OnSearch();
	afx_msg void OnSort();
};

#ifndef _DEBUG  // Zh1View.cpp �еĵ��԰汾
inline CZh1Doc* CZh1View::GetDocument() const
   { return reinterpret_cast<CZh1Doc*>(m_pDocument); }
#endif

