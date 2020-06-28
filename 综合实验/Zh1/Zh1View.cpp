
// Zh1View.cpp : CZh1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Zh1.h"
#endif

#include "Zh1Set.h"
#include "Zh1Doc.h"
#include "Zh1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyDlg.h"
#include "MyDlg1.h"
#include "MyDlg2.h"
#include "MyDlg3.h"


// CZh1View

IMPLEMENT_DYNCREATE(CZh1View, CRecordView)

BEGIN_MESSAGE_MAP(CZh1View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CZh1View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CZh1View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CZh1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CZh1View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CZh1View::OnBnClickedButton1)
	ON_COMMAND(ID_DELE, &CZh1View::OnDele)
	ON_COMMAND(ID_ADD, &CZh1View::OnAdd)
	ON_COMMAND(ID_UPDATE, &CZh1View::OnUpdate)
	ON_COMMAND(ID_SEARCH, &CZh1View::OnSearch)
	ON_COMMAND(ID_SORT, &CZh1View::OnSort)
END_MESSAGE_MAP()

// CZh1View 构造/析构

CZh1View::CZh1View()
	: CRecordView(IDD_ZH1_FORM)
	, name(_T(""))
	, number(0)
	, Zy(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, phone(0)
	, dz(_T(""))
	, pname(_T(""))
	, jname(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\Users\\破晓之灵\\Pictures\\图片\\");

}

CZh1View::~CZh1View()
{
}

void CZh1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_5);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->m_6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->m_7);
	DDX_Text(pDX, IDC_EDIT10,m_pSet->m_8);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->m_9);
}

BOOL CZh1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CZh1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Zh1Set;
	CRecordView::OnInitialUpdate();

}


// CZh1View 诊断

#ifdef _DEBUG
void CZh1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CZh1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CZh1Doc* CZh1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZh1Doc)));
	return (CZh1Doc*)m_pDocument;
}
#endif //_DEBUG


// CZh1View 数据库支持
CRecordset* CZh1View::OnGetRecordset()
{
	return m_pSet;
}



// CZh1View 消息处理程序
void CZh1View::draw_pic(CString file)
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

void CZh1View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	OnPaint();
}


void CZh1View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	OnPaint();
}


void CZh1View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveNext();
	UpdateData(false);
	OnPaint();
}


void CZh1View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	OnPaint();
}


void CZh1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CString s, filename;
	GetDlgItemText(IDC_EDIT10, s);
	filename = path + s;
	draw_pic(filename);
}


void CZh1View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg dlg;
	CString s, filename;
	this->UpdateData(true);
	GetDlgItemText(IDC_EDIT10, s);
	filename = path + s;
	dlg.file = filename;
	UpdateData(false);
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}


void CZh1View::OnDele()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData();

}


void CZh1View::OnAdd()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg1 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		CString s1 = dlg.i1;
		long s2 = dlg.i2;
		CString s3 = dlg.i3;
		CString s4 = dlg.i4;
		CString s5 = dlg.i5;
		long s6 = dlg.i6;
		CString s7 = dlg.i7;
		CString s8 = dlg.i8;
		CString s9 = dlg.i9;
		m_pSet->AddNew();
		m_pSet->m_1 = s1;
		m_pSet->m_2 = s2;
		m_pSet->m_3 = s3;
		m_pSet->m_4 = s4;
		m_pSet->m_5 = s5;
		m_pSet->m_6 = s6;
		m_pSet->m_7 = s7;
		m_pSet->m_8 = s8;
		m_pSet->m_9 = s9;
		m_pSet->Update();
		UpdateData(false);

	}
}


void CZh1View::OnUpdate()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		CString s1 = dlg.r1;
		long s2 = dlg.r2;
		CString s3 = dlg.r3;
		CString s4 = dlg.r4;
		CString s5 = dlg.r5;
		long s6 = dlg.r6;
		CString s7 = dlg.r7;
		CString s8 = dlg.r8;
		CString s9 = dlg.r9;
		m_pSet->Edit();
		m_pSet->m_1 = s1;
		m_pSet->m_2 = s2;
		m_pSet->m_3 = s3;
		m_pSet->m_4 = s4;
		m_pSet->m_5 = s5;
		m_pSet->m_6 = s6;
		m_pSet->m_7 = s7;
		m_pSet->m_8 = s8;
		m_pSet->m_9 = s9;
		m_pSet->Update();
		UpdateData(false);

	}
}


void CZh1View::OnSearch()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg3 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		this->UpdateData(false);
		m_pSet->m_strFilter = dlg.a;
		m_pSet->Requery();
		Invalidate();
	}
}


void CZh1View::OnSort()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg3 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		this->UpdateData(false);
		m_pSet->m_strSort = dlg.a;
		m_pSet->Requery();
		Invalidate();
	}
}
