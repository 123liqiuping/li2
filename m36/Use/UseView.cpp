
// UseView.cpp: CUseView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Use.h"
#endif

#include "UseDoc.h"
#include "UseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Jiecheng.h"


// CUseView

IMPLEMENT_DYNCREATE(CUseView, CView)

BEGIN_MESSAGE_MAP(CUseView, CView)
END_MESSAGE_MAP()

// CUseView 构造/析构

CUseView::CUseView() noexcept
{
	// TODO: 在此处添加构造代码

}

CUseView::~CUseView()
{
}

BOOL CUseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUseView 绘图

void CUseView::OnDraw(CDC* pDC)
{
	CUseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s.Format(_T("%d,阶乘5返回值"), factorial(5));
	pDC->TextOutW(200,200,s);

}


// CUseView 诊断

#ifdef _DEBUG
void CUseView::AssertValid() const
{
	CView::AssertValid();
}

void CUseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUseDoc* CUseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUseDoc)));
	return (CUseDoc*)m_pDocument;
}
#endif //_DEBUG


// CUseView 消息处理程序
