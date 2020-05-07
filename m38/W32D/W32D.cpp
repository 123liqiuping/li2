// W32D.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "W32D.h"


// 这是导出变量的一个示例
W32D_API int nW32D=0;
W32D_API int factorial(int n)
{
	int i, j = 1;
	if (n < 10)
	{
		for (i = 1; i <= n; i++)
		{
			j *= i;
		}
		return j;
	}
}
float FAC::convert(float deg)
{
	float pi = 3.14159265f;
	float j;
	j = deg / 180 * pi;
	return j;
}
// 这是导出函数的一个示例。
W32D_API int fnW32D(void)
{
    return 0;
}

// 这是已导出类的构造函数。
CW32D::CW32D()
{
    return;
}


