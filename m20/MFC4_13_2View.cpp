
// MFC4_13_2View.cpp: CMFC4132View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_13_2.h"
#endif

#include "MFC4_13_2Doc.h"
#include "MFC4_13_2View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4132View

IMPLEMENT_DYNCREATE(CMFC4132View, CView)

BEGIN_MESSAGE_MAP(CMFC4132View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POPOUT, &CMFC4132View::OnPopout)
END_MESSAGE_MAP()

// CMFC4132View 构造/析构

CMFC4132View::CMFC4132View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4132View::~CMFC4132View()
{
}

BOOL CMFC4132View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4132View 绘图

void CMFC4132View::OnDraw(CDC* /*pDC*/)
{
	CMFC4132Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC4132View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC4132View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC4132View 诊断

#ifdef _DEBUG
void CMFC4132View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4132View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4132Doc* CMFC4132View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4132Doc)));
	return (CMFC4132Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4132View 消息处理程序


void CMFC4132View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int X, Y, sum;
		X = dlg.x;
		Y = dlg.y;
		sum = dlg.z;
	}

}
