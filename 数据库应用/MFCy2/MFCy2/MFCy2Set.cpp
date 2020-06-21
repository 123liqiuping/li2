
// MFCy2Set.cpp : CMFCy2Set ���ʵ��
//

#include "stdafx.h"
#include "MFCy2.h"
#include "MFCy2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCy2Set ʵ��

// ���������� 2020��6��9��, 20:34

IMPLEMENT_DYNAMIC(CMFCy2Set, CRecordset)

CMFCy2Set::CMFCy2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = 0;
	m_3 = 0;
	m_4 = L"";
	m_5 = 0;
	m_6 = L"";
	m_7 = L"";
	m_nFields = 8;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCy2Set::GetDefaultConnect()
{
	return _T("DSN=y1;DBQ=C:\\Users\\\x7834\x6653\x4e4b\x7075\\Documents\\a.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCy2Set::GetDefaultSQL()
{
	return _T("[a1]");
}

void CMFCy2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Long(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Long(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Long(pFX, _T("[�ֶ�5]"), m_5);
	RFX_Text(pFX, _T("[�ֶ�6]"), m_6);
	RFX_Text(pFX, _T("[�ֶ�7]"), m_7);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCy2Set ���

#ifdef _DEBUG
void CMFCy2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCy2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

