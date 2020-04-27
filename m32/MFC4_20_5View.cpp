
// MFC4_20_5View.cpp: CMFC4205View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_20_5.h"
#endif

#include "MFC4_20_5Doc.h"
#include "MFC4_20_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyDlg.h"


// CMFC4205View

IMPLEMENT_DYNCREATE(CMFC4205View, CView)

BEGIN_MESSAGE_MAP(CMFC4205View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TUOYUAN, &CMFC4205View::OnTuoyuan)
END_MESSAGE_MAP()

// CMFC4205View 构造/析构

CMFC4205View::CMFC4205View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4205View::~CMFC4205View()
{
}

BOOL CMFC4205View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4205View 绘图

void CMFC4205View::OnDraw(CDC* /*pDC*/)
{
	CMFC4205Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC4205View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC4205View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC4205View 诊断

#ifdef _DEBUG
void CMFC4205View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4205View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4205Doc* CMFC4205View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4205Doc)));
	return (CMFC4205Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4205View 消息处理程序


void CMFC4205View::OnTuoyuan()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int r, g, b;
		r = dlg.R;
		g = dlg.G;
		b = dlg.B;
		CDC* pDC = GetDC();
		CBrush brush(RGB(r, g, b));
		CBrush* old;
		old = pDC->SelectObject(&brush);
		pDC->Ellipse(200,100,500,250);
		pDC->SelectObject(old);
		this->ReleaseDC(pDC);
	}
}
