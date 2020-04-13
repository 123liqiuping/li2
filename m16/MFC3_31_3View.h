
// MFC3_31_3View.h: CMFC3313View 类的接口
//

#pragma once


class CMFC3313View : public CView
{
protected: // 仅从序列化创建
	CMFC3313View() noexcept;
	DECLARE_DYNCREATE(CMFC3313View)

// 特性
public:
	CMFC3313Doc* GetDocument() const;

// 操作
public:
	CString s;
	CString s1;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3313View();
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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFC3_31_3View.cpp 中的调试版本
inline CMFC3313Doc* CMFC3313View::GetDocument() const
   { return reinterpret_cast<CMFC3313Doc*>(m_pDocument); }
#endif

