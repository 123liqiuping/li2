
// MFCtxView.cpp: CMFCtxView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtx.h"
#endif

#include "MFCtxDoc.h"
#include "MFCtxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtxView

IMPLEMENT_DYNCREATE(CMFCtxView, CView)

BEGIN_MESSAGE_MAP(CMFCtxView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtxView 构造/析构

CMFCtxView::CMFCtxView() noexcept
{
	// TODO: 在此处添加构造代码
	cr.left = 50;
	cr.top = 50;
	cr.right = 600;
	cr.bottom = 400;

}

CMFCtxView::~CMFCtxView()
{
}

BOOL CMFCtxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtxView 绘图

void CMFCtxView::OnDraw(CDC* pDC)
{
	CMFCtxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPen newp(PS_DASH, 1, RGB(0, 0, 0));
	CPen* oldp = pDC->SelectObject(&newp);
	pDC->MoveTo(rect.left, rect.top);
	pDC->LineTo(rect.right, rect.top);
	pDC->LineTo(rect.right, rect.bottom);
	pDC->LineTo(rect.left, rect.bottom);
	pDC->LineTo(rect.left, rect.top);
	pDC->SelectObject(oldp);
	pDC->Ellipse(cr);
}


// CMFCtxView 诊断

#ifdef _DEBUG
void CMFCtxView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtxDoc* CMFCtxView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtxDoc)));
	return (CMFCtxDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtxView 消息处理程序


void CMFCtxView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	rect.left = 50;
	rect.top = 50;
	rect.right = 600;
	rect.bottom = 400;
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
