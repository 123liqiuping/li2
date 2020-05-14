
// MFC2_24View.cpp: CMFC224View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2_24.h"
#endif

#include "MFC2_24Doc.h"
#include "MFC2_24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC224View

IMPLEMENT_DYNCREATE(CMFC224View, CView)

BEGIN_MESSAGE_MAP(CMFC224View, CView)
END_MESSAGE_MAP()

// CMFC224View 构造/析构

CMFC224View::CMFC224View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC224View::~CMFC224View()
{
}

BOOL CMFC224View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC224View 绘图

void CMFC224View::OnDraw(CDC* /*pDC*/)
{
	CMFC224Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC224View 诊断

#ifdef _DEBUG
void CMFC224View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC224View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC224Doc* CMFC224View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC224Doc)));
	return (CMFC224Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC224View 消息处理程序
