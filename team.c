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
