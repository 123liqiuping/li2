
// MFC3-23-2View.h: CMFC3232View 类的接口
//

#pragma once


class CMFC3232View : public CView
{
protected: // 仅从序列化创建
	CMFC3232View() noexcept;
	DECLARE_DYNCREATE(CMFC3232View)

// 特性
public:
	CMFC3232Doc* GetDocument() const;

// 操作
public:
	bool set;
	int begin;
	CRect ca;
	int  b, color;
	

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3232View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC3-23-2View.cpp 中的调试版本
inline CMFC3232Doc* CMFC3232View::GetDocument() const
   { return reinterpret_cast<CMFC3232Doc*>(m_pDocument); }
#endif

