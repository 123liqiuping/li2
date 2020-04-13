
// MFC3_10_3View.cpp: CMFC3103View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3_10_3.h"
#endif

#include "MFC3_10_3Doc.h"
#include "MFC3_10_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3103View

IMPLEMENT_DYNCREATE(CMFC3103View, CView)

BEGIN_MESSAGE_MAP(CMFC3103View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3103View 构造/析构

CMFC3103View::CMFC3103View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3103View::~CMFC3103View()
{
}

BOOL CMFC3103View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3103View 绘图

void CMFC3103View::OnDraw(CDC* pDC)
{
	CMFC3103Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(50,50,150,150);
	pDC->Rectangle(200, 50, 300, 150);
	pDC->Rectangle(350, 50, 450, 150);

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC3103View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3103View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3103View 诊断

#ifdef _DEBUG
void CMFC3103View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3103View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3103Doc* CMFC3103View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3103Doc)));
	return (CMFC3103Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3103View 消息处理程序

int c;
int d;
void CMFC3103View::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	int a = rand() % 50;
	int b = rand() % 50;
	
	CString s;
	CString s1;
	CString s2;
	CString s3=_T("点击无效");
	if ((point.y > 50) && (point.y < 150)) {
		if (point.x > 50 && point.x < 150) {
			s.Format(_T("%d"), a);
			c = a;
			dc.TextOutW(point.x, point.y, s);
		}
		if (point.x > 200 && point.x < 300) {
			s1.Format(_T("%d"), b);
			d = b;
			dc.TextOutW(point.x, point.y, s1);
		}
		if (point.x > 350 && point.x < 450) {
			s2.Format(_T("%d"),c+d );
			dc.TextOutW(point.x, point.y, s2);
		}
	}
	else
		dc.TextOutW(point.x, point.y, s3);

	
	
	CView::OnLButtonDown(nFlags, point);
}
