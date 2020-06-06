
// z3View.h : Cz3View 类的接口
//

#pragma once

class Cz3Set;

class Cz3View : public CRecordView
{
protected: // 仅从序列化创建
	Cz3View();
	DECLARE_DYNCREATE(Cz3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_Z3_FORM };
#endif
	Cz3Set* m_pSet;

// 特性
public:
	Cz3Doc* GetDocument() const;

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
	virtual ~Cz3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long s;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // z3View.cpp 中的调试版本
inline Cz3Doc* Cz3View::GetDocument() const
   { return reinterpret_cast<Cz3Doc*>(m_pDocument); }
#endif

