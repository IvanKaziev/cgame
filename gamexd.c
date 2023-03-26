#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

void setcur(int cx, int cy)
{
    COORD crd;
    crd.X = cx;
    crd.Y = cy;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
}

int main()
{
    char key;
    int i, y, x, player_x = 1, player_y = 1, money_x = 2, money_y = 2;
    int counter = 0, len, hg;
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    printf("Введите длину мира: ");
    scanf("%d", &len);
    printf("Введите высоту мира: ");
    scanf("%d", &hg);
    system("cls");

    char field[hg + 2][len + 2];

    do
    {
        for (y = 0; y < hg; y++)
        {
            for (x = 0; x < len; x++)
            {
                if (y == 0 || y == hg - 1)
                {
                    for (i = 0; i < len; i++) field[y][i] = '#';
                }
                if (y > 0 && y < hg)
                {
                    if (x == 0 || x == len - 1) field[y][x] = '#';
                    else field[y][x] = ' ';
                }
            }
            field[y][len] = '\0';
        }

        field[money_y][money_x] = '$';
        field[player_y][player_x] = '@';
        setcur(0, 0);
        Sleep(1);

        for (i = 0; i < hg; i++)
        {
            printf("%s\n", field[i]);
        }
        printf("Собрано денег: %d$", counter);
        key = getch();
        
        if (key == 'w') player_y--;
        if (key == 'a') player_x--;
        if (key == 's') player_y++;
        if (key == 'd') player_x++;

        if (player_x == 0) player_x++;
        if (player_x == len - 1) player_x--;
        if (player_y == 0) player_y++;
        if (player_y == hg - 1) player_y--;

        if (player_x == money_x && player_y == money_y)
        {
            counter++;
            money_x = 1 + rand() % (len - 3);
            money_y = 1 + rand() % (hg - 3);
        }
    }
    while (key != 'e');
}
