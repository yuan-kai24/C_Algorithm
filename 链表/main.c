#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct _main
{
    int a;//������
    struct _main *next;//ָ����
}Main;//��ʼ���ṹ

Main * Init()
{
    Main *head,*ptr_1,*ptr_2;
    ptr_1 = (Main*)malloc(sizeof(Main));
    scanf("%d",&ptr_1->a);//��Ȼptr_1��ָ��������Բ���ȡ��ַ����ptr_1->a����
    head =  ptr_2 = ptr_1;

    while(ptr_1->a != 0)//���ǰһ������0ֹͣ¼�룬���㻹��¼����
    {
        ptr_1 = (Main*)malloc(sizeof(Main));
        scanf("%d",&ptr_1->a);
        ptr_2->next = ptr_1;
        ptr_2 = ptr_1;//������һ��������
    }
    ptr_2->next = NULL;//ĩβa=0ָ���

    return head;

    /*
    ĩβ����ֱ�ӵ��ڿգ�����a=0��next=NULL
    ���ڵ�ײ���
    */
}//��ʼ������

void Input(Main * head)
{
    Main*ptr_1 = head;
    while(ptr_1->next != NULL)
    {
        printf("\t%d\n",ptr_1->a);
        ptr_1 = ptr_1->next;//����
    }

    /*
    ��û�����a=0�Ľڵ�
    */
}//�����ӡ

Main * Insert(Main * head)
{
    Main * ptr_fin = head;//����head��ֵ
    Main * adsr = (Main *)malloc(sizeof(Main));
    printf("������ڵ������");
    scanf("%d",&adsr->a);
    adsr->next = NULL;//���ղ���������ָ����ָ
    if(adsr->a < ptr_fin->a)
    {
        adsr->next = ptr_fin;
        head = adsr;

    }//��λ���룬������ڵ�Ϊ��λ��ֱ�Ӳ���
    else
        {
            /*
            ĩβ�Ľڵ��a��¼��ʱΪ�㣬nextΪnull�����ô�����
            */
        Main * ptr_fin2 = ptr_fin;//�˷������Բ��øı��ʼ������headֵ
        int flag = 0;
        while(ptr_fin2->next->next != NULL)//��a=0��ף�ѭ��
        {
                if(ptr_fin2->next->a > adsr->a)
                {
                    adsr->next = ptr_fin2->next;//�û���������ڻ��Ǹ������ĸ��壬��ָ����Ҫ�����ǰһ���ڵ�ָ���λ��
                    ptr_fin2->next = adsr;//�ٰ�ǰһ���ڵ�ָ����
                    flag = 1;//�ж��Ƿ��Ѿ�����
                    break;
                }//�м���룬��˳��
            ptr_fin2 = ptr_fin2->next;
        }//�����ж�
        if(flag == 0)
        {
            adsr->next = ptr_fin2->next;//���յ�׵Ľڵ㣬ԭ��ͬ��
            ptr_fin2->next = adsr;

        }//ĩβ����
    }


    return head;
}//����ڵ�

Main * deletes(Main * head)
{
    Main * ptr_fin = head;
    int num;
    printf("\n��������Ҫɾ���ı�ţ�");
    scanf("%d",&num);//¼��

    if(num == ptr_fin->a)
    {

        head = ptr_fin->next;//ֱ��ָ����һ������
        free(ptr_fin);//�ͷ�ԭ����
    }//��λɾ��
    else
    {
        Main * ptr_fin2 = ptr_fin;
        int flag = 0;
        while(ptr_fin2->next->next != NULL)
        {
            if(num == ptr_fin2->next->a)
            {
                ptr_fin2->next = ptr_fin2->next->next;//���ڵ�ָ����һ���ڵ����һ���ڵ�����
                free(&ptr_fin2->next);//�ͷ���һ���ڵ㣨���ҵĽڵ㣩
                flag = 1;
                break;
            }
            ptr_fin2 = ptr_fin2->next;
        }
        if(flag == 0)
        {
            printf("û���ҵ�Ҫɾ���Ľڵ�\n");
        }
    }

    return head;

}

Main * dellinlis(Main * head)
{
    int i = 1;
    Main * ptr_1 = head;
    Main * ptr_2 = ptr_1->next;//������һ���ڵ�
    while(ptr_2 != NULL)
    {
        free(ptr_1);
        ptr_1 = ptr_2;//��¼��һ���ڵ�
        ptr_2 = ptr_2->next;//����
        i++;//��¼ɾ���˼���
    }
    printf("\n+++++++++++++++++%d+++++++++++++++++\n",i);
    return head;

}//ɾ������

int main()
{
    while(1)//��ѭ��
    {
    Main * head = Init();
    Input(head);//����
    head = Insert(head);//����
    Input(head);
    head = deletes(head);//ɾ���ڵ�
    Input(head);
    head = dellinlis(head);//ɾ������
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
//    {1,"����",201701,NULL},
//    {2,"���",201702,NULL},
//    {3,"�ո�",201703,NULL},
//    {4,"����",201704,NULL},
//    {5,"��ŷ",201705,NULL},
//};
//
//Node * finds(Node * stdu,int index);//��ѧ�Ų�ѯѧ��
//
//Node Inits();//��ʼ��
//
//int main()
//{
//    int index;
//
//    Inits();
//    printf("������Ҫ���ҵ�ѧ�ţ�");
//    scanf("%d",&index);
//    Node * ptr_fin = finds(&stdu[0],index);
//    if(ptr_fin == NULL)
//    {
//        printf("\nû���ҵ�������\n");
//        system("pause");
//        return 0;
//    }
//    printf("\nѧ��Ϊ%d��ѧ����ϸ��ϢΪ:");
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
//    stdu[5].next = NULL;//��ʼ������
//
//}
//
//
//Node * finds(Node * stdu,int index)
//{
//    Node * ptr_js = stdu;
//    while(ptr_js != NULL)
//    {
//        if(ptr_js->std_num == index)//�ж��Ƿ�ΪҪ�ҵ�ѧ��
//        {
//            return ptr_js;//����ǣ����ص�ַ
//        }
//        ptr_js = ptr_js->next;//����
//    }
//
//    return NULL;//û�ҵ����ؿ�
//}
