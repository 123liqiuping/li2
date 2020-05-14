
// MFC3_02_4View.cpp: CMFC3024View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_02_4.h"
#endif

#include "MFC3_02_4Doc.h"
#include "MFC3_02_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3024View

IMPLEMENT_DYNCREATE(CMFC3024View, CView)

BEGIN_MESSAGE_MAP(CMFC3024View, CView)
END_MESSAGE_MAP()

// CMFC3024View 构造/析构

CMFC3024View::CMFC3024View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3024View::~CMFC3024View()
{
}

BOOL CMFC3024View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3024View 绘图

void CMFC3024View::OnDraw(CDC* pDC)
{
	CMFC3024Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	
	//int r, g, b;
	CBrush brush(RGB(250, 0, 0));
	CBrush* old;
	old = pDC->SelectObject(&brush);
	CRect cr;
	this->GetClientRect(cr);
	pDC->Ellipse(cr);
	pDC->SelectObject(old);
	this->ReleaseDC(pDC);
}


// CMFC3024View 诊断

#ifdef _DEBUG
void CMFC3024View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3024View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3024Doc* CMFC3024View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3024Doc)));
	return (CMFC3024Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3024View 消息处理程序
