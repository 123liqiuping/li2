﻿
// MFC4_20_4View.h: CMFC4204View 类的接口
//

#pragma once


class CMFC4204View : public CView
{
protected: // 仅从序列化创建
	CMFC4204View() noexcept;
	DECLARE_DYNCREATE(CMFC4204View)

// 特性
public:
	CMFC4204Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4204View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4_20_4View.cpp 中的调试版本
inline CMFC4204Doc* CMFC4204View::GetDocument() const
   { return reinterpret_cast<CMFC4204Doc*>(m_pDocument); }
#endif

