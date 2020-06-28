
// MFCtxView.h: CMFCtxView 类的接口
//

#pragma once


class CMFCtxView : public CView
{
protected: // 仅从序列化创建
	CMFCtxView() noexcept;
	DECLARE_DYNCREATE(CMFCtxView)

// 特性
public:
	CMFCtxDoc* GetDocument() const;

// 操作
public:
	CRect cr, rect;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtxView();
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

#ifndef _DEBUG  // MFCtxView.cpp 中的调试版本
inline CMFCtxDoc* CMFCtxView::GetDocument() const
   { return reinterpret_cast<CMFCtxDoc*>(m_pDocument); }
#endif

