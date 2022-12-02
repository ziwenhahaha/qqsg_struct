# 道路

游戏里玩家能站立，爬的都是道路

道路的结构

``` cpp

// 坐标
struct CoordinateInfo {
	int x;
	int y;
};

// 道路
struct MoveLapMeta
{
	// 道路Id
	unsigned __int16 LapId;
	// 道路类型 2:水平道路,4:斜坡道路,8:垂直道路
	int Type;
	// 角度，浮点数，有些情况其实需要校验玩家的道路信息
	// 比如，通过玩家的X的坐标减去道路的StartPoint.x，得到玩家的直角边长度
	// 通过三角函数就能算出玩家的Y轴坐标
	float Angle;

	// 道路本质是一条线段，2点确定一线
	CoordinateInfo StartPoint;
	CoordinateInfo EndPoint;

	// 顺序可能反了，但是这2个字段都是表示当前道路的两端接壤道路的id
	unsigned __int16 prevLapId;
	unsigned __int16 nextLapId;

	int unknown_1;
	// 该道路关联的传送带编号
	int DynamicLapId;
};
// 传送带
// 传送带不是传送点，传送带的作用是为了实现类似十里坡里那种玩家不需要操作，也会跟着水流滑动的效果
struct MoveDynamicLapMeta
{
	int pad[9];
	// 貌似是每一帧滑动的距离
	int add_x;
	int add_y;
	int pad1[200];
};

```
