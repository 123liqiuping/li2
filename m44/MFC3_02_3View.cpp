
// MFC3_02_3View.cpp: CMFC3023View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_02_3.h"
#endif

#include "MFC3_02_3Doc.h"
#include "MFC3_02_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3023View

IMPLEMENT_DYNCREATE(CMFC3023View, CView)

BEGIN_MESSAGE_MAP(CMFC3023View, CView)
END_MESSAGE_MAP()

// CMFC3023View 构造/析构

CMFC3023View::CMFC3023View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3023View::~CMFC3023View()
{
}

BOOL CMFC3023View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3023View 绘图

void CMFC3023View::OnDraw(CDC* pDC)
{
	CMFC3023Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	this->GetClientRect(cr);
	pDC->Ellipse(cr);
}


// CMFC3023View 诊断

#ifdef _DEBUG
void CMFC3023View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3023View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3023Doc* CMFC3023View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3023Doc)));
	return (CMFC3023Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3023View 消息处理程序
