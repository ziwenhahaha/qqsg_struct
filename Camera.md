# 游戏相机对象

``` cpp

DWORD* GetCamera()
{
    return GetOverWorld() + 0xC;
}

```
## Sample

``` cpp

void main()
{
    // 清除黑色图层
    // 黑色图层分2种，区别是可视范围大小不同
    GetCamera()[154] = 0;
    GetCamera()[157] = 0;
}

```
