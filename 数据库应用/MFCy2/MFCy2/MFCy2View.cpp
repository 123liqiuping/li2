
// MFCy2View.cpp : CMFCy2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCy2.h"
#endif

#include "MFCy2Set.h"
#include "MFCy2Doc.h"
#include "MFCy2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyDlg.h"


// CMFCy2View

IMPLEMENT_DYNCREATE(CMFCy2View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCy2View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCy2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCy2View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCy2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCy2View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCy2View::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCy2View 构造/析构

CMFCy2View::CMFCy2View()
	: CRecordView(IDD_MFCY2_FORM)
	, a1(_T(""))
	, a2(0)
	, a3(0)
	, a4(_T(""))
	, a5(0)
	, a6(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("D:\\图片\\");

}

CMFCy2View::~CMFCy2View()
{
}

void CMFCy2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_5);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_6);
}

BOOL CMFCy2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCy2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCy2Set;
	CRecordView::OnInitialUpdate();

}


// CMFCy2View 诊断

#ifdef _DEBUG
void CMFCy2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCy2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCy2Doc* CMFCy2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCy2Doc)));
	return (CMFCy2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCy2View 数据库支持
CRecordset* CMFCy2View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCy2View 消息处理程序
void CMFCy2View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC*pDC = GetDlgItem(IDC_STATICD)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATICD)->GetClientRect(&rect);
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

void CMFCy2View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	OnPaint();
}


void CMFCy2View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	OnPaint();
}


void CMFCy2View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveNext();
	UpdateData(false);
	OnPaint();
}


void CMFCy2View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	OnPaint();
}


void CMFCy2View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg dlg;
	CString s, filename;
	this->UpdateData(true);
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	dlg.file = filename;
	UpdateData(false);
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}

}


void CMFCy2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CString s, filename;
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	draw_pic(filename);
}
