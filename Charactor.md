# 玩家角色偏移量

``` cpp

#define CHARACTOR_STATE 0x8A;
#define MOVE_FORWARD = 0x89;
#define CHARACTOR_NAME 0x8868;
#define LocationX 0x6;
#define LocationY 0x11;

DWORD* GetCharactor()
{
    return (DWORD*)((DWORD*)(GetOverWorld()[0x5]))[0x38];
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
