
// MFC3_20(2)View.cpp : CMFC3_202View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3_20(2).h"
#endif

#include "MFC3_20(2)Doc.h"
#include "MFC3_20(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3_202View

IMPLEMENT_DYNCREATE(CMFC3_202View, CView)

BEGIN_MESSAGE_MAP(CMFC3_202View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC3_202View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC3_202View ����/����

CMFC3_202View::CMFC3_202View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC3_202View::~CMFC3_202View()
{
}

BOOL CMFC3_202View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC3_202View ����

void CMFC3_202View::OnDraw(CDC* pDC)
{
	CMFC3_202Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//CClientDC dc(this);
	if (flag == true)
	{
		img.Draw(pDC->m_hDC, sx, sy, w, h);
	}
	
	
}


// CMFC3_202View ���

#ifdef _DEBUG
void CMFC3_202View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3_202View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3_202Doc* CMFC3_202View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3_202Doc)));
	return (CMFC3_202Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3_202View ��Ϣ�������


void CMFC3_202View::OnFileOpen()
{
	// TODO: �ڴ���������������
	flag = true;
	CClientDC dc(this);
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString file = cfd.GetPathName();
		img.Load(file);
		CRect rect;
		GetClientRect(&rect);
		float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
		if (rect_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}
		img.Draw(dc.m_hDC, sx, sy, w, h);
		
	}

	
}
