# 玩家角色偏移量

``` cpp

/// 角色信息 偏移量 [[[11F6FEC]+14]+98]+0x88F0
typedef struct CharactorInfo
{
	char NickName[132];
	DWORD MaxHeath;
	DWORD CurrentHealth;
	DWORD MaxMagic;
	DWORD CurrentMagic;
	char unknown[8];
	DWORD Country;
	DWORD Occupation;
	
};
```
