
// MFC3_24View.cpp: CMFC324View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_24.h"
#endif

#include "MFC3_24Doc.h"
#include "MFC3_24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC324View

IMPLEMENT_DYNCREATE(CMFC324View, CView)

BEGIN_MESSAGE_MAP(CMFC324View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_VIEW_MINGZI, &CMFC324View::OnViewMingzi)
END_MESSAGE_MAP()

// CMFC324View 构造/析构

CMFC324View::CMFC324View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC324View::~CMFC324View()
{
}

BOOL CMFC324View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC324View 绘图

void CMFC324View::OnDraw(CDC* /*pDC*/)
{
	CMFC324Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC324View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC324View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC324View 诊断

#ifdef _DEBUG
void CMFC324View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC324View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC324Doc* CMFC324View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC324Doc)));
	return (CMFC324Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC324View 消息处理程序


void CMFC324View::OnViewMingzi()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("李秋萍");
	CClientDC dc(this);
	dc.TextOutW(200,200,s);
}
