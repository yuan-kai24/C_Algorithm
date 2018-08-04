#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct _main
{
    int a;//数据域
    struct _main *next;//指针域
}Main;//初始化结构

Main * Init()
{
    Main *head,*ptr_1,*ptr_2;
    ptr_1 = (Main*)malloc(sizeof(Main));
    scanf("%d",&ptr_1->a);//虽然ptr_1是指针变量可以不用取地址，但ptr_1->a不是
    head =  ptr_2 = ptr_1;

    while(ptr_1->a != 0)//如果前一个输入0停止录入，但零还是录入了
    {
        ptr_1 = (Main*)malloc(sizeof(Main));
        scanf("%d",&ptr_1->a);
        ptr_2->next = ptr_1;
        ptr_2 = ptr_1;//保存下一个，跟踪
    }
    ptr_2->next = NULL;//末尾a=0指向空

    return head;

    /*
    末尾不是直接等于空，而是a=0，next=NULL
    用于垫底操作
    */
}//初始化输入

void Input(Main * head)
{
    Main*ptr_1 = head;
    while(ptr_1->next != NULL)
    {
        printf("\t%d\n",ptr_1->a);
        ptr_1 = ptr_1->next;//遍历
    }

    /*
    并没有输出a=0的节点
    */
}//输出打印

Main * Insert(Main * head)
{
    Main * ptr_fin = head;//保留head的值
    Main * adsr = (Main *)malloc(sizeof(Main));
    printf("请输入节点参数：");
    scanf("%d",&adsr->a);
    adsr->next = NULL;//保险操作，不让指针乱指
    if(adsr->a < ptr_fin->a)
    {
        adsr->next = ptr_fin;
        head = adsr;

    }//首位插入，若输入节点为首位则直接插入
    else
        {
            /*
            末尾的节点的a在录入时为零，next为null，利用此特性
            */
        Main * ptr_fin2 = ptr_fin;//此方法可以不用改变初始保留的head值
        int flag = 0;
        while(ptr_fin2->next->next != NULL)//让a=0垫底，循环
        {
                if(ptr_fin2->next->a > adsr->a)
                {
                    adsr->next = ptr_fin2->next;//用户输入的现在还是个独立的个体，先指向它要插入的前一个节点指向的位置
                    ptr_fin2->next = adsr;//再把前一个节点指向它
                    flag = 1;//判断是否已经插入
                    break;
                }//中间插入，按顺序
            ptr_fin2 = ptr_fin2->next;
        }//遍历判断
        if(flag == 0)
        {
            adsr->next = ptr_fin2->next;//接收垫底的节点，原理同上
            ptr_fin2->next = adsr;

        }//末尾插入
    }


    return head;
}//插入节点

Main * deletes(Main * head)
{
    Main * ptr_fin = head;
    int num;
    printf("\n请输入你要删除的编号：");
    scanf("%d",&num);//录入

    if(num == ptr_fin->a)
    {

        head = ptr_fin->next;//直接指向下一个数据
        free(ptr_fin);//释放原数据
    }//首位删除
    else
    {
        Main * ptr_fin2 = ptr_fin;
        int flag = 0;
        while(ptr_fin2->next->next != NULL)
        {
            if(num == ptr_fin2->next->a)
            {
                ptr_fin2->next = ptr_fin2->next->next;//本节点指向下一个节点的下一个节点数据
                free(&ptr_fin2->next);//释放下一个节点（查找的节点）
                flag = 1;
                break;
            }
            ptr_fin2 = ptr_fin2->next;
        }
        if(flag == 0)
        {
            printf("没有找到要删除的节点\n");
        }
    }

    return head;

}

Main * dellinlis(Main * head)
{
    int i = 1;
    Main * ptr_1 = head;
    Main * ptr_2 = ptr_1->next;//保存下一个节点
    while(ptr_2 != NULL)
    {
        free(ptr_1);
        ptr_1 = ptr_2;//记录下一个节点
        ptr_2 = ptr_2->next;//遍历
        i++;//记录删除了几个
    }
    printf("\n+++++++++++++++++%d+++++++++++++++++\n",i);
    return head;

}//删除链表

int main()
{
    while(1)//死循环
    {
    Main * head = Init();
    Input(head);//输入
    head = Insert(head);//插入
    Input(head);
    head = deletes(head);//删除节点
    Input(head);
    head = dellinlis(head);//删除链表
    printf("%d",head->a);
    printf("-------------------------------\n");
    }

    return 0;
}



















































//typedef struct _node
//{
//
//    int id;
//    char name[20];
//    int std_num;
//    struct _node * next;
//} Node;
//
//Node stdu[] =
//{
//    {1,"青牙",201701,NULL},
//    {2,"会歌",201702,NULL},
//    {3,"空格",201703,NULL},
//    {4,"流汗",201704,NULL},
//    {5,"里欧",201705,NULL},
//};
//
//Node * finds(Node * stdu,int index);//按学号查询学生
//
//Node Inits();//初始化
//
//int main()
//{
//    int index;
//
//    Inits();
//    printf("请输入要查找的学号：");
//    scanf("%d",&index);
//    Node * ptr_fin = finds(&stdu[0],index);
//    if(ptr_fin == NULL)
//    {
//        printf("\n没有找到！！！\n");
//        system("pause");
//        return 0;
//    }
//    printf("\n学号为%d的学生详细信息为:");
//    printf("\nID:%d\tnaem:%s\tstd_num:%d\n",ptr_fin->id,ptr_fin->name,ptr_fin->std_num);
//    system("pause");
//    return 0;
//}
//
//Node Inits()
//{
//    stdu[0].next = &stdu[1];
//    stdu[1].next = &stdu[2];
//    stdu[2].next = &stdu[3];
//    stdu[3].next = &stdu[4];
//    stdu[4].next = &stdu[5];
//    stdu[5].next = NULL;//初始化链表
//
//}
//
//
//Node * finds(Node * stdu,int index)
//{
//    Node * ptr_js = stdu;
//    while(ptr_js != NULL)
//    {
//        if(ptr_js->std_num == index)//判断是否为要找的学号
//        {
//            return ptr_js;//如果是，返回地址
//        }
//        ptr_js = ptr_js->next;//遍历
//    }
//
//    return NULL;//没找到返回空
//}
