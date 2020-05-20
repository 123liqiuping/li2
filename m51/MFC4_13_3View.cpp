
// MFC4_13_3View.cpp: CMFC4133View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_13_3.h"
#endif

#include "MFC4_13_3Doc.h"
#include "MFC4_13_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4133View

IMPLEMENT_DYNCREATE(CMFC4133View, CView)

BEGIN_MESSAGE_MAP(CMFC4133View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC4133View 构造/析构

CMFC4133View::CMFC4133View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	cr.left = 0;
	cr.top = 200;
	cr.right = 100;
	cr.bottom = 300;

}

CMFC4133View::~CMFC4133View()
{
}

BOOL CMFC4133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4133View 绘图

void CMFC4133View::OnDraw(CDC* pDC)
{
	CMFC4133Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (set)
	{
		SetTimer(1, 300, NULL);
		set = false;
	}
	
	pDC->Ellipse(cr);
}


// CMFC4133View 诊断

#ifdef _DEBUG
void CMFC4133View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4133View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4133Doc* CMFC4133View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4133Doc)));
	return (CMFC4133Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4133View 消息处理程序


void CMFC4133View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	a = 1;
	set1 = true;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC4133View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set1=false;

	CView::OnLButtonDblClk(nFlags, point);
}


void CMFC4133View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	this->GetClientRect(rect);
	if (a = 1 && set1)
	{
		cr.left += 50;
		cr.right += 50;
		
	}
	if (cr.right >= rect.right)
	{
		cr.left -= 50;
		cr.right -= 50;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
