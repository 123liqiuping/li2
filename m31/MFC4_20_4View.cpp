
// MFC4_20_4View.cpp: CMFC4204View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_20_4.h"
#endif

#include "MFC4_20_4Doc.h"
#include "MFC4_20_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4204View

IMPLEMENT_DYNCREATE(CMFC4204View, CView)

BEGIN_MESSAGE_MAP(CMFC4204View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC4204View 构造/析构

CMFC4204View::CMFC4204View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4204View::~CMFC4204View()
{
}

BOOL CMFC4204View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4204View 绘图

void CMFC4204View::OnDraw(CDC* pDC)
{
	CMFC4204Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(pDoc->cr);

}

void CMFC4204View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC4204View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC4204View 诊断

#ifdef _DEBUG
void CMFC4204View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4204View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4204Doc* CMFC4204View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4204Doc)));
	return (CMFC4204Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4204View 消息处理程序


void CMFC4204View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4204Doc* pDoc = GetDocument();
	CClientDC dc(this);
	int x1 = pDoc->cr.left, y1 = pDoc->cr.top, x2 = pDoc->cr.right, y2 = pDoc->cr.bottom;
	CRect ct(x1, y1, x2, y2);
	dc.Rectangle(ct);
	InvalidateRect(NULL,FALSE);

	CView::OnLButtonDown(nFlags, point);

}
