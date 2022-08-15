# 玩家角色偏移量

``` cpp

#define CHARACTOR_STATE 0x8A;

DWORD* GetGameWorld()
{
   return (DWORD*)((*(DWORD*)0x11F6FEC) + 0x14);
}

DWORD* GetCharactor()
{
    return (DWORD*)GetGameWorld()[0x98];
}

DWORD GetCharactorOf(int index)
{
    return GetCharactor()[index];
}

```

## 获取角色的状态

``` cpp

DWORD state = GetCharactorOf(CHARACTOR_STATE);

// 静止状态
if(state == 0x2)
{

}
// 左右移动状态
if(state == 0x4)
{

}

// 跳跃状态
if(state == 0x10)
{

}

```
