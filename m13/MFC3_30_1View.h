
// MFC3_30_1View.h: CMFC3301View 类的接口
//

#pragma once


class CMFC3301View : public CView
{
protected: // 仅从序列化创建
	CMFC3301View() noexcept;
	DECLARE_DYNCREATE(CMFC3301View)

// 特性
public:
	CMFC3301Doc* GetDocument() const;

// 操作
public:


// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3301View();
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
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC3_30_1View.cpp 中的调试版本
inline CMFC3301Doc* CMFC3301View::GetDocument() const
   { return reinterpret_cast<CMFC3301Doc*>(m_pDocument); }
#endif

