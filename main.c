#include <stdio.h>
#include <stdlib.h>
#include"LinkList.h"

int main() {
    printf("*************************************************\n");
    printf("1�����ԭ�������������봴������\n");
    printf("2�����ԭ�������������һ����n�����ݵ�����\n");
    printf("3����ָ��λ�ò���һ������\n");
    printf("4��ɾ��ָ��λ�õ�һ������\n");
    printf("5�����������������\n");
    printf("6������ٶ��ҳ�������м�λ�������ֵ\n");
    printf("7���������Ԫ�ظ���\n");
    printf("8�������һ����ָ����ֵ��ͬ������Ԫ�ص�λ��\n");
    printf("9�����ָ��λ�õ�����\n");
    printf("0����������\n");
    printf("*************************************************\n\n");

    int x, n, i;
    ElemType e;
    Status y = 1;
    LinkList L;
    InitList(&L);

    while(y) {
        printf("��������Ҫִ�е�ѡ�");
        scanf("%d", &x);
        switch(x) {
            case 1:
	            y = ClearList(&L);
	            y = CreateList(&L);
	            break;
	        case 2:
	            ClearList(&L);
	            printf("���������������������ȣ�");
	            scanf("%d", &n);
	            y = CreateListTail(&L, n);
	            printf("%d", y);
	            break;
	        case 3:
	            printf("��������Ҫ��������ݼ�������λ��");
	            scanf("%d %d", &e, &i);
	            y = ListInsert(&L, i, e);
	            break;
	        case 4:
	            printf("��������Ҫɾ��������λ��");
	            scanf("%d", &i);
	            y = ListDelete(&L, i, &e);
	            break;
	        case 5:
	            if(ListEmpty(L) == 1)
	            printf("������Ϊ�ձ�\n");
	            else
	            ListTraverse(L);
	            break;
	        case 6:
	            if(ListEmpty(L) == 1)
	            printf("������Ϊ�ձ�\n");
	            else {
	                GetMidElem(L, &i, &e);
	                printf("��������м�λ��Ϊ%d����ֵΪ%d", i, e);
	            }
	            break;
	        case 7:
	            i = ListLength(L);
	            printf("��������Ϊ��%d\n", i);
	            break;
	        case 8:
	            if(ListEmpty(L) == 1)
	            printf("������Ϊ�ձ�\n");
	            else {
	                printf("��������Ҫ���ҵ�ֵ��");
	                scanf("%d", &e);
	                i = LocateElem(L, e);
	                printf("��һ����ָ����ֵ��ͬ������Ԫ�ص�λ����(0��ʾ�޽��)��%d", i);
	            }
	            break;
	        case 9:
	            if(ListEmpty(L) == 1)
	            printf("������Ϊ�ձ�\n");
	            else {
	                printf("��������Ҫ�����Ԫ��λ��");
	                scanf("%d", &i);
	                y = GetElem(L, i, &e);
	                printf("��Ӧλ�������Ϊ��%d", e);
	            }
	        	break;
	        case 0:
	            goto out;
	        default:
	            printf("�������\n");
        }
        if(!y)
        printf("����");
    }
    out:

    return 0;
}
