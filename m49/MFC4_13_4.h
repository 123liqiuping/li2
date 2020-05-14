
// MFC4_13_4.h: MFC4_13_4 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMFC4134App:
// 有关此类的实现，请参阅 MFC4_13_4.cpp
//

class CMFC4134App : public CWinApp
{
public:
	CMFC4134App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC4134App theApp;
