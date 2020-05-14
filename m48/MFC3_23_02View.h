
// MFC3_23_02View.h: CMFC32302View 类的接口
//

#pragma once


class CMFC32302View : public CView
{
protected: // 仅从序列化创建
	CMFC32302View() noexcept;
	DECLARE_DYNCREATE(CMFC32302View)

// 特性
public:
	CMFC32302Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC32302View();
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

#ifndef _DEBUG  // MFC3_23_02View.cpp 中的调试版本
inline CMFC32302Doc* CMFC32302View::GetDocument() const
   { return reinterpret_cast<CMFC32302Doc*>(m_pDocument); }
#endif

