#include <stdio.h>

int n;
int arr[100001] = {
    0,
};
int end = -1;
int command[10000000] = {
    0,
};
int nCommand = 0;
int toPush = 1;

void push();
int pop();
void print();

int main()
{
    scanf("%d", &n);
    int num;
    int temp = 0;
    int flag = 1;
    push();
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (arr[end] < num)
        {
            for (int j = toPush; j <= num; j++)
            {
                push();
            }
            pop();
        }
        else
        {
            temp = pop();
            if (temp != num)
            {
                flag = 0;
                break;
            }
        }
        // print();
    }
    if (flag)
    {
        int i = 0;
        while (command[i] == 1 || command[i] == -1)
        {
            if (command[i] == 1)
            {
                printf("+\n");
            }
            else
            {
                printf("-\n");
            }
            i++;
        }
    }
    else
    {
        printf("NO");
    }
    return 0;
}

void push()
{
    command[nCommand++] = 1;
    arr[++end] = toPush++;
}

int pop()
{
    command[nCommand++] = -1;
    int x = arr[end];
    arr[end--] = 0;
    return x;
}

void print()
{
    printf("arr : ");
    for (int i = 0; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}