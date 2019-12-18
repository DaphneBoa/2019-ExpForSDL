// .c文件不需要写main函数
#include<windows.h>

int int_func()
{
	return 0;
}

int lib_func(char* msg)
{
	// do some works
	MessageBoxA(0, "msg from base lib",msg,MB_OK);
	return 0;
}