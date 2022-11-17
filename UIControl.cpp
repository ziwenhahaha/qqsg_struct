// 数据来源于 https://www.bilibili.com/video/BV1Jg411q73X

typedef struct UIControl *PUIControl;

// 虚函数表
typedef struct UIControl_vftable
{
  int pad[3];
  bool (__thiscall *IsEnabled)(UIRoot *);
  int pad1[2];
  char *(__thiscall *id)(UIRoot *);
  int pad2[23];
  int (__thiscall *type)(UIRoot *);
  int pad6;
  int (__thiscall *style)(UIRoot *);
  int pad3[13];
  UIRoot *(__thiscall *GetElement)(UIRoot *, int *, int, int);
  int pad4[10];
  void (__thiscall *setcaption)(UIRoot *, const char *);
  char *(__thiscall *caption)(UIRoot *);
  int pad5[52];
  void (__thiscall *show)(UIRoot *, bool);
  int pad7[7];
  void (__thiscall *click)(UIRoot *);
} *PUIControl_vftable;

// 控件结构
struct UIControl
{
  UIRoot_vftable *vftable;
  int pad0[8];
  UIControl *father;
  int pad1;
  UIControl **begin;
  UIControl **end;
  int pad2[3];
  char *name;
  int pad3[11];
  char *uiname;
  int pad4[73];
  int *bkimage;
  int *coverpic;
  int pad4_1[4];
  int bkimagex;
  int bkimagey;
  int coverpicx;
  int coverpicy;
  int pad5[33];
  unsigned int State;
  int pad6[11];
  int initlayer;
  int plusplayer;
  int prelayer;
  int pad7[62];
  int textstyle;
  int pad8;
  int textsize;
  int pad9[4];
  unsigned int Style;
  int pad10[130];
  int *name_ref;
  int pad11[5];
  UIControl *Related;
  int pad12[20];
  int luaEnv;
};
