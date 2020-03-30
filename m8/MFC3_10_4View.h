
// MFC3_10_4View.h: CMFC3104View 类的接口
//

#pragma once


class CMFC3104View : public CView
{
protected: // 仅从序列化创建
	CMFC3104View() noexcept;
	DECLARE_DYNCREATE(CMFC3104View)

// 特性
public:
	CMFC3104Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3104View();
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

#ifndef _DEBUG  // MFC3_10_4View.cpp 中的调试版本
inline CMFC3104Doc* CMFC3104View::GetDocument() const
   { return reinterpret_cast<CMFC3104Doc*>(m_pDocument); }
#endif

