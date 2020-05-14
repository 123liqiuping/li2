
// MFC4_13_4View.cpp: CMFC4134View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_13_4.h"
#endif

#include "MFC4_13_4Doc.h"
#include "MFC4_13_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyDlg.h"


// CMFC4134View

IMPLEMENT_DYNCREATE(CMFC4134View, CView)

BEGIN_MESSAGE_MAP(CMFC4134View, CView)
	ON_COMMAND(ID_POPOUT, &CMFC4134View::OnPopout)
END_MESSAGE_MAP()

// CMFC4134View 构造/析构

CMFC4134View::CMFC4134View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4134View::~CMFC4134View()
{
}

BOOL CMFC4134View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4134View 绘图

void CMFC4134View::OnDraw(CDC* /*pDC*/)
{
	CMFC4134Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4134View 诊断

#ifdef _DEBUG
void CMFC4134View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4134View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4134Doc* CMFC4134View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4134Doc)));
	return (CMFC4134Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4134View 消息处理程序


void CMFC4134View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK) {
		CString r;
		r.Format(_T("%d"), dlg.s2);
		dlg.s3 = dlg.s1 + r;

	}

}
