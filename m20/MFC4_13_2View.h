
// MFC4_13_2View.h: CMFC4132View 类的接口
//

#pragma once


class CMFC4132View : public CView
{
protected: // 仅从序列化创建
	CMFC4132View() noexcept;
	DECLARE_DYNCREATE(CMFC4132View)

// 特性
public:
	CMFC4132Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4132View();
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

#ifndef _DEBUG  // MFC4_13_2View.cpp 中的调试版本
inline CMFC4132Doc* CMFC4132View::GetDocument() const
   { return reinterpret_cast<CMFC4132Doc*>(m_pDocument); }
#endif

