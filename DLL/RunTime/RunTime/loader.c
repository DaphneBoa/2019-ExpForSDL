#include<windows.h>
//�������ͣ�����ָ�����ͣ���ָ��һ��������
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
	func("run time load"); //�п��ܳ��������ض��壬�����ﲻ�ᣬ��Ϊһ��ȫ��һ���ֲ���
}