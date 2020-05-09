
// MFC4_27_02View.h: CMFC42702View 类的接口
//

#pragma once


class CMFC42702View : public CView
{
protected: // 仅从序列化创建
	CMFC42702View() noexcept;
	DECLARE_DYNCREATE(CMFC42702View)

// 特性
public:
	CMFC42702Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC42702View();
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

#ifndef _DEBUG  // MFC4_27_02View.cpp 中的调试版本
inline CMFC42702Doc* CMFC42702View::GetDocument() const
   { return reinterpret_cast<CMFC42702Doc*>(m_pDocument); }
#endif

