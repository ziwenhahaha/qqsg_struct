# 技能数据的研究

主要是针对技能数值表未知列的研究。

F列，技能标志位：

枚举值

``` cpp
0x1 物理伤害招式
0x2 魔法伤害招式
0x4 治疗类招式
0x8 挑衅类招式
0x10 恐惧类招式
0x20 增益类招式
0x40 减益类招式
0x100 未知，此类招式会让受击者进入攻击状态
0x200 未知，此类招式会让受击者进入攻击状态
0x1000 怪物控制类
0x4000 瞬移类技能，目前仅有JS的90技能的第二段
0x8000 具有遮罩动画的技能
0x10000 具有飞行动画的招式
0x100000 冲锋类技能，会导致受击者大幅度击退/击飞
0x800000 冲锋子类，效果比冲锋类更弱，会小幅度击退受击者
0x4000000 特殊动画的招式，110XS
```

防止有人使用此数据作弊，我就不提供如何找 ComboItem 的方法了

``` cpp
struct ComboItem_vftable
{
  int pad;
  int (__thiscall *serverPos)(PComboItem combo);
  int pad1[68];
  int (__thiscall *level)(PComboItem combo);
};

// 玩家技能
struct ComboItem
{
  ComboItem_vftable *vftable;
  int pad[9];
  SkillMeta *Meta;
};
// 数值表
struct SkillMeta
{
  int SkillId;
  char name[32];
  char desc[304];
  int values[6];
  int Flag;
  int values2[29];
  // 修改为0可以无视僵直效果（仅客户端生效，可僵直结束后瞬移，但不能发招）
  int yinzhiTime;
  int values3[3];
  int MixStatusId;
  int values4[7];
  // 通过修改此值貌似可以实现连击的伤害增幅效果
  int LianJiCount;
  int values5[2];
  SkillLvlMeta *LvlMeta;
  int values6[20];
};
struct SkillLvlMeta
{
  int id;
  int maxLvl;
  // 持续时间增益
  int TimeAddon;
  int pad1[178];
  // 混合异常状态id
  int lvlMixStatuId;
  int pad2[20];
};

```
