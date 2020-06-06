
// z1View.h : Cz1View 类的接口
//

#pragma once

class Cz1Set;

class Cz1View : public CRecordView
{
protected: // 仅从序列化创建
	Cz1View();
	DECLARE_DYNCREATE(Cz1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_Z1_FORM };
#endif
	Cz1Set* m_pSet;

// 特性
public:
	Cz1Doc* GetDocument() const;
	void draw_pic(CString file);
	CString path;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~Cz1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString s1;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // z1View.cpp 中的调试版本
inline Cz1Doc* Cz1View::GetDocument() const
   { return reinterpret_cast<Cz1Doc*>(m_pDocument); }
#endif

