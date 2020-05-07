#include "pch.h"
#include "framework.h"
#include "32.h"
float FAC::convert(float deg) {
	float pi = 3.14159265f;
	float j;
	j = deg / 180 * pi;
	return j;
}