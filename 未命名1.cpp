#include<stdio.h>
#include<Windows.h>//��ֹ����һ������
#include<malloc.h>

typedef struct Node {
	int data;//������
	struct Node *next;//ָ����
}LinkStack;

void InitStack(LinkStack **S)
{
	(*S) = (LinkStack *)malloc(sizeof(LinkStack));
	(*S)->next = NULL;
}

/*��ջ*/
void Push(LinkStack **S, char x)
{
	LinkStack *p;
	p = (LinkStack *)malloc(sizeof(LinkStack));
	p->data = x;//����Ҫ��ջ����Ϣ
	p->next = (*S)->next;
	(*S)->next = p;

}

/*��ջ*/
int Pop(LinkStack **S, char *c)
{
	LinkStack *p=(*S)->next;
	if ((*S)->next == NULL)
	{
		printf("error\n");
		return 0;
	}
	else 
	{
		*c = p->data;//����ջ����ֵ
		(*S)->next = p->next;//ջ��λ�ñ仯
		free(p);//�ͷ�ջ���ռ�
	}
}

/*ȡջ��Ԫ��*/
int GetTop(LinkStack **S,char *e)//���ջ������ڲ��ı�ջ
{
	if ((*S)->next == NULL)
	{
		printf("error\n");
		exit(-1);
	}
	*e = (*S)->next->data;
}

int main()
{
	LinkStack *s;
    InitStack(&s);
    int i = 0;
    char str[128],e;
    printf("START:");
    gets(str);
    while (str[i]){
        if(str[i] == '('||str[i] == '['||str[i]=='{'){
            Push(&s,str[i]);
        }
        if(str[i] == ')') {
            GetTop(&s,&e);
            if (e == '(') {
                Pop(&s,&e);
            }else {
                printf("error");
                exit(-1);
            }
        } else if(str[i] == ']') {
            GetTop(&s,&e);
            if (e == '[') {
                Pop(&s,&e);
            }else {
                printf("error");
                exit(-1);
            }
        } else if(str[i] == '}') {
            GetTop(&s,&e);
            if (e == '{') {
                Pop(&s,&e);
            }else {
                printf("error");
                exit(-1);
            }
        }
        i++;
    }
    if(s->next) {
        printf("error");
    } else {
        printf("ok");
    }
	return 0;
}
