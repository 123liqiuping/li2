
// MFC9(2)View.h : CMFC92View ��Ľӿ�
//

#pragma once


class CMFC92View : public CView
{
protected: // �������л�����
	CMFC92View();
	DECLARE_DYNCREATE(CMFC92View)

// ����
public:
	CMFC92Doc* GetDocument() const;

// ����
public:
	CRect cr;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC92View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC9(2)View.cpp �еĵ��԰汾
inline CMFC92Doc* CMFC92View::GetDocument() const
   { return reinterpret_cast<CMFC92Doc*>(m_pDocument); }
#endif

