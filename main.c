#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define mw 60
#define mh 40


int kub[] = {20,30, 5,5};
char map[mh][mw];

void setcurs(){
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ikub(){
    for(int i = 0;i < kub[2];i++){
        for(int j = 0;j < kub[3];j++){
            map[kub[0]-i][kub[1]+j] = '@';
        }
    }
}

void init(){
    for(int i = 0;i < mh;i++){
        for(int j = 0;j< mw;j++){
            if(i == 0 || i == mh-1){
                map[i][j] = '#';
            }else if(j == 0 || j == mw-1){
                map[i][j] = '#';
            }else{
                map[i][j] = ' ';
            }
        }
    }
}

void draw(){
    for(int i = 0;i < mh;i++){
        for(int j = 0;j< mw;j++){
            printf(" %c", map[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int yyy = 0;
    int upp = 0;
    while(GetKeyState(VK_ESCAPE) >= 0){
    if ((upp == 0)&&(yyy < 10)){
        yyy++;
        kub[0] = kub[0]++;
    }
    if(yyy == 10){
        yyy = 0;
        upp = 1;
    }
    if((upp == 1)&&(yyy < 10)){
        yyy++;
        kub[0] = kub[0]--;
    }
    if((upp == 1)&&(yyy == 10)){
        upp = 0;
        yyy = 0;
    }
    system("cls");
    setcurs();
    init();
    ikub();
    draw();
    //Sleep(10);
    }
    system("pause");
}