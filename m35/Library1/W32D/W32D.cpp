// W32D.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "W32D.h"


// 这是导出变量的一个示例
W32D_API int nW32D=0;

// 这是导出函数的一个示例。
W32D_API int fnW32D(void)
{
    return 0;
}

W32D_API int GetInt()
{
    return 2020;
}
// 这是已导出类的构造函数。
CW32D::CW32D()
{
    return;
}
