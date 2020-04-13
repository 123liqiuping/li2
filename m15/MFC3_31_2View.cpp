
// MFC3_31_2View.cpp: CMFC3312View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_31_2.h"
#endif

#include "MFC3_31_2Doc.h"
#include "MFC3_31_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3312View

IMPLEMENT_DYNCREATE(CMFC3312View, CView)

BEGIN_MESSAGE_MAP(CMFC3312View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3312View 构造/析构

CMFC3312View::CMFC3312View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3312View::~CMFC3312View()
{
}

BOOL CMFC3312View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3312View 绘图

void CMFC3312View::OnDraw(CDC* /*pDC*/)
{
	CMFC3312Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	dc.Rectangle(200,200,400,240);

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC3312View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3312View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3312View 诊断

#ifdef _DEBUG
void CMFC3312View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3312View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3312Doc* CMFC3312View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3312Doc)));
	return (CMFC3312Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3312View 消息处理程序


void CMFC3312View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s1;
	CClientDC dc(this);
	if (nChar == 'a')
	{
		s += 'a';
		s1 = 'a';
		
	}
	else if (nChar == 'b')
	{
		s += 'b';
		s1 = 'b';
		
	}
	else if (nChar == 'c')
	{
		s += 'c';
		s1 = 'c';
		
	}
	else if (nChar == 'd')
	{
		s += 'd';
		s1 = 'd';
	}
	dc.TextOutW(210, 210, s);
	dc.TextOutW(p.x, p.y, s1);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC3312View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p = point;
	CView::OnLButtonDown(nFlags, point);
}
