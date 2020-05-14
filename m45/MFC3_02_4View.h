
// MFC3_02_4View.h: CMFC3024View 类的接口
//

#pragma once


class CMFC3024View : public CView
{
protected: // 仅从序列化创建
	CMFC3024View() noexcept;
	DECLARE_DYNCREATE(CMFC3024View)

// 特性
public:
	CMFC3024Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3024View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC3_02_4View.cpp 中的调试版本
inline CMFC3024Doc* CMFC3024View::GetDocument() const
   { return reinterpret_cast<CMFC3024Doc*>(m_pDocument); }
#endif

