#include<stdio.h>

#define OK 1
#define ERROR 0
#define TURE 1
#define FLAST 0
#define MAXSIZE 255

typedef int Status;
typedef char String[MAXSIZE+1];

//�����û���������鸳ֵ������ȡ��#ֹͣ
Status ScanfString(String S) {
    int i = 0;
    char c;
    scanf("%c", &c);
    if(c == '\n')
    scanf("%c", &c);
    while(c != '#') {
        S[++i] = c;
        scanf("%c", &c);
    }
    S[0] = i;
    return OK;
}

Status get_next(String S, int *next) {
    int i, j; //jΪ�����Ӧλ���������±�+1����iΪ������
    j = 1;
    i = 0;
    next[1] = 0;
    while(j < S[0]) {
        if(i == 0 || S[j] == S[i]) {
            next[++j]=++i;
        }else
        i = next[i];
    }
    return OK;
}

int Index(String S, String T, int pos)//SΪ������TΪ�Ӵ�
{
    int i = pos;
    int j = 1;
    int next[32];
    get_next(T, next);
    while(i <= S[0] && j <= T[0]) {
        if(j == 0 || S[i] == T[j]) {
            i++;
            j++;
        }else
        {
            j = next[j];
        }
    }
    if(j > T[0])
    return i-T[0];
    else
    return 0;
}

int main() {
    int x = -1;
    int i = 0;
    String S;
    String T;
    printf("�������ı�:\n");
    ScanfString(S);
    printf("%d", S[0]);
    printf("����������ҵ���:\n");
    ScanfString(T);
    while(1) {
        i++;
        x = Index(S, T, x+1);
        if(!x)
        break;
        printf("���ʵ�%d�γ������ı��е�%d������%d���ַ���\n", i, x-1, x+T[0]);
    }

    return OK;
}
