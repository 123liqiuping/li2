
// MFC4_21_2View.h: CMFC4212View 类的接口
//

#pragma once


class CMFC4212View : public CView
{
protected: // 仅从序列化创建
	CMFC4212View() noexcept;
	DECLARE_DYNCREATE(CMFC4212View)

// 特性
public:
	CMFC4212Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4212View();
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
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // MFC4_21_2View.cpp 中的调试版本
inline CMFC4212Doc* CMFC4212View::GetDocument() const
   { return reinterpret_cast<CMFC4212Doc*>(m_pDocument); }
#endif

