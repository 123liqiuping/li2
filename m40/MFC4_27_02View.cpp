
// MFC4_27_02View.cpp: CMFC42702View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_27_02.h"
#endif

#include "MFC4_27_02Doc.h"
#include "MFC4_27_02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42702View

IMPLEMENT_DYNCREATE(CMFC42702View, CView)

BEGIN_MESSAGE_MAP(CMFC42702View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC42702View 构造/析构

CMFC42702View::CMFC42702View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC42702View::~CMFC42702View()
{
}

BOOL CMFC42702View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC42702View 绘图

void CMFC42702View::OnDraw(CDC* pDC)
{
	CMFC42702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(pDoc->cr);


}


// CMFC42702View 诊断

#ifdef _DEBUG
void CMFC42702View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42702View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42702Doc* CMFC42702View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42702Doc)));
	return (CMFC42702Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42702View 消息处理程序


void CMFC42702View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	CMFC42702Doc* pDoc = GetDocument();
	pDoc->cr.left += 5;
	pDoc->cr.top += 5;
	pDoc->cr.right -= 5;
	pDoc->cr.bottom -= 5;
	InvalidateRect(NULL, FALSE);
	CView::OnLButtonDown(nFlags, point);

}
