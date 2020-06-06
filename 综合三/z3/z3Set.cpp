
// z3Set.cpp : Cz3Set ���ʵ��
//

#include "stdafx.h"
#include "z3.h"
#include "z3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cz3Set ʵ��

// ���������� 2020��6��1��, 10:20

IMPLEMENT_DYNAMIC(Cz3Set, CRecordset)

Cz3Set::Cz3Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cz3Set::GetDefaultConnect()
{
	return _T("DSN=zzz3;DBQ=D:\\Documents\\z3.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Cz3Set::GetDefaultSQL()
{
	return _T("[zz3]");
}

void Cz3Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// Cz3Set ���

#ifdef _DEBUG
void Cz3Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cz3Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

