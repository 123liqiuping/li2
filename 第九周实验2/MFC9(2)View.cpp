
// MFC9(2)View.cpp : CMFC92View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC9(2).h"
#endif

#include "MFC9(2)Doc.h"
#include "MFC9(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC92View

IMPLEMENT_DYNCREATE(CMFC92View, CView)

BEGIN_MESSAGE_MAP(CMFC92View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC92View 构造/析构

CMFC92View::CMFC92View()
{
	// TODO: 在此处添加构造代码
	cr.left = 50;
	cr.top = 50;
	cr.right = 450;
	cr.bottom = 350;

}

CMFC92View::~CMFC92View()
{
}

BOOL CMFC92View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC92View 绘制

void CMFC92View::OnDraw(CDC* pDC)
{
	CMFC92Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(cr);
}


// CMFC92View 诊断

#ifdef _DEBUG
void CMFC92View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC92View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC92Doc* CMFC92View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC92Doc)));
	return (CMFC92Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC92View 消息处理程序


void CMFC92View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	cr.left += 5;
	cr.top += 5;
	cr.right -= 5;
	cr.bottom -= 5;
	InvalidateRect(NULL,FALSE);

	CView::OnLButtonDown(nFlags, point);
}
