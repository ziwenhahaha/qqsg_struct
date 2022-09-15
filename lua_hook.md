# 在QQ三国的lua函数中安装钩子

## 代码

``` cpp

string replace_all(string src, const string& old_value, const string& new_value) {

	for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
		if ((pos = src.find(old_value, pos)) != string::npos) {
			src.replace(pos, old_value.length(), new_value);
		}
		else break;
	}
	return src;
}

typedef const char* (__stdcall* LuaHookProvider)(string func);

void luaL_hook(lua_State* L, string func, LuaHookProvider hook_func)
{
	auto temp = "hook_" + replace_all(func, ".", "_");

	auto declare = temp + "=" + func;

	luaL_dostring(L, declare.c_str());

	auto hook = hook_func(temp);

	auto installHook = func + "=" + hook;

	luaL_dostring(L, installHook.c_str());
}

```

## 使用方法

``` cpp

string hook_func;

const char* __stdcall installHook(string func)
{
	hook_func = "function(showMsg)\n" + func + "('hook'..showMsg)\nend";

	return hook_func.c_str();
}

int main()
{


	auto luaEnv = luaL_newstate();

	lua_register(luaEnv, "PrintToCpp", PrintToCpp);

	if (luaL_dofile(luaEnv, "sample.lua"))
	{
		printf("error %s", lua_tostring(luaEnv, -1));
	}

	luaL_hook(luaEnv, "GameUI.BeastDlg.OnUpdate", installHook);

	if (luaL_dostring(luaEnv, "GameUI.BeastDlg.OnUpdate('hello world')")) {
		printf("error %s", lua_tostring(luaEnv, -1));
	}
}

```

### sample.lua

``` lua
GameUI = {
	BeastDlg = {
		OnUpdate = function( showMsg )
			PrintToCpp(showMsg);
		end
	}
}

```
