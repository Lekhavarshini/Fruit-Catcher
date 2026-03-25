#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int basketX = WIDTH / 2;
int fruitX, fruitY;
int score = 0;
int speed = 120;

// Draw
void draw() {
    system("cls");

    for(int i=0;i<WIDTH;i++) printf("#");
    printf("\n");

    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {

            if(j==0 || j==WIDTH-1)
                printf("|");

            else if(i == HEIGHT-1 && (j == basketX || j == basketX-1 || j == basketX+1))
                printf("U");   // Basket

            else if(i == fruitY && j == fruitX)
                printf("O");   // Fruit

            else
                printf(" ");
        }
        printf("\n");
    }

    for(int i=0;i<WIDTH;i++) printf("#");
    printf("\nScore: %d\n", score);
}

// Input
void input() {
    if(_kbhit()) {
        char ch = _getch();

        if(ch == 'a' && basketX > 2)
            basketX--;

        if(ch == 'd' && basketX < WIDTH-3)
            basketX++;
    }
}

// Logic
int logic() {

    fruitY++;

    // Catch fruit
    if(fruitY == HEIGHT-1 &&
       (fruitX == basketX || fruitX == basketX-1 || fruitX == basketX+1)) {

        score++;
        fruitY = 0;
        fruitX = rand() % (WIDTH-2) + 1;

        // Increase speed
        if(score % 3 == 0 && speed > 40)
            speed -= 10;
    }

    // Miss fruit
    if(fruitY >= HEIGHT) {
        return 1; // Game over
    }

    return 0;
}

int main() {
    srand(time(0));

    fruitX = rand() % (WIDTH-2) + 1;
    fruitY = 0;

    while(1) {
        draw();
        input();

        if(logic()) {
            printf("\n YOU MISSED THE FRUIT \n");
            printf("Final Score: %d\n", score);
            break;
        }

        Sleep(speed);
    }

    return 0;
}