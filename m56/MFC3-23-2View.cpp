
// MFC3-23-2View.cpp: CMFC3232View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3-23-2.h"
#endif

#include "MFC3-23-2Doc.h"
#include "MFC3-23-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3232View

IMPLEMENT_DYNCREATE(CMFC3232View, CView)

BEGIN_MESSAGE_MAP(CMFC3232View, CView)
	ON_COMMAND(ID_POPOUT, &CMFC3232View::OnPopout)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC3232View 构造/析构

CMFC3232View::CMFC3232View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	b = 50;
	color = RGB(0, 0, b);
	ca.left = 500;
	ca.top = 300;
	ca.right = 520;
	ca.bottom = 320;

}

CMFC3232View::~CMFC3232View()
{
}

BOOL CMFC3232View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3232View 绘图

void CMFC3232View::OnDraw(CDC* pDC)
{
	CMFC3232Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (set)
	{
		SetTimer(1, 50, NULL);
		set = false;
	}
	CBrush brush(color);
	CBrush* old;
	old = pDC->SelectObject(&brush);
	pDC->Ellipse(ca);
	pDC->SelectObject(old);
	this->ReleaseDC(pDC);
}


// CMFC3232View 诊断

#ifdef _DEBUG
void CMFC3232View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3232View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3232Doc* CMFC3232View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3232Doc)));
	return (CMFC3232Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3232View 消息处理程序


void CMFC3232View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	begin = 1;
}


void CMFC3232View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	this->GetClientRect(&rect);
	if (begin == 1 && (ca.left > 0) && (ca.top > 0) && (ca.right < rect.right) && (ca.bottom < rect.bottom))
	{
		ca.left -= 20;
		ca.top -= 20;
		ca.right += 20;
		ca.bottom += 20;
		b += 20;
	}

	Invalidate();


	CView::OnTimer(nIDEvent);
}
