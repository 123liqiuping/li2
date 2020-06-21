
// MFCy2View.cpp : CMFCy2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCy2View ����/����

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
	// TODO: �ڴ˴���ӹ������
	path = _T("D:\\ͼƬ\\");

}

CMFCy2View::~CMFCy2View()
{
}

void CMFCy2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_5);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_6);
}

BOOL CMFCy2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCy2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCy2Set;
	CRecordView::OnInitialUpdate();

}


// CMFCy2View ���

#ifdef _DEBUG
void CMFCy2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCy2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCy2Doc* CMFCy2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCy2Doc)));
	return (CMFCy2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCy2View ���ݿ�֧��
CRecordset* CMFCy2View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCy2View ��Ϣ�������
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
	pDC->SetStretchBltMode(HALFTONE);//��֤ͼƬ��ʧ��
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void CMFCy2View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	OnPaint();
}


void CMFCy2View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	OnPaint();
}


void CMFCy2View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveNext();
	UpdateData(false);
	OnPaint();
}


void CMFCy2View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	OnPaint();
}


void CMFCy2View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CString s, filename;
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	draw_pic(filename);
}
