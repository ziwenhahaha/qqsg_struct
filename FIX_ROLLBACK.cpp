// 此方法可以有效缓解释放技能拉回的bug，但是无法根本性解决。
// 最好的办法是需要针对几个地址做inlinehook，比如在服务器通知的玩家坐标时的hook，当服务器的坐标和玩家坐标的差异不大时，直接丢掉这个包
// 这样发包线程会直接通知服务器强制更新玩家坐标为客户端坐标。
// 但是此处不提供这些写法，原因是这些写法本质是一种瞬移外挂。

HWND mainWnd;

BOOL CALLBACK IsQQSGWnd(HWND hWnd, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	DWORD processId;
  
	if (GetWindowThreadProcessId(hWnd, &processId) == FALSE)
	{
		return TRUE;
	}

	LPWSTR className = new WCHAR[128];

	if (GetCurrentProcessId() == processId && GetClassName(hWnd, className, 128) > 0 && wcscmp(className, TEXT("QQSGWinClass")) == 0)
	{
		mainWnd = hWnd;

		return FALSE;
	}

	delete[]className;

	return TRUE;
}

DWORD WINAPI MoveMoveMove(LPVOID lpThreadParameter)
{
    while(true)
    {
      if(CharatorOf(MOVE_FORWARD) == 0x5)
        PostMessage(mainWnd, WM_KEYDOWN, VK_LEFT, NULL);
      if(CharatorOf(MOVE_FORWARD) == 0x3)
        PostMessage(mainWnd, WM_KEYDOWN, VK_RIGHT, NULL);
        
      Sleep(10);
    }
}

// 注入到三国进程
int dllmain(...)
{
	EnumWindows(IsQQSGWnd, NULL);

  if(mainWnd == NULL)
    return 0;
    
  auto handle = CreateThread(NULL, 0, MoveMoveMove, NULL, 0, NULL);
  
  if(handle)
    CloseHandle(handle);
}
