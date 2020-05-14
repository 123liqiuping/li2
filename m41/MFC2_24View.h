
// MFC2_24View.h: CMFC224View 类的接口
//

#pragma once


class CMFC224View : public CView
{
protected: // 仅从序列化创建
	CMFC224View() noexcept;
	DECLARE_DYNCREATE(CMFC224View)

// 特性
public:
	CMFC224Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC224View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC2_24View.cpp 中的调试版本
inline CMFC224Doc* CMFC224View::GetDocument() const
   { return reinterpret_cast<CMFC224Doc*>(m_pDocument); }
#endif

