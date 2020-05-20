
// MFC3_09_1View.cpp: CMFC3091View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_09_1.h"
#endif

#include "MFC3_09_1Doc.h"
#include "MFC3_09_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3091View

IMPLEMENT_DYNCREATE(CMFC3091View, CView)

BEGIN_MESSAGE_MAP(CMFC3091View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3091View 构造/析构

CMFC3091View::CMFC3091View() noexcept
{
	// TODO: 在此处添加构造代码
	
	
	
}

CMFC3091View::~CMFC3091View()
{
}

BOOL CMFC3091View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3091View 绘图

void CMFC3091View::OnDraw(CDC* pDC)
{
	CMFC3091Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	pDC->Ellipse(cr);
}


// CMFC3091View 诊断

#ifdef _DEBUG
void CMFC3091View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3091View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3091Doc* CMFC3091View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3091Doc)));
	return (CMFC3091Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3091View 消息处理程序


void CMFC3091View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	this->GetClientRect(&rect);
	cr.left = 0;
	cr.top = 0;
	cr.right = rect.bottom;
	cr.bottom = rect.bottom;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
