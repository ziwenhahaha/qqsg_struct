// 数据来源于 https://www.bilibili.com/video/BV1Jg411q73X

typedef struct UIControl *PUIControl;

// 虚函数表
typedef struct UIControl_vftable
{
  int pad[6];
  char *(__thiscall *id)(PUIControl);
  int pad2[23];
  int (__thiscall *type)(PUIControl);
  int pad6;
  int (__thiscall *style)(PUIControl);
  int pad3[86];
  void (__thiscall *click)(PUIControl);
} *PUIControl_vftable;

// 控件结构
struct UIControl
{
  UIControl_vftable *vftable;
  int pad0[8];
  UIControl *father;
  int pad1;
  UIControl **begin;
  UIControl **end;
  int pad2[3];
  char *name;
  int pad3[11];
  char *uiname;
  int pad4[116];
  unsigned int State;
  int pad6[11];
  int initlayer;
  int plusplayer;
  int prelayer;
  int pad7[69];
  unsigned int MovableInfo;
};
