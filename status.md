# 实体状态

不仅仅是玩家，还包含了建筑物，怪物，其他玩家的状态，都是使用下述结构体。

``` cpp

template<typename T>
struct GameTreeNode {

	GameTreeNode<T>* LeftChild;
	GameTreeNode<T>* Father;
	GameTreeNode<T>* RightChild;
	int ValueId;
	T* Value;
};

template<typename T>
struct GameTree {
	int unknown_0;
	GameTreeNode<T>* Summary;
	int unknown_1;
	int Count;
};



// 状态数值表
typedef struct StatusMetadata {
	DWORD TotalTime;
	DWORD unknown_1;
	DWORD unknown_2;
	DWORD unknown_3;
	DWORD RecordTimeFlag;
	DWORD unknown_5;
	DWORD unknown_6;
	DWORD unknown_7;
	DWORD unknown_8;
	char Desc[32];
	DWORD unknown_17;
	DWORD unknown_18;
	DWORD unknown_19;
	DWORD unknown_20;
	DWORD unknown_21;
	DWORD unknown_22;
	DWORD unknown_23;
	DWORD unknown_24;
	DWORD unknown_25;
	DWORD unknown_26;
	DWORD unknown_27;
	DWORD unknown_28;
	DWORD unknown_29;
	DWORD unknown_30;
	DWORD unknown_31;
	DWORD unknown_32;
	DWORD unknown_33;
	DWORD unknown_34;
	DWORD PicCode;
	DWORD unknown_36;
	DWORD LeftTime;
	DWORD Type;
	StatusMetaValues Values; // int[15];
	DWORD SomeFlag;
	DWORD Effect;
	DWORD MaxImposeTimes;
	DWORD Todo[4];
	DWORD Todo1;
	DWORD Todo2[30];
} *PStatusMetadata;

// 状态
typedef struct Status {
	DWORD CurrentTime;
	PStatusMetadata Metadata;
	DWORD unknown_0;
	DWORD unknown_1;
	DWORD unknown_2;
	DWORD CurrentTime2;
	DWORD unknown_4;
	DWORD unknown_5;
	DWORD unknown_6;
	DWORD ShowType;
} PStatus;
```

使用方法：

``` cpp
// 实现一个获取青梅倒计时的代码

auto root = (GameTree<Status>) ...;

// 玩家状态树的描述节点，
auto summary = root->Summary;

// 最左边的节点
auto leftmost = summary->LeftChild;
// 最右边的节点
auto rightmost = summary->RightChild;

// 根节点
auto top_root = summary->Father;

search(top_root);

search(GameTree<Status> top_root)
{
    if(top_root && top_root->Value && top_root->Value->Metadata)
    {
        if(top_root->Value->Metadata->Type == 152)
	  printf("玩家身上有减速状态");
	search(top_root->LeftChild);
	search(top_root->RightChild);
    }
}

```
