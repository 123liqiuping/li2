
// MFC3_24_3View.cpp: CMFC3243View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_24_3.h"
#endif

#include "MFC3_24_3Doc.h"
#include "MFC3_24_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3243View

IMPLEMENT_DYNCREATE(CMFC3243View, CView)

BEGIN_MESSAGE_MAP(CMFC3243View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_HuaXian, &CMFC3243View::OnHuaxian)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_JuXing, &CMFC3243View::OnJuxing)
	ON_COMMAND(ID_TuoYuan, &CMFC3243View::OnTuoyuan)
END_MESSAGE_MAP()

// CMFC3243View 构造/析构

CMFC3243View::CMFC3243View() noexcept
{
	// TODO: 在此处添加构造代码
	a = 1;
	b = 1;


}

CMFC3243View::~CMFC3243View()
{
}

BOOL CMFC3243View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3243View 绘图

void CMFC3243View::OnDraw(CDC* pDC)
{
	CMFC3243Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC3243View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3243View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3243View 诊断

#ifdef _DEBUG
void CMFC3243View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3243View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3243Doc* CMFC3243View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3243Doc)));
	return (CMFC3243Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3243View 消息处理程序


void CMFC3243View::OnHuaxian()
{
	// TODO: 在此添加命令处理程序代码
	a==1;
	InvalidateRect(NULL, FALSE);
	
}


void CMFC3243View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (a == 1)
	{
		CClientDC dc(this);
		if (b == 1);
		{
			dc.MoveTo(m_point);
			dc.LineTo(point);
			m_point = point;
		}
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFC3243View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CPoint m_point1 = point;
	b == 0;
	CView::OnLButtonUp(nFlags, point);
}


void CMFC3243View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CPoint m_point = point;
	b == 1;
	m_point = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC3243View::OnJuxing()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	dc.Rectangle(50, 50, 200, 200);
	
}


void CMFC3243View::OnTuoyuan()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	dc.Ellipse(300, 200, 350, 300);
}
