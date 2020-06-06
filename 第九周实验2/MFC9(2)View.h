
// MFC9(2)View.h : CMFC92View 类的接口
//

#pragma once


class CMFC92View : public CView
{
protected: // 仅从序列化创建
	CMFC92View();
	DECLARE_DYNCREATE(CMFC92View)

// 特性
public:
	CMFC92Doc* GetDocument() const;

// 操作
public:
	CRect cr;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC92View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC9(2)View.cpp 中的调试版本
inline CMFC92Doc* CMFC92View::GetDocument() const
   { return reinterpret_cast<CMFC92Doc*>(m_pDocument); }
#endif

