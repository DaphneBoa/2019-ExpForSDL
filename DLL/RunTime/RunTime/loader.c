#include<windows.h>
//数据类型，函数指针类型；（指向一个函数）
typedef int (WINAPI* MY_PROC)(char*);
int func() {}
int main()
{
	//MessageBoxA(0, 0, 0, 0);
	HMODULE hBaselib = LoadLibraryA("baselib.dll");

	if (hBaselib == NULL)
		return 0;

	MY_PROC func = (MY_PROC)GetProcAddress(
			hBaselib, "lib_func");
	func("run time load"); //有可能出错，名称重定义，但这里不会，因为一个全局一个局部。
}