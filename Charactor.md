# 玩家角色偏移量

``` cpp

#define CHARACTOR_STATE 0x8A;
#define MOVE_FORWARD = 0x89;

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
   DWORD forward = GetCharactorOf(MOVE_FORWARD);
   if(forward == 0x5)
   {
      // 往左移动
   }
   
   if(forward == 0x3)
   {
      // 右
   }
   
   if(forward == 0x11)
   {
      // 下
   }
   
   if(forward == 0x9)
   {
      // 上
   }
   
   // 0x15:左下
   // 0x13：右下
   // 0xD:左上
   // 0xB 右上
   
   // 可以通过修改这个值实现变速效果
   GetCharactorOf(0x128); // 运动时长 单位ms
}

// 跳跃状态
if(state == 0x10)
{

}

```
