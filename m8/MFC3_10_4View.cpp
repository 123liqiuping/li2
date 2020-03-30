
// MFC3_10_4View.cpp: CMFC3104View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_10_4.h"
#endif

#include "MFC3_10_4Doc.h"
#include "MFC3_10_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3104View

IMPLEMENT_DYNCREATE(CMFC3104View, CView)

BEGIN_MESSAGE_MAP(CMFC3104View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3104View 构造/析构

CMFC3104View::CMFC3104View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3104View::~CMFC3104View()
{
}

BOOL CMFC3104View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3104View 绘图

void CMFC3104View::OnDraw(CDC* /*pDC*/)
{
	CMFC3104Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC3104View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3104View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3104View 诊断

#ifdef _DEBUG
void CMFC3104View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3104View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3104Doc* CMFC3104View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3104Doc)));
	return (CMFC3104Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3104View 消息处理程序


void CMFC3104View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC3104Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s;
	s.Format(_T("%d+%d=%d"), pDoc->A, pDoc->B, pDoc->A + pDoc->B);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
