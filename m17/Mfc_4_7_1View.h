
// Mfc_4_7_1View.h: CMfc471View 类的接口
//

#pragma once


class CMfc471View : public CView
{
protected: // 仅从序列化创建
	CMfc471View() noexcept;
	DECLARE_DYNCREATE(CMfc471View)

// 特性
public:
	CMfc471Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMfc471View();
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

#ifndef _DEBUG  // Mfc_4_7_1View.cpp 中的调试版本
inline CMfc471Doc* CMfc471View::GetDocument() const
   { return reinterpret_cast<CMfc471Doc*>(m_pDocument); }
#endif

