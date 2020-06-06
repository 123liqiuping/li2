
// z3View.cpp : Cz3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "z3.h"
#endif

#include "z3Set.h"
#include "z3Doc.h"
#include "z3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "ADD_DLG.h"
#include "UPDATE_DLG.h"


// Cz3View

IMPLEMENT_DYNCREATE(Cz3View, CRecordView)

BEGIN_MESSAGE_MAP(Cz3View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON3, &Cz3View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &Cz3View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cz3View::OnBnClickedButton2)
END_MESSAGE_MAP()

// Cz3View ����/����

Cz3View::Cz3View()
	: CRecordView(IDD_Z3_FORM)
	, s(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

Cz3View::~Cz3View()
{
}

void Cz3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL Cz3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void Cz3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_z3Set;
	CRecordView::OnInitialUpdate();

}


// Cz3View ���

#ifdef _DEBUG
void Cz3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cz3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cz3Doc* Cz3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cz3Doc)));
	return (Cz3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cz3View ���ݿ�֧��
CRecordset* Cz3View::OnGetRecordset()
{
	return m_pSet;
}



// Cz3View ��Ϣ�������


void Cz3View::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void Cz3View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADD_DLG adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long ii = adddlg.i;
		m_pSet->AddNew();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}


void Cz3View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UPDATE_DLG updlg;
	int r = updlg.DoModal();
	if (r == IDOK)
	{
		long ii = updlg.i2;
		m_pSet->Edit();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}

}
