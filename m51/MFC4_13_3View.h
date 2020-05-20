
// MFC4_13_3View.h: CMFC4133View 类的接口
//

#pragma once


class CMFC4133View : public CView
{
protected: // 仅从序列化创建
	CMFC4133View() noexcept;
	DECLARE_DYNCREATE(CMFC4133View)

// 特性
public:
	CMFC4133Doc* GetDocument() const;

// 操作
public:
	bool set;
	bool set1;
	CRect cr;
	int a;
	int b;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4133View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC4_13_3View.cpp 中的调试版本
inline CMFC4133Doc* CMFC4133View::GetDocument() const
   { return reinterpret_cast<CMFC4133Doc*>(m_pDocument); }
#endif

