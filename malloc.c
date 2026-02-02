#include <stdio.h>
#include <stdlib.h>
int main(){

    int *arr;
    int days = 0;

    printf("분석할 영업일수를 입력하세요: ");
    scanf("%d", &days);

    arr = (int*)malloc(sizeof(int) * days);
    
    if(arr == NULL){
        printf("메모리가 부족합니다!\n");
        return 1;
    }

    for(int i = 0; i < days; i++){
        printf("%d일차 매출: " , i+1);
        scanf("%d", &arr[i]);
    }

    printf("--분석결과--\n");

    float avg = 0;
    int sum = 0;
    for(int i = 0; i < days; i++){
        sum += arr[i];
        avg = sum/days ;
    }

    printf("평균매출: %.1f원\n",avg);

    for(int i = 0; i < days; i++){
        if(avg > arr[i]){
            printf("[경고] %d일차 매출 부진 (%d원)\n", i+1,arr[i]);
        }
    }

    free(arr);
    
    return 0;
}