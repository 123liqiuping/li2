
// MFC3_03_3View.h: CMFC3033View 类的接口
//

#pragma once


class CMFC3033View : public CView
{
protected: // 仅从序列化创建
	CMFC3033View() noexcept;
	DECLARE_DYNCREATE(CMFC3033View)

// 特性
public:
	CMFC3033Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3033View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3_03_3View.cpp 中的调试版本
inline CMFC3033Doc* CMFC3033View::GetDocument() const
   { return reinterpret_cast<CMFC3033Doc*>(m_pDocument); }
#endif

