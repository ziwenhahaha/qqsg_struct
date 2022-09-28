# 玩家角色偏移量

``` cpp
// file Charactor.h

#include "status.h"

// 可以自己去分析这块内存的数据，包含了（当前实体的坐标、名字、职业、国家、三国币、五铢、5维属性、基础生命值、当前生命值等等）
typedef struct PGameEntity
{
    DWORD Unknown[0x8658/4];
    
    // 树的状态根节点
	PPlayerStatusNode Root;
	// 树的最高根节点（此节点是默认拥有的，即玩家就算没有任何状态，也有此节点，如果 Root == TopRoot，则说明实体没有任何状态）
	PPlayerStatusNode TopRoot;
	// 树的节点数量
	DWORD Count;
};

```

## 说明

这个结构的使用就不写例子了，防止有人用于写外挂
