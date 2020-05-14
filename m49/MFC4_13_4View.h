
// MFC4_13_4View.h: CMFC4134View 类的接口
//

#pragma once


class CMFC4134View : public CView
{
protected: // 仅从序列化创建
	CMFC4134View() noexcept;
	DECLARE_DYNCREATE(CMFC4134View)

// 特性
public:
	CMFC4134Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4134View();
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
};

#ifndef _DEBUG  // MFC4_13_4View.cpp 中的调试版本
inline CMFC4134Doc* CMFC4134View::GetDocument() const
   { return reinterpret_cast<CMFC4134Doc*>(m_pDocument); }
#endif

