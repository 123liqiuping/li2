
// MFCy2Doc.h : CMFCy2Doc ��Ľӿ�
//


#pragma once
#include "MFCy2Set.h"


class CMFCy2Doc : public CDocument
{
protected: // �������л�����
	CMFCy2Doc();
	DECLARE_DYNCREATE(CMFCy2Doc)

// ����
public:
	CMFCy2Set m_MFCy2Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCy2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
