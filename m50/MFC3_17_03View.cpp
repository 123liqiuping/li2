
// MFC3_17_03View.cpp: CMFC31703View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_17_03.h"
#endif

#include "MFC3_17_03Doc.h"
#include "MFC3_17_03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC31703View

IMPLEMENT_DYNCREATE(CMFC31703View, CView)

BEGIN_MESSAGE_MAP(CMFC31703View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC31703View 构造/析构

CMFC31703View::CMFC31703View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	cr.left = 50;
	cr.top = 0;
	cr.right = 100;
	cr.bottom = 50;
	

}

CMFC31703View::~CMFC31703View()
{
}

BOOL CMFC31703View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC31703View 绘图

void CMFC31703View::OnDraw(CDC* pDC)
{
	CMFC31703Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		SetTimer(1, 50, NULL);
		set = false;
	}
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(cr);
}


// CMFC31703View 诊断

#ifdef _DEBUG
void CMFC31703View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC31703View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC31703Doc* CMFC31703View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC31703Doc)));
	return (CMFC31703Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC31703View 消息处理程序


void CMFC31703View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//int t = nIDEvent;
	CRect rect;
	this->GetClientRect(rect);
	int t = rect.bottom;
	if (cr.bottom >= t)
	{   
		cr.left = 50;
		cr.top = 0;
		cr.right = 100;
		cr.bottom = 50;

	}
	else
	{
		cr.top += 30;
		cr.bottom += 30;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
