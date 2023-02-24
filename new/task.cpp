#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
int x,y;
int timer;
int score;
string enemydirection="Down";
string enemydirection2="Right";
string enemyDirection3="Left";
void instructions();
int menu();
void enemy1Bullet();
void logo();
void printmaze();
void printtank();
void printenemy();
void movetankleft();
void movetankright();
void movetankup();
void movetankdown();
void erasetank();
void moveenemy();
void eraseenemy();
void printenemy2();
void moveenemy2();
void eraseenemy2();
void printbullet(int x,int y);
void erasebullet(int x,int y);
void generatebullet();
void movebullet();
void makebulletinactive(int index);
void bulletcollisionwithenemy();
void addscore();
void printscore();
char getCharAtxy(short int x,short int y);
void gotoxy(int x,int y);
void moveEnemy1Bullet();
void printEnemy3();
void moveEnemy3();
void eraseEnemy3();
void printmaze()
{
    cout << "*********************************************************************************" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;
    cout << "*********************************************************************************" << endl;
}
// player character
char box=219;
char tank1[6]={box,box,box,'-','-','>'};
char tank2[6]={'0',' ','0',' ',' ',' '};
// enemy character
char enemy1[6]={' ',' ',' ','-','-','-'};
char enemy2[6]={'<','=','=','(', '-', ')'};
char enemy3[6]={' ',' ',' ','\\','@','/'};
char enemy4[6]={' ',' ',' ','*','*','*'};
// enemy 2 character
char enemy5[5] = {' ',' ','o',' ',' '};
char enemy6[5] = {'-','-',box,'-','-'};
// enemy3 character

char enemy31[5] = {' ', '0', ' ', ' ', ' '};
char enemy32[5] = {' ', '=', ' ', ' ', ' '};
char enemy33[5] = {'|', ' ', '|', ' ', ' '};
char enemy34[5] = {'-', ' ', '-', ' ', ' '};
// player coordinates
int tankX=5;
int tankY=5;
// enemy coordinates
int enemyX=70;
int enemyY=10;
// enemy2 coordinates
int enemy1X=10;
int enemy1Y=2;
// enemy3coordinates
int enemy3X = 5;
int enemy3Y = 20;
// player bullets
int bulletX[100];
int bulletY[100];
bool isbulletactive[100];
int bulletcount=0;
// enemy 1 bullets
int index1 = 0;
int enemy1BulletX[1000];
int enemy1BulletY[1000];
// enemy bullet
void enemy1Bullet()
{
    int k = 2;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    enemy1BulletX[index1] = enemyX - 1;
    enemy1BulletY[index1] = enemyY + 1;
    gotoxy(enemy1BulletX[index1], enemy1BulletY[index1]);
    cout << '.';
    index1++;
}
void printtank()
{
    int k = 1;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(tankX,tankY);
    for(int idx=0;idx<6;idx++)
    {
        cout << tank1[idx];
    }
    gotoxy(tankX,tankY+1);
    for(int idx=0;idx<6;idx++)
    {
        cout << tank2[idx];
    }
}
void printEnemy3()
{
    int k = 4;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(enemy3X, enemy3Y);
    for (int n = 0; n < 5; n++)
    {
        cout << enemy31[n];
    }
    gotoxy(enemy3X, enemy3Y + 1);
    for (int n = 0; n < 5; n++)
    {
        cout << enemy32[n];
    }
    gotoxy(enemy3X, enemy3Y + 2);
    for (int n = 0; n < 5; n++)
    {
        cout << enemy33[n];
    }
    gotoxy(enemy3X, enemy3Y + 3);
    for (int n = 0; n < 5; n++)
    {
        cout << enemy34[n];
    }
}
void printenemy2()
{
    int k = 4;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(enemy1X,enemy1Y);
    for(int idx=0;idx<5;idx++)
    {
        cout << enemy5[idx];
    }
    gotoxy(enemy1X,enemy1Y+1);
    for(int idx=0;idx<5;idx++)
    {
        cout << enemy6[idx];
    }
}
void printenemy()
{
    int k = 4;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(enemyX,enemyY);
    for(int idx=0;idx<6;idx++)
    {
        cout << enemy1[idx];
    }
    gotoxy(enemyX,enemyY+1);
    for(int idx=0;idx<6;idx++)
    {
        cout << enemy2[idx];
    }
    gotoxy(enemyX,enemyY+2);
    for(int idx=0;idx<6;idx++)
    {
        cout << enemy3[idx];
    }
    gotoxy(enemyX,enemyY+3);
    for(int idx=0;idx<6;idx++)
    {
        cout << enemy4[idx];
    }
}
void movetankleft()
{
    char next=getCharAtxy(tankX-1,tankY);
    if(next==' ')
    {
        erasetank();
        tankX=tankX-1;
        printtank();
    }
}
void movetankright()
{
    char next=getCharAtxy(tankX+6,tankY);
    if(next==' ')
    {
        erasetank();
        tankX=tankX+1;
        printtank();
    }
}
void movetankup()
{
    char next=getCharAtxy(tankX,tankY-1);
    if(next==' ')
    {
        erasetank();
        tankY=tankY-1;
        printtank();
    }
}
void movetankdown()
{
    char next=getCharAtxy(tankX,tankY+2);
    if(next==' ')
    {
        erasetank();
        tankY=tankY+1;
        printtank();
    }
}
void erasetank()
{
    gotoxy(tankX,tankY);
    for(int idx=0;idx<6;idx++)
    {
        cout << " ";
    }
    gotoxy(tankX,tankY+1);
    for(int idx=0;idx<6;idx++)
    {
        cout << " ";
    }
}
void moveEnemy3()
{
    if (enemyDirection3 == "Left")
    {
        char next = getCharAtxy(enemy3X - 1, enemy3Y);
        if (next == ' ')
        {
            eraseEnemy3();
            enemy3X--;
            printEnemy3();
        }
        Sleep(100);
        if (next != ' ')
        {
            enemyDirection3 = "Right";
        }
    }
    if (enemyDirection3 == "Right")
    {
        char next = getCharAtxy(enemy3X + 6, enemy3Y);
        if (next == ' ')
        {
            eraseEnemy3();
            enemy3X++;
            printEnemy3();
        }
        Sleep(100);
        if (next != ' ')
        {
            enemyDirection3 = "Left";
        }
    }
}
void moveenemy2()
{
    if(enemydirection2=="Left")
    {
        char next=getCharAtxy(enemy1X+1,enemy1Y);
        if(next==' ')
        {
            eraseenemy2();
            enemy1X++;
            printenemy2();
        }
        if(next=='*')
        {
            enemydirection2="Right";
        }
    }
    if(enemydirection2=="Right")
    {
        char next=getCharAtxy(enemy1X-1,enemy1Y);
        if(next==' ')
        {
            eraseenemy2();
            enemy1X--;
            printenemy2();
        }
        if(next=='*')
        {
            enemydirection2="Left";
        }
    }
}
void moveenemy()
{
    if(enemydirection=="Up")
    {
        char next=getCharAtxy(enemyX,enemyY-1);
        if(next==' ')
        {
            eraseenemy();
            enemyY--;
            printenemy();
        }
        if(next=='*')
        {
            enemydirection="Down";
        }
    }
    if(enemydirection=="Down")
    {
        char next=getCharAtxy(enemyX,enemyY+4);
        if(next==' ')
        {
            eraseenemy();
            enemyY++;
            printenemy();
        }
        if(next=='*')
        {
            enemydirection="Up";
        }
    }
}
void eraseEnemy3()
{
    gotoxy(enemy3X, enemy3Y);
    for (int index = 0; index < 5; index++)
    {
        cout << " ";
    }
    gotoxy(enemy3X, enemy3Y + 1);
    for (int index = 0; index < 5; index++)
    {
        cout << " ";
    }
    gotoxy(enemy3X, enemy3Y + 2);
    for (int index = 0; index < 5; index++)
    {
        cout << " ";
    }
    gotoxy(enemy3X, enemy3Y + 3);
    for (int index = 0; index < 5; index++)
    {
        cout << " ";
    }
}
void eraseenemy2()
{
    gotoxy(enemy1X,enemy1Y);
    for(int idx=0;idx<5;idx++)
    {
        cout << " ";
    }
    gotoxy(enemy1X,enemy1Y+1);
    for(int idx=0;idx<5;idx++)
    {
        cout << " ";
    }
}
void eraseenemy()
{
    gotoxy(enemyX,enemyY);
    for(int idx=0;idx<6;idx++)
    {
        cout << " ";
    }
    gotoxy(enemyX,enemyY+1);
    for(int idx=0;idx<6;idx++)
    {
        cout << " ";
    }
    gotoxy(enemyX,enemyY+2);
    for(int idx=0;idx<6;idx++)
    {
        cout << " ";
    }
    gotoxy(enemyX,enemyY+3);
    for(int idx=0;idx<6;idx++)
    {
        cout << " ";
    }
}
void generatebullet()
{
    bulletX[bulletcount]=tankX+7;
    bulletY[bulletcount]=tankY;
    isbulletactive[bulletcount]=true;
    gotoxy(tankX+7,tankY);
    cout << ".";
    bulletcount++;
}
void printbullet(int x,int y)
{
    int k = 6;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(x,y);
    cout << "*";
}
void erasebullet(int x,int y)
{
    gotoxy(x,y);
    cout << " ";
}
void makebulletinactive(int index)
{
    isbulletactive[index]=false;
}
void movebullet()
{
    for(int x=0;x<bulletcount;x++)
    {
        if(isbulletactive[x]==true)
        {
            char next=getCharAtxy(bulletX[x]+1,bulletY[x]);
            if(next!=' ')
            {
                erasebullet(bulletX[x],bulletY[x]);
                makebulletinactive(x);
            }
            else 
            {
                erasebullet(bulletX[x],bulletY[x]);
                bulletX[x]=bulletX[x]+1;
                printbullet(bulletX[x],bulletY[x]);
            }
        }
    }
}
void bulletcollisionwithenemy()
{
    for(int x=0;x<bulletcount;x++)
    {
        if(isbulletactive[x]==true)
        {
            if(bulletX[x]+1==enemyX && (bulletY[x]==enemyY || bulletY[x]==enemyY+2 || bulletY[x]==enemyY+3))
            {
                addscore();
            }
            if(enemyX-1==bulletX[x] && enemyY+1==bulletY[x])
            {
                addscore();
            }
        }
    }
}
void addscore()
{
    score++;
}
void printscore()
{
    gotoxy(45,18);
    cout << "Score is:" << score;
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy ={0,0};
    SMALL_RECT rect={x,y,x,y};
    COORD coordBufSize;
    coordBufSize.X=1;
    coordBufSize.Y=1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),&ci,coordBufSize,xy,&rect) ? ci.Char.AsciiChar : ' ';
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X=x;
    coordinates.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
main()
{
    system("cls");
    logo();
    cout << endl
         << endl
         << endl;
    cout << "Enter any key to continue...." << endl;
    getch();
    system("cls");
    while(true)
    {
        int result=menu();
        if(result==1)
        {
            system("cls");
    printmaze();
    printtank();
    printenemy();
    printenemy2();
    printEnemy3();
    while(true)
    {
        printscore();
        if(GetAsyncKeyState(VK_LEFT))
        {
            movetankleft();
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            movetankright();
        }
        if(GetAsyncKeyState(VK_UP))
        {
            movetankup();
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            movetankdown();
        }
        if(GetAsyncKeyState(VK_SPACE))
        {
            generatebullet();
        }
        if(timer==3)
        {
            moveenemy();
            moveenemy2();
            enemy1Bullet();
            moveEnemy1Bullet();
            moveEnemy3();
            timer=0;
        }
        movebullet();
        bulletcollisionwithenemy();
        moveEnemy1Bullet();
        timer++;
        Sleep(90);
     }
        }
        if (result == 2)
        {
            system("cls");
            instructions();
            cout << endl
                 << endl
                 << endl;
            cout << "Enter any key to go back to main menu..." << endl;
            getch();
            menu();
        }
        if (result == 3)
        {
            system("cls");
            break;
        }
    }
}
void moveEnemy1Bullet()
{
    for (int i = 0; i < index1; i++)
    {
        char next = getCharAtxy(enemy1BulletX[i] - 1, enemy1BulletY[i]);
        if (next == ' ')
        {
            gotoxy(enemy1BulletX[i], enemy1BulletY[i]);
            cout << " ";
            enemy1BulletX[i]--;
            gotoxy(enemy1BulletX[i], enemy1BulletY[i]);
            cout << "-";
        }
        if ((next == '%') || (next == '.') || (next == '*') || (next == ')') || (next == '-'))
        {
            gotoxy(enemy1BulletX[i], enemy1BulletY[i]);
            cout << " ";
            for (int j; j < index1 - 1; j++)
            {
                enemy1BulletX[j] = enemy1BulletX[j + 1];
                enemy1BulletY[j] = enemy1BulletY[j + 1];
            }
            index1--;
        }
    }
}
void logo()
{
    int k = 5;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);

    cout << "________  __                                                ______                                     __                        " << endl;
    cout << "|        \\|  \\                                              |      \\                                   |  \\                      " << endl;
    cout << " \\$$$$$$$$| $$____    ______                                 \\$$$$$$ _______  __     __  ______    ____| $$  ______    ______    " << endl;
    cout << "   | $$   | $$    \\  /      \\                                 | $$  |       \\|  \\   /  \\|      \\  /      $$ /      \\  /      \\   " << endl;
    cout << "   | $$   | $$$$$$$\\|  $$$$$$\\                                | $$  | $$$$$$$\\$$\\ /  $$ \\$$$$$$\\|  $$$$$$$|  $$$$$$\\|  $$$$$$\\  " << endl;
    cout << "   | $$   | $$  | $$| $$    $$                                | $$  | $$  | $$ \\$$\\  $$ /      $$| $$  | $$| $$    $$| $$   \\$$  " << endl;
    cout << "   | $$   | $$  | $$| $$$$$$$$                               _| $$_ | $$  | $$  \\$$ $$ |  $$$$$$$| $$__| $$| $$$$$$$$| $$        " << endl;
    cout << "   | $$   | $$  | $$ \\$$     \\                              |   $$ \\| $$  | $$   \\$$$   \\$$    $$ \\$$    $$ \\$$     \\| $$        " << endl;
    cout << "    \\$$    \\$$   \\$$  \\$$$$$$$                               \\$$$$$$ \\$$   \\$$    \\$     \\$$$$$$$  \\$$$$$$$  \\$$$$$$$ \\$$        " << endl;
}
int menu()
{
    int k = 3;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    system("cls");
    int option;

    cout << "********************************************************************" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*            __      _____| | ___ ___  _ __ ___   ___              *" << endl;
    cout << "*            \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\      *" << endl;
    cout << "*             \\ V  V /  __/ | (_| (_) | | | | | |  __/            *" << endl;
    cout << "*              \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|       *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;

    cout << endl
         << endl;
    cout << "1- Start the game..." << endl;
    cout << "2- Instructions..." << endl;
    cout << "3- Exit..." << endl;
    cout << endl;
    cout << "Enter your option: " << endl;
    cin >> option;
    return option;
}
void instructions()
{
    cout << "For left movement----press LEFT arrow key" << endl;
    cout << "For right movement---press RIGHT arrow key" << endl;
    cout << "For up movement------press UP arrow key" << endl;
    cout << "For down movement----press DOWN arrow key" << endl;
    cout << "For firing ----------press SPACE key" << endl;
}