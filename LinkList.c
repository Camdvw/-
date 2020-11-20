#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include"LinkList.h"

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

//��ʼ��������
Status InitList(LinkList *L) {
    //����ͷ��㣬Ϊͷ�������ռ�
    *L = (LinkList)malloc(sizeof(Node));
    //�ж��洢�����Ƿ�ɹ�
    if(!(*L))
    return ERROR;
    (*L)->next = NULL; //()�����ȼ�����->��(*L)->next����ǿ����*L��һ������

    return OK;
}

//�ж��������Ƿ�Ϊ�ձ�
//��������LΪ�ձ���TRUE�����򷵻�FALSE
Status ListEmpty (LinkList L) {
    if(L->next)
    return FALSE;
    else
    return TURE;
}

//���������ÿ�
//��������L����Ϊ�ձ�
Status ClearList(LinkList *L) {
    LinkList p, r;
    //����*L��ͷ����λ�ã��뱣�����ʴ�(*L)->next��ʼɾ
    p = (*L)->next;

    while(p) {
        //�Ƚ�p->next����r��ɾ����㣬��֤����ʧ����ĺ��
        r = p->next;
        free(p); //�ͷ�p���ڵ�ǰ�����ڴ�
        p = r;
    }
    //�������н���ͷź󣬱�������ͷ���ָ���
    (*L)->next = NULL;

    return OK;
}

//��ȡ�����Ԫ�ظ���
//����������L������Ԫ�ظ���
int ListLength(LinkList L) {
    int i = 0;
    LinkList p;

    p = L->next; //ע�ⲻ�ܽ�ͷ���������
    //����ĳ���while(p->next)�ᵼ�����һ����㲻������
    while(p) {
        p = p->next;
        i++;
    }
    return i;
}

//��ȡָ��Ԫ��
//��������e����L�е�i������Ԫ��
Status GetElem(LinkList L, int i, ElemType *e) {
    int j = 1; //����p=L->next;�Ǵӵ�һ����㿪ʼ����j���1��ʼ����
    LinkList p;
    p = L->next;
    //��p��Ϊ�ջ������j��û����iʱ��ѭ������
    while(p && j < i) {
        p = p->next;
        j++;
    }
    //�ж���i��Ԫ���Ƿ����
    if(j > i||!p)
    return ERROR;
    *e = p->data;

    return OK;
}

//�ҵ���һ������ָ����ϵ��Ԫ�ص�λ��
//����������L�е�1����e�����ϵ��Ԫ��λ���������ڸ�Ԫ�أ��򷵻�0���˴���"��e���"Ϊ����
int LocateElem(LinkList L, ElemType e) {
    int i = 0;
    LinkList p;
    p = L->next;

    while(p) {
        i++;
        //��������p=p->next���ж�������i���ʵ��С1
        if(p->data == e)
        return i;
        p = p->next;
    }

    return 0;
}

//��ָ��λ�ò���Ԫ��
//��������L�е�i��λ��֮ǰ�����µ�����Ԫ��e
Status ListInsert(LinkList *L, int i, ElemType e) {
    //Ҫʹ������Ԫ�����������ŵ�iλ������ӵ�i-1λ�͵�iλ֮����룬���ص�Ӧ���ڵ�i-1λԪ����
    int j = 1;
    LinkList p, s;
    p=*L; //��ͬ��GetElem������p���ͷ��㿪ʼ������ʹp����ͣ���ڵ�i-1λԪ����

    while(p && j < i) {
        p = p->next;
        j++;
    }
    //�������ֻ������ǰһλ�Ƿ���ڣ������ж���i-1��Ԫ���Ƿ����
    if(!p || j > i)
    return ERROR;
    //Ϊ�½��s���붯̬�ڴ�
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    //�����������ɵ���������p->next=s;���ᵼ�¶�ʧ������
    s->next = p->next;
    p->next = s;

    return OK;
}

//ɾ��ָ��λ�õ�Ԫ��
//������ɾ��L�е�i������Ԫ�أ�����e������ֵ
Status ListDelete(LinkList *L, int i, ElemType *e) {
    //��ȻҪɾ����Ԫ���ǵ�i��Ԫ�أ�����Ҫ���ص���ڵ�i-1��Ԫ����
    int j = 1;
    LinkList p, q;
    p=*L; //����p���������ҵ���i-1��Ԫ�أ���p���ͷ��㿪ʼ
    //��ͬ��ListInsert������ɾ������������Ҫɾ����Ԫ���Ƿ���ڣ���Ҫ��p->next�Ƿ����Ϊ�ж���׼
    while(p->next && j < i) {
        j++;
        p = p->next;
    }
    //ͬ��Ҫ��p->next�Ƿ����Ϊ�ж���׼
    if(!(p->next) || j > i)
    return ERROR;
    //�����������ɵ���������ᵼ�¶�ʧ���
    q = p->next; //��ʱqΪ��i��Ԫ�أ�����Ҫ��ɾ����Ԫ��
    p->next = q->next;
    *e = q->data;
    free(q);

    return OK;
}

//���������������
//���������ζ�L��ÿ������Ԫ�����
Status ListTraverse(LinkList L) {
    LinkList p;
    p = L->next;

    while(p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");

    return OK;
}

//ͷ�巨����n�����ֵ������
//����������n�������Ԫ��ֵ�Ľ�㣬���δ�ͷ���֮���λ�ò����γ�����L
Status CreateListHead(LinkList *L, int n) {
    int i;
    LinkList p;
    srand(time(0)); //��ʼ�������
    //�Ƚ���һ��������
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    for(i = 1; i <= n; i++) {
        p = (LinkList)malloc(sizeof(Node)); //�����½��
        p->data = rand()%10+1; //�������һ��10���ڵ�����
        p->next = (*L)->next;
        (*L)->next = p; //���뵽��ͷ
    }

    return OK;
}

//β�巨����n�����ֵ������
//����������n�������Ԫ��ֵ�Ľ�㣬���νӵ���β��λ���γ�����
Status CreateListTail(LinkList *L, int n) {
    int i;
    LinkList p, q;
    srand(time(0));

    *L = (LinkList)malloc(sizeof(Node));
    q=*L;

    for(i = 1; i <= n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%10+1;
        q->next = p;
        q = p;
    }
    q->next = NULL; //�����������q->next = NULL;��ʹ��βָ��գ��ɶԿձ�ͷǿձ�����ͳһ������Ϊ���

    return OK;
}

//�����û����봴������
//������ÿ��ȡһ���û��������ֵ�㴴��һ����������һ�����֮�����û�����-1�����������
Status CreateList(LinkList *L) {
    int x = 1;
    LinkList p, q;

    *L = (LinkList)malloc(sizeof(Node));
    q=*L;
    printf("������Ҫ�洢������(����-1��Ϊֹͣ�洢)��");
    while(x != -1) {
        scanf("%d", &x);
        if(x == -1)
        break;
        p = (LinkList)malloc(sizeof(Node));
        q->next = p;
        p->data = x;
        q = p;
    }
    q->next = NULL;

    return OK;
}

//����ٶ��ҳ�������м�λ�������ֵ
//�������ÿ���ָ���ҳ�������м�λ�򽻸�i������ֵ����e
Status GetMidElem(LinkList L, int *i, ElemType *e) {
    int j = 0;
    LinkList fast, slow;
    fast = L;
    slow = L;

    while(fast->next != NULL) {
        if(fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }else
        {
            fast = fast->next; //��֤fastָ�����һ��Ԫ�أ�ʹ��������whileѭ��
        }
        j++;
    }

    *i = j;
    *e = slow->data;

    return OK;
}
