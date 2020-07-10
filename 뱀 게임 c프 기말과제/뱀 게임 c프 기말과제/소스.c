#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define UP 72

#define MAPWIDTH 29
#define MAPHEIGHT 29
#define SNAKELENGTH 17

typedef struct _body
{
    int x;
    int y;
}Body;

Body body[18][18];
Body Temp[18][18];

typedef struct _food
{
    int x;
    int y;
}Food;

Food food;
Food food2;




typedef struct _logic
{
    bool Up;
    bool Down;
    bool Right;
    bool Left;
}Logic;
Logic l;

int snake[18][18] =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1}
};

int map[29][29] =//원래 30이나 더 크게 할려고 했으나 창이 표시가 안되서 최대인 29로 함.
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void Map();
void Init();
void TempToBody();
void MoveCoor();

void BodyToTemp();
void Delete();
void Output();
void Move();

void FoodOutput();
void FoodOutput2();
void Eat();
void BodyPlus();
void Score();
void Score2();
void Clear();

void GameOver();
void GameExplain();

void gotoxy(int x, int y);
void CursorView(char show);//커서숨기기

char restart = 0;
static int score = 0;


void Map()
{
    int i, j;
    system("cls");
    
    for (i = 0; i < MAPHEIGHT; i++)
    {
        for (j = 0; j < MAPWIDTH; j++)
        {
            if (map[i][j] == 1)
                printf("■");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void Init()
{
    l.Up = false;
    l.Down = false;
    l.Right = false;
    l.Left = false;

    int i, j;
    
    

    restart = 0;
    score = 0;
    

    for (i = 0; i < 18; i++)

    {

        for (j = 0; j < 18; j++)

        {

            body[i][j].x = 0;

            body[i][j].y = 0;

            Temp[i][j].x = 0;

            Temp[i][j].y = 0;

            snake[i][j] = 0;

        }

    }

    i = j = 0;

    snake[17][17] = 1;

    snake[17][16] = 1;

    snake[17][15] = 1;


    body[17][17].x = 14;
    body[17][17].y = 14;

    body[17][16].x = 12;
    body[17][16].y = 14;

    body[17][15].x = 10;
    body[17][15].y = 14;
    

   
}

void TempToBody()
{
    int i, j;
    bool ExitOutLoop = false;

    for (i = 17; i >= 0; i--)
    {
        for (j = 17; j >= 0; j--)
        {
            if (snake[i][j] == 1)
            {
                Temp[i][j].x = body[i][j].x;
                Temp[i][j].y = body[i][j].y;
            }

            if (snake[i][j] == 0)
            {
                ExitOutLoop = true;
                break;
            }
        }

        if (ExitOutLoop == true)
        {
            ExitOutLoop = false;
            break;
        }
    }
}

void MoveCoor()
{

    if (l.Up == true)
    {
        TempToBody();
        body[17][17].y--;
        BodyToTemp();
    }

    if (l.Down == true)
    {
        TempToBody();
        body[17][17].y++;
        BodyToTemp();
    }

    if (l.Right == true)
    {
        TempToBody();
        body[17][17].x += 2;
        BodyToTemp();
    }

    if (l.Left == true)
    {
        TempToBody();
        body[17][17].x -= 2;
        BodyToTemp();
    }
}

void BodyToTemp()
{
    int i, j;
    bool ExitOutLoop = false;

    for (i = 17; i > 0; i--)
    {
        for (j = 17; j >= 0; j--)
        {
            if (snake[i][j] == 0 && j == 0)
            {
                body[i - 1][17].x = Temp[i][j].x;
                body[i - 1][17].y = Temp[i][j].y;
                ExitOutLoop = true;
                break;
            }

            body[i][j - 1].x = Temp[i][j].x;
            body[i][j - 1].y = Temp[i][j].y;
        }

        if (ExitOutLoop == true)
        {
            ExitOutLoop = false;
            break;
        }
    }
}

void Delete()
{
    int i, j;
    bool ExitOutLoop = false;

    for (i = 17; i >= 0; i--)
    {
        for (j = 17; j >= 0; j--)
        {
            if (snake[i][j] == 1)
            {
                gotoxy(body[i][j].x, body[i][j].y);
                printf("  ");
            }

            else
            {
                ExitOutLoop = true;
                break;
            }
        }

        if (ExitOutLoop == true)
        {
            ExitOutLoop = false;
            break;
        }
    }
}

void Output()
{
    int i, j;
    bool ExitOutLoop = false;

    for (i = 17; i >= 0; i--)
    {
        for (j = 17; j >= 0; j--)
        {
            if (snake[i][j] == 1)
            {
                gotoxy(body[i][j].x, body[i][j].y);
                printf("■");
            }

            else
            {
                ExitOutLoop = true;
                break;
            }
        }

        if (ExitOutLoop == true)
        {
            ExitOutLoop = false;
            break;
        }
    }
}

void Move()
{
    int Time = 150;
    
    while (1)
    {
        Sleep(Time);
        Delete();
        MoveCoor();
        Output();
        Eat();
        GameOver();
           
           
      if (_kbhit()||restart)
            break;
            
    }


}

void FoodOutput()
{
    int i, j;
    bool ExitOutLoop = false;



    food.x = (rand() % 18 + 1) * 2;
    food.y = rand() % 18 + 1;

    for (i = 17; i >= 0; i--)
    {
        for (j = 17; j >= 0; j--)
        {
            if (body[i][j].x == food.x && body[i][j].y == food.y)
            {
                food.x = (rand() % 18 + 1) * 2;
                food.y = rand() % 18 + 1;
            }
        }
    }

    gotoxy(food.x, food.y);
    printf("★");
}

void FoodOutput2()
{
    int i, j;
    bool ExitOutLoop = false;



    food2.x = (rand() % 18 + 1) * 2;
    food2.y = rand() % 18 + 1;

    for (i = 16; i >= 0; i--)
    {
        for (j = 16; j >= 0; j--)
        {
            if (body[i][j].x == food2.x && body[i][j].y == food2.y)
            {
                food2.x = (rand() % 18 + 1) * 2;
                food2.y = rand() % 18 + 1;
            }
        }
    }

    gotoxy(food2.x, food2.y);
    printf("●");
}

void Eat()
{
    if (body[17][17].x == food.x && body[17][17].y == food.y)
    {
        Score();
        BodyPlus();
        FoodOutput();
    }
    else if (body[17][17].x == food2.x && body[17][17].y == food2.y)
    {
        Score2();
        BodyPlus();
        FoodOutput2();
    }
}

void BodyPlus()
{
    int i, j;
    bool ExitOutLoop = false;

    for (i = 17; i >= 0; i--)
    {
        for (j = 17; j >= 0; j--)
        {
            if (snake[i][j] == 0)
            {
                snake[i][j] = 1;
                ExitOutLoop = true;
                break;
            }
        }

        if (ExitOutLoop == true)
        {
            ExitOutLoop = false;
            break;
        }
    }
}




void Score()
{

    score += 100;
    gotoxy(70, 20);
    printf("점수 : %d", score);
    if (score == 30000)
        Clear();
}

void Score2()
{
    score += 50;
    gotoxy(70, 20);
    printf("점수 : %d", score);
    if (score == 30000)
        Clear();
}



void GameOver()
{
    int i, j, a;
   
    
    if (body[17][17].x >= 56 || body[17][17].x <= 0)
    {
        system("cls");
        printf("게임 오버!\n");
        printf("점수는 %d입니다.\n", score);
        printf("다시하시겠습니다? (0/1) 0을 누르면 종료, 1을 누르면 재시작: ");
        scanf_s("%d", &a);      
        if (a == 1)
            restart = 1;
        else
            exit(0);
    }

    if (body[17][17].y >= 28 || body[17][17].y <= 0)
    {
        system("cls");
        printf("게임 오버\n");
        printf("점수는 %d입니다.\n", score);
        printf("다시하시겠습니다? (0/1) 0을 누르면 종료, 1을 누르면 재시작: ");
        scanf_s("%d", &a); 
        if (a == 1)
            restart = 1;
        else
        exit(0);
    }

    for (i = 17; i >= 0; i--)
    {
        for (j = 16; j >= 0; j--)
        {
            if (body[17][17].x == body[i][j].x &&
                body[17][17].y == body[i][j].y)
            {
                system("cls");
                printf("게임 오버\n");
                printf("점수는 %d입니다.\n", score);
                printf("다시하시겠습니다? (0/1) 0을 누르면 종료, 1을 누르면 재시작: ");
                scanf_s("%d", &a);   
                if (a == 1)
                    restart = 1;
                else
               exit(0);
            }
        }
    }
}

void GameExplain()
{
    gotoxy(70, 10);
    puts("처음엔 왼쪽키 안됨");

    gotoxy(70, 11);
    puts("이동은 방향키");

    gotoxy(70, 12);
    puts("머리가 몸이나 벽에 닿을시 게임오버");

    gotoxy(70, 13);
    puts("별은 +100점/ 원은 +50점");

    gotoxy(70, 14);
    puts("q누르면 게임종료/ 재시작 불가!");

}

void Clear()
{
    system("cls");
    printf("클리어");
    exit(0);
}



int main()

{

    int key;
    
    
        srand((unsigned int)(time(NULL)));
        
        while (1)
        {

        Map();

        CursorView(0);
        
        Init();               // init 함수 안에서 restart 변수를 0으로 초기화 해주는것 추가

        Output();

        FoodOutput();
        FoodOutput2();
                       
        while(!restart)
        
        {


            GameExplain();
            
            

            if (_kbhit())
            { 

                    key = _getch();
                    
                 
                    if (key == 'q')	// 이렇게 재시작에 대한 조건을 추가해서 while문을 빠져나갈 수 있도록 해줌
                        break;
                       
                    
                switch (key)

                {

                case UP:

                    if (l.Down == true)

                        l.Up = false;

                    else

                    {

                        l.Up = true;

                        l.Down = false;

                        l.Right = false;

                        l.Left = false;

                    }

                    Move();

                    break;

                case DOWN:

                    if (l.Up == true)

                        l.Down = false;

                    else

                    {

                        l.Down = true;

                        l.Up = false;

                        l.Right = false;

                        l.Left = false;

                    }

                    Move();

                    break;

                case LEFT:

                    if (body[17][17].x == 14 && body[17][17].y == 14)

                        l.Left = false;

                    else if (l.Right == true)

                        l.Left = false;

                    else

                    {

                        l.Left = true;

                        l.Down = false;

                        l.Right = false;

                        l.Up = false;

                    }

                    Move();

                    break;

                case RIGHT:

                    if (l.Left == true)

                        l.Right = false;

                    else

                    {

                        l.Right = true;

                        l.Down = false;

                        l.Up = false;

                        l.Left = false;

                    }

                    Move();

                    break;

                default:

                    break;

                }

            }



        }
        if (key == 'q')
        {
            gotoxy(0, 30);
            break;
        }


        
    }
    return  0;
}
 



void gotoxy(int x, int y)
{
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void CursorView(char show)//커서숨기기
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}