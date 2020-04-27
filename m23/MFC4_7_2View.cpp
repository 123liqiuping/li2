
// MFC4_7_2View.cpp: CMFC472View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_7_2.h"
#endif
#include "MyDlg2.h"

#include "MFC4_7_2Doc.h"
#include "MFC4_7_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC472View

IMPLEMENT_DYNCREATE(CMFC472View, CView)

BEGIN_MESSAGE_MAP(CMFC472View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POPOUT, &CMFC472View::OnPopout)
END_MESSAGE_MAP()

// CMFC472View 构造/析构

CMFC472View::CMFC472View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC472View::~CMFC472View()
{
}

BOOL CMFC472View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC472View 绘图

void CMFC472View::OnDraw(CDC* /*pDC*/)
{
	CMFC472Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC472View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC472View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC472View 诊断

#ifdef _DEBUG
void CMFC472View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC472View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC472Doc* CMFC472View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC472Doc)));
	return (CMFC472Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC472View 消息处理程序


void CMFC472View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
	}
}
