# 玩家状态

``` cpp

// 数值表记录model
typedef struct StatusMetadata {

  ...

} *PStatusMetadata;

// 我的异常状态
typedef struct MyStatus {
char unknown[4];
PStatusMetadata Metadata;

// 该状态已经持续了多久，单位毫秒
DWORD KeepTime;

...

} *PMyStatus;

typedef struct Status {
char unknown[10];
PMyStatus DotInfo;
...
} *PStatus;

DWORD statusCount = playerInfo+0x8650;

PStatus* statuses = playerInfo+0x8654;

PStatus* nullStatus = playerInfo+0x8658;

```

