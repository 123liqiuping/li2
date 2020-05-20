
// MFC3_09_2View.cpp: CMFC3092View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_09_2.h"
#endif

#include "MFC3_09_2Doc.h"
#include "MFC3_09_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3092View

IMPLEMENT_DYNCREATE(CMFC3092View, CView)

BEGIN_MESSAGE_MAP(CMFC3092View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3092View 构造/析构

CMFC3092View::CMFC3092View() noexcept
{
	// TODO: 在此处添加构造代码
	cr.SetSize(256);

}

CMFC3092View::~CMFC3092View()
{
}

BOOL CMFC3092View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3092View 绘图

void CMFC3092View::OnDraw(CDC* pDC)
{
	CMFC3092Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < cr.GetSize(); i++)
		pDC->Ellipse (cr.GetAt(i));
}


// CMFC3092View 诊断

#ifdef _DEBUG
void CMFC3092View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3092View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3092Doc* CMFC3092View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3092Doc)));
	return (CMFC3092Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3092View 消息处理程序


void CMFC3092View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int a = rand() % 50 + 10;
	int b = rand() % 50 + 10;
	CRect ca(point.x - a, point.y - b,point.x+a,point.y+b);
	cr.Add(ca);
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
