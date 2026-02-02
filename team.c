#include <stdio.h>
typedef struct{
    char name[20];
    int score;
} Student;

double get_average(Student *list,int count){
    int sum = 0;
    double avg = 0;

    for(int i = 0; i < count; i++){
        sum += list[i].score;
    }
    avg = (double)sum / count ;
    return avg;
}


void check(Student *list, int count){
    int sum = 0;
    double avg = 0;

    for(int i = 0; i < count; i++){
        sum += list[i].score;
    }
    avg = (double)sum / count ;

    for(int i = 0; i < count; i++){
        if(avg > list[i].score){
            printf("%s학생은 평균보다 낮습니다. 추가학습이 필요합니다.(%d)",list[i].name,list[i].score);
        }
    }
}
