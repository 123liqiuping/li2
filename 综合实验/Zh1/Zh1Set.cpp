
// Zh1Set.cpp : CZh1Set ���ʵ��
//

#include "stdafx.h"
#include "Zh1.h"
#include "Zh1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZh1Set ʵ��

// ���������� 2020��6��21��, 10:35

IMPLEMENT_DYNAMIC(CZh1Set, CRecordset)

CZh1Set::CZh1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = 0;
	m_3 = L"";
	m_4 = L"";
	m_5 = L"";
	m_6 = 0;
	m_7 = L"";
	m_8 = L"";
	m_9 = L"";
	m_nFields = 10;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CZh1Set::GetDefaultConnect()
{
	return _T("DSN=bb2;DBQ=C:\\Users\\\x7834\x6653\x4e4b\x7075\\Documents\\b.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CZh1Set::GetDefaultSQL()
{
	return _T("[b1]");
}

void CZh1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Long(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Text(pFX, _T("[�ֶ�5]"), m_5);
	RFX_Long(pFX, _T("[�ֶ�6]"), m_6);
	RFX_Text(pFX, _T("[�ֶ�7]"), m_7);
	RFX_Text(pFX, _T("[�ֶ�8]"), m_8);
	RFX_Text(pFX, _T("[�ֶ�9]"), m_9);

}
/////////////////////////////////////////////////////////////////////////////
// CZh1Set ���

#ifdef _DEBUG
void CZh1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CZh1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

