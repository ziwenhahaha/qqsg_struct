# QQ三国注入方法的分析

QQ三国由于是很老的游戏了，在安全方面做的实在差强人意。ACE虽然防范了外部的注入方式，但ACE本身无法解决游戏自身的安全漏洞。

## 使用DLL劫持注入QQ三国进程

这种方法是目前三国外挂开发者使用的主流做法。已经发现的有：

1. 麻子（或成478）使用的外挂，采用的是劫持 msacm32.drv 文件实现的劫持注入。
2. 三足大区某位开发者（外挂名称据说是叫 修行者），采用的是劫持 d3d9x.dll 文件实现的劫持注入。

还有一些其他的外挂使用的注入，目前还没研究，比如 黑皮猪的外挂。

修行者的劫持方式是直接劫持d3d9x.dll文件，目前已经在2022.7.28日的更新中，ACE反作弊已经针对此种注入方式进行了和谐。

## 注入的实现代码

[攻击演示视频](https://space.bilibili.com/236140068)

攻击视频我还在录制，目前这个链接只是链接到我的个人空间。

## 漏洞详细的细节

编写DLL文件，在`DllMain` 中增加如下代码：

``` cpp
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		wsprintf(buffer, L"注入成功 %d", (DWORD)hModule);

		MessageBox(NULL, buffer, L"SUCCESS", MB_OK);

		return TRUE;
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{

		wsprintf(buffer, L"退出成功 %d", (DWORD)hModule);

		MessageBox(NULL, buffer, L"SUCCESS", MB_OK);

		return TRUE;
	}

	return TRUE;
}
```

编译为32位的dll文件，并把文件重命名为 **msacm32.drv**,将该文件复制到三国的根目录，如 *C:\Program Files\腾讯游戏\QQ三国\*

一切就绪，运行QQ三国程序，选择大区后点击进入游戏。

稍后在游戏界面将连续弹窗：注入成功->退出成功->注入成功->退出成功

可以利用上述机制实现一些恶意代码

## 反作弊方法

可以通过枚举模块实现反作弊的效果。