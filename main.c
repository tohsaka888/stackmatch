#include<stdio.h>
#include<malloc.h>

typedef struct Node {
    int data;//数据域
    struct Node *next;//指针域
}LinkStack;

void InitStack(LinkStack **S)
{
    (*S) = (LinkStack *)malloc(sizeof(LinkStack));
    (*S)->next = NULL;
}

/*入栈*/
void Push(LinkStack **S, char x)
{
    LinkStack *p;
    p = (LinkStack *)malloc(sizeof(LinkStack));
    p->data = x;//存入要入栈的信息
    p->next = (*S)->next;
    (*S)->next = p;

}

/*出栈*/
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
        *c = p->data;//返回栈顶的值
        (*S)->next = p->next;//栈顶位置变化
        free(p);//释放栈顶空间
    }
}

/*取栈顶元素*/
int GetTop(LinkStack **S,char *e)
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