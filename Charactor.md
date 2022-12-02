# 玩家角色偏移量

``` cpp
// file Charactor.h

#include "status.h"

// playerinfo+0x304 玩家横轴速度结构
// playerinfo+0x330 玩家竖轴速度结构
typedef struct Speed {
	DWORD Unknown;
	// 速度值
	DWORD SpeedVal;
	DWORD Unknown2;
	
	// 速度向量
	DWORD SpeedVector1;
	DWORD SpeedVector2;
	DWORD SpeedVector3;
	DWORD SpeedVector4;
	
	DWORD UnknownFields[0x2C/4];
} *PSpeed;

// 可以自己去分析这块内存的数据，包含了（当前实体的坐标、名字、职业、国家、三国币、五铢、5维属性、基础生命值、当前生命值等等）
typedef struct PGameEntity
{
	DWORD UnknownBlock[0x304/4];
	// X轴移速
	PSpeed SpeedX;
	// Y轴跳跃高度
	PSpeed SpeedY;
	// Y轴移速 固定2000
	PSpeed SpeedUnknown;
    	DWORD UnknownBlock2[(0x8658-0x304-sizeof(PSpeed) * 3)/4];
    	// 树的状态根节点
	PPlayerStatusNode Root;
	// 树的最高根节点（此节点是默认拥有的，即玩家就算没有任何状态，也有此节点，如果 Root == TopRoot，则说明实体没有任何状态）
	PPlayerStatusNode TopRoot;
	// 树的节点数量
	DWORD Count;
};

// direction values:
// 0-right,1-left,2-top,3-down

// location direction values:
// 1:水平移动
// 5:静止
// 2:跳跃浮空
// 3:攀爬

// moveState:
// 2:静止
// 4:移动
// 8:攀爬不动
// 16：浮空状态（跳跃）
// 32: 攀爬中

// moveForward (pressedKey) FLAG enum:
// 4:press left
// 2:press right
// 8:press up
// 16:press down

// 无法同时按左右 或 上下，其他组合可以位运算实现，比如按左上  1|4|8=13

// entityType
// 1:玩家
// 2:怪物
// 3:NPC
```
