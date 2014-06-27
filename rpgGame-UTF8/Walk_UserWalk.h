#ifndef _Walk_UserWalk_H_
#define _Walk_UserWalk_H_


//#define PLAYER_IN_MAP    1

//#define BARRIER_IN_MAP 2

//#define WALL_IN_MAP      3

//#define BOSS_IN_MAP      4
#define PLAYER                    1

#define SPACE                     0

#define BARRIER                   2

#define WALL                      3

#define LITTLE_MONSTER            7

#define BIG_MONSTER                4


#define NUM_RAND_1                10

#define MIN_OF_RAND_1              6
#define MAX_OF_RAND_1              9

#define FLAG_OF_BOSS               1
#define FLAG_OF_LITTLE_MONSTER     0



int Walk_ChooseEquiment(SUserAllInfoInGame *pRole); //选择更换装备函数声明
int Walk_ChooseMedicine(SUserAllInfoInGame * pRole); // 选择使用药水装备函数声明


void GameStart(SUserAllInfoInGame * pRole,
                  SMonsterInfo* pSmallMonster,
                   SMonsterInfo* pBossMonster);

static void Walk_Walk(SUserAllInfoInGame * pRole ,
	                      U8               key,
	                      U32              currentMap,
	                      SMonsterInfo*    pSmallMonster,
                          SMonsterInfo*    pBossMonster);

static int NextJudge(U32 flagOfMap) ;//下一个数组元素，是什么，传进来
static int UpJudge(SPosition *oldPosPtr);//旧位置的上一个位置，注意二维数组的下标引用和坐标是转置的
static int DownJudge(SPosition *oldPosPtr);//旧位置的下一个位置
static int LeftJudge(SPosition *oldPosPtr);// 旧位置的左一个位置
static int RightJudge(SPosition *oldPosPtr);// 旧位置的右一个位置

static  int FindLittleMonsterAndFight(SUserAllInfoInGame * pRole,
	                                      SMonsterInfo*    pSmallMonster,
                                          SMonsterInfo*    pBossMonster );


//显示角色各个属性值

static void Walk_DisplayAttriOfRole(SUserAllInfoInGame * pRole);


#endif

