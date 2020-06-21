
// MFC3_20(2)View.cpp : CMFC3_202View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFC3_202View 构造/析构

CMFC3_202View::CMFC3_202View()
{
	// TODO: 在此处添加构造代码

}

CMFC3_202View::~CMFC3_202View()
{
}

BOOL CMFC3_202View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3_202View 绘制

void CMFC3_202View::OnDraw(CDC* pDC)
{
	CMFC3_202Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//CClientDC dc(this);
	if (flag == true)
	{
		img.Draw(pDC->m_hDC, sx, sy, w, h);
	}
	
	
}


// CMFC3_202View 诊断

#ifdef _DEBUG
void CMFC3_202View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3_202View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3_202Doc* CMFC3_202View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3_202Doc)));
	return (CMFC3_202Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3_202View 消息处理程序


void CMFC3_202View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
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
