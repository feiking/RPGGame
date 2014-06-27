#ifndef _INIT_GAME_DATA_H_
#define _INIT_GAME_DATA_H_

/* 1. All head file */

/* 2. All Micro  */

#define FALSE          0

#define TRUE           1

#define ERROR          -1

/*  9 - 30 for equipment Micro */

#define SWORD_OF_EQUIP 9
#define BAR_OF_MAGIC     10

#define LOW_WEAPON     11
#define MID_WEAPON     12
#define HIGH_WEAPON    13
#define SUPER_WEAPON   14

#define LOW_CLOTH      15
#define MID_CLOTH      16
#define HIGH_CLOTH     17
#define SUPER_CLOTH    18

#define LOW_SHOE     19
#define MID_SHOE     20
#define HIGH_SHOE    21
#define SUPER_SHOE   22

/* 31 - 40 for skills Micro */

#define MAGIC_SKILL_SMALL_FIRE    31 //小火球
#define MAGIC_SKILL_BIG_FIRE      32 //大火球
#define MAGIC_SKILL_PROTECT       33 //魔法盾

#define FIGHTER_SKILL_DEFEND_ATTACK    34 //战士技能:防守反击
#define FIGHTER_SKILL_DEAD_ATTACK      35 //战士技能:致命一击



/* map Micro */
#define MAP_1 1

#define MAP_2 2

#define MAP_3 3

#define MAP_4 4

#define MAP_5 5


/* other Micro */

#define USER_ID_LEN         12
#define USER_PASSWORD_LEN   12

#define NUMBER_OF_BOSS              5
#define NUMBER_OF_SMALL_MONSTER     50





/*******所有小怪宏设定********************/
#define MONSTER_HP_INIT              200

#define MONSTER_ATTACK_INIT          20

#define MONSTER_DEFEND_INIT          5

#define MONSTER_DEX_INIT             5

#define MONSTER_EXP_INIT             10

#define MONSTER_MONEY_INIT           10


#define MONSTER_HP_INCREMENT         100

#define MONSTER_ATTACK_INCREMENT     5

#define MONSTER_DEFEND_INCREMENT     2

#define MONSTER_DEX_INCREMENT        5

/*******所有小怪宏设定********************/



/*******所有BOSS宏设定********************/

#define BOSS_HP_INIT            800

#define BOSS_ATTACK_INIT        50

#define BOSS_DEFEND_INIT        10

#define BOSS_DEX_INIT           15

#define BOSS_EXP_INIT           50

#define BOSS_MONEY_INIT         100


#define BOSS_HP_INCREMENT         500

#define BOSS_ATTACK_INCREMENT     30

#define BOSS_DEFEND_INCREMENT     7

#define BOSS_DEX_INCREMENT        15


/*******所有BOSS宏设定********************/

#define MONSTER_IS_BOSS        100

#define MONSTER_IS_NOT_BOSS    101


/*******控制字体颜色宏设定****************/
#define NONE         "\033[m"
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"


/* 3. All typdef */

typedef unsigned char U8;
typedef unsigned int U32;

typedef enum EUserLogChoice
{
    ELogChoice_Nochoice,
    ELogChoice_NewGame,
    ELogChoice_RestartGame,
    ELogChoice_ExitGame,

}EUserLogChoice;

typedef enum EProfession
{
    EResultOfProfession_InitValue,
    EResultOfProfession_SwordMan,
    EResultOfProfession_MagicMan,
}EProfession;

typedef enum EModeSelect
{
    EModeSelect_InitValue,
    EModeSelect_StandAloneFight,
    EModeSelect_NetFight,
}EModeSelect;


/********* 1. user infomation struct ***************/

typedef struct SPosition//坐标位置
{
    U32 x;
    U32 y;
}SPosition;

typedef struct SRolePositon
{
    SPosition *pOldPos; //旧位置
    SPosition *pNewPos; //新位置
}SRolePositon;


typedef struct SCurrentWearEquip//目前身上穿戴装备   修改过了
{
    U8 weaponName[20]; //武器名称 不能超过20个字符，即10个字
    U8 weaponKind;      //武器种类
    U8 weaponLevel;     //武器等级（等级为0 表示没有穿戴）

    U8 clothName[20];   //衣服名称 不能超过20个字符，即10个字
    U8 clothLevel;     //衣服等级（分为4级） （等级为0 表示没有穿戴）

    U8 shoeName[20];  //鞋子名称 不能超过20个字符，即10个字            修改过了
    U8 shoeLevel;     //鞋子等级（分为4级） （等级为0 表示没有穿戴）
}SCurrentWearEquip;

typedef struct SSkilLevel //技能名称以及技能等级
{
    U8 SkillName;//技能名称
    U8 skillLevel;//技能等级
}SSkilLevel;


typedef struct SSkills //所有技能种类
{
    SSkilLevel *pSkillKind_1;//技能1
    SSkilLevel *pSkillKind_2;//技能2
    SSkilLevel *pSkillKind_3;//技能3
}SSkills;

typedef struct SMedicine //控制所有药水信息结构体
{
    U8 lowRedMedicine; //低级红药(最大拥有255)
    U8 midRedMedicine; //中级红药
    U8 superRedMedicine;//高级红药

    U8 lowBlueMedicine;//低级蓝药
    U8 midBlueMedicine;//中级蓝药
    U8 superBlueMedicine;//高级蓝药
}SMedicine;

typedef struct SWeapon//武器结构体
{
    U8 weaponName[20];//武器名称 不能超过20个字符，即10个字
    U8 weaponKind; //武器种类 （分为sword 和 magic bar）
    U8 weaponLevel; //武器等级（分为4级）
    struct SWeapon * next; //链表存储武器
}SWeapon;

typedef struct SCloth//衣服结构体
{
    U8 clothName[20];//衣服名称 不能超过20个字符，即10个字
    U8 clothLevel; //衣服等级（分为4级）
    struct SCloth * next; //链表存储衣服
}SCloth;

typedef struct SShoe//鞋子结构体
{
    U8 shootName[20];//鞋子名称 不能超过20个字符，即10个字
    U8 shootLevel; //鞋子等级（分为4级）
    struct SShoe * next; //链表存储鞋子
}SShoe;

typedef struct SEquipment
{
    SWeapon* pWeapon; //存储武器链表的首指针
    SCloth*  pCloth;  //存储衣服链表的首指针
    SShoe*   pShoe;  //存储鞋子链表的首指针

    U8 weaponCurrentCount;//当前包裹中武器数量
    U8 clothCurrentCount; //当前包裹中衣服数量
    U8 shootCurrentCount; //当前包裹中鞋子数量
}SEquipment;

typedef struct SUserPocket //口袋结构体
{
    U32 money;//口袋里面的金钱

    SMedicine *pMedicine;//所有药水记录结构体

    SEquipment *pEquip;//口袋中所有的装备

}SUserPocket;


typedef struct SUserAllInfoInGame     /* 此结构体控制人物所有信息 */
{
    U8  userID[12];//用户ID
    U8  password[12];//用户密码
    U8  profession;//角色人物：战士或法师
    U8  level;     //等级
    U8  currentMap; //目前以及通关关卡
    U32 exp;       //经验值

    U32 HP;//生命值(health point)
    U32 MP;        //魔法值(magic point)
    U32 attack;    //攻击力
    U32 defend;   //防御力

    U32 strength;   //力量
    U32 dex;        //敏捷
    U32 intelligence; //智力

    SRolePositon *pPos; //角色新旧位置

    SCurrentWearEquip *pCurrentWearEuip;//玩家当前创带的装备

    SSkills *pSkillKind; //技能结构体（包括技能1 ，2, 3 ）

    SUserPocket *pPocket; //玩家口袋
}SUserAllInfoInGame;



/*****2. Boss infomation struct ****************/

 typedef struct SMonsterPocketEquip //怪物口袋中装备结构体
{
    U8 weaponName[20]; //武器名称 不能超过20个字符，即10个字
    U8 weaponKind;    //武器种类
    U8 weaponLevel;   //武器等级（等级为0 表示 没有此装备）

    U8 clothName[20];//衣服名称 不能超过20个字符，即10个字
    U8 clothLevel; //衣服等级（分为4级） （等级为0 表示没有此装备）

    U8 shootName[20];//鞋子名称 不能超过20个字符，即10个字
    U8 shootLevel; //鞋子等级（分为4级） （等级为0 表示没有此装备）

}SMonsterPocketEquip;

typedef struct SMonsterPocket  //怪兽口袋
{
    U32 money; //所掉金钱
    U32 exp;   //所掉经验

    SMonsterPocketEquip *pMonsterEquip;//所掉装备
}SMonsterPocket;

typedef struct SMonsterInfo
{
    U8 monsterName[12]; // 怪物名称
    U8 level;          //怪物等级（boss都大于10级，小怪低于10级）

    int HP; //怪物生命值(health point)

    U32 attack;    //怪物攻击力
    U32 defend;    //怪物防御力

    U32 dex;      //怪物敏捷 (人物敏捷度小于怪物时不能逃跑)

    SMonsterPocket * pMonsterPocket;//怪物口袋结构体
}SMonsterInfo;


/* 4 global variety */


/* 5. All function */

void InitAllGameData(SMonsterInfo*        pSmallMonster,
                     SMonsterInfo*        pBossMonster,
                     SUserAllInfoInGame*  pUserInfo,
                     SMonsterPocket*      pMonsterPocketLibray,
                     SMonsterPocketEquip* pMonsterPocketEquipLibrary,
                     EProfession          profession,
                     U8* userID,
                     U8* userPassword);//初始化所有游戏数据(比如:地图、boss、小怪库、人物信息)


void RefreshBuff();

SMonsterInfo* Init_RoleOfEnemy(SMonsterInfo* pSmallMonster,
                               SMonsterInfo* pBossMonster,
                               SUserAllInfoInGame* pUserInfo,
                               U32 flags);


#endif
