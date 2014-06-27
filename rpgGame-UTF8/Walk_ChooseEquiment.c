#include<stdio.h>
#include<string.h>
#include<malloc.h>

#include"Init_GameData.h"

#if 0
 /*
 **Name   :   void Walk_ChoooseEquiment()
 **Para 	:	SUserAllInfoInGame *rolePtr
 **Return  :   void
 */
 /*选择使用装备的时候，就是先显示用户的的装备种类和数量，
 **然后用户输入要使用的种类和数量，然后使用，使用后，玩家更换的
 **是自己当前的装备
 ** 成功选择了装备则返回1，否则返回0，就是没有选择到，无论是错误输入还是没有了该装备
 */
#endif



 int Walk_ChooseEquiment(SUserAllInfoInGame *pRole)
 {
	 int i = 0;//循环控制

	 U8 choiceOfWeapon;
	 U8 choiceOfCloth;
	 U8 choiceOfShoe;

	 U8 kindsOfWeapon;
	 U8 kindsOfCloth;
	 U8 kindsOfShoe;


	 SWeapon * weaponPtr = pRole->pPocket->pEquip->pWeapon; //定义一个指向武器的结构体的指针，用作遍历用
	// printf("1.%x\n",weaponPtr);
	 SWeapon *tempWeaponPtr = weaponPtr; //初始化指向第一节点

	 SCloth * clothPtr = pRole->pPocket->pEquip->pCloth; //初始化为头指针
	 SCloth * tempClothPtr = clothPtr;

	 SShoe * shoePtr = pRole->pPocket->pEquip->pShoe; //初始化为头指针
	 SShoe * tempShoePtr = shoePtr;

	 printf("欢迎来到装备选择界面\n");
	 printf("a.武器\n");
	 printf("b.衣服\n");
	 printf("c.鞋子\n");

	 printf("请输入要选择的装备:");
	 choiceOfWeapon = getchar();
	 getchar();

	 switch(choiceOfWeapon)
	 {
		 case 'a':
			 //显示装备和数量
			 //显示武器信息
			 if(pRole->pPocket->pEquip->weaponCurrentCount == 0)
			 {
				 printf("没有可用的武器!\n");
				sleep(2);
				 return FALSE;
			 }
			 else
			 {
				 //武器链表并不为空，至少一个啦
				 printf("a.武器种类和数量: \n");

				 //数量由weaponCurrentCount控制
				 for(i = 0; i < pRole->pPocket->pEquip->weaponCurrentCount; i++)
				 {
					 printf("%d.%s\n",i+1,weaponPtr->weaponName);
					 weaponPtr = weaponPtr->next;//结束是为NULl
				 }

				 printf("请输入要使用的武器种类: ");

				 scanf("%c",&kindsOfWeapon);
				 getchar();

				 if(kindsOfWeapon < 1 || kindsOfWeapon > pRole->pPocket->pEquip->weaponCurrentCount)
				 {
					 printf("没有这种武器!\n");
					 return FALSE;
				 }
				 else // 此时会选择一种武器
				 {
					 //穿上这个装备(增加相对应的属性值)，然后销毁这个单元
					 //先查找到用户选择的装备

					 weaponPtr = pRole->pPocket->pEquip->pWeapon; //复原指针
					 tempWeaponPtr = weaponPtr;
					 //按照输入的标号来寻找
					 //此时已经指向要删除的结构
					 for(i = 1; i<kindsOfWeapon; i++)
					 {
						 tempWeaponPtr = weaponPtr;
						 weaponPtr = weaponPtr->next;
					 }


					 if(weaponPtr->weaponKind == SWORD_OF_EQUIP)//剑
					 {

						 switch(weaponPtr->weaponLevel)
						 {
							 case LOW_WEAPON:
								 pRole->attack += 10;
								 break;
							 case MID_WEAPON:
								 pRole->attack += 60;
								 break;
							 case HIGH_WEAPON:
								 pRole->attack += 100;
								 break;
							 case SUPER_WEAPON:
								 pRole->attack += 150;
								 break;
							 default:
								 break;
						 }
					 }
					 //if(weaponPtr->weaponKind == BAR_OF_MAGIC) //魔法杖
					 else
					 {
						 switch(weaponPtr->weaponLevel)
						 {
							 case LOW_WEAPON:
								  pRole->intelligence += 30;
								  break;
							 case MID_WEAPON:
								 pRole->intelligence  += 60;
								 break;
							 case HIGH_WEAPON:
								 pRole->intelligence  += 100;
								 break;
							 case SUPER_WEAPON:
								 pRole->intelligence  += 150;
								 break;
							 default:
								 break;
						 }

					 }
					// printf("1.%x\n",weaponPtr);

					 //更新操作
					 --pRole->pPocket->pEquip->weaponCurrentCount;//武器种类减少一个
					// printf("%s\n",weaponPtr->weaponName);
					//printf("%s\n",pRole->pCurrentWearEquip->weaponName);
					 strcpy(pRole->pCurrentWearEuip->weaponName,weaponPtr->weaponName);//当前装备
					 // printf("DD\n");
					 pRole->pCurrentWearEuip->weaponLevel = weaponPtr->weaponLevel;
					 pRole->pCurrentWearEuip->weaponKind = weaponPtr->weaponKind;
					// printf("2.%x\n",weaponPtr);

					 //释放节点
					 //只有一个节点，并且选择了
					 if( kindsOfWeapon == 1)
					 {
						 tempWeaponPtr = NULL;
						 pRole->pPocket->pEquip->pWeapon = weaponPtr->next;
					 }
					 else
					 {
						 tempWeaponPtr->next= weaponPtr->next;
					 }

					 free(weaponPtr);
				 }
			 }
			 break;
		 case 'b':	//处理衣服选择
			 if(pRole->pPocket->pEquip->clothCurrentCount == 0)
			 {
				 printf("没有可用的衣服!\n");
				sleep(2);
				 return FALSE;
			 }
			 else
			 {
				 printf("b.衣服的种类和数量");

				 //显示衣服装备的种类
				 for(i = 0; i < pRole->pPocket->pEquip->clothCurrentCount; i++)
				 {
					 printf("%d.%s\n",i+1,clothPtr->clothName);
					 clothPtr = clothPtr->next;//最后一个节点已经指向NULL，后面要令其指向第一个节点
				 }

				 printf("请输入要使用的衣服的种类: ");
				 kindsOfCloth = getchar(); //选择
				 getchar(); //去除回车符

				 if(kindsOfCloth < 1 || kindsOfCloth > pRole->pPocket->pEquip->clothCurrentCount)//输入合法判断
				 {
					 printf("没有这种衣服装备!\n");
					 return FALSE;
				 }
				 else
				 {
					 //clothPtr指向选择的衣服装备节点
					 clothPtr = pRole->pPocket->pEquip->pCloth; //指向第一个节点
					 tempClothPtr = clothPtr;

					 for(i = 1; i < kindsOfCloth; i++)
					 {
						 tempClothPtr = clothPtr;
						 clothPtr = clothPtr->next;
					 }

					 switch(clothPtr->clothLevel) //按照等级来加防御值
					 {
						 case LOW_CLOTH:
							 pRole->defend += 10;
							 break;
						 case MID_CLOTH:
							 pRole->defend += 20;
							 break;
						 case HIGH_CLOTH:
							 pRole->defend += 40;
							 break;
						 case SUPER_CLOTH:
							 pRole->defend += 80;
						 default:
							 break;
					 }

					 //更新操作，当前装备和衣服数量需要更新
					 --pRole->pPocket->pEquip->clothCurrentCount;
					 strcpy(pRole->pCurrentWearEuip->clothName,clothPtr->clothName);
					 pRole->pCurrentWearEuip->clothLevel = clothPtr->clothLevel;

					 //释放节点
					 if(kindsOfCloth == 1)
					 {
						 tempClothPtr =NULL; //防止总共有一个节点，指针悬空问题
						 pRole->pPocket->pEquip->pCloth = clothPtr->next;

					 }
					 else
					 {
						 tempClothPtr->next = clothPtr->next;
					 }

					 free(clothPtr);
				 }
			 }
			 break;
		 case 'c': //处理鞋子
			 if(pRole->pPocket->pEquip->shootCurrentCount == 0)
			 {
				 printf("没有可用的鞋子!\n");
				sleep(2);
				 return FALSE;
			 }
			 else
			 {
				 printf("c.鞋子的种类和数量");

				 //显示
				 for(i = 0; i < pRole->pPocket->pEquip->shootCurrentCount; i++)
				 {
					 printf("%d.%s\n",i+1,shoePtr->shootName);
					 shoePtr = shoePtr->next;
				 }

				 printf("请输入要选择的鞋子种类:");
				 kindsOfShoe = getchar();//输入
				 getchar();

				 if(kindsOfShoe < 1 || kindsOfShoe > pRole->pPocket->pEquip->shootCurrentCount)
				 {
					 printf("没有这种鞋子装备!\n");
					 return FALSE;
				 }
				 else
				 {
					 //令shoePtr 指向选择的鞋子装备
					 shoePtr = pRole->pPocket->pEquip->pShoe;
					 tempShoePtr = shoePtr;

					 for(i = 1; i < kindsOfShoe; i++)
					 {
						 tempShoePtr = shoePtr;
						 shoePtr = shoePtr->next;
					 }

					 switch(shoePtr->shootLevel)//增加敏捷度
					 {
						 case LOW_SHOE:
							 pRole->dex += 10;
							 break;
						 case MID_SHOE:
							 pRole->dex += 20;
							 break;
						 case HIGH_SHOE:
							 pRole->dex += 40;
							 break;
						 case SUPER_SHOE:
							 pRole->dex += 60;
							 break;
						 default:
							 break;
					 }

					 //更新当前装备
					 --pRole->pPocket->pEquip->shootCurrentCount;
					 strcpy(pRole->pCurrentWearEuip->shoeName,shoePtr->shootName);
					 pRole->pCurrentWearEuip->shoeLevel = shoePtr->shootLevel;

					 //释放节点
					 if(kindsOfShoe == 1)
					 {
						 tempShoePtr =	NULL;
						 pRole->pPocket->pEquip->pShoe = shoePtr->next;
					 }
					 else
					 {
						 tempShoePtr->next = shoePtr->next;
					 }

					 free(clothPtr);
				 }
			 }
			 break;
		 default:
			 break;
	 }

	 return TRUE;
 }




