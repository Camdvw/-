#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0

#define MAXSIZE 100
#define MAXSIZE_BUF 10

typedef int SElemType;
typedef int Status;

//����˳��ջ 
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
}Stack;

//��ʼ��ջ 
Status InitStack(Stack *S) {
    S->top = -1;
    return OK;
}

//��ջ 
Status Push(Stack *S, SElemType e) {
    if(S->top == MAXSIZE-1)
    return ERROR;
    S->data[++S->top] = e;
    return OK;
}

//��ջ 
Status Pop(Stack *S, SElemType *e) {
    if(S->top == -1)
    return ERROR;
    *e = S->data[S->top--];
    return OK;
}

//���ջ��Ԫ�� 
Status GetTop(Stack S, SElemType *e) {
    if(S.top == -1)
    return ERROR;
    *e = S.data[S.top];
    return OK;
}

//���ջ��ָ��λ��Ԫ�� 
Status GetElem(Stack S, int i, SElemType *e) {
    if(S.top == -1)
    return ERROR;
    if(i < 1 || i > S.top+1)
    return ERROR;
    *e = S.data[i-1];
    return OK;
}

//��������������ȼ� 
int Priority(char c) {
    switch(c) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case ')': return 3;
        default: return -1;
    }
}

//��ջ�ױ������ջ��Ԫ�� 
Status StackTraverse(Stack S) {
    int i;
    for(i = 0; i <= S.top; i++) {
        printf("%c", S.data[i]);
    }
    return OK;
}

//��׺���ʽת��׺���ʽ
Status Conversion(Stack *S, Stack *L) {
    char c;
    SElemType e;

    printf("��������ʽ������'#'��������:\n");
    scanf("%c", &c);

    while(c != '#') {

        while(c >= '0' && c <= '9')//��������
        {
            Push(L, c);
            //printf("%c", c);
            scanf("%c", &c);
            if(c < '0' || c > '9') {
                Push(L, ' ');
                //printf(" ");
            }
        }

        if(c == '#')
        break;
        else if(Priority(c) == -1) {
            printf("\n���������ʽ����\n");
            return ERROR;
        }
        else if(S->top == -1 || c == '(')
        Push(S, c);
        else if(c == ')') {
            Pop(S, &e);
            while(e != '(') {
                //printf("%c ", e);
                Push(L, e);
                Push(L, ' ');
                Pop(S, &e);
            }
        }
        else if(Priority(c) >= Priority(S->data[S->top]))
        Push(S, c);
        else if(Priority(c) < Priority(S->data[S->top])) {
            while(S->top != -1) {
                Pop(S, &e);
                Push(L, e);
                Push(L, ' ');
                //printf("%c ", e);
            }
            Push(S, c);
        }

        scanf("%c", &c);
    }

    while(S->top != -1) {
        Pop(S, &e);
        Push(L, e);
        //printf("%c ", e);
    }

    return OK;
}

//�����׺���ʽ 
Status Count(Stack *S, Stack L) {
    int k, f, s;
    int i = 1;
    int j = 0;
    char buf[MAXSIZE_BUF];
    SElemType e;

    GetElem(L, i, &e);

    for(i; i <= L.top+1;) {

        while(e >= '0' && e <= '9')//�������� 
		{
            buf[j++] = e;
            buf[j] = '\0';
            if(j >= MAXSIZE_BUF) {
                printf("\n��ֵ��������Χ\n");
                return ERROR;
            }
            GetElem(L, ++i, &e);
            if(e == ' ') {
                k = atoi(buf);
                Push(S, k);
                j = 0;
                GetElem(L, ++i, &e);
            }
        }

        switch(e) {
            case '+':
            Pop(S, &s);
            Pop(S, &f);
            Push(S, f+s);
            break;
            case '-':
            Pop(S, &s);
            Pop(S, &f);
            Push(S, f-s);
            break;
            case '*':
            Pop(S, &s);
            Pop(S, &f);
            Push(S, f*s);
            break;
            case '/':
            Pop(S, &s);
            Pop(S, &f);
            if(f%s != 0) {
                printf("����������֧�ָ������");
                return ERROR;
            }
            else if(!s)
            printf("\n��������Ϊ0\n");
            else
            Push(S, f/s);
            break;
        }

        GetElem(L, ++i, &e);
    }

    Pop(S, &k);
    printf("������Ϊ��%d\n", k);

    return OK;
}

int main() {
    Stack s, l;
    Status t;
    InitStack(&s);
    InitStack(&l);
    t = Conversion(&s, &l);
    if(t)
    Count(&s, l);
    else
    return ERROR;
    return OK;
}
