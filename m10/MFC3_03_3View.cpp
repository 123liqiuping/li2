
// MFC3_03_3View.cpp: CMFC3033View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_03_3.h"
#endif

#include "MFC3_03_3Doc.h"
#include "MFC3_03_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3033View

IMPLEMENT_DYNCREATE(CMFC3033View, CView)

BEGIN_MESSAGE_MAP(CMFC3033View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3033View 构造/析构

CMFC3033View::CMFC3033View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3033View::~CMFC3033View()
{
}

BOOL CMFC3033View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3033View 绘图

void CMFC3033View::OnDraw(CDC* /*pDC*/)
{
	CMFC3033Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC3033View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3033View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3033View 诊断

#ifdef _DEBUG
void CMFC3033View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3033View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3033Doc* CMFC3033View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3033Doc)));
	return (CMFC3033Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3033View 消息处理程序


void CMFC3033View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CClientDC dc(this);
	CMFC3033Doc* pDoc = GetDocument();
	pDoc->count += 1;
	

	CView::OnLButtonDown(nFlags, point);
}


void CMFC3033View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CMFC3033Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("count=%d"), pDoc->count);
	dc.TextOutW(200, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
