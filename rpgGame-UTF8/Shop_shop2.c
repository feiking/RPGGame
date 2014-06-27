#include<stdio.h>
#include"Init_GameData.h"
#include"Shop_Init_Shop.h"
void Buy_Sword()
{
    int buttom;

    printf("商品按键:\n");
    printf("1、低级剑(价格:20,攻击力:10)\n");
    printf("2、中级剑(价格:40,攻击力:60)\n");
    printf("3、退出\n");
    printf("从1~3中选择按键\n");

    scanf("%d",&buttom);

    switch(buttom)
    {
        case 1:
            printf("购买低级剑\n");
            break;
        case 2:
            printf("购买中级剑\n");
            break;
        case 3:
            break;
        default:
            printf("输入错误\n");
            break;    
    }
    printf("\n");
}

void Buy_BAR_OF_MAGIC() 
{
    int buttom;
    printf("商品按键:\n");
    printf("1、低级法杖(价格:20,智力:30)\n");
    printf("2、中级法杖(价格:40,智力:60)\n");
    printf("3、退出\n");
    printf("从1~3中选择按键\n");
    scanf("%d",&buttom);
    switch(buttom)
    {
        case 1:
            printf("购买低级法杖\n");
            break;
        case 2:
            printf("购买中级法杖\n");
            break;
        case 3:
            break;
        default:
            printf("输入错误\n");
            break;    
    }
    printf("\n");
}

void Buy_Cloth()
{
    int buttom;

    printf("商品按键:\n");
    printf("1、低级铠甲(价格:20,防御力:10)\n");
    printf("2、中级铠甲(价格:40,防御力:20)\n");
    printf("3、退出\n");
    printf("从1~3中选择按键\n");

    scanf("%d",&buttom);

    switch(buttom)
    {
        case 1:
            printf("购买低级铠甲\n");
            break;
       
        case 2:
            printf("购买中级铠甲\n");
            break;
        case 3:
            break;
        default:
            printf("输入错误\n");
            break;    
    }
    printf("\n");
}

void Buy_Shoe()
{
    int buttom;
    printf("商品按键:\n");
    printf("1、低级鞋子(价格:20,敏捷力:10)\n");
    printf("2、中级鞋子(价格:30,敏捷力:20)\n");
    printf("3、退出\n");
    printf("从1~3中选择按键\n");
    scanf("%d",&buttom);
    switch(buttom)
    {
        case 1:
           printf("购买低级鞋子\n");
           break;
        case 2:
           printf("购买中级鞋子\n");
           break;
        case 3:
            break;
        default:
            printf("输入错误\n");
            break;    
    }
    printf("\n");
}
void Buy_RedMedicine()
{
    int buttom;
    printf("商品按键:\n");
    printf("1、低级红药水(价格:20,回复生命值:100)\n");
    printf("2、中级红药水(价格:40,回复生命值:200)\n");
    printf("3、高级红药水(价格:80,回复生命值:300)\n");
    printf("4、退出\n");
    printf("从1~4中选择按键\n");
    scanf("%d",&buttom);
    switch(buttom)
    {
        case 1:
            printf("购买低级红药水\n");
            break;

        case 2:
            printf("购买中级红药水\n");
            break;

        case 3:
            printf("购买高级红药水\n");
            break;

        default:
            printf("输入错误\n");
            break;    
    }
    printf("\n");
}

void Buy_BlueMedicine()
{
    int buttom;
    printf("商品按键:\n");
    printf("1、低级蓝药水(价格:20,回复魔法值:100)\n");
    printf("2、中级蓝药水(价格:40,回复魔法值:200)\n");
    printf("3、高级蓝药水(价格:80,回复魔法值:300)\n");
    printf("4、退出\n");
    printf("从1~4中选择按键\n");
    scanf("%d",&buttom);
    switch(buttom)
    {
        case 1:
           printf("购买低级蓝药水\n");
           break;

        case 2:
            printf("购买中级蓝药水\n");
            break;

        case 3:
            printf("购买高级蓝药水\n");
            break;

        case 4:
            break;

        default:
            printf("输入错误\n");
            break;    
    }
    printf("\n");
}

void Buy_Medicine()
{
    int buttom;
    printf("商品按键:\n");
    printf("1、红药水\n");
    printf("2、蓝药水\n");
    printf("3、退出\n");
    printf("从1~3中选择按键\n");
    scanf("%d",&buttom);
    switch(buttom)
    {
        case 1:
            Buy_RedMedicine();
            break;

        case 2:
            Buy_BlueMedicine();
            break;

        case 3:
            break;

        default:
            printf("输入错误\n");
            break;
    }
    printf("\n");
}

void Buy_Weapon()
{
    int buttom;
    printf("商品按键:\n");
    printf("1、剑\n");
    printf("2、法杖\n");
    printf("3、铠甲\n");
    printf("4、鞋子\n");
    printf("5、退出\n");
    printf("从1~5中选择按键\n");
    scanf("%d",&buttom);
    switch(buttom)
    {
        case 1:
            Buy_Sword();
            break;

        case 2:
            Buy_BAR_OF_MAGIC();
            break;

        case 3:
            Buy_Cloth();
            break;

        case 4:
            Buy_Shoe();
            break;

        case 5:
            break;

        default:
            printf("输入错误\n");
            break;    
    }
    printf("\n");
}

void Buy_Book()
{
    int buttom;
    printf("商品按键:\n");
    printf("1、力量之书(价格:50,增加力量:5)\n");
    printf("2、智力之书(价格:50,增加智力:5)\n");
    printf("3、退出\n");
    printf("从1~3中选择按键\n");
    scanf("%d",&buttom);
    switch(buttom)
    {
        case 1:
            printf("购买力量之书\n");
            break;

        case 2:
            printf("购买智力之书\n");
            break;

        case 3:
            break;

        default:
            printf("输入错误\n");
            break;    
    }
    printf("\n");
}

void Display_Shop()
{
    printf
("**************************************************************\n");

    printf("                                 欢饮来到商店!                            \n");


    printf("                                   1、装备                                 \n");

    printf("                                   2、药水                                 \n");

    printf("                                   3、书籍                                  \n");

    printf("                                   4、 退出                                 \n");

    printf
 ("**************************************************************\n");
}
shop()
{
    
    Display_Shop();
    int buttom;
    scanf("%d",&buttom);
    switch(buttom)
    {
        case 1:
            Buy_Weapon();
            break;

        case 2:
            Buy_Medicine();
            break;

        case 3:
            Buy_Book();
            break;

        case 4:
            break;

        default:
            printf("输入错误\n");
            break;    
    }
    printf("\n");
}
