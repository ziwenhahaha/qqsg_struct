# 玩家状态

``` cpp


typedef struct PlayerStatus {
	DWORD CurrentTime;
	PDWORD Metadata;
} *PPlayerStatus;

typedef struct PlayerStatusNode {
	PlayerStatusNode* Pre;

	PlayerStatusNode* Next;

	PPlayerStatusNode Cur;

	DWORD Unknown;

	PPlayerStatus Status;

} *PPlayerStatusNode;

typedef struct PlayerStatusTree {
	PPlayerStatusNode Root;
	DWORD unknow;
	DWORD Count;
};

PlayerStatusTree* tree = playerInfo+0x8658;

```

