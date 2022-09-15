# 使用劫持技术实现绕过QQ三国反作弊检测和注入

## 免责声明

这只是个攻击的演示，本文不是对腾讯公司的攻击，而是呼吁采取行动，做出必要的改进。这项研究通过私人研究来吸引ACE修复潜在的攻击向量，以维护游戏安全，这意味着本文只是出于教育目的。我不与任何游戏外挂发行商合作，也不是为了金钱利益而写游戏外挂的活跃作者。

对于那些希望就与作弊无关的问题/担忧与我联系的人，我的公共电子邮件是 *yafeng.wu@outlook.com*

## 介绍

Anti-CheatExpert，叫反作弊专家，简称ACE。
是由腾讯云移动安全团队与腾讯游戏安全团队合作打造的专业移动游戏安全解决方案。
具备全天候的安全保护能力，支持全面的多维度保护和检测。

## ACE的功能

ACE保护游戏客户端免受恶意篡改、调试和注入，使恶意修改器失效并保护游戏内存数据完整性。
此外，它可以精确识别并有效阻止游戏作弊者采用的各种加速/减速技术。
ACE阻止了12亿台移动设备上的意外和异常驱动行为。
基于腾讯的安全评估标准，检测准确率达到99.99%以上，确保流畅的用户体验。
此外，它还可以进行24/7实时监控和数据分析，一旦发现游戏作弊者，就将其消灭。
游戏客户端调用2-3个API即可快速访问ACE，不产生后端开发成本。

## 问题

正如任何黑客/外挂可能会告诉你的那样，除非你知道自己在做什么，否则直接注入游戏不会有好结果。这种说法很好地证明了这一点，因为任何改变被ACE保护的应用程序内存部分的尝试都会导致不可避免的软件崩溃，使用户感到困惑。目前，ACE针对注入的保护主要在：
1. 针对打开进程的NtOpenProcess的保护
2. 针对读内存的NtReadVirtualMemory的保护
3. 针对写内存的NtWriteVirtualMemory的保护
4. 针对打开线程的NtOpenThread的保护

常规的外部注入需要直接或者间接的依赖到上述的API。

## 使用DLL劫持注入QQ三国进程

QQ三国运行时，会加载许多DLL文件，比如游戏自身的SGBase.dll（使用反作弊ACE生成的文件）。也有一些外部的DLL文件，比如d3d9x.dll（游戏引擎渲染图形界面）。如果直接劫持dll会存在问题，因为ACE保护的缘故，会无法劫持QQ三国加载的系统目录下的dll文件。

``` txt

QQSG.exe
  -- QQSGBase.dll
  -- d3d9x.dll
  -- msacm32.dll
```

如果直接劫持 QQSGBase.dll 等，会无法劫持。但如果劫持驱动文件呢？ 其中的一个dll文件和驱动文件的依赖关系为 `msacm32.dll->msacm32.drv`。

## 注入的实现代码

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
