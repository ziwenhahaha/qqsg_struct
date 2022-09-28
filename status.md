# 实体状态

不仅仅是玩家，还包含了建筑物，怪物，其他玩家的状态，都是使用下述结构体。

``` cpp

// 数值表结构
typedef struct StatusMetadata {
	DWORD offset[0x94/4];
	// 持续时间
	DWORD LeftTime;
	// 状态大类
	DWORD Type;
} *PStatusMetadata;

// 玩家状态
typedef struct PlayerStatus {
	// 持续时间1，如果数值表里的某个字段 & 0x4000 的值为0 （RecordTimeFlag），则此时间不会增加
	DWORD CurrentTime;
	// 状态信息，如果当前是根状态，则此值为 nullptr
	PStatusMetadata Metadata;
	
	DWORD unknown[4];
	
	// 持续时间2
	DWORD CurrentTime2;
} *PPlayerStatus;

// 玩家链表节点
typedef struct PlayerStatusNode {
	// 上一个状态
	PlayerStatusNode* Pre;
	// 下一个状态
	PlayerStatusNode* Next;
	// 当前状态
	PlayerStatusNode* Cur;
	
	DWORD Unknown;
	// 玩家的状态信息
	PPlayerStatus Status;

} *PPlayerStatusNode;

```

使用方法：

``` cpp
// 实现一个获取青梅倒计时的代码

auto root = (PPlayerStatusNode) GetMonsterOf(0x8658/4)

while(root != nullptr && root->Status != nullptr && root->Status->Metadata != nullptr)
{
	// 此怪物所携带的buff,279表示青梅倒计时buff
	if(root->Status->Metadata->Type == 279)
	{
		auto left_seconds = root->Status->Metadata->LeftTime - root->Status->CurrentTime;
		
		printf("青梅煮酒还有 %d 毫秒开启", left_seconds);
	}
	
	root = root.Next;
}

```
