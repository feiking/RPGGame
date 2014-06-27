#define LOW_RED_MEDICINE 1
#define MID_RED_MEDICINE 2
#define HIG_RED_MEDICINE 3
#define LOW_BLUE_MEDICINE 4
#define MID_BLUE_MEDICINE 5
#define HIG_BLUE_MEDICINE 6
#define LOW_SWORD_OF_EQUIP  7
#define MID_SWORD_OF_EQUIP  8
#define LOW_BAR_OF_MAGIC 9
#define MID_BAR_OF_MAGIC 10
#define POWER_BOOK 11
#define BRAINS_BOOK 12
#define GOODS 13

 struct Low_of_RedMedicine
{
    int price;
    int please_refresh;
}Low_of_RedMedicine = {20,100};

struct Mid_of_RedMedicine
{
    int price;
    int please_refresh;
}Mid_of_RedMedicine = {40,200};

struct Hig_of_RedMedicine
{
    int price;
    int please_refresh;
}Hig_of_RedMedicine = {80,300};

struct Low_of_BlueMedicine
{
    int price;
    int REG;
}Low_of_BlueMedicine = {20,100};

struct Mid_of_BlueMedicine
{
    int price;
    int REG;
}Mid_of_BlueMedicine = {40,200};

struct Hig_of_BlueMedicine
{
    int price;
    int REG;
}Hig_of_BlueMedicine = {80,300};

struct Low_of_Sworod_Of_Equip
{
    int price;
    int ATK;
}Low_of_Sworod_Of_Equip = {20,10};

struct Mid_of_Sworod_Of_Equip
{
    int price;
    int ATK;
}Mid_of_Sworod_Of_Equip = {40,60};

struct Low_of_Bar_Of_Magic
{
    int price;
    int brains;
}Low_of_Bar_Of_Magic = {20,30};

struct Mid_of_Bar_Of_Magic
{
    int price;
    int brains;
}Mid_of_Bar_Of_Magic = {40,60};

struct Low_of_Cloth
{
    int price;
    int DEF;
}Low_of_Cloth = {20,10};

struct Mid_of_Cloth
{
    int price;
    int DEF;
}Mid_of_Cloth = {40,20};

struct Low_of_Shoe
{
    int price;
    int agility;
}Low_of_Shoe = {20,10};

struct Mid_of_Shoe
{
    int price;
    int agility;
}Mid_of_Shoe = {40,20};

struct Power_of_Book
{
    int price;
    int power;
}Power_of_Book = {50,5};

struct Brains_of_Book
{
    int price;
    int brains;
}Brains_of_Book = {50,5};

