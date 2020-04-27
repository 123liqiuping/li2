
// MFC4_20_1View.h: CMFC4201View 类的接口
//

#pragma once


class CMFC4201View : public CView
{
protected: // 仅从序列化创建
	CMFC4201View() noexcept;
	DECLARE_DYNCREATE(CMFC4201View)

// 特性
public:
	CMFC4201Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4201View();
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

#ifndef _DEBUG  // MFC4_20_1View.cpp 中的调试版本
inline CMFC4201Doc* CMFC4201View::GetDocument() const
   { return reinterpret_cast<CMFC4201Doc*>(m_pDocument); }
#endif

