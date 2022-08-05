# 玩家角色偏移量

// 国家信息 sizeof(Country)=348
typedef struct Country
{
	DWORD Id; // 1:魏，2:蜀，3:吴
	// TODO
};

结构 偏移量 [基地址+14+98+0x8868]
/// 角色信息
typedef struct CharactorInfo
{
	// base_addr+14+98+0x8868
	char NickName[84];
	DWORD MaxHeath;
	DWORD CurrentHealth;
	DWORD MaxMagic;
	DWORD CurrentMagic;
	Country Country;
	DWORD Level;
};
