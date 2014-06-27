#include <curses.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>

#include "Init_GameData.h"
#include "Show_AllDisplayFunc.h"




static void AllocateAllMemory(SMonsterInfo**               const SmallMonsterPtrPtr,
                                     SMonsterInfo**        const BossMonsterPtrPtr,
                                     SUserAllInfoInGame**  const pUserInfoPtrPtr,
                                     SMonsterPocket**      const monsterPocketLibrayPtrPtr,
                                     SMonsterPocketEquip** const monsterPocketEquipLibraryPtrPtr)
{

    assert(NULL != SmallMonsterPtrPtr);

    assert(NULL != BossMonsterPtrPtr);

    assert(NULL != pUserInfoPtrPtr);

    assert(NULL != monsterPocketLibrayPtrPtr);

    assert(NULL !=monsterPocketEquipLibraryPtrPtr);

    SMonsterInfo* tempPtrForBoss       = NULL;

    SMonsterInfo* tempPtrForMonster    = NULL;

    SUserAllInfoInGame* pUserInfo      = NULL;

    SMonsterPocket* tempPtrForMonsterPocket = NULL;

    SMonsterPocketEquip* tempPtrForMonsterPockerEquip = NULL;

    tempPtrForBoss =(SMonsterInfo*)malloc(sizeof(SMonsterInfo)*NUMBER_OF_BOSS);

    if(!tempPtrForBoss)
    {
        printf("tempPtrForBoss don't malloc !!!!\n");
        exit(-1);
    }
    memset(tempPtrForBoss,'0',sizeof(SMonsterInfo)*NUMBER_OF_BOSS);

    tempPtrForMonster = (SMonsterInfo*)malloc(sizeof(SMonsterInfo)*NUMBER_OF_SMALL_MONSTER);

    if(!tempPtrForMonster)
    {
        printf("tempPtrForMonster don't malloc !!!!\n");
        exit(-1);
    }
    memset(tempPtrForMonster,'0',sizeof(SMonsterInfo)*NUMBER_OF_SMALL_MONSTER);

     pUserInfo =(SUserAllInfoInGame*)malloc(sizeof(SUserAllInfoInGame));

    if(!tempPtrForBoss)
    {
        printf("pUserInfoPtrPtr don't malloc !!!!\n");
        exit(-1);
    }

    memset(pUserInfo,'0',sizeof(SUserAllInfoInGame));


    tempPtrForMonsterPocket =\
        (SMonsterPocket*)malloc(sizeof(SMonsterPocket)*(NUMBER_OF_BOSS+NUMBER_OF_SMALL_MONSTER));

     if(!tempPtrForMonsterPocket)
    {
        printf("tempPtrForMonsterPocket don't malloc !!!!\n");
        exit(-1);
    }
    memset(tempPtrForMonsterPocket,'0',sizeof(SMonsterPocket)*(NUMBER_OF_SMALL_MONSTER+NUMBER_OF_BOSS));


      tempPtrForMonsterPockerEquip =\
        (SMonsterPocketEquip*)malloc(sizeof(SMonsterPocketEquip)*(NUMBER_OF_BOSS+NUMBER_OF_SMALL_MONSTER));

     if(!tempPtrForMonsterPockerEquip)
    {
        printf("tempPtrForMonsterPockerEquip don't malloc !!!!\n");
        exit(-1);
    }
    memset(tempPtrForMonsterPockerEquip,'0',sizeof(SMonsterPocketEquip)*(NUMBER_OF_SMALL_MONSTER+NUMBER_OF_BOSS));


    *BossMonsterPtrPtr  = tempPtrForBoss;

    *SmallMonsterPtrPtr = tempPtrForMonster;

    *pUserInfoPtrPtr    = pUserInfo;

    *monsterPocketLibrayPtrPtr = tempPtrForMonsterPocket;

    *monsterPocketEquipLibraryPtrPtr = tempPtrForMonsterPockerEquip;

}



static void CreateEquipmentMemoryPool(SWeapon** const weaponListPtrPtr,
                                                 SCloth**  const clothListPtrPtr,
                                                 SShoe**   const shoeListPtrPtr
                                                 )
{

    assert(NULL != weaponListPtrPtr);

    assert(NULL != clothListPtrPtr);

    assert(NULL != shoeListPtrPtr);

    U32 i = 0;

    SWeapon* tempPtrForWeapon   = NULL;

    SCloth*  tempPtrForCloth    = NULL;

    SShoe*   tempPtrForShoe     = NULL;

    //口袋里面装备最多只能10个，所以乘以10 ，以下一样
    tempPtrForWeapon = (SWeapon*)malloc(sizeof(SWeapon)*10);

    tempPtrForCloth  = (SCloth*)malloc(sizeof(SCloth)*10);

    tempPtrForShoe   = (SShoe*)malloc(sizeof(SShoe)*10);

    if((!tempPtrForWeapon) || (!tempPtrForCloth) || (!tempPtrForCloth))
    {
        printf("equipment don't allocate!!!!\n");
        exit(-1);
    }

    //顺序表链式化，为了方便释放，-1是因为最后一个必须设为NULL
    for(i=0;i<(10-1);i++)
    {
        tempPtrForWeapon[i].next = tempPtrForWeapon+i+1;

        tempPtrForCloth[i].next  = tempPtrForCloth+i+1;

        tempPtrForShoe[i].next   = tempPtrForShoe+i+1;
    }

    tempPtrForWeapon[i].next = NULL;

    tempPtrForCloth[i].next  = NULL;

    tempPtrForShoe[i].next   = NULL;


    *weaponListPtrPtr = tempPtrForWeapon;

    *clothListPtrPtr  = tempPtrForCloth;

    *shoeListPtrPtr   = tempPtrForShoe;



}

static void FreeAllMemory(SMonsterInfo*             const SmallMonsterPtrPtr,
                               SMonsterInfo*        const BossMonsterPtrPtr,
                               SUserAllInfoInGame*  const pUserInfoPtrPtr,
                               SMonsterPocket*      const monsterPocketLibrayPtrPtr,
                               SMonsterPocketEquip* const monsterPocketEquipLibraryPtrPtr,
                               SWeapon* const weaponListPtrPtr,
                               SCloth*  const clothListPtrPtr,
                               SShoe*   const shoeListPtrPtr)
{
    assert(NULL != SmallMonsterPtrPtr);

    assert(NULL != BossMonsterPtrPtr);

    assert(NULL != pUserInfoPtrPtr);

    assert(NULL != monsterPocketLibrayPtrPtr);

    assert(NULL != monsterPocketEquipLibraryPtrPtr);

    assert(NULL != weaponListPtrPtr);

    assert(NULL != clothListPtrPtr);

    assert(NULL != shoeListPtrPtr);

    free(SmallMonsterPtrPtr);

    free(BossMonsterPtrPtr);

    free(pUserInfoPtrPtr);

    free(monsterPocketLibrayPtrPtr);

    free(monsterPocketEquipLibraryPtrPtr);

    free(weaponListPtrPtr);

    free(clothListPtrPtr);

    free(shoeListPtrPtr);

}


static int File_JudgeIDWhetherExist()//存在返回 0
{
    return 0;
}

static int File_LoadUserInfo(U8 *a,SUserAllInfoInGame* p)
{
    return 0;
}


int main(void)
{

    U8 temp[1] = {0};

    U8 userID[USER_ID_LEN]         = {0};

    U8 userPassword[USER_ID_LEN]   = {0};


    EUserLogChoice resultOfChoice = ELogChoice_Nochoice;

    EProfession resultOfProfession = EResultOfProfession_InitValue;

    EModeSelect resultOfModeSelect = EModeSelect_InitValue;


    SMonsterInfo* pSmallMonster = NULL;      //小怪顺序表头指针

    SMonsterInfo* pBossMonster    = NULL;    //BOSS顺序表头指针

    SUserAllInfoInGame* pUserInfo = NULL;    //人物信息结构体

    SMonsterPocket*       pMonsterPocketLibray            =NULL;//怪物口袋库头指针

    SMonsterPocketEquip * pMonsterPocketEquipLibrary = NULL; //装备库头指针

    SWeapon* pWeaponList = NULL; //武器库

    SCloth*  pClothList   = NULL;//衣服库

    SShoe*   pShoeList    = NULL;//鞋子库

    /* 0.分配内存给所有游戏数据*/
    AllocateAllMemory(&pSmallMonster,&pBossMonster,&pUserInfo,&pMonsterPocketLibray,&pMonsterPocketEquipLibrary);//为怪物、boss、人物分配内存
    CreateEquipmentMemoryPool(&pWeaponList,&pClothList,&pShoeList);

    /* 1.进入登录界面 */
    resultOfChoice  = Show_OpenLoginGameSelectUI();


    /* 2.根据选择值判断*/

    if(resultOfChoice == ELogChoice_NewGame)   /* 2.select-1- 新游戏开始 */
    {
        /* 2.select-1.1 进入用户注册界面以及用户注册模块函数处理 */
        while(1)
        {
            system("clear");
            Show_RegisterIDUI(userID,userPassword);


            printf("tempID %s\n",userID);

            printf("tempPasswd %s\n",userPassword);



            /* 2.select-1.1 读取文件判断该ID是否存在 */
            if(!File_JudgeIDWhetherExist(userID))//返回1代表不存在
            {

                /* 2.select-1.2 进入职业选择 */
                resultOfProfession = Show_ProfessionSelectUI();
                break;

            }
            else
            {
                printf("ID exist，re-put:");//存在
                continue;
            }

        }


    }

    else if(resultOfChoice == ELogChoice_RestartGame) // 2.select-2 继续游戏开始
    {
        while(1)
        {
            Show_LoginUI(userID,userPassword);

            if(!File_LoadUserInfo(userID,pUserInfo))
            {
                printf("ID or password error, re-put");
                continue;

            }
            else
            {
                break;
            }
        }

    }
    else /* 2.select-3 退出游戏 */
   {
        return;
    }


    resultOfModeSelect = Show_ModeSelectUI();

    if(resultOfModeSelect == EModeSelect_StandAloneFight)
    {
        InitAllGameData(pSmallMonster,pBossMonster,pUserInfo,\
                           pMonsterPocketLibray,pMonsterPocketEquipLibrary,\
                           resultOfProfession,userID,userPassword);

        getchar();
		GameStart(pUserInfo,pSmallMonster,pBossMonster);


    }
    else
    {
        //网络对战模块
    }

    FreeAllMemory(pSmallMonster,pBossMonster,pUserInfo,pMonsterPocketLibray,pMonsterPocketEquipLibrary,\
                  pWeaponList,pClothList,pShoeList);


    return 0;
}


