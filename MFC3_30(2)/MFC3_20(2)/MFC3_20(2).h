
// MFC3_20(2).h : MFC3_20(2) Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC3_202App:
// �йش����ʵ�֣������ MFC3_20(2).cpp
//

class CMFC3_202App : public CWinApp
{
public:
	CMFC3_202App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC3_202App theApp;
