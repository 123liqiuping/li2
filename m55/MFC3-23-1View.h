
// MFC3-23-1View.h: CMFC3231View 类的接口
//

#pragma once


class CMFC3231View : public CView
{
protected: // 仅从序列化创建
	CMFC3231View() noexcept;
	DECLARE_DYNCREATE(CMFC3231View)

// 特性
public:
	CMFC3231Doc* GetDocument() const;

// 操作
public:
	//CArray<CRect, CRect&> cr;
	bool set;
	int begin;
	CRect ca;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3231View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC3-23-1View.cpp 中的调试版本
inline CMFC3231Doc* CMFC3231View::GetDocument() const
   { return reinterpret_cast<CMFC3231Doc*>(m_pDocument); }
#endif

