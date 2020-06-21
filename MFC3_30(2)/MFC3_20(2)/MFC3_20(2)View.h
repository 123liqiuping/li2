
// MFC3_20(2)View.h : CMFC3_202View 类的接口
//

#pragma once


class CMFC3_202View : public CView
{
protected: // 仅从序列化创建
	CMFC3_202View();
	DECLARE_DYNCREATE(CMFC3_202View)

// 特性
public:
	CMFC3_202Doc* GetDocument() const;

// 操作
public:
	bool flag;
	CImage img;
	int sx, sy, w, h;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3_202View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC3_20(2)View.cpp 中的调试版本
inline CMFC3_202Doc* CMFC3_202View::GetDocument() const
   { return reinterpret_cast<CMFC3_202Doc*>(m_pDocument); }
#endif

