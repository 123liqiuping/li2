
// MFCy2View.h : CMFCy2View 类的接口
//

#pragma once

class CMFCy2Set;

class CMFCy2View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCy2View();
	DECLARE_DYNCREATE(CMFCy2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCY2_FORM };
#endif
	CMFCy2Set* m_pSet;
	void draw_pic(CString file);

// 特性
public:
	CMFCy2Doc* GetDocument() const;

// 操作
public:
	CString path;

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCy2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString a1;
	long a2;
	long a3;
	CString a4;
	long a5;
	CString a6;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCy2View.cpp 中的调试版本
inline CMFCy2Doc* CMFCy2View::GetDocument() const
   { return reinterpret_cast<CMFCy2Doc*>(m_pDocument); }
#endif

