
// MFC4_14_2View.cpp: CMFC4142View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_14_2.h"
#endif

#include "MFC4_14_2Doc.h"
#include "MFC4_14_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyDlg.h"
#include "MyDlg2.h"


// CMFC4142View

IMPLEMENT_DYNCREATE(CMFC4142View, CView)

BEGIN_MESSAGE_MAP(CMFC4142View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POPOUT, &CMFC4142View::OnPopout)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC4142View 构造/析构

CMFC4142View::CMFC4142View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4142View::~CMFC4142View()
{
}

BOOL CMFC4142View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4142View 绘图

void CMFC4142View::OnDraw(CDC* /*pDC*/)
{
	CMFC4142Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC4142View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC4142View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC4142View 诊断

#ifdef _DEBUG
void CMFC4142View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4142View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4142Doc* CMFC4142View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4142Doc)));
	return (CMFC4142Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4142View 消息处理程序


void CMFC4142View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		//dlg.x = s2;
	}
}


void CMFC4142View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnLButtonDblClk(nFlags, point);
}
