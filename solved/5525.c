#include <stdio.h>

int main()
{
    char S[1000001];
    char lastChar;
    int lastIndex;
    int cnt = 0;
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%s", S);

    int Icount = 0;
    int isOn = 0;
    int i = 0;

    while (i < M)
    {
        // printf("i:%d icount:%d\n", i, Icount);
        if (!isOn)
        {
            if (S[i] == 'I')
            {
                isOn = 1;
                i++;
                Icount = 1;
                lastChar = 'I';
            }
            else
            {
                i++;
            }
        }
        else
        {
            if (lastChar == 'I')
            {
                if (S[i] == 'O')
                {
                    i++;
                    lastChar = 'O';
                }
                else
                {
                    isOn = 0;
                    Icount = 0;
                }
            }
            else
            {
                if (S[i] == 'I')
                {
                    Icount++;
                    i++;
                    lastChar = 'I';
                }
                else
                {
                    i++;
                    isOn = 0;
                    Icount = 0;
                }
            }
        }

        if (Icount == N + 1)
        {
            // printf("%d %d %d\n", i, Icount, N);
            Icount--;
            cnt++;
        }
    }

    printf("%d", cnt);
}