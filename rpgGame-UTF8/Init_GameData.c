#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <time.h>

#include "Init_GameData.h"




static void InitAllGameMap()
{
}


static void InitAllGameSmallMonster(SMonsterInfo* pSmallMonster,
                                              SMonsterPocket* pMonsterPocketLibray,
                                              SMonsterPocketEquip * pMonsterPocketEquipLibrary)

{

    assert(NULL != pSmallMonster);

    assert(NULL != pMonsterPocketLibray);

    assert(NULL != pMonsterPocketEquipLibrary);
    U32 i = 0;
    U32 tempRandNum = 0;

    srand((U32)time(NULL));//产生随机数种子

    for(i=0;i<NUMBER_OF_SMALL_MONSTER;i++)
    {


        tempRandNum = rand()%100;

        if(i<10)
        {
            pSmallMonster[i].HP     = MONSTER_HP_INIT+(i/10)*MONSTER_HP_INCREMENT;

            pSmallMonster[i].attack = MONSTER_ATTACK_INIT+(i/10)*MONSTER_ATTACK_INCREMENT;

            pSmallMonster[i].defend = MONSTER_DEFEND_INIT+(i/10)*MONSTER_DEFEND_INCREMENT;

            pSmallMonster[i].dex    = MONSTER_DEX_INIT+(i/10)*MONSTER_DEX_INCREMENT;

            strcpy(pSmallMonster[i].monsterName,"初级小怪");

            pSmallMonster[i].level  = (i/10)+1;

            pSmallMonster[i].pMonsterPocket = (pMonsterPocketLibray+i);

            if( !pSmallMonster[i].pMonsterPocket)
            {
                printf("pSmallMonster[%d].pMonsterPocket don't allocate!!\n",i);
                exit(-1);
            }

             pSmallMonster[i].pMonsterPocket->exp    = MONSTER_EXP_INIT*(i/10+1);

             pSmallMonster[i].pMonsterPocket->money  = MONSTER_MONEY_INIT*(i/10+1);

             pSmallMonster[i].pMonsterPocket->pMonsterEquip =(pMonsterPocketEquipLibrary+i);


              if( !pSmallMonster[i].pMonsterPocket->pMonsterEquip)
            {
                printf("pSmallMonster[%d].pMonsterPocke->pMonsterEquipt don't allocate!!\n",i);
                exit(-1);
            }


            if( tempRandNum>0 && tempRandNum<10 )//百分之十 掉武器
            {

                if(tempRandNum <= 5)//其中百分之5是sword
                {
                    pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponKind \
                    = SWORD_OF_EQUIP;

                    strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponName,"低级宝剑");

                    pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel \
                    = LOW_WEAPON;
                }
                else //其他百分之5是魔法杖
                {
                     pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponKind \
                    = BAR_OF_MAGIC;

                    strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponName,"低级法杖");

                    pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel \
                    = LOW_WEAPON;
                }

                 /* 因为一个小怪只能掉一个装备，等级等于0口袋中没有装备 */
                 pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel = 0;
                 pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel = 0;

            }
            else if( tempRandNum>10 && tempRandNum<20 )//百分之十 掉衣服
            {
                strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothName,"低级铠甲");

                pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel = \
                LOW_CLOTH;

                 /* 因为一个小怪只能掉一个装备，等级等于0口袋中没有装备 */
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel = 0;

            }
            else if( tempRandNum>30 && tempRandNum<40 )//百分之十 掉鞋子
            {
                strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootName,"低级鞋子");

                pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel= \
                LOW_SHOE;

                 /* 因为一个小怪只能掉一个装备，等级等于0口袋中没有装备 */
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel= 0;
            }
            else //什么装备都不掉
            {
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel  = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel  = 0;
            }

        }
        else if(i>10 && i<30)
        {

            pSmallMonster[i].HP     = MONSTER_HP_INIT+(i/10)*MONSTER_HP_INCREMENT;

            pSmallMonster[i].attack = MONSTER_ATTACK_INIT+(i/10)*MONSTER_ATTACK_INCREMENT;

            pSmallMonster[i].defend = MONSTER_DEFEND_INIT+(i/10)*MONSTER_DEFEND_INCREMENT;

            pSmallMonster[i].dex    = MONSTER_DEX_INIT+(i/10)*MONSTER_DEX_INCREMENT;

            strcpy(pSmallMonster[i].monsterName,"中级小怪");

            pSmallMonster[i].level  = (i/10)+1;

            pSmallMonster[i].pMonsterPocket = (pMonsterPocketLibray+i);

            if( !pSmallMonster[i].pMonsterPocket)
            {
                 printf("pSmallMonster[%d].pMonsterPocket don't allocate!!\n",i);
                 exit(-1);
            }

            pSmallMonster[i].pMonsterPocket->exp    = MONSTER_EXP_INIT*(i/10+1);

            pSmallMonster[i].pMonsterPocket->money  = MONSTER_MONEY_INIT*(i/10+1);

            pSmallMonster[i].pMonsterPocket->pMonsterEquip = (pMonsterPocketEquipLibrary+i);

            if( !pSmallMonster[i].pMonsterPocket->pMonsterEquip)
            {
                 printf("pSmallMonster[%d].pMonsterPocke->pMonsterEquipt don't allocate!!\n",i);
                 exit(-1);
            }



            if( tempRandNum>0 && tempRandNum<10 )//百分之十 掉武器
            {

                if(tempRandNum <= 5)//其中百分之5是sword
                {
                    pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponKind \
                    = SWORD_OF_EQUIP;

                    strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponName,"中级宝剑");

                    pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel \
                    = MID_WEAPON;
                }
                else //其他百分之5是魔法杖
                {
                     pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponKind \
                    = BAR_OF_MAGIC;

                    strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponName,"中级法杖");

                    pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel \
                    = MID_WEAPON;
                }

                 /* 因为一个小怪只能掉一个装备，等级等于0口袋中没有装备 */
                 pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel = 0;
                 pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel = 0;

            }
            else if( tempRandNum>10 && tempRandNum<20 )//百分之十 掉衣服
            {
                strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothName,"中级铠甲");

                pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel = \
                MID_CLOTH;

                 /* 因为一个小怪只能掉一个装备，等级等于0口袋中没有装备 */
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel = 0;

            }
            else if( tempRandNum>30 && tempRandNum<40 )//百分之十 掉衣服
            {
                strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootName,"中级鞋子");

                pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel= \
                MID_SHOE;

                 /* 因为一个小怪只能掉一个装备，等级等于0口袋中没有装备 */
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel= 0;
            }
            else //什么装备都不掉
            {
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel  = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel  = 0;
            }

        }
        else
        {
            pSmallMonster[i].HP     = MONSTER_HP_INIT+(i/10)*MONSTER_HP_INCREMENT;

            pSmallMonster[i].attack = MONSTER_ATTACK_INIT+(i/10)*MONSTER_ATTACK_INCREMENT;

            pSmallMonster[i].defend = MONSTER_DEFEND_INIT+(i/10)*MONSTER_DEFEND_INCREMENT;

            pSmallMonster[i].dex    = MONSTER_DEX_INIT+(i/10)*MONSTER_DEX_INCREMENT;

            strcpy(pSmallMonster[i].monsterName,"高级小怪");

            pSmallMonster[i].level  = (i/10)+1;

            pSmallMonster[i].pMonsterPocket = (pMonsterPocketLibray+i);;

            if( !pSmallMonster[i].pMonsterPocket)
            {
                 printf("pSmallMonster[%d].pMonsterPocket don't allocate!!\n",i);
                 exit(-1);
            }

            pSmallMonster[i].pMonsterPocket->exp    = MONSTER_EXP_INIT*(i/10+1);

            pSmallMonster[i].pMonsterPocket->money  = MONSTER_MONEY_INIT*(i/10+1);

            pSmallMonster[i].pMonsterPocket->pMonsterEquip = (pMonsterPocketEquipLibrary+i);;

            if( !pSmallMonster[i].pMonsterPocket->pMonsterEquip)
            {
                 printf("pSmallMonster[%d].pMonsterPocke->pMonsterEquipt don't allocate!!\n",i);
                 exit(-1);
            }



            if( tempRandNum>0 && tempRandNum<10 )//百分之十 掉武器
            {

                if(tempRandNum <= 5)//其中百分之5是sword
                {
                    pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponKind \
                    = SWORD_OF_EQUIP;

                    strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponName,"中级宝剑");

                    pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel \
                    = MID_WEAPON;
                }
                else //其他百分之5是魔法杖
                {
                     pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponKind \
                    = BAR_OF_MAGIC;

                    strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponName,"中级法杖");

                    pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel \
                    = MID_WEAPON;
                }

                 /* 因为一个小怪只能掉一个装备，等级等于0口袋中没有装备 */
                 pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel = 0;
                 pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel = 0;

            }
            else if( tempRandNum>10 && tempRandNum<20 )//百分之十 掉衣服
            {
                strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothName,"中级铠甲");

                pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel = \
                MID_CLOTH;

                 /* 因为一个小怪只能掉一个装备，等级等于0口袋中没有装备 */
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel = 0;

            }
            else if( tempRandNum>30 && tempRandNum<40 )//百分之十 掉衣服
            {
                strcpy(pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootName,"中级鞋子");

                pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel= \
                MID_SHOE;

                 /* 因为一个小怪只能掉一个装备，等级等于0口袋中没有装备 */
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel= 0;
            }
            else //什么装备都不掉
            {
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->weaponLevel = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->clothLevel  = 0;
                pSmallMonster[i].pMonsterPocket->pMonsterEquip->shootLevel  = 0;
            }
        }

    }

}

static void InitAllGameBoss(SMonsterInfo*       pBossMonster,
                                  SMonsterPocket* pMonsterPocketLibray,
                                  SMonsterPocketEquip * pMonsterPocketEquipLibrary)
{
    assert(NULL != pBossMonster);

    assert(NULL != pMonsterPocketLibray);

    assert(NULL != pMonsterPocketEquipLibrary);


    U32 i = 0;

    for(i=0;i<NUMBER_OF_BOSS;i++)
    {
        pBossMonster[i].HP     = BOSS_HP_INIT + i*BOSS_HP_INCREMENT;

        pBossMonster[i].attack = BOSS_ATTACK_INIT + i*BOSS_ATTACK_INCREMENT;

        pBossMonster[i].defend = BOSS_DEFEND_INIT + i*BOSS_DEFEND_INCREMENT;

        pBossMonster[i].dex    = BOSS_DEX_INIT + i*BOSS_DEX_INCREMENT;

        pBossMonster[i].level  = (i+1)*15+1;

        pBossMonster[i].pMonsterPocket = pMonsterPocketLibray+NUMBER_OF_SMALL_MONSTER+i;

        if( !pBossMonster[i].pMonsterPocket)
        {
            printf("pBossMonster[i].pMonsterPocket don't allocate!!\n",i);
            exit(-1);
        }

        memset(pBossMonster[i].pMonsterPocket,'0',sizeof(SMonsterPocket));

        pBossMonster[i].pMonsterPocket->exp   = BOSS_EXP_INIT *(i+1);

        pBossMonster[i].pMonsterPocket->money = BOSS_MONEY_INIT*(i+1);

        pBossMonster[i].pMonsterPocket->pMonsterEquip = pMonsterPocketEquipLibrary+NUMBER_OF_SMALL_MONSTER+i;

        if( ! pBossMonster[i].pMonsterPocket->pMonsterEquip)
        {
            printf(" pBossMonster[i].pMonsterPocket->pMonsterEquip don't allocate!!\n",i);
            exit(-1);
        }

        memset(pBossMonster[i].pMonsterPocket->pMonsterEquip,'0',sizeof(SMonsterPocketEquip));

    }

/***********************第一关BOSS所掉装备 ***********************************/

    pBossMonster[0].pMonsterPocket->pMonsterEquip->clothLevel = MID_CLOTH;
    strcpy(pBossMonster[0].pMonsterPocket->pMonsterEquip->clothName,"中级铠甲");


/***********************第二关BOSS所掉装备 ***********************************/

    pBossMonster[1].pMonsterPocket->pMonsterEquip->weaponKind = BAR_OF_MAGIC;

    pBossMonster[1].pMonsterPocket->pMonsterEquip->weaponLevel = HIGH_WEAPON;

    strcpy(pBossMonster[1].pMonsterPocket->pMonsterEquip->weaponName,"高级法杖");

/***********************第三关BOSS所掉装备 ***********************************/

    pBossMonster[2].pMonsterPocket->pMonsterEquip->weaponKind = SWORD_OF_EQUIP;

    pBossMonster[2].pMonsterPocket->pMonsterEquip->weaponLevel = HIGH_WEAPON;

    strcpy(pBossMonster[2].pMonsterPocket->pMonsterEquip->weaponName,"高级宝剑");


    pBossMonster[2].pMonsterPocket->pMonsterEquip->clothLevel = HIGH_CLOTH;
    strcpy(pBossMonster[2].pMonsterPocket->pMonsterEquip->clothName,"高级铠甲");

/***********************第四关BOSS所掉装备 ***********************************/

    pBossMonster[3].pMonsterPocket->pMonsterEquip->weaponKind = BAR_OF_MAGIC;

    pBossMonster[3].pMonsterPocket->pMonsterEquip->weaponLevel = SUPER_WEAPON;

    strcpy(pBossMonster[3].pMonsterPocket->pMonsterEquip->weaponName,"极品法杖");


    pBossMonster[3].pMonsterPocket->pMonsterEquip->shootLevel = HIGH_SHOE;
    strcpy(pBossMonster[3].pMonsterPocket->pMonsterEquip->shootName,"高级鞋子");

/***********************第五关BOSS所掉装备 ***********************************/
    pBossMonster[4].pMonsterPocket->pMonsterEquip->weaponKind = SWORD_OF_EQUIP;

    pBossMonster[4].pMonsterPocket->pMonsterEquip->weaponLevel = SUPER_WEAPON;

    strcpy(pBossMonster[4].pMonsterPocket->pMonsterEquip->weaponName,"极品宝剑");

    pBossMonster[4].pMonsterPocket->pMonsterEquip->clothLevel = SUPER_CLOTH;
    strcpy(pBossMonster[4].pMonsterPocket->pMonsterEquip->clothName,"极品铠甲");




}

static void InitGameUserInfo(SUserAllInfoInGame* pUserInfo,EProfession profession,
                                    U8* userID,
                                    U8* userPassword)
{
    assert(NULL != pUserInfo);
    if(profession == EResultOfProfession_SwordMan)//战士属性赋值
    {
        pUserInfo->HP = 500;

        pUserInfo->MP = 200;

        pUserInfo->attack   = 100;

        pUserInfo->strength = 20;

        pUserInfo->dex = 10;

        pUserInfo->defend = 10;

        pUserInfo->intelligence = 10;

        pUserInfo->currentMap = MAP_1;

        pUserInfo->exp = 0;

        pUserInfo->level = 1;

        pUserInfo->profession = EResultOfProfession_SwordMan;

        strcpy(pUserInfo->userID,userID);

        strcpy(pUserInfo->password,userPassword);


/************************************************************************************/

        pUserInfo->pPos = (SRolePositon*)malloc(sizeof(SRolePositon));

        pUserInfo->pPos->pNewPos = (SPosition*)malloc(sizeof(SPosition));

        pUserInfo->pPos->pOldPos = (SPosition*)malloc(sizeof(SPosition));

        if(!pUserInfo->pPos || !pUserInfo->pPos->pNewPos || !pUserInfo->pPos->pOldPos)
        {
            printf("position pointer don't allocate memory!!!\n");
            exit(-1);
        }

        pUserInfo->pPos->pOldPos->x = 1;
        pUserInfo->pPos->pOldPos->y = 1;

        pUserInfo->pPos->pNewPos->x = 1;
        pUserInfo->pPos->pNewPos->y = 1;

/************************************************************************************/

        pUserInfo->pCurrentWearEuip = \
        (SCurrentWearEquip*)malloc(sizeof(SCurrentWearEquip));

        if(!pUserInfo->pCurrentWearEuip)
        {
            printf("pUserInfo->pCurrentWearEuip  don't allocate memory!!!\n");
            exit(-1);
        }

        memset(pUserInfo->pCurrentWearEuip,'0',sizeof(SCurrentWearEquip));

        pUserInfo->pCurrentWearEuip->clothLevel  = 0;

        pUserInfo->pCurrentWearEuip->shoeLevel   = 0;

        pUserInfo->pCurrentWearEuip->weaponLevel = 0;

/************************************************************************************/

        pUserInfo->pPocket = (SUserPocket*)malloc(sizeof(SUserPocket));


        if(!pUserInfo->pPocket)
       {
           printf("pUserInfo->pPocket  don't allocate memory!!!\n");
           exit(-1);
       }

        memset(pUserInfo->pPocket,0,sizeof(SUserPocket));

        pUserInfo->pPocket->money = 200;

/************************************************************************************/
        pUserInfo->pPocket->pMedicine = (SMedicine*)malloc(sizeof(SMedicine));


        if(!(pUserInfo->pPocket->pMedicine))
        {
          printf("pUserInfo->pPocket->pMedicine  don't allocate memory!!!\n");
          exit(-1);
        }

        memset(pUserInfo->pPocket->pMedicine,0,sizeof(SMedicine));

        pUserInfo->pPocket->pMedicine->lowRedMedicine  = 3;

        pUserInfo->pPocket->pMedicine->lowBlueMedicine = 3;

/************************************************************************************/

        pUserInfo->pPocket->pEquip = (SEquipment*)malloc(sizeof(SEquipment));

        memset(pUserInfo->pPocket->pEquip,0,sizeof(SEquipment));


/************************************************************************************/

        pUserInfo->pSkillKind = (SSkills*)malloc(sizeof(SSkills));

        pUserInfo->pSkillKind->pSkillKind_1 = (SSkilLevel*)malloc(sizeof(SSkilLevel));

        pUserInfo->pSkillKind->pSkillKind_2 = (SSkilLevel*)malloc(sizeof(SSkilLevel));

        pUserInfo->pSkillKind->pSkillKind_3 = (SSkilLevel*)malloc(sizeof(SSkilLevel));

         if(!pUserInfo->pSkillKind || !pUserInfo->pSkillKind->pSkillKind_1 || \
           !pUserInfo->pSkillKind->pSkillKind_2 ||  !pUserInfo->pSkillKind->pSkillKind_3)
        {
          printf("pUserInfo->pPocket->pMedicine  don't allocate memory!!!\n");
          exit(-1);
        }


        pUserInfo->pSkillKind->pSkillKind_1->SkillName = FIGHTER_SKILL_DEFEND_ATTACK;

        pUserInfo->pSkillKind->pSkillKind_1->skillLevel = 0;


        pUserInfo->pSkillKind->pSkillKind_2->SkillName = FIGHTER_SKILL_DEAD_ATTACK;

        pUserInfo->pSkillKind->pSkillKind_2->skillLevel = 0;


        pUserInfo->pSkillKind->pSkillKind_3->SkillName  = 0;
        pUserInfo->pSkillKind->pSkillKind_3->skillLevel = 0;

    }
    else
    {
        pUserInfo->HP = 400;

        pUserInfo->MP = 600;

        pUserInfo->attack   = 80;

        pUserInfo->strength = 10;

        pUserInfo->dex = 5;

        pUserInfo->defend = 10;

        pUserInfo->intelligence = 5;

        pUserInfo->currentMap = MAP_1;

        pUserInfo->exp = 0;

        pUserInfo->level = 1;

        pUserInfo->profession = EResultOfProfession_MagicMan;

        strcpy(pUserInfo->userID,userID);

        strcpy(pUserInfo->password,userPassword);
/************************************************************************************/

        pUserInfo->pPos = (SRolePositon*)malloc(sizeof(SRolePositon));

        pUserInfo->pPos->pNewPos = (SPosition*)malloc(sizeof(SPosition));

        pUserInfo->pPos->pOldPos = (SPosition*)malloc(sizeof(SPosition));

        if(!pUserInfo->pPos || !pUserInfo->pPos->pNewPos || !pUserInfo->pPos->pOldPos)
        {
            printf("position pointer don't allocate memory!!!\n");
            exit(-1);
        }

        pUserInfo->pPos->pOldPos->x = 1;
        pUserInfo->pPos->pOldPos->y = 1;

        pUserInfo->pPos->pNewPos->x = 1;
        pUserInfo->pPos->pNewPos->y = 1;

/************************************************************************************/

        pUserInfo->pCurrentWearEuip = \
        (SCurrentWearEquip*)malloc(sizeof(SCurrentWearEquip));

        if(!pUserInfo->pCurrentWearEuip)
        {
            printf("pUserInfo->pCurrentWearEuip  don't allocate memory!!!\n");
            exit(-1);
        }

        memset(pUserInfo->pCurrentWearEuip,'0',sizeof(SCurrentWearEquip));

        pUserInfo->pCurrentWearEuip->clothLevel  = 0;

        pUserInfo->pCurrentWearEuip->shoeLevel   = 0;

        pUserInfo->pCurrentWearEuip->weaponLevel = 0;

/************************************************************************************/

        pUserInfo->pPocket = (SUserPocket*)malloc(sizeof(SUserPocket));


        if(!pUserInfo->pPocket)
       {
           printf("pUserInfo->pPocket  don't allocate memory!!!\n");
           exit(-1);
       }

        memset(pUserInfo->pPocket,0,sizeof(SUserPocket));

        pUserInfo->pPocket->money = 200;

/************************************************************************************/
        pUserInfo->pPocket->pMedicine = (SMedicine*)malloc(sizeof(SMedicine));


        if(!(pUserInfo->pPocket->pMedicine))
        {
          printf("pUserInfo->pPocket->pMedicine  don't allocate memory!!!\n");
          exit(-1);
        }

        memset(pUserInfo->pPocket->pMedicine,0,sizeof(SMedicine));

        pUserInfo->pPocket->pMedicine->lowRedMedicine  = 3;

        pUserInfo->pPocket->pMedicine->lowBlueMedicine = 3;

/************************************************************************************/

        pUserInfo->pPocket->pEquip = (SEquipment*)malloc(sizeof(SEquipment));

        memset(pUserInfo->pPocket->pEquip,0,sizeof(SEquipment));


/************************************************************************************/

        pUserInfo->pSkillKind = (SSkills*)malloc(sizeof(SSkills));

        pUserInfo->pSkillKind->pSkillKind_1 = (SSkilLevel*)malloc(sizeof(SSkilLevel));

        pUserInfo->pSkillKind->pSkillKind_2 = (SSkilLevel*)malloc(sizeof(SSkilLevel));

        pUserInfo->pSkillKind->pSkillKind_3 = (SSkilLevel*)malloc(sizeof(SSkilLevel));

         if(!pUserInfo->pSkillKind || !pUserInfo->pSkillKind->pSkillKind_1 || \
           !pUserInfo->pSkillKind->pSkillKind_2 || ! pUserInfo->pSkillKind->pSkillKind_3)
        {
          printf("pUserInfo->pPocket->pMedicine  don't allocate memory!!!\n");
          exit(-1);
        }

        pUserInfo->pSkillKind->pSkillKind_1->SkillName  = MAGIC_SKILL_SMALL_FIRE;

        pUserInfo->pSkillKind->pSkillKind_1->skillLevel = 1;


        pUserInfo->pSkillKind->pSkillKind_2->SkillName = MAGIC_SKILL_PROTECT;

        pUserInfo->pSkillKind->pSkillKind_2->skillLevel = 0;


        pUserInfo->pSkillKind->pSkillKind_3->SkillName  = MAGIC_SKILL_BIG_FIRE;
        pUserInfo->pSkillKind->pSkillKind_3->skillLevel = 0;

    }
}




SMonsterInfo* Init_RoleOfEnemy(SMonsterInfo* pSmallMonster,
                                      SMonsterInfo* pBossMonster,
                                      SUserAllInfoInGame* pUserInfo,
                                      U32 flags)

{

    assert(NULL != pSmallMonster);
    assert(NULL != pBossMonster);
    assert(NULL != pUserInfo);


    U32 i = 0;
    SMonsterInfo* returnPtr = NULL;

    srand((U32)time(NULL));//产生随机数种子

    if(flags == MONSTER_IS_NOT_BOSS)
    {
        i = rand()%10+(pUserInfo->currentMap-1)*10;
        returnPtr = pSmallMonster+i;

    }
    else
    {
        i = pUserInfo->currentMap-1;

        returnPtr = pBossMonster + i;
    }

    printf("i = %d\n",i);

    return returnPtr;

}

void RefreshBuff()
{
    FILE *fp;
    int ch;
    for(;;)
    {
        ch = getchar();
        if(ch == '\n' || ch == EOF)
        {
            break;
        }
    }
}

void InitAllGameData(SMonsterInfo*              pSmallMonster,
                           SMonsterInfo*        pBossMonster,
                           SUserAllInfoInGame*  pUserInfo,
                           SMonsterPocket*      pMonsterPocketLibray,
                           SMonsterPocketEquip* pMonsterPocketEquipLibrary,
                           EProfession profession,
                           U8* userID,
                           U8* userPassword)
{

    /* 1. 地图初始化 */
    InitAllGameMap();

    /* 2. 小怪库初始化 */
    InitAllGameSmallMonster(pSmallMonster,pMonsterPocketLibray,pMonsterPocketEquipLibrary);

    /* 3. Boss数组初始化 */
    InitAllGameBoss(pBossMonster,pMonsterPocketLibray,pMonsterPocketEquipLibrary);

    /* 4. 人物信息初始化 */
    InitGameUserInfo(pUserInfo,profession,userID,userPassword);

}



