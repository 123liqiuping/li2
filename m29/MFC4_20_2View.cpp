
// MFC4_20_2View.cpp: CMFC4202View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_20_2.h"
#endif

#include "MFC4_20_2Doc.h"
#include "MFC4_20_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4202View

IMPLEMENT_DYNCREATE(CMFC4202View, CView)

BEGIN_MESSAGE_MAP(CMFC4202View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC4202View 构造/析构

CMFC4202View::CMFC4202View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4202View::~CMFC4202View()
{
}

BOOL CMFC4202View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4202View 绘图

void CMFC4202View::OnDraw(CDC* pDC)
{
	CMFC4202Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(pDoc->cr);
}

void CMFC4202View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC4202View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC4202View 诊断

#ifdef _DEBUG
void CMFC4202View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4202View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4202Doc* CMFC4202View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4202Doc)));
	return (CMFC4202Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4202View 消息处理程序


void CMFC4202View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4202Doc* pDoc = GetDocument();
	int i = 1;
	while(point.x > pDoc->cr.left&& point.y > pDoc->cr.top)
	{
		pDoc->cr.left+=i;
		pDoc->cr.top +=i;
		pDoc->cr.right+=i;
		pDoc->cr.bottom+=i;
		i++;
	}
	InvalidateRect(NULL,FALSE);
	CView::OnLButtonDown(nFlags, point);

}


void CMFC4202View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
}
