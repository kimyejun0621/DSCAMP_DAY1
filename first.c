#include <stdio.h>
#include <string.h>
//1.문자열을 입력받는다.
//2. 한글자씩 뒤로 배치한다.(배열인덱스를 사용하지않고?)
void reverse_spell(char *str);

int main(){
    char spell[100];

    scanf("%s",spell);
    reverse_spell(spell);
    printf("%s",spell);
    return 0; 
}

void reverse_spell(char *str){
    int len = strlen(str);// str[len-1]
    char *start = str;
    char *end = str + len -1;
    char temp;

    while(start < end){
        temp = *start;
        *start = *end;
        *end = temp;

        start ++;
        end --;
    }

}
