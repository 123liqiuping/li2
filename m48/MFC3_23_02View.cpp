
// MFC3_23_02View.cpp: CMFC32302View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_23_02.h"
#endif

#include "MFC3_23_02Doc.h"
#include "MFC3_23_02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC32302View

IMPLEMENT_DYNCREATE(CMFC32302View, CView)

BEGIN_MESSAGE_MAP(CMFC32302View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC32302View 构造/析构

CMFC32302View::CMFC32302View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC32302View::~CMFC32302View()
{
}

BOOL CMFC32302View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC32302View 绘图

void CMFC32302View::OnDraw(CDC* pDC)
{
	CMFC32302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CBrush brush(pDoc->color);
	CBrush* old;
	old = pDC->SelectObject(&brush);
	//CRect cr;
	this->GetClientRect(pDoc->cr);
	int x, y;
	x = pDoc->cr.right / 2;
	y = pDoc->cr.bottom / 2;
	pDoc->cr.left = x - pDoc->r;
	pDoc->cr.top = y - pDoc->r;
	pDoc->cr.right = x + pDoc->r;
	pDoc->cr.bottom = y + pDoc->r;
	pDC->Ellipse(pDoc->cr);
	pDC->SelectObject(old);
	this->ReleaseDC(pDC);
	
}


// CMFC32302View 诊断

#ifdef _DEBUG
void CMFC32302View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC32302View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC32302Doc* CMFC32302View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC32302Doc)));
	return (CMFC32302Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC32302View 消息处理程序


void CMFC32302View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC32302Doc* pDoc = GetDocument();
	pDoc->r += 5;
	pDoc->b += 20;
	InvalidateRect(NULL, FALSE);
	CView::OnLButtonDown(nFlags, point);
}
