
// MFC3_16View.cpp: CMFC316View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_16.h"
#endif

#include "MFC3_16Doc.h"
#include "MFC3_16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC316View

IMPLEMENT_DYNCREATE(CMFC316View, CView)

BEGIN_MESSAGE_MAP(CMFC316View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC316View 构造/析构

CMFC316View::CMFC316View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC316View::~CMFC316View()
{
}

BOOL CMFC316View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC316View 绘图

void CMFC316View::OnDraw(CDC* pDC)
{
	CMFC316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}


// CMFC316View 诊断

#ifdef _DEBUG
void CMFC316View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC316View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC316Doc* CMFC316View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC316Doc)));
	return (CMFC316Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC316View 消息处理程序


void CMFC316View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC316Doc* pDoc = GetDocument();
	pDoc->p1 = point;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC316View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC316Doc* pDoc = GetDocument();
	//pDoc->p2 = point;
	CRect cr;
	CClientDC dc(this);
	dc.Rectangle(pDoc->p1.x, pDoc->p1.y, point.x, point.y);
	CView::OnLButtonUp(nFlags, point);
}


void CMFC316View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
}
