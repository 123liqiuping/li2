
// z1Set.cpp : Cz1Set ���ʵ��
//

#include "stdafx.h"
#include "z1.h"
#include "z1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cz1Set ʵ��

// ���������� 2020��5��25��, 11:25

IMPLEMENT_DYNAMIC(Cz1Set, CRecordset)

Cz1Set::Cz1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cz1Set::GetDefaultConnect()
{
	return _T("DSN=\x76f8\x7247\x6d4f\x89c8;DBQ=G:\\Database1.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Cz1Set::GetDefaultSQL()
{
	return _T("[��Ƭ]");
}

void Cz1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// Cz1Set ���

#ifdef _DEBUG
void Cz1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cz1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

