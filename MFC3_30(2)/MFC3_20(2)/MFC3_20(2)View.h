
// MFC3_20(2)View.h : CMFC3_202View ��Ľӿ�
//

#pragma once


class CMFC3_202View : public CView
{
protected: // �������л�����
	CMFC3_202View();
	DECLARE_DYNCREATE(CMFC3_202View)

// ����
public:
	CMFC3_202Doc* GetDocument() const;

// ����
public:
	bool flag;
	CImage img;
	int sx, sy, w, h;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC3_202View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC3_20(2)View.cpp �еĵ��԰汾
inline CMFC3_202Doc* CMFC3_202View::GetDocument() const
   { return reinterpret_cast<CMFC3_202Doc*>(m_pDocument); }
#endif

