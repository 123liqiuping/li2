
// MFC3_02_2View.cpp: CMFC3022View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_02_2.h"
#endif

#include "MFC3_02_2Doc.h"
#include "MFC3_02_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3022View

IMPLEMENT_DYNCREATE(CMFC3022View, CView)

BEGIN_MESSAGE_MAP(CMFC3022View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3022View 构造/析构

CMFC3022View::CMFC3022View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3022View::~CMFC3022View()
{
}

BOOL CMFC3022View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3022View 绘图

void CMFC3022View::OnDraw(CDC* pDC)
{
	CMFC3022Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	int r = rand() % 40 + 39;
	pDoc->cr.left = pDoc->p.x - r;
	pDoc->cr.top = pDoc->p.y - r;
	pDoc->cr.right = pDoc->p.x + r;
	pDoc->cr.bottom = pDoc->p.y + r;
	pDC->Ellipse(pDoc->cr);

	

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3022View 诊断

#ifdef _DEBUG
void CMFC3022View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3022View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3022Doc* CMFC3022View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3022Doc)));
	return (CMFC3022Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3022View 消息处理程序


void CMFC3022View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC3022Doc* pDoc = GetDocument();
	pDoc->p = point;
	InvalidateRect(NULL,FALSE);

	CView::OnLButtonDown(nFlags, point);
}
