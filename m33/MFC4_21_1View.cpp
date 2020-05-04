
// MFC4_21_1View.cpp: CMFC4211View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4_21_1.h"
#endif

#include "MFC4_21_1Doc.h"
#include "MFC4_21_1View.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4211View

IMPLEMENT_DYNCREATE(CMFC4211View, CView)

BEGIN_MESSAGE_MAP(CMFC4211View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMFC4211View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMFC4211View::OnFileSaveAs)
END_MESSAGE_MAP()

// CMFC4211View 构造/析构

CMFC4211View::CMFC4211View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4211View::~CMFC4211View()
{
}

BOOL CMFC4211View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4211View 绘图

void CMFC4211View::OnDraw(CDC* /*pDC*/)
{
	CMFC4211Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC4211View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC4211View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC4211View 诊断

#ifdef _DEBUG
void CMFC4211View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4211View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4211Doc* CMFC4211View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4211Doc)));
	return (CMFC4211Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4211View 消息处理程序


void CMFC4211View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		s = cfd.GetPathName();
	}
	
}


void CMFC4211View::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(cfd.GetPathName());
		CString t = cfd.GetPathName();
		ofs <<CT2A(s.GetString()) << endl;
		
	}
}
