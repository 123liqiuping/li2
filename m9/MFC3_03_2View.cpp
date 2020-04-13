
// MFC3_03_2View.cpp: CMFC3032View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_03_2.h"
#endif

#include "MFC3_03_2Doc.h"
#include "MFC3_03_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3032View

IMPLEMENT_DYNCREATE(CMFC3032View, CView)

BEGIN_MESSAGE_MAP(CMFC3032View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC3032View 构造/析构

CMFC3032View::CMFC3032View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3032View::~CMFC3032View()
{
}

BOOL CMFC3032View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3032View 绘图

void CMFC3032View::OnDraw(CDC* pDC)
{
	CMFC3032Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString a;
	a.Format(_T("%d"), pDoc->A);
	pDC->TextOutW(200, 200, pDoc->s);
	pDC->TextOutW(300, 300, a);
}

void CMFC3032View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3032View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3032View 诊断

#ifdef _DEBUG
void CMFC3032View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3032View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3032Doc* CMFC3032View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3032Doc)));
	return (CMFC3032Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3032View 消息处理程序
