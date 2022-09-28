# 世界信息

``` cpp
// File OverWorld.h

#include "Charactor.h"
#include "Camera.h";

typedef struct CurMap {

    // 这一块的内存数据应该是固定的一些数值，可能是当前地图的Id，特性（是否能PK，是否可以使用XX类道具）
    DWORD Unknown[0x98/4];
    // 当前玩家
    PGameEntity CurCharactor;

} PCurMap;

typedef struct GameWorld{
    // 某些固定的数值
    DWORD UnknownField3[0xC/4];
    Camera* Carame;
    // 某些固定的数值
    DWORD UnknownFileds[(0x14-0xC-sizeof(Camera*))/4];
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
