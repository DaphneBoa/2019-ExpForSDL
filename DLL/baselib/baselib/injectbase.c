// ����c����c ������c++

// ����Ҫдmain��������Ϊmain������exe��
// ֻ��Ҫ�ṩ��������
#include <Windows.h>

int WINAPI lib_func(char*);

// ���ᱻ����
int intnal_func() {
	return 0;
}
// �ᱻ����
int WINAPI lib_func(char* msg) {
	// do some works
	MessageBoxA(0, 
		"msg from base lib", 
		msg, 
		MB_OK);
	return 0;
}
BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,  // handle to DLL module
	DWORD fdwReason,     // reason for calling function
	LPVOID lpReserved)  // reserved
{
	// Perform actions based on the reason for calling.
	switch (fdwReason)
	{
		// ���̼�����Dll�����ú��������Ե���������
	case DLL_PROCESS_ATTACH:
		// Initialize once for each new process.
		// Return FALSE to fail DLL load.
		Sleep(1000);
		lib_func("load");
		break;

	case DLL_THREAD_ATTACH:
		// Do thread-specific initialization.
		break;

	case DLL_THREAD_DETACH:
		// Do thread-specific cleanup.
		break;

	case DLL_PROCESS_DETACH:
		// Perform any necessary cleanup.
		break;
	}
	return TRUE;  // Successful DLL_PROCESS_ATTACH.
}