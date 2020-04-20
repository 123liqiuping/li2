
// MFC4_14_1View.h: CMFC4141View 类的接口
//

#pragma once


class CMFC4141View : public CView
{
protected: // 仅从序列化创建
	CMFC4141View() noexcept;
	DECLARE_DYNCREATE(CMFC4141View)

// 特性
public:
	CMFC4141Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4141View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4_14_1View.cpp 中的调试版本
inline CMFC4141Doc* CMFC4141View::GetDocument() const
   { return reinterpret_cast<CMFC4141Doc*>(m_pDocument); }
#endif

