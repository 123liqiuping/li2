
// MFC3_09_2View.h: CMFC3092View 类的接口
//

#pragma once


class CMFC3092View : public CView
{
protected: // 仅从序列化创建
	CMFC3092View() noexcept;
	DECLARE_DYNCREATE(CMFC3092View)

// 特性
public:
	CMFC3092Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect&> cr;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3092View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3_09_2View.cpp 中的调试版本
inline CMFC3092Doc* CMFC3092View::GetDocument() const
   { return reinterpret_cast<CMFC3092Doc*>(m_pDocument); }
#endif

