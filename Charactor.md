# 玩家角色偏移量

``` cpp

// 可以自己去分析这块内存的数据，包含了（当前玩家的坐标、名字、职业、国家、三国币、五铢、5维属性、基础生命值、当前生命值等等）
typedef struct Charactor
{
    // TODO
};

typedef struct HObject
{
    char padding[38]; // 38 * 4 = 0x98;
    Charactor* playerInfo;
};

typedef struct Overworld
{
    char padding_1[5];
    
};

#define CHARACTOR_STATE 128;
#define MOVE_FORWARD = 0x89;
#define CHARACTOR_NAME 0x8868;
#define LocationX 0x6;
#define LocationY 0x11;

DWORD* GetCharactor()
{
    // 玩家结构首地址= [[[基地址]+0x14]+0x98]
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
}

// 跳跃状态
if(state == 0x10)
{

}

```
