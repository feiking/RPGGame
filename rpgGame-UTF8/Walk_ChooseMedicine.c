#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"Init_GameData.h"
/*
**Name     :    void Walk_ChooseMedicine()
**para     :    SUserAllInfoInGame * rolePtr
**Return   :    int
*/
/*选择成功(选择到了)则返回1，若是没有选择(退出)或者是输入不合法，直接返回0*/
int Walk_ChooseMedicine(SUserAllInfoInGame * pRole)
{
	 U32 kindsOfMedicine; //药水种类
	 U32 levelsOfMedicine; //药水等级
	 U32 numberOfMedicine; //一次选择的药水数量

		// system("clear");// 刷新

		/*显示所有的药水种类以及数量*/
		printf("a.红药水:\n");
		printf("b.蓝药水:\n");
		printf("c.退出选择\n");
		printf("请选择要使用的药水总类:");

		kindsOfMedicine = getchar();

		getchar(); //消除回车
	//printf("%p\n",pRole);
	//printf("%p\n",pRole->pPocket);
	//选择完成后进行处理
    if(kindsOfMedicine == 'a')  //选择红药水,增加生命值
    {
        printf("红药水各等级和数量:\n");
		printf("1.初级红药水: %d\n",pRole->pPocket->pMedicine->lowRedMedicine);
		printf("2.中级红药水: %d\n",pRole->pPocket->pMedicine->midRedMedicine);
		printf("3.高级红药水: %d\n",pRole->pPocket->pMedicine->superRedMedicine);

		//输入药水等级和数量
		printf("请输入要用的红药水的种类和数量:");
		scanf("%d %d",&levelsOfMedicine,&numberOfMedicine);
		getchar(); //消除回车

		//口袋红药水减少numberOfMedicine(要进行判断)，但pRole的生命值增加
		if(levelsOfMedicine == 1 &&
		   numberOfMedicine <= pRole->pPocket->pMedicine->lowRedMedicine)
		{
			pRole->HP += 100 * numberOfMedicine;
			pRole->pPocket->pMedicine->lowRedMedicine -= numberOfMedicine;
		}

		else
		if(levelsOfMedicine == 2 &&
		   numberOfMedicine <= pRole->pPocket->pMedicine->midRedMedicine)
	    {
    		pRole->HP += 200 * numberOfMedicine;
			pRole->pPocket->pMedicine->midRedMedicine -= numberOfMedicine;
 		}

		else
    	if(levelsOfMedicine == 3 &&
			numberOfMedicine <= pRole->pPocket->pMedicine->superRedMedicine)
	    {
		    pRole->HP += 300 * numberOfMedicine;
			pRole->pPocket->pMedicine->superRedMedicine -= numberOfMedicine;
	    }

		else //输入不合法，直接返回0，从新选择
		{

			printf("选择的红药水不合法!\n");
			return FALSE;
		}

		//选择成功，返回1
		return TRUE;

	}

	else
	if(kindsOfMedicine == 'b') //选择蓝药水，增加魔法值
    {
	    printf("蓝药水的等级和数量:\n");
		printf("1.初级蓝药水: %d\n",pRole->pPocket->pMedicine->lowBlueMedicine);
		printf("2.中级蓝药水: %d\n",pRole->pPocket->pMedicine->midBlueMedicine);
		printf("3.高级蓝药水: %d\n",pRole->pPocket->pMedicine->superBlueMedicine);

		//输入药水等级和数量
		printf("请输入要使用的蓝药水的种类和数量:");
		scanf("%d %d",&levelsOfMedicine,&numberOfMedicine);
		getchar(); // 消除回车

		//口袋蓝药水数量减少numberofMedicine，pRole各属性值增加

		if(levelsOfMedicine == 1 &&
			numberOfMedicine <= pRole->pPocket->pMedicine->lowBlueMedicine)
		{
			pRole->MP += 100 * numberOfMedicine;
			pRole->pPocket->pMedicine->lowBlueMedicine -= numberOfMedicine;
		}
		else
			if(levelsOfMedicine == 2 &&
				numberOfMedicine <= pRole->pPocket->pMedicine->midBlueMedicine)
		    {
	    		pRole->MP += 200 * numberOfMedicine;
				pRole->pPocket->pMedicine->midBlueMedicine -= numberOfMedicine;
     		}
		else
	    	if(levelsOfMedicine == 3 &&
				numberOfMedicine <= pRole->pPocket->pMedicine->superBlueMedicine)
		    {
			    pRole->MP += 300 * numberOfMedicine;
				pRole->pPocket->pMedicine->superBlueMedicine -= numberOfMedicine;
		    }
		else //输入不合法，直接返回，从新选择
		{
			printf("选择的蓝药水不合法!\n");
			return FALSE;
		}

		//选择成功，返回1
		return TRUE;

    }

	else
	if(kindsOfMedicine == 'c') //退出选择,此时的返回值也是0
	{
		printf("并未选择药水，退出!\n");
        return FALSE;

	}

	else//输入不合法
	{
		printf("您的选择不合适,请重新选择!\n");
		return FALSE;

	}


 }
