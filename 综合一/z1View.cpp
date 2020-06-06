
// z1View.cpp : Cz1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "z1.h"
#endif

#include "z1Set.h"
#include "z1Doc.h"
#include "z1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cz1View

IMPLEMENT_DYNCREATE(Cz1View, CRecordView)

BEGIN_MESSAGE_MAP(Cz1View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &Cz1View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &Cz1View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &Cz1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &Cz1View::OnRecordLast)
END_MESSAGE_MAP()

// Cz1View 构造/析构

Cz1View::Cz1View()
	: CRecordView(IDD_Z1_FORM)
	, s1(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("G:\\图片\\");

}

Cz1View::~Cz1View()
{
}

void Cz1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL Cz1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Cz1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_z1Set;
	CRecordView::OnInitialUpdate();

}


// Cz1View 诊断

#ifdef _DEBUG
void Cz1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cz1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cz1Doc* Cz1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cz1Doc)));
	return (Cz1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cz1View 数据库支持
CRecordset* Cz1View::OnGetRecordset()
{
	return m_pSet;
}



// Cz1View 消息处理程序


void Cz1View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename,s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}


void Cz1View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s1;
	GetDlgItemText(IDC_EDIT1, s1);
	filename = path + s1;
	draw_pic(filename);
}


void Cz1View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveNext();
	UpdateData(false);
	CString filename, s2;
	GetDlgItemText(IDC_EDIT1, s2);
	filename = path + s2;
	draw_pic(filename);
}


void Cz1View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s3;
	GetDlgItemText(IDC_EDIT1, s3);
	filename = path + s3;
	draw_pic(filename);
}
void Cz1View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);//保证图片不失真
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
