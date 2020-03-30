
// MFC7_5View.cpp: CMFC75View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7_5.h"
#endif

#include "MFC7_5Doc.h"
#include "MFC7_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC75View

IMPLEMENT_DYNCREATE(CMFC75View, CView)

BEGIN_MESSAGE_MAP(CMFC75View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC75View 构造/析构

CMFC75View::CMFC75View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	for (int i = 0; i < 5; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t,0,t+20,20);
		cr.Add(rect);
	}

}

CMFC75View::~CMFC75View()
{
}

BOOL CMFC75View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC75View 绘图

void CMFC75View::OnDraw(CDC* pDC)
{
	CMFC75Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < 5; i++)
		{
			SetTimer(i,rand() % 400 + 100,NULL);
			set = false;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		pDC->Ellipse(cr[i]);
	}
	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC75View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC75View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC75View 诊断

#ifdef _DEBUG
void CMFC75View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC75View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC75Doc* CMFC75View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC75Doc)));
	return (CMFC75Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC75View 消息处理程序


void CMFC75View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	cr[i].top+=10;
	cr[i].bottom += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
