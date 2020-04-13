
// Mfc_4_7_1View.cpp: CMfc471View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Mfc_4_7_1.h"
#endif

#include "Mfc_4_7_1Doc.h"
#include "Mfc_4_7_1View.h"
#include "MyDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfc471View

IMPLEMENT_DYNCREATE(CMfc471View, CView)

BEGIN_MESSAGE_MAP(CMfc471View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POPOUT, &CMfc471View::OnPopout)
END_MESSAGE_MAP()

// CMfc471View 构造/析构

CMfc471View::CMfc471View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMfc471View::~CMfc471View()
{
}

BOOL CMfc471View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMfc471View 绘图

void CMfc471View::OnDraw(CDC* /*pDC*/)
{
	CMfc471Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMfc471View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMfc471View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMfc471View 诊断

#ifdef _DEBUG
void CMfc471View::AssertValid() const
{
	CView::AssertValid();
}

void CMfc471View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMfc471Doc* CMfc471View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMfc471Doc)));
	return (CMfc471Doc*)m_pDocument;
}
#endif //_DEBUG


// CMfc471View 消息处理程序


void CMfc471View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	MyDlg0 dlg;
	int t = dlg.DoModal();
	CString s = _T("你已退出对话框");
	if (t == IDOK)
	{
		dc.TextOutW(200,200,s);
	}
}
