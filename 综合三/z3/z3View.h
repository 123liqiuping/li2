
// z3View.h : Cz3View ��Ľӿ�
//

#pragma once

class Cz3Set;

class Cz3View : public CRecordView
{
protected: // �������л�����
	Cz3View();
	DECLARE_DYNCREATE(Cz3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_Z3_FORM };
#endif
	Cz3Set* m_pSet;

// ����
public:
	Cz3Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~Cz3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long s;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // z3View.cpp �еĵ��԰汾
inline Cz3Doc* Cz3View::GetDocument() const
   { return reinterpret_cast<Cz3Doc*>(m_pDocument); }
#endif

