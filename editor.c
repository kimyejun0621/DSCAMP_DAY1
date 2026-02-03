#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//기존 문자열 입력하기.

//노드 구조체 정의하기.
typedef struct Node{
    char data;
    struct Node *prev;
    struct Node *next;
} Node;

//노드 새롭게 만들기
Node* createNode(char data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
} 

int main(){
    char str[100000];
    scanf("%s",str);

    //더미 노드 생성하기
    //맨 앞에 커서가 있어도 왼쪽 노드가 존재하게 하기 위해서 
    Node* head = createNode('|');
    Node* cursor = head;

    int len = strlen(str);
    for(int i = 0; i < len; i++){
        Node* newNode = createNode(str[i]);

        //연결로직작성
        newNode -> prev = cursor;
        cursor -> next = newNode;
        cursor = newNode;

        //숫자 작성
        int M;
        scanf("%d", &M);

        for(int i = 0; i < M; i++){
            char cmd;
            scanf(" %c",&cmd);

            if (cmd == 'L'){
                if(cursor != head){
                    cursor = cursor ->prev;
                }
            }

            else if(cmd == 'D'){
                if(cursor->next != head){
                    cursor = cursor -> next;
                }
            }

            else if(cmd == 'B'){
                if(cursor != head){
                    Node* toDelete = cursor;
                    cursor = toDelete->prev;
                    
                    Node* rightNode = toDelete ->next;
                    cursor -> next = rightNode;

                    if(rightNode != NULL){
                        rightNode->prev = cursor;
                    }
                    free(toDelete);
                }
            }

            else if(cmd =='P'){
                char c;
                scanf(" %c", &c);
                Node* newNode = createNode(c);
                
                //새노드 위치 잡기
                Node* rightNode = cursor -> next;// 원래 커서 오른쪽에 있었던
                newNode->prev = cursor;
                newNode->next = rightNode;

                //기존꺼 새걸로 바꿔주기
                   newNode->prev = cursor;
                if(rightNode != NULL){
                    rightNode->prev = newNode;
                }

                //커서 위치 업데이트 해주기 
                cursor = newNode;
            }
        }

        Node *p = head -> next;
        while(p != NULL){
            printf("%c",p->data);
            p = p-> next;
        }
        printf("\n");

        return 0;
    }
}