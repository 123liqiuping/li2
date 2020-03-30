﻿
// MFC3_24_2View.cpp: CMFC3242View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_24_2.h"
#endif

#include "MFC3_24_2Doc.h"
#include "MFC3_24_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3242View

IMPLEMENT_DYNCREATE(CMFC3242View, CView)

BEGIN_MESSAGE_MAP(CMFC3242View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC3242View 构造/析构

CMFC3242View::CMFC3242View() noexcept
{
	// TODO: 在此处添加构造代码
	BITMAP bm;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&bm);
	m_width = bm.bmWidth;
	m_height = bm.bmHeight;


}

CMFC3242View::~CMFC3242View()
{
}

BOOL CMFC3242View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3242View 绘图

void CMFC3242View::OnDraw(CDC* pDC)
{
	CMFC3242Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC menDC;
	menDC.CreateCompatibleDC(NULL);
	menDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0,0,m_width,m_height,&menDC,0,0,SRCCOPY);
}

void CMFC3242View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3242View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3242View 诊断

#ifdef _DEBUG
void CMFC3242View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3242View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3242Doc* CMFC3242View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3242Doc)));
	return (CMFC3242Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3242View 消息处理程序
