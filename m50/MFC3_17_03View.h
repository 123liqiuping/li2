
// MFC3_17_03View.h: CMFC31703View 类的接口
//

#pragma once


class CMFC31703View : public CView
{
protected: // 仅从序列化创建
	CMFC31703View() noexcept;
	DECLARE_DYNCREATE(CMFC31703View)

// 特性
public:
	CMFC31703Doc* GetDocument() const;

// 操作
public:
	bool set;
	CRect cr;
	

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC31703View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC3_17_03View.cpp 中的调试版本
inline CMFC31703Doc* CMFC31703View::GetDocument() const
   { return reinterpret_cast<CMFC31703Doc*>(m_pDocument); }
#endif

