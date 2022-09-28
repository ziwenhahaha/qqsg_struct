# 世界信息

``` cpp
// File OverWorld.h

#include "Charactor.h"

typedef struct CurMap {

    // 这一块的内存数据应该是固定的一些数值，可能是当前地图的Id，特性（是否能PK，是否可以使用XX类道具）
    DWORD Unknown[0x98/4];
    // 当前玩家
    PGameEntity CurCharactor;

} PCurMap;

typedef struct GameWorld{

    // 这一块的数据应该是固定的一些数值，可能是上一张地图，下一张地图，数值表等全局使用的信息。
    DWORD UnknownFileds[0x14/4];
    
    PCurMap CurMap;
} PGameWorld;

auto constexpr BaseAddress = 0x1111111;

// 获取游戏世界
PGameWorld GetGameWorld()
{
    // 自己去用CE扫一下基地址就行
    return (PGameWorld)BaseAddress;
}

```
