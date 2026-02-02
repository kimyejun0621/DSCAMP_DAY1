#include <stdio.h>
typedef struct{
    char model[20];
    int temp;
} Boiler;

void heat_up(Boiler *b){
    b -> temp += 1;
    printf("현재온도: %d도(난방중..)\n", b->temp);
}

int main(){
    Boiler b = {"samsung",0};
    // Boiler *test = &b;
    for(int i = 0; i < 2; i++){
        heat_up(&b);
    }
}
