
// MFC3_09_1View.h: CMFC3091View 类的接口
//

#pragma once


class CMFC3091View : public CView
{
protected: // 仅从序列化创建
	CMFC3091View() noexcept;
	DECLARE_DYNCREATE(CMFC3091View)

// 特性
public:
	CMFC3091Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	int x, y;


// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3091View();
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

#ifndef _DEBUG  // MFC3_09_1View.cpp 中的调试版本
inline CMFC3091Doc* CMFC3091View::GetDocument() const
   { return reinterpret_cast<CMFC3091Doc*>(m_pDocument); }
#endif

