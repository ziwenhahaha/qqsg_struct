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
    GetCamera()[127] = 0;
    GetCamera()[129] = 0;
}

```
