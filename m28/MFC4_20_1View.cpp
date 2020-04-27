
// MFC4_20_1View.cpp: CMFC4201View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_20_1.h"
#endif

#include "MFC4_20_1Doc.h"
#include "MFC4_20_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyDlg.h"


// CMFC4201View

IMPLEMENT_DYNCREATE(CMFC4201View, CView)

BEGIN_MESSAGE_MAP(CMFC4201View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POPOUT, &CMFC4201View::OnPopout)
END_MESSAGE_MAP()

// CMFC4201View 构造/析构

CMFC4201View::CMFC4201View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4201View::~CMFC4201View()
{
}

BOOL CMFC4201View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4201View 绘图

void CMFC4201View::OnDraw(CDC* /*pDC*/)
{
	CMFC4201Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC4201View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC4201View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC4201View 诊断

#ifdef _DEBUG
void CMFC4201View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4201View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4201Doc* CMFC4201View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4201Doc)));
	return (CMFC4201Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4201View 消息处理程序


void CMFC4201View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
	}
}
