#include <iostream>
#include <conio.h>
#include "MyLibrary.h"
using namespace std;

const int MAX = 100;
int lengthOfSnake = 3;

void borderTop();
void borderBottom();
void borderLeft();
void borderRight();
void drawBorderGame();

void initSnake(int snakeX[], int snakeY[]);
void drawSnake(int snakeX[], int snakeY[]);
void removeOldSnake(int snakeX[], int snakeY[]);

void changeDirection(int &checkDirection, int &x, int &y);

void addToArray(int array[], int value);
void removeFromArray(int array[], int pos);
void snakeHandling(int snakeX[], int snakeY[], int headSnakeX, int headSnakeY, int &foodX, int &foodY);

bool checkSnakeTouchingTheBorder(int headSnakeX, int headSnakeY);
bool checkSnakeTouchingItsTail(int snakeX[], int snakeY[]);
bool checkGameOver(int snakeX[], int snakeY[]);

void drawFood(int &foodX, int &foodY, int snakeX[], int snakeY[]);
bool checkSpawnsFood(int foodX, int foodY, int snakeX[], int snakeY[]);
bool checkEatFood(int foodX, int foodY, int headSnakeX, int headSnakeY);

int main()
{
    srand(time(NULL));
    int playGame = 0;

    if (playGame == 0)
    {
        gotoXY(100, 10);
        do
        {
            cout << "\n\t\t\t\t\t\tMUON CHOI GAME KHONG?";
            cout << "\n\t\t\t\t\t\t1. CO\n\t\t\t\t\t\t0. KHONG";
            cout << "\n\t\t\t\t\t\tCHON DI: ";
            cin >> playGame;

            if (playGame != 1 && playGame != 0)
            {
                cout << "\nNhap sai roi nhap lai di.";
                Sleep(1000);
                system("cls");
            }
        } while (playGame != 1 && playGame != 0);
    }

    if (playGame == 1)
    {
        do
        {
            system("cls");
            lengthOfSnake = 3;
            int snakeX[MAX];
            int snakeY[MAX];

            bool gameOver = false;

            int changeColors = rand() % (15 - 1 + 1) + 1;
            SetColor(changeColors);
            drawBorderGame();

            initSnake(snakeX, snakeY);
            drawSnake(snakeX, snakeY);
            int x = 50;
            int y = 13;

            int checkDirection = 2; // Cho n?? m???c ?????nh l?? ??i qua ph???i
                                    /*
                                        check = 0 l?? ch???m bi??n tr??n -> ??i xu???ng
                                        check = 1 l?? ch???m bi??n d?????i -> ??i l??n
                                        check = 2 l?? ch???m bi??n tr??i -> ??i qua ph???i
                                        check = 3 l?? ch???m bi??n ph???i -> ??i qua tr??i
                                    */

            /*srand(time(NULL));*/
            int foodX = 0;
            int foodY = 0;

            drawFood(foodX, foodY, snakeX, snakeY);

            // ===========================================================================================

            while (gameOver == false)
            {
                // S??? d???ng backspace ????? x??a kh??ng b??? nh??y m??n nh?? system("cls")
                removeOldSnake(snakeX, snakeY);

                // ??i???u khi???n
                changeDirection(checkDirection, x, y);

                // X??? l?? di chuy???n c??c th???
                snakeHandling(snakeX, snakeY, x, y, foodX, foodY);

                // Kiem tra win or lose
                gameOver = checkGameOver(snakeX, snakeY);
                Sleep(70);
            }

            if (gameOver == true)
            {
                Sleep(1000);
                system("cls");
                SetColor(7);
                gotoXY(100, 10);
                cout << "\n\t\t\t\t\t\tBAN CHOI THUA ROI :)))";
                cout << "\n\t\t\t\t\t\tMUON CHOI NUA KHONG?";
                cout << "\n\t\t\t\t\t\t1. CO\n\t\t\t\t\t\t0. KHONG";
                cout << "\n\t\t\t\t\t\tCHON DI: ";
                cin >> playGame;
            }

        } while (playGame == 1);
    }

    if (playGame == 0)
    {
        cout << "\n\t\t\t\t\t\tBYE BYE BYE :)))";
    }

    // ===========================================================================================

    _getch();
    return 0;
}

void borderTop()
{
    int x = 10;
    int y = 1;
    while (x < 100)
    {
        gotoXY(x, y);
        cout << "+";
        x++;
    }
}

void borderBottom()
{
    int x = 10;
    int y = 26;
    while (x < 100)
    {
        gotoXY(x, y);
        cout << "+";
        x++;
    }
}

void borderLeft()
{
    int x = 10;
    int y = 1;
    while (y <= 26)
    {
        gotoXY(x, y);
        cout << "|";
        y++;
    }
}

void borderRight()
{
    int x = 100;
    int y = 1;
    while (y <= 26)
    {
        gotoXY(x, y);
        cout << "|";
        y++;
    }
}

void drawBorderGame()
{
    borderTop();
    borderBottom();
    borderLeft();
    borderRight();
}

void initSnake(int snakeX[], int snakeY[])
{
    int x = 50;
    int y = 13;
    // Cho con r???n ??? gi???a map t???a ????? con r???n (50, 13)
    for (int i = 0; i < lengthOfSnake; i++)
    {
        snakeX[i] = x;
        snakeY[i] = y;
        x--;
    }
}

void drawSnake(int snakeX[], int snakeY[])
{
    /*int changeColors = rand() % (15 - 1 + 1) + 1;
    SetColor(changeColors);*/
    for (int i = 0; i < lengthOfSnake; i++)
    {
        gotoXY(snakeX[i], snakeY[i]);

        if (i == 0)
            cout << "0";
        else
            cout << "o";
    }
}

void removeOldSnake(int snakeX[], int snakeY[]) // X??a b???ng backspace
{
    for (int i = 0; i < lengthOfSnake; i++)
    {
        gotoXY(snakeX[i], snakeY[i]);
        cout << " ";
    }
}

void addToArray(int array[], int value)
{
    for (int i = lengthOfSnake; i > 0; i--)
    {
        array[i] = array[i - 1];
    }

    array[0] = value;
    lengthOfSnake++;
}

void removeFromArray(int array[], int pos)
{
    for (int i = pos; i < lengthOfSnake; i++)
    {
        array[i] = array[i + 1];
    }

    lengthOfSnake--;
}

void snakeHandling(int snakeX[], int snakeY[], int headSnakeX, int headSnakeY, int &foodX, int &foodY) // x, y l?? t???a ????? m???i s??? th??m v??o ?????u m???ng (con r???n) khi di chuy???n
{
    // Th??m t???a ????? m???i cho m???ng
    addToArray(snakeX, headSnakeX);
    addToArray(snakeY, headSnakeY);

    if (checkEatFood(foodX, foodY, snakeX[0], snakeY[0]) == false) // R???n kh??ng ??n ????? ??n th?? x??a ??u??i l??c di chuy???n
    {
        // X??a t???a ????? cu???i m???ng
        removeFromArray(snakeX, lengthOfSnake - 1);
        removeFromArray(snakeY, lengthOfSnake - 1);
    }
    else
        drawFood(foodX, foodY, snakeX, snakeY);
    // N???u ??n th?? n?? d??i th??m kh???i x??a

    // V??? r???n
    drawSnake(snakeX, snakeY);
}

bool checkSnakeTouchingTheBorder(int headSnakeX, int headSnakeY)
{
    // Ch???m bi??n tr??n
    if (headSnakeY == 1 && (headSnakeX >= 10 && headSnakeX <= 100))
    {
        return true; // Game over
    }
    // Ch???m bi??n d?????i
    else if (headSnakeY == 26 && (headSnakeX >= 10 && headSnakeX <= 100))
    {
        return true; // Game over
    }
    // Ch???m bi??n tr??i
    else if (headSnakeX == 10 && (headSnakeY >= 1 && headSnakeY <= 26))
    {
        return true; // Game over
    }
    // Ch???m bi??n ph???i
    else if (headSnakeX == 100 && (headSnakeY >= 1 && headSnakeY <= 26))
    {
        return true; // Game over
    }

    return false;
}

bool checkSnakeTouchingItsTail(int snakeX[], int snakeY[])
{
    for (int i = 1; i < lengthOfSnake; i++)
    {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
            return true;
    }

    return false;
}

bool checkGameOver(int snakeX[], int snakeY[])
{
    bool gameOver1 = checkSnakeTouchingItsTail(snakeX, snakeY);
    bool gameOver2 = checkSnakeTouchingTheBorder(snakeX[0], snakeY[0]);

    if (gameOver1 == true || gameOver2 == true)
        return true;
    else
        return false;
}

void drawFood(int &foodX, int &foodY, int snakeX[], int snakeY[])
{
    do
    {
        // rand() % (b - a + 1) + a //Random S??? t??? a t???i b [a, b]
        foodX = rand() % (99 - 11 + 1) + 11;
        foodY = rand() % (25 - 2 + 1) + 2;

    } while (checkSpawnsFood(foodX, foodY, snakeX, snakeY) == true);

    int changeColors = rand() % (15 - 1 + 1) + 1;
    SetColor(changeColors);
    gotoXY(foodX, foodY);
    cout << "@";

    // SetColor(7); // 7 l?? m??u tr???ng (ch???nh con r???n v??? m??u tr???ng)
}

bool checkSpawnsFood(int foodX, int foodY, int snakeX[], int snakeY[])
{
    for (int i = 0; i < lengthOfSnake; i++)
    {
        if (foodX == snakeX[i] && foodY == snakeY[i])
        {
            // Ki???m tra coi ????? ??n n?? c?? hi???n ra tr??ng l??n con r???n kh??ng?,
            // kh??ng th?? ????? ??n t??ng h??nh
            return true;
        }
    }

    return false;
}

bool checkEatFood(int foodX, int foodY, int headSnakeX, int headSnakeY)
{
    if (foodX == headSnakeX && foodY == headSnakeY)
    {
        return true;
    }

    return false;
}

void changeDirection(int &checkDirection, int &x, int &y)
{
    if (_kbhit()) // H??m n??y nh???p t??? ph??m n?? s??? tr??? true c??n kh??ng nh???p g?? n?? tr??? false
    {
        char characterUserEnter = _getch();

        if (characterUserEnter == -32) // Ph??m m??i t??n l?? PH??M K??P n??n c?? 2 m?? ASCII, m?? chung l?? -32
        {
            characterUserEnter = _getch();

            if (characterUserEnter == 72 && checkDirection != 0) // ASCII c???a m??i t??n ??i L??N l?? 72
            {
                checkDirection = 1;
            }
            else if (characterUserEnter == 80 && checkDirection != 1) // ASCII c???a m??i t??n ??i XU???NG l?? 80
            {
                checkDirection = 0;
            }
            else if (characterUserEnter == 75 && checkDirection != 2) // ASCII c???a m??i t??n ??i TR??I l?? 75
            {
                checkDirection = 3;
            }
            else if (characterUserEnter == 77 && checkDirection != 3) // ASCII c???a m??i t??n ??i PH???I l?? 77
            {
                checkDirection = 2;
            }
        }
    }

    if (checkDirection == 0) //??i xu???ng
    {
        y++;
    }
    else if (checkDirection == 1) //??i l??n
    {
        y--;
    }
    else if (checkDirection == 2) //??i qua ph???i
    {
        x++;
    }
    else if (checkDirection == 3) //??i qua tr??i
    {
        x--;
    }
}