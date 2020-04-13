
// MFC3_30_1View.cpp: CMFC3301View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_30_1.h"
#endif

#include "MFC3_30_1Doc.h"
#include "MFC3_30_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3301View

IMPLEMENT_DYNCREATE(CMFC3301View, CView)

BEGIN_MESSAGE_MAP(CMFC3301View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMFC3301View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC3301View 构造/析构

CMFC3301View::CMFC3301View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3301View::~CMFC3301View()
{
}

BOOL CMFC3301View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3301View 绘图

void CMFC3301View::OnDraw(CDC* /*pDC*/)
{
	CMFC3301Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC3301View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3301View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3301View 诊断

#ifdef _DEBUG
void CMFC3301View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3301View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3301Doc* CMFC3301View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3301Doc)));
	return (CMFC3301Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3301View 消息处理程序


void CMFC3301View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	
	CRect client;
	this->GetClientRect(&client);
	CPoint p = client.CenterPoint();
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK)
	{
		CString file = cfd.GetPathName();
		CImage img;
		img.Load(file);
		img.Draw(dc.m_hDC,p.x-(img.GetWidth()/2), p.y-(img.GetHeight()/2), img.GetWidth(), img.GetHeight());
	}
}
