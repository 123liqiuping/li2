
// MFC3_23_1View.cpp: CMFC3231View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_23_1.h"
#endif

#include "MFC3_23_1Doc.h"
#include "MFC3_23_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3231View

IMPLEMENT_DYNCREATE(CMFC3231View, CView)

BEGIN_MESSAGE_MAP(CMFC3231View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3231View 构造/析构

CMFC3231View::CMFC3231View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3231View::~CMFC3231View()
{
}

BOOL CMFC3231View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3231View 绘图

void CMFC3231View::OnDraw(CDC* /*pDC*/)
{
	CMFC3231Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC3231View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3231View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3231View 诊断

#ifdef _DEBUG
void CMFC3231View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3231View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3231Doc* CMFC3231View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3231Doc)));
	return (CMFC3231Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3231View 消息处理程序


void CMFC3231View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMButtonDown(nFlags, point);
}


void CMFC3231View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CPoint p;
	CRect cr;
	this->GetClientRect(cr);
	p = cr.CenterPoint();
	int i = 0;
	while(i < 100) {
		CClientDC dc2(this);
	//}
	//for (int i = 0; i < 100; i++) {
		dc2.Ellipse(p.x - i, p.y - i, p.x + i, p.y + i);
		i++;
	}
		CView::OnLButtonDown(nFlags, point);
	
}
