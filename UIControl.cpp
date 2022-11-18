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

// 判断窗体是否可见
// 如果你要实现自动切仓，需要判断私仓的窗口是否已经展示。
// 这个函数的性能比LUA更高，而且可以在非UI线程执行。
#include <string>
bool WinIsVisible(UIRoot* root, const char* window)
{
	auto lstr = std::string(window);

	auto index = lstr.find_first_of(".");

	if (strcmp(root->name, lstr.substr(0, index).c_str()) != 0)
	{
		return false;
	}

	// should not search children.
	if (index > lstr.size())
	{
		return ((root->State >> 7) & 1) != 0;
	}

	auto size = root->end - root->begin;

	for (auto i = 0; i < size; i++)
	{
		auto child = lstr.substr(index + 1);

		if (WinIsVisible(root->begin[i], child.c_str())) 
		{
			return true;
		}
	}

	return false;
}

int main()
{
  UIRoot* uiroot = ...;
  
  auto bShowMsgbox = WinIsVisible(uiroot, "UI.SysMsgbox");
  
  printf("The msgbox is show is %d.", bShowMsgbox);
}
