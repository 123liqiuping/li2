
// MFC3_31_1View.cpp: CMFC3311View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_31_1.h"
#endif

#include "MFC3_31_1Doc.h"
#include "MFC3_31_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3311View

IMPLEMENT_DYNCREATE(CMFC3311View, CView)

BEGIN_MESSAGE_MAP(CMFC3311View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFC3311View 构造/析构

CMFC3311View::CMFC3311View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3311View::~CMFC3311View()
{
}

BOOL CMFC3311View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3311View 绘图

void CMFC3311View::OnDraw(CDC* pDC)
{
	CMFC3311Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	CClientDC dc(this);
	dc.Rectangle(200,200,400,240);
}

void CMFC3311View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3311View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3311View 诊断

#ifdef _DEBUG
void CMFC3311View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3311View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3311Doc* CMFC3311View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3311Doc)));
	return (CMFC3311Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3311View 消息处理程序


void CMFC3311View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	
	if (nChar == 'a')
		s = 'a';
	else if(nChar == 'b')
		s = s+'b';
	else if (nChar == 'c')
		s = s + 'c';
		dc.TextOutW(210, 210, s); 
	

	CView::OnChar(nChar, nRepCnt, nFlags);
}
