
// MFC4_7_2View.h: CMFC472View 类的接口
//

#pragma once


class CMFC472View : public CView
{
protected: // 仅从序列化创建
	CMFC472View() noexcept;
	DECLARE_DYNCREATE(CMFC472View)

// 特性
public:
	CMFC472Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC472View();
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

#ifndef _DEBUG  // MFC4_7_2View.cpp 中的调试版本
inline CMFC472Doc* CMFC472View::GetDocument() const
   { return reinterpret_cast<CMFC472Doc*>(m_pDocument); }
#endif

