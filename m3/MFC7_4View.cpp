
// MFC7_4View.cpp: CMFC74View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7_4.h"
#endif

#include "MFC7_4Doc.h"
#include "MFC7_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC74View

IMPLEMENT_DYNCREATE(CMFC74View, CView)

BEGIN_MESSAGE_MAP(CMFC74View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFC74View 构造/析构

CMFC74View::CMFC74View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC74View::~CMFC74View()
{
}

BOOL CMFC74View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC74View 绘图

void CMFC74View::OnDraw(CDC* pDC)
{
	CMFC74Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRect);
}

void CMFC74View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC74View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC74View 诊断

#ifdef _DEBUG
void CMFC74View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC74View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC74Doc* CMFC74View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC74Doc)));
	return (CMFC74Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC74View 消息处理程序


void CMFC74View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC74Doc* pDoc = GetDocument();
	pDoc->m_tagRect.left = 100;
	pDoc->m_tagRect.top = 100;
	pDoc->m_tagRect.right = 150;
	pDoc->m_tagRect.bottom = 150;
	InvalidateRect(NULL,TRUE);
	CView::OnLButtonDown(nFlags, point);
}


void CMFC74View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC74Doc* pDoc = GetDocument();
	CRect crect;
	GetClientRect(&crect);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->m_tagRect.left > 0)
		{
			pDoc->m_tagRect.left-=5;
			pDoc->m_tagRect.right-=5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->m_tagRect.right <= (crect.right - crect.left))
		{
			pDoc->m_tagRect.left += 5;
			pDoc->m_tagRect.right += 5;
		}
		break;
	case VK_UP:
		if (pDoc->m_tagRect.top > 0)
		{
			pDoc->m_tagRect.top -= 5;
			pDoc->m_tagRect.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_tagRect.bottom <= (crect.bottom - crect.top))
		{
			pDoc->m_tagRect.top += 5;
			pDoc->m_tagRect.bottom += 5;
		}
	case VK_HOME:
	{
		pDoc->m_tagRect.left -=8;
		pDoc->m_tagRect.right +=8;
		pDoc->m_tagRect.top -= 8;
		pDoc->m_tagRect.bottom += 8;
	}
	case VK_END:
	{
		pDoc->m_tagRect.left += 8;
		pDoc->m_tagRect.right -= 8;
		pDoc->m_tagRect.top += 8;
		pDoc->m_tagRect.bottom -= 8;
	}
	}
	InvalidateRect(NULL,TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
