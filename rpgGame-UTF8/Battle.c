#include<stdio.h>
#include<stdlib.h>
#include"Init_GameData.h"
#define USERROLE_CONTINUE_FIGHT 1/*返回值为1用户可以继续战斗*/
#define USERROLE_FIGHT_FAIL 0/*返回值为0用户战斗失败*/
#define SMALLMONSTER_CONTINUE_FIGHT 2/*返回值为2小怪未死还需用户战斗*/
#define USERROLE_FIGHT_SMALLMONSTER_WIN 3/*返回值为0小怪死亡用户战斗胜利*/
#define BOSS_CONTINUE_FIGHT 4
#define USERROLE_FIGHT_BOSS_WIN 5

#define ESCAPE_SUCCESSFULL 6
#define ESCAPE_FAIL 7

#define BOSS 100
#define SMALLMONSTER 101

static const int Battle_MAP_X_LENGTH = 60;
static const int Battle_MAP_Y_LENGTH = 18;

/*战斗模块封装函数，供其他模块调用*/
int Battle_Combat(SUserAllInfoInGame *customer, SMonsterInfo *monster, int flag);

void Battle_SpaceShow();       /*战场界面显示函数*/
void Battle_SpaceShut();       /*战场界面关闭函数*/

/*用户与小怪战斗函数*/
int Battle_FightAgainstSmallMonster(SUserAllInfoInGame *customer, SMonsterInfo *SmallMonster, int flag);
int Battle_FightAgainstBoss();    /*用户与Boss战斗函数*/

/*每隔一段时间读取用户和怪物的生命值等属性*/
static void Battle_GetUserAndMonsterValue(SUserAllInfoInGame *customer, SMonsterInfo *monster);


static int Battle_Escape(SUserAllInfoInGame *customer,SMonsterInfo *SmallMonster, int flag);/*逃跑处理函数*/
static void Battle_SpaceShowInfo();   /*战场界面标题栏显示信息*/
static char Battle_AttackingEventChooseShow();/*进入战场界面后的各种选择界面显示函数*/

/*小怪攻击用户角色函数*/
static void Battle_SmallMonsterAttackUserRole(SUserAllInfoInGame *customer, SMonsterInfo *SmallMonster);

/*Boss攻击用户角色函数*/
static void Battle_BossAttackUserRole(SUserAllInfoInGame *customer, SMonsterInfo *Boss);
/*对小怪进行物理攻击函数*/
static void Battle_PhysicalAttackToSmallMonster(SUserAllInfoInGame *customer, SMonsterInfo *SmallMonster);

/*对BOSS进行物理攻击函数*/
static void Battle_PhysicalAttackToBoss(SUserAllInfoInGame *customer, SMonsterInfo *Boss);

/*技能攻击种类选择函数,小火球术,大火球术 */
static char Battle_TypeSkillAttack();

/*第二层选择窗口是选择技能选择还是逃跑*/
static char Battle_SecondChooseShow();

static void Battle_SmallFireBolt(SUserAllInfoInGame *customer, SMonsterInfo *monster,int flag);       /*小火球术使用函数*/
static void Battle_BigFireBolt(SUserAllInfoInGame *customer, SMonsterInfo *monster,int flag);         /*大火球术使用函数*/


static int Battle_JudgeSmallMonsterHP(SMonsterInfo *SmallMonster);   /*小怪生命值判断函数*/
static int Battle_JudgeBossHP(SMonsterInfo *Boss);    /*Boss生命值判断函数*/
static int Battle_JudgeUserRoleHP(SUserAllInfoInGame *customer);     /*用户角色生命值判断函数*/
static int Battle_JudgeUserRoleMP(SUserAllInfoInGame *customer, int skill);     /*用户角色魔法值判断函数*/
static void Battle_UserRoleUpgrade();/*用户角色等级升级函数,当用户等级增加一等级时相应属性值升级*/
static void Battle_WinnerDealPocketMoneyExp(SUserAllInfoInGame *customer, SMonsterInfo *monster, int flag);/*用户胜利后对小

怪口袋中经验值和*/


/*战场界面显示函数*/
void Battle_SpaceShow()
{
	int display[18][60] = {
			{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3},
			{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}

	};
	int i = 0, j = 0;
	int temp = 0;
	for(i=0; i<Battle_MAP_Y_LENGTH; i++)
	{
		for(j=0; j<Battle_MAP_X_LENGTH; j++)
		{
			temp = display[i][j];
			if(temp==3)
			{
				printf("■");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

}
void Battle_SpaceShow1()
{
	int display[18][60] = {
			{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}

	};
	int i = 0, j = 0;
	int temp = 0;
	for(i=0; i<Battle_MAP_Y_LENGTH; i++)
	{
		for(j=0; j<Battle_MAP_X_LENGTH; j++)
		{
			temp = display[i][j];
			if(temp==3)
			{
				printf("■");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

}

void Battle_SpaceShow2()
{
	int display[18][60] = {
			{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}

	};
	int i = 0, j = 0;
	int temp = 0;
	for(i=0; i<Battle_MAP_Y_LENGTH; i++)
	{
		for(j=0; j<Battle_MAP_X_LENGTH; j++)
		{
			temp = display[i][j];
			if(temp==3)
			{
				printf("■");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

}

void Battle_SpaceShow3()
{
	int display[18][60] = {
			{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
			{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}

	};
	int i = 0, j = 0;
	int temp = 0;
	for(i=0; i<Battle_MAP_Y_LENGTH; i++)
	{
		for(j=0; j<Battle_MAP_X_LENGTH; j++)
		{
			temp = display[i][j];
			if(temp==3)
			{
				printf("■");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

}

void Battle_FightWalk()
{
  Battle_SpaceShow();
  sleep(1);
  system("clear");
  Battle_SpaceShow1();
  sleep(1);
  system("clear");
  Battle_SpaceShow2();
  sleep(1);
  system("clear");
  Battle_SpaceShow3();
  sleep(1);
  system("clear");
  Battle_SpaceShow2();
  sleep(1);
  system("clear");
  Battle_SpaceShow1();
  sleep(1);
  system("clear");
  Battle_SpaceShow();
}
/*每隔一秒读取用户角色和怪物相关属性值*/
void Battle_GetUserAndMonsterValue(SUserAllInfoInGame *customer, SMonsterInfo *monster)
{
}



/*战场界面标题栏显示信息*/
void Battle_SpaceShowInfo()
{
	printf("==============================================================\n");
	printf("==============已经进入战场,请全力以赴攻击对手==============\n");
	printf("==============================================================\n");
}

/*对小怪进行物理攻击函数*/
void Battle_PhysicalAttackToSmallMonster(SUserAllInfoInGame *customer, SMonsterInfo *SmallMonster)
{
  Battle_FightWalk();
	printf("用户攻击小怪\n");
	SmallMonster->HP = SmallMonster->HP -(customer->attack -SmallMonster->defend);
}

/*对Boss进行物理攻击函数*/
void Battle_PhysicalAttackToBoss(SUserAllInfoInGame *customer, SMonsterInfo *Boss)
{
  Battle_FightWalk();
  printf("用户攻击Boss\n");
  Boss->HP = Boss->HP - (customer->attack - Boss->defend);
}
/*小怪攻击用户角色函数*/
void Battle_SmallMonsterAttackUserRole(SUserAllInfoInGame *customer, SMonsterInfo *SmallMonster)
{
	printf("小怪攻击用户\n");
	customer->HP = customer->HP - (SmallMonster->attack - customer->defend);
}

/*Boss攻击用户角色函数*/
void Battle_BossAttackUserRole(SUserAllInfoInGame *customer, SMonsterInfo *Boss)
{
	printf("Boss攻击用户\n");
	customer->HP = customer->HP - (Boss->attack - customer->defend);
}

/*用户生命值判断函数*/
int Battle_JudgeUserRoleHP(SUserAllInfoInGame *customer)
{
	if(customer->HP>0)
		return USERROLE_CONTINUE_FIGHT;

	if(customer->HP<=0)
		return USERROLE_FIGHT_FAIL;
}

/*小怪生命值判断函数*/
int Battle_JudgeSmallMonsterHP(SMonsterInfo *SmallMonster)
{
	if(SmallMonster->HP>0)
		return SMALLMONSTER_CONTINUE_FIGHT;

	if(SmallMonster->HP<=0)
		return USERROLE_FIGHT_SMALLMONSTER_WIN;
}

/*战斗胜利后处理怪物口袋中的经验值*/
void Battle_WinnerDealPocketMoneyExp(SUserAllInfoInGame *customer, SMonsterInfo *monster, int flag)
{
	if(flag==BOSS)
	{
		SMonsterInfo *Boss = monster;
		customer->exp = customer->exp + Boss->pMonsterPocket->exp;
	}
	else if(flag==SMALLMONSTER)
	{
		SMonsterInfo *SmallMonster = monster;
		customer->exp = customer->exp + SmallMonster->pMonsterPocket->exp;
	}
}


/*Boss生命值判断函数*/
int Battle_JudgeBossHP(SMonsterInfo *Boss)
{
  if(Boss->HP>0)
    return BOSS_CONTINUE_FIGHT;
  if(Boss->HP<=0)
    return USERROLE_FIGHT_BOSS_WIN;
}

/*用户角色魔法值判断函数*/
int Battle_JudgeUserRoleMP(SUserAllInfoInGame *customer, int skill)
{
  if(skill==MAGIC_SKILL_SMALL_FIRE)
    return (customer->MP) / 20;
  if(skill==MAGIC_SKILL_BIG_FIRE)
    return (customer->MP) / 50;
  if(skill==MAGIC_SKILL_PROTECT)
    return (customer->MP) / 50;
}


/*使用小火球术函数*/
void Battle_SmallFireBolt(SUserAllInfoInGame *customer, SMonsterInfo *monster, int flag)
{
	int skill = MAGIC_SKILL_SMALL_FIRE;
  if(flag==SMALLMONSTER)
  {
    int MP = Battle_JudgeUserRoleMP( customer, skill );
    if(MP>=1)
    {
      Battle_FightWalk();
      printf("使用小火球术攻击成功!");
      monster->HP = monster->HP - (customer->attack - monster->defend) * 2;
      customer->MP = customer->MP - 20;
    }
    else
    {
      printf("魔法值不足，无法使用大火球术");
    }
  }
  if(flag==BOSS)
  {
    int MP = Battle_JudgeUserRoleMP(customer, skill);
    if(MP>=1)
    {
      Battle_FightWalk();
      printf("使用小火球术攻击成功!");
      monster->HP = monster->HP - (customer->attack - monster->defend) * 2;
      customer->MP = customer->MP - 20;
    }
    else
    {
      printf("魔法值不足，无法使用大火球术");
    }
  }
}

/*使用大火球术函数*/
void Battle_BigFireBolt(SUserAllInfoInGame *customer, SMonsterInfo *monster,int flag)
{
	int skill = MAGIC_SKILL_BIG_FIRE;
  if(flag==SMALLMONSTER)
  {
    int MP = Battle_JudgeUserRoleMP( customer, skill);
    if(MP>=1)
    {
      Battle_FightWalk();
      printf("使用大火球术攻击成功!");
      monster->HP = monster->HP - (customer->attack - monster->defend)*3;
      customer->MP = customer->MP - 50;
    }
    else
    {
      printf("魔法值不足，无法使用大火球术");
    }


  }
  if(flag==BOSS)
  {
    int MP = Battle_JudgeUserRoleMP(customer, skill);
    if(MP>=1)
    {
      Battle_FightWalk();
      printf("使用大火球术攻击成功!");
      monster->HP = monster->HP - (customer->attack - monster->defend)*3;
      customer->MP = customer->MP - 50;
    }
    else
    {
      printf("魔法值不足，无法使用大火球术");
    }
  }
}

/*逃跑处理函数*/
int Battle_Escape(SUserAllInfoInGame *customer,SMonsterInfo *SmallMonster, int flag)
{
  if(flag==SMALLMONSTER)
  {
    if(customer->dex>SmallMonster->dex)
    {
      customer->HP = customer->HP - 5;
      printf("逃跑成功");
	  printf("\n");
      return ESCAPE_SUCCESSFULL;
    }

    if(customer->dex<=SmallMonster->dex)
    {
      customer->HP = customer->HP - 5;
      printf("逃跑失败");

	  printf("\n");
      return ESCAPE_FAIL;
    }

  }
  if(flag==BOSS)
  {
    printf("和BOSS 战斗时无法逃跑，你只能拼尽全力啦");
    return ESCAPE_FAIL;
  }
}







/*与小怪战斗函数*/
int Battle_FightAgainstSmallMonster(SUserAllInfoInGame *customer, SMonsterInfo *SmallMonster, int flag)
{
	int escape = 0;
	while(customer->HP>0 && SmallMonster->HP>0&&(escape==0||escape==ESCAPE_FAIL))
	{
		printf("请给出你的选择：\nk:直接进行物理攻击.\np:进入功能选择窗口.");
		printf("\n你的选择是:");

		U8 chr = getchar();
		getchar();

		switch(chr)
		{
			case 'k':

				printf("用户的生命值:%d\n", customer->HP);
                printf("小怪的生命值:%d\n", SmallMonster->HP);
				Battle_PhysicalAttackToSmallMonster(customer, SmallMonster);
				if(SmallMonster->HP>0)
				{
					Battle_SmallMonsterAttackUserRole(customer,SmallMonster);
					printf("用户的生命值:%d\n", customer->HP);
                    printf("小怪的生命值:%d\n", SmallMonster->HP);
				}
				else
                                {return 0;}

			break;
			case 'p':
			{
				printf("请给出你的选择:\n1选择逃跑.\n2:进入技能选择窗口.");
				printf("\n你的选择是:");
				U8 ch = getchar();
					getchar();
				switch(ch)
				{
					case '1':
					{
						escape = Battle_Escape(customer, SmallMonster,flag);
					}break;
					case '2':
					{
						printf("请给出你的选择:\ns:小火球术.\nb:大火球术.");
						printf("\n你的选择是:");
						U8 ch1 = getchar();
					    getchar();
						switch(ch1)
						{
							case 's':
							{
								int skill = MAGIC_SKILL_SMALL_FIRE;
								int SmallMP = Battle_JudgeUserRoleMP(customer, skill);
								if(SmallMP>=1)
								{
									printf("用户的生命值:%d\n", customer->HP);
                                    printf("小怪的生命值:%d\n", SmallMonster->HP);
									Battle_SmallFireBolt( customer,SmallMonster, flag);
									if(SmallMonster->HP>0)
									{
										Battle_SmallMonsterAttackUserRole(customer,SmallMonster);
										printf("用户的生命值:%d\n", customer->HP);
                                        printf("小怪的生命值:%d\n", SmallMonster->HP);
									}
								}
							}break;
							case 'b':
							{
								int skill = MAGIC_SKILL_SMALL_FIRE;
								int BigMP = Battle_JudgeUserRoleMP(customer, skill);
								if(BigMP>=1)
					            {
									printf("用户的生命值:%d\n", customer->HP);
                                    printf("小怪的生命值:%d\n", SmallMonster->HP);
									Battle_BigFireBolt(customer,SmallMonster,flag);
									if(SmallMonster->HP>0)
									{
										Battle_SmallMonsterAttackUserRole(customer, SmallMonster);
										printf("用户的生命值:%d\n", customer->HP);
                                        printf("小怪的生命值:%d\n", SmallMonster->HP);
									}
								}
							}break;
						}
					}break;
				}

			}break;
		}
	}
  if(customer->HP<=0)
  {
    printf("战斗失败\n");
	sleep(2);
    return USERROLE_FIGHT_FAIL;
  }
  else if(SmallMonster->HP<=0)
  {

    Battle_WinnerDealPocketMoneyExp (customer, SmallMonster, flag);
    printf("经验值增长为%d\n:", customer->exp);
	sleep(2);
    return USERROLE_FIGHT_SMALLMONSTER_WIN;
  }
  else if(customer->HP>0 && escape==ESCAPE_SUCCESSFULL)
    return ESCAPE_SUCCESSFULL;
}

/*与BOSS战斗函数*/
int Battle_FightAgainstBoss(SUserAllInfoInGame *customer, SMonsterInfo *Boss, int flag)
{
	  while(customer->HP>0 && Boss->HP>0)
	  {
		  printf("请给出你的选择：\nk:直接进行物理攻击.\np:进入功能选择窗口.");
		  printf("\n你的选择是:");
		  U8 ch2 = getchar();
		getchar();
		  switch(ch2)
		  {
			  case 'k':
			  {
				  printf("用户的生命值:%d\n", customer->HP);
				  printf("Boss的生命值:%d\n", Boss->HP);
				  Battle_PhysicalAttackToBoss(customer, Boss);
				  if(Boss->HP>0)
				  {
					  Battle_BossAttackUserRole(customer, Boss);
					  printf("用户的生命值:%d\n", customer->HP);
					  printf("Boss的生命值:%d\n", Boss->HP);
				  }
			  }break;
			  case 'p':
			  {
				  printf("请给出你的选择:\n1选择逃跑.\n2:进入技能选择窗口.");
				  printf("\n你的选择是:");
				  U8 ch3 = getchar();
					    getchar();
				  switch(ch3)
				  {
					  case '1':
					  {
						  Battle_Escape(customer, Boss,flag);
					  }break;
					  case '2':
					  {
						  printf("请给出你的选择:\ns:小火球术.\nb:大火球术.");
						  printf("\n你的选择是:");
						  U8 ch4 = getchar();
							getchar();

						  switch(ch4)
						  {
							  case 's':
							  {
								  int skill = MAGIC_SKILL_SMALL_FIRE;
								  int SmallMP = Battle_JudgeUserRoleMP(customer, skill);
								  if(SmallMP>=1)
								  {
									  printf("用户的生命值:%d\n", customer->HP);
									  printf("Boss的生命值:%d\n", Boss->HP);
									  Battle_SmallFireBolt( customer,Boss, flag);
									  if(Boss->HP>0)
									  {
										  Battle_BossAttackUserRole(customer,Boss);
										  printf("用户的生命值:%d\n", customer->HP);
										  printf("Boss的生命值:%d\n", Boss->HP);
									  }
								  }
							  }break;
							  case 'b':
							  {
								  int skill = MAGIC_SKILL_SMALL_FIRE;
								  int BigMP = Battle_JudgeUserRoleMP(customer, skill);
								  if(BigMP>=1)
								  {
									  printf("用户的生命值:%d\n", customer->HP);
									  printf("Boss的生命值:%d\n", Boss->HP);
									  Battle_BigFireBolt(customer,Boss,flag);
									  if(Boss->HP>0)
									  {
										  Battle_SmallMonsterAttackUserRole(customer, Boss);
										  printf("用户的生命值:%d\n", customer->HP);
										  printf("Boss的生命值:%d\n", Boss->HP);
									  }
								  }
							  }break;
						  }
					  }break;
				  }

			  }break;
		  }
	  }
	if(customer->HP<=0)
	{
	  printf("战斗失败\n");
	  return USERROLE_FIGHT_FAIL;
	}
	else if(Boss->HP<=0)
	{

	  Battle_WinnerDealPocketMoneyExp (customer, Boss, flag);

	  printf("经验值增长为%d\n:", customer->exp);
          sleep(3);
          shop();
	  return USERROLE_FIGHT_SMALLMONSTER_WIN;
	}

}


/*战斗模块封装函数*/
int Battle_Combat(SUserAllInfoInGame *customer, SMonsterInfo *monster, int flag)
{
  Battle_SpaceShowInfo();
  Battle_SpaceShow();

  if(flag==SMALLMONSTER)
  {

    SMonsterInfo *SmallMonster = monster;
    return Battle_FightAgainstSmallMonster( customer, SmallMonster, flag);
  }
  if(flag==BOSS)
  {
    SMonsterInfo *Boss = monster;
    return Battle_FightAgainstBoss( customer,Boss, flag);
  }

}

