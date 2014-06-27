//#include"Walk_PickUp.h"
//拾取装备
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>

#include"Init_GameData.h"

/***********************************************************
* This module is revoked when user fights over little-monsters,then little-monster ,whose equipments and
* medicine can be picked by users ,is killed,and the function will return true,if not ,the function will return false.
*Name  : Walk_PickUp
*Para  : SUserAllInfoInGame * pRole , monsterInfo * pMonster
*Return : int
*
***********************************************************/
/*成功消灭敌人以后，敌人掉落了装备，玩家会选择拾取*/
int Walk_PickUp(SUserAllInfoInGame * pRole , SMonsterInfo * pMonster)
{
	assert(pRole);
	assert(pMonster);

	U32 kindsOfPickup;
	U32 kinds;
	//用户战胜了怪物

	if(pMonster->pMonsterPocket->money != 0)
	{
		printf("1.金钱: \n");
		printf("%d\n",pMonster->pMonsterPocket->money);
		printf("金钱增加%d\n",pMonster->pMonsterPocket->money);

		pRole->pPocket->money += pMonster->pMonsterPocket->money;
	}

	if(pMonster->pMonsterPocket->pMonsterEquip->weaponLevel != 0 ||
		pMonster->pMonsterPocket->pMonsterEquip->clothLevel != 0 ||
		pMonster->pMonsterPocket->pMonsterEquip->shootLevel != 0)
	{
		printf("2.装备:\n"); //没有显示的话，则没有装备
	}
	else
	{
		printf("没有掉落装备!\n");
		return FALSE;
	}
	//挨个显示
	//武器
	if(pMonster->pMonsterPocket->pMonsterEquip->weaponLevel != 0)
	{
		printf("a.武器:\n");
		printf("名称:%s\n",pMonster->pMonsterPocket->pMonsterEquip->weaponName);
		printf("种类:%d\n",pMonster->pMonsterPocket->pMonsterEquip->weaponKind);
		printf("等级:%d\n",pMonster->pMonsterPocket->pMonsterEquip->weaponLevel);

		//对武器处理
		printf("%s武器增加\n",pMonster->pMonsterPocket->pMonsterEquip->weaponName);
		pRole->pPocket->pEquip->weaponCurrentCount += 1; //数量增加1

	    //新建立一个玩家武器节点，连接到武器链表上，头插法

		SWeapon * weaponPtr = (SWeapon *)malloc(sizeof(SWeapon));
		assert(weaponPtr);
		strcpy(weaponPtr ->weaponName , pMonster->pMonsterPocket->pMonsterEquip->weaponName);//名称
		weaponPtr->weaponKind = pMonster->pMonsterPocket->pMonsterEquip->weaponKind; //种类
		weaponPtr->weaponLevel = pMonster->pMonsterPocket->pMonsterEquip->weaponLevel; //等级

		//将节点连到武器链表上
		weaponPtr->next = pRole->pPocket->pEquip->pWeapon;
		pRole->pPocket->pEquip->pWeapon = weaponPtr;

	}
    //衣服
	if(pMonster->pMonsterPocket->pMonsterEquip->clothLevel != 0)
	{
		printf("b.衣服:\n");
		printf("名称:%s\n",pMonster->pMonsterPocket->pMonsterEquip->clothName);
		printf("等级:%d\n",pMonster->pMonsterPocket->pMonsterEquip->clothLevel);

		//对衣服进行处理
		printf("%s衣服增加\n",pMonster->pMonsterPocket->pMonsterEquip->clothName);
		pRole->pPocket->pEquip->clothCurrentCount += 1; //衣服数量增加

		//建立链表，连接到衣服连表上
		SCloth * clothPtr = (SCloth *)malloc(sizeof(SCloth));
		assert(clothPtr);

		strcpy(clothPtr->clothName , pMonster->pMonsterPocket->pMonsterEquip->clothName);
		clothPtr->clothLevel = pMonster->pMonsterPocket->pMonsterEquip->clothLevel;

		//连接到衣服链表上
		clothPtr->next = pRole->pPocket->pEquip->pCloth;
		pRole->pPocket->pEquip->pCloth= clothPtr;
	}

    //鞋子
	if(pMonster->pMonsterPocket->pMonsterEquip->shootLevel != 0)
	{
		printf("c.鞋子:\n");
		printf("名称:%s\n",pMonster->pMonsterPocket->pMonsterEquip->shootName);
		printf("等级:%d\n",pMonster->pMonsterPocket->pMonsterEquip->shootLevel);

		printf("%s鞋子增加\n",pMonster->pMonsterPocket->pMonsterEquip->shootName);
		pRole->pPocket->pEquip->shootCurrentCount += 1;

		//建立节点 插入到鞋子链表上去
		SShoe * shoePtr = (SShoe *)malloc(sizeof(SShoe));

		strcpy(shoePtr->shootName , pMonster->pMonsterPocket->pMonsterEquip->shootName);
		shoePtr->shootLevel = pMonster->pMonsterPocket->pMonsterEquip->shootLevel;

		//插入节点
		shoePtr->next = pRole->pPocket->pEquip->pShoe;
		pRole->pPocket->pEquip->pShoe = shoePtr;

	}

	return TRUE;
}

