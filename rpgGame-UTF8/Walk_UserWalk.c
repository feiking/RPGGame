#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#include"Init_GameData.h"
#include "Show_AllDisplayFunc.h"

#include"Walk_UserWalk.h"

extern U32 mapArray_1[18][24] ;
//SUserAllInfoInGame role; //这个是全局变量


/* 提供出去的借口,这个由main函数调用
传入的参数,用户角色，大怪和小怪的顺序表的头指针
*/
void GameStart(SUserAllInfoInGame * pRole,
                  SMonsterInfo* pSmallMonster,
                   SMonsterInfo* pBossMonster)
{
		//SMonsterInfo * smallMonsterPtr =   NULL;
	   // SMonsterInfo * bossPtr           = NULL;
#if 0
	U8 mapChoice;
	printf("请输入要玩的关卡:");
	mapChoice = getchar() - 48;
	getchar();

	printf("%d\n",mapChoice);
    //加载文件时已经确定该用户已过的关卡
//    printf("请输入要玩的关卡: ");
#endif
    U8 key ;
    while(1)
    {
		//Show_DisplayMap(mapChoice);
        Show_DisplayMap(1);

        key = getchar();  //字符输出
        printf("key = %d\n",key);
        getchar();
		//RefreshBuff();
       // sscanf();
        Walk_Walk(pRole, key,1,pSmallMonster,pBossMonster);
#if 0
       int i,j;
       for(i = 0;i < 18; i++)
       {
           for(j = 0; j < 24; j++)
               printf("%d ",mapArray_1[i][j]);

           printf("\n");
       }
#endif
        if(key == 1 + 48)
            break;

        //每次都询问是否保存
    }

    //判断用户是继续玩以前玩过的关卡，还是直接退出
    printf("游戏结束,退出!\n");

  //  exit(EXIT_FAILURE);

}


/*参数跟着传进来的是大怪小怪的顺序表指针*/
static void Walk_Walk(SUserAllInfoInGame * pRole ,
	                      U8                   key,
	                      U32                  currentMap,
	                      SMonsterInfo*        pSmallMonster,
                          SMonsterInfo*        pBossMonster)//进入第几关
{

	SMonsterInfo*		  monsterPtr    = NULL;//定义的小怪


	/* 1.进入关卡，显示地图*/


	/*记录旧位置*/
	pRole->pPos->pOldPos = pRole->pPos->pNewPos;

	/*2.开始行走，这个由键盘控制*/
	/* 碰见空格则走，不然则进行处理*/

	switch(key)
	{
        case 'e': //换装备
           Walk_ChooseEquiment(pRole);
            //一次行走结束
            break;
        case 'm':
            //调用药水选择模块
           Walk_ChooseMedicine(pRole);
            //一次行走结束
            break;

        case 'q':
            //选择关卡
            break;
		case 'w':
    		if(NextJudge(UpJudge(pRole->pPos->pNewPos)) == SPACE)
    		{
    			//up
    			// 按照概率来产生小妖
    			if(FindLittleMonsterAndFight(pRole,pSmallMonster,pBossMonster) == FALSE)
    			{
    			    pRole->pPos->pNewPos->y  -= 1;  //下标的变换

    				//位置变换
    				mapArray_1[pRole->pPos->pNewPos->y][pRole->pPos->pNewPos->x]   = 1;
    				mapArray_1[pRole->pPos->pOldPos->y + 1][pRole->pPos->pOldPos->x]   = 0;
    			}
    		}
    		else
    		if(NextJudge(UpJudge(pRole->pPos->pNewPos)) == WALL ||
              NextJudge(UpJudge(pRole->pPos->pNewPos)) == BARRIER)
    		{
    			printf("不能行走!\n");
    		}
    		else
    		{
				printf("Fight with boss!\n");
				monsterPtr= Init_RoleOfEnemy(pSmallMonster,pBossMonster,pRole,MONSTER_IS_BOSS);
    			//和boss战斗模块,这个时候是碰见boss了
    		}
    		break;

		case 's':  //down
		    printf("ff%d\n",NextJudge(DownJudge(pRole->pPos->pNewPos)));


    		if(NextJudge(DownJudge(pRole->pPos->pNewPos)) == SPACE)
    		{
    			if(FindLittleMonsterAndFight(pRole,pSmallMonster,pBossMonster) == FALSE)
    			{
    			    pRole->pPos->pNewPos->y += 1;

    			//位置变换
    			mapArray_1[pRole->pPos->pNewPos->y][pRole->pPos->pNewPos->x]   = 1;
             //   printf("mapArray_1[%d][%d] = %d\n",pRole->pPos->pNewPos->y,pRole->pPos->pNewPos->x,mapArray_1[pRole->pPos->pNewPos->y][pRole->pPos->pNewPos->x]);

    			mapArray_1[pRole->pPos->pOldPos->y - 1][pRole->pPos->pOldPos->x]   = 0;
             //   printf("mapArray_1[%d][%d] = %d\n",pRole->pPos->pOldPos->y,pRole->pPos->pOldPos->x,mapArray_1[pRole->pPos->pOldPos->y][pRole->pPos->pOldPos->x]);


    			}
    		}
    		else
    		if(NextJudge(DownJudge(pRole->pPos->pNewPos)) == WALL ||
              NextJudge(DownJudge(pRole->pPos->pNewPos)) == BARRIER)
    		{
    			printf("不能行走!\n");
    		}
    		else
    		{
				printf("Fight with boss!\n");
				monsterPtr= Init_RoleOfEnemy(pSmallMonster,pBossMonster,pRole,MONSTER_IS_BOSS);
    			//和boss战斗模块
    		}
    		break;

		case 'a': //left
    		if(NextJudge(LeftJudge(pRole->pPos->pNewPos)) == SPACE)
    		{
    			if(FindLittleMonsterAndFight(pRole,pSmallMonster,pBossMonster) == FALSE)
    			{
    			    pRole->pPos->pNewPos->x -= 1;

    			//位置变换
    			mapArray_1[pRole->pPos->pNewPos->y][pRole->pPos->pNewPos->x]   = 1;
    			mapArray_1[pRole->pPos->pOldPos->y][pRole->pPos->pOldPos->x + 1]   = 0;

    			}
    		}
    		else
    		if(NextJudge(LeftJudge(pRole->pPos->pNewPos)) == WALL ||
              NextJudge(LeftJudge(pRole->pPos->pNewPos)) == BARRIER)
    		{
    			printf("不能行走!\n");
    		}
    		else
    		{
				printf("Fight with boss!\n");
				monsterPtr= Init_RoleOfEnemy(pSmallMonster,pBossMonster,pRole,MONSTER_IS_BOSS);
    			//和boss战斗模块
    		}
    		break;

		case 'd': //right
    		if(NextJudge(RightJudge(pRole->pPos->pNewPos)) == SPACE)
    		{
    			if(FindLittleMonsterAndFight(pRole,pSmallMonster,pBossMonster)== FALSE)
    			{
    			    pRole->pPos->pNewPos->x += 1;

    			//位置变换
    			mapArray_1[pRole->pPos->pNewPos->y][pRole->pPos->pNewPos->x]   = 1;
    			mapArray_1[pRole->pPos->pOldPos->y][pRole->pPos->pOldPos->x - 1]   = 0;

    			}
    		}
    		else
    		if(NextJudge(RightJudge(pRole->pPos->pNewPos) )== WALL ||
              NextJudge(RightJudge(pRole->pPos->pNewPos)) == BARRIER)
    		{
    			printf("不能行走!\n");
    		}
    		else
    		{
				printf("Fight with boss!\n");
				//产生大boss
			    monsterPtr= Init_RoleOfEnemy(pSmallMonster,pBossMonster,pRole,MONSTER_IS_BOSS);
				Battle_Combat(pRole,monsterPtr,MONSTER_IS_BOSS);
    			//和boss战斗模块
    		}

    		break;

        case '1':
            //按下按键1，则存盘
          //  File_Write(&role); 调用文件操作
            break;
        case '2':
            Walk_DisplayAttriOfRole(pRole); // 按下'q',查看人物属性
            sleep(4);
            break;
		default:
		    break;
	}



}

/*judge next step*/
/*************************************************************
*name: NextJudge
*para: a pointer to postion including x and y
*function: what the role will meet when he want to have a step?
*return: int
****************************************************************/

static  int NextJudge(U32 flagOfMap) //下一个数组元素，是什么，传进来
{
	if (flagOfMap == 0)
		return SPACE;

	if(flagOfMap == 2)
		return BARRIER;

	if(flagOfMap == 3)
		return WALL;

	if(flagOfMap == 4)
	{
		return BIG_MONSTER;
	}
}

 static int UpJudge(SPosition * const oldPosPtr)//旧位置的上一个位置，注意二维数组的下标引用和坐标是转置的
{
    assert(oldPosPtr);
	return mapArray_1[oldPosPtr->y - 1][oldPosPtr->x];

}

 static int DownJudge(SPosition * const oldPosPtr)//旧位置的下一个位置
{

    assert(oldPosPtr);
	return mapArray_1[oldPosPtr->y + 1][oldPosPtr->x];
}

static int LeftJudge(SPosition * const oldPosPtr) // 旧位置的左一个位置
{

    assert(oldPosPtr);
	return mapArray_1[oldPosPtr->y][oldPosPtr->x - 1];
}

static  int RightJudge(SPosition * const oldPosPtr) // 旧位置的右一个位置
{

    assert(oldPosPtr);
	return mapArray_1[oldPosPtr->y][oldPosPtr->x + 1];
}

/******************************************************************
* 按概率产生小妖怪并且判断是否是小妖怪，若是，则战斗，需要调用小妖的实体,概率设为20%
*参数:玩家
*返回值:若产生了，则返回TRUE,否则返回FALSE
*******************************************************************/
static  int FindLittleMonsterAndFight(SUserAllInfoInGame * pRole,
	                                      SMonsterInfo*         pSmallMonster,
                                          SMonsterInfo*         pBossMonster )
{
	SMonsterInfo*		  monsterPtr = NULL;
    assert(NULL != pRole);

	U8 randNum; //随机数
	U8 i ;
	srand(time(NULL)); //设置随机数产生种子

	randNum = rand()%NUM_RAND_1; //产生 0 - 9 的随机数,20%的概率
	if(randNum > MIN_OF_RAND_1 && randNum < MAX_OF_RAND_1) //随机数是7或者8产生小怪
	{
      printf("generate a monster!\n");
		/*
			1.产生小怪 --初始化模块
			2.和小怪战斗 -- 战斗模块
            3.拾取装备模块调用

		*/
		monsterPtr = Init_RoleOfEnemy(pSmallMonster,pBossMonster,pRole,MONSTER_IS_NOT_BOSS);
		int resultOfBattle;
		resultOfBattle = Battle_Combat(pRole,monsterPtr,MONSTER_IS_NOT_BOSS);
	//	printf("%d\n",monsterPtr->HP);
		 //Walk_PickUp(pRole);
		if(resultOfBattle == 1)
		{
			Walk_PickUp(pRole,monsterPtr);
		}


		return TRUE;  // 产生了小怪则返回1
	}

	return FALSE;    //这一步没有产生小怪

}

/*显示人物角色当前的各个属性值 */
static void Walk_DisplayAttriOfRole(SUserAllInfoInGame * pRole)
{

    printf("用户信息:\n");
    printf("用户ID :%s\n",pRole->userID);
    printf("用户角色: ");

    if(pRole->profession == EResultOfProfession_SwordMan)
    {
        printf("SwordMan\n");
    }
    else
    {
        printf("MagicMan\n");
    }

    printf("等级: %d\n",pRole->level);
    printf("目前以及通关关卡: %d\n",pRole->currentMap);
    printf("经验值:%d\n",pRole->exp);
    printf("生命值:%d\n",pRole->HP);
    printf("魔法值:%d\n",pRole->MP);
    printf("攻击力:%d\n",pRole->attack);
    printf("防御力:%d\n",pRole->defend);

    printf("力量:%d\n",pRole->strength);
    printf("敏捷:%d\n",pRole->dex);
    printf("智力:%d\n",pRole->intelligence);

//装备
//武器
	printf("玩家当前装备:\n");

    if(pRole->pCurrentWearEuip->weaponLevel != 0)
    {
		printf("武器:\n");
        printf("武器名称:%s\n",pRole->pCurrentWearEuip->weaponName);
        printf("武器总类:%d\n",pRole->pCurrentWearEuip->weaponKind);
        printf("武器等级:%d\n",pRole->pCurrentWearEuip->weaponLevel);
    }
	else
	{
		printf("没有可用武器!\n");
	}
//鞋子
    if(pRole->pCurrentWearEuip->shoeLevel != 0)
    {
		printf("鞋子:\n");
        printf("鞋子名称:%s\n",pRole->pCurrentWearEuip->shoeName);
        printf("鞋子等级:%d\n",pRole->pCurrentWearEuip->shoeLevel);
    }
	else
	{
		printf("没有可用鞋子!\n");
	}
//衣服
    if(pRole->pCurrentWearEuip->clothLevel != 0)
    {
		printf("衣服:\n");
        printf("衣服名称:%s\n",pRole->pCurrentWearEuip->clothName);
        printf("衣服总类:%d\n",pRole->pCurrentWearEuip->clothLevel);
    }
	else
	{
		printf("没有可用衣服!\n");

	}

//技能
    if(NULL != pRole->pSkillKind)
    {
		printf("技能:\n");
        if(NULL != pRole->pSkillKind->pSkillKind_1)
        {
            printf("技能1名称:%d\n",pRole->pSkillKind->pSkillKind_1->SkillName);
            printf("技能1等级:%d\n",pRole->pSkillKind->pSkillKind_1->skillLevel);

        }

        if(NULL != pRole->pSkillKind->pSkillKind_2)
        {
            printf("技能2名称:%d\n",pRole->pSkillKind->pSkillKind_2->SkillName);
            printf("技能2等级:%d\n",pRole->pSkillKind->pSkillKind_2->skillLevel);

        }

        if(NULL != pRole->pSkillKind->pSkillKind_3)
        {
            printf("技能3名称:%d\n",pRole->pSkillKind->pSkillKind_3->SkillName);
            printf("技能3等级:%d\n",pRole->pSkillKind->pSkillKind_3->skillLevel);

        }

    }
	else
	{
		printf("没有可用技能!\n");
	}

    //口袋
    if(NULL != pRole->pPocket) //口袋非空
    {
        //金钱
        printf("金钱:%d\n",pRole->pPocket->money);

        //口袋装备非空
        if(NULL != pRole->pPocket->pEquip)
        {
            int i = 0; //用做循环
            //武器
            if(NULL != pRole->pPocket->pEquip->pWeapon)
            {
                SWeapon * tempWeaponPtr;
                tempWeaponPtr = pRole->pPocket->pEquip->pWeapon;

                printf("武器:\n");
				printf("count = %d\n",pRole->pPocket->pEquip->weaponCurrentCount);
                for(i = 0; i < pRole->pPocket->pEquip->weaponCurrentCount; i++ )
                {

                    printf("武器名称:%s\n",tempWeaponPtr->weaponName);
                    printf("武器等级:%d\n",tempWeaponPtr->weaponLevel);
                    printf("武器种类:%d\n",tempWeaponPtr->weaponKind);

                    tempWeaponPtr = tempWeaponPtr->next;
                }
            }
			else
			{
				printf("口袋没有武器装备!\n");
			}

           //鞋子
           if(NULL != pRole->pPocket->pEquip->pShoe)
           {
                SShoe * tempShoePtr;
                tempShoePtr = pRole->pPocket->pEquip->pShoe;

                printf("鞋子:\n");

                for(i = 0; i < pRole->pPocket->pEquip->shootCurrentCount; i++)
                {
                    printf("鞋子名称:%s\n",tempShoePtr->shootName);
                    printf("鞋子等级:%d\n",tempShoePtr->shootLevel);

                    tempShoePtr = tempShoePtr->next;
                }

           }
		   else
		   {
				printf("口袋没有可用鞋子!\n");
		   }

           //衣服
           if(NULL != pRole->pPocket->pEquip->pCloth)
           {
                SCloth * tempClothPtr;
                tempClothPtr = pRole->pPocket->pEquip->pCloth;

                printf("衣服:\n");

                for(i = 0; i < pRole->pPocket->pEquip->clothCurrentCount; i++)
                {
                    printf("衣服名称:%s\n",tempClothPtr->clothName);
                    printf("衣服等级:%d\n",tempClothPtr->clothLevel);

                    tempClothPtr = tempClothPtr->next;
                }
           }
		   else
		   {
				printf("口袋没有可用衣服!\n");
		   }

        }
        //药水
        if(NULL != pRole->pPocket->pMedicine)
        {
            printf("药水:\n");
            printf("红药水:\n");
            printf("初级红药:%d\n",pRole->pPocket->pMedicine->lowRedMedicine);
            printf("中级红药:%d\n",pRole->pPocket->pMedicine->midRedMedicine);
            printf("高级红药:%d\n",pRole->pPocket->pMedicine->superRedMedicine);


            printf("蓝药:\n");
            printf("初级蓝药:%d\n",pRole->pPocket->pMedicine->lowBlueMedicine);
            printf("中级蓝药:%d\n",pRole->pPocket->pMedicine->midBlueMedicine);
            printf("高级蓝药:%d\n",pRole->pPocket->pMedicine->superBlueMedicine);
        }
		else
		{
			printf("口袋没有可用药水!\n");
		}

    }
	else
	{
		printf("口袋为空!\n");
	}


}

