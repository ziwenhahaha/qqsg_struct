CtrlState4 枚举:

``` txt
低位
0x2 禁止使用道具
0x4 禁止拾取
0x8 灵魂状态/剑状态
0x10 治疗增益/减益标志
0x20 获得青梅状态（获得1颗/3颗）
0x40 隐身 我要藏起来 （可能是策划为了某些活动搞的状态）
0x80 隐身 我要藏起来 （可能是策划为了某些活动搞的状态） 0x40是主体目标获得的状态（比如玩家自身） 0x80是关联主体获得的状态(比如玩家选中的目标)
0x200 不可被鼠标hovered
0x400 不知道什么状态
0x800 红名状态
高位

```


CtrlState 枚举：

``` txt
0x4 粽子状态，换键盘吧，方向键完全不清使唤了！
0x20 速战/减蓄气状态
0x40 眩晕/石化的 去除的时候需要同时设置bCtrl1为1
0x80 失明状态，此标志位不控制实际的失明效果
0x100 恐惧状态 去除的时候同时设置bCtrl1为1
0x200 禁止加速状态
0x800 防沉迷状态
0x1000 置身
0x2000 禁止攀爬状态 
0x4000 缴械状态 
0x8000 左右相反状态
0x10000 不知道什么状态
0x20000 附体属性改变
0x40000 指定加血状态
0x80000 不可附体状态
0x100000 不可被选中状态
0x200000 无敌、不可被攻击状态
0x400000 不可被攻击状态
0x800000 击飞别人
0x1000000 换装状态

0x20000000 JS/HJ释放110的状态

0x40000000 物理系释放110的状态
```

LifeState 枚举：

``` txt
LIFE_STATE_NORMAL      = 1; --普通状态
LIFE_STATE_FIGHT       = 2; --战斗状态
LIFE_STATE_DEAD        = 8; --死亡状态
LIFE_STATE_EXCHANGE    = 16; --交流，交易，交换状态
LIFE_STATE_DREAM       = 32; --梦境状态
LIFE_STATE_ERRER       = 64;
```

FightState 枚举

``` lua
FIGHT_STATE_INVALID    =0;                        -- 无效战斗状态
FIGHT_STATE_CALM       =1 ;                           -- 处于战斗状态但未进行战斗
FIGHT_STATE_GATHER     =2 ;                         -- 战斗蓄气中
FIGHT_STATE_COMBAT     =3 ;                         -- 战斗进行中
FIGHT_STATE_FREEZE     =4 ;                         -- 战斗硬直中
FIGHT_STATE_INJURE     =5 ;                         -- 战斗受伤中
FIGHT_STATE_STATUS     =6 ;                         -- 战斗中中异常状态，不受控制状态
FIGHT_STATE_DEAD       =7 ;                         -- 战斗死亡状态
``` 
