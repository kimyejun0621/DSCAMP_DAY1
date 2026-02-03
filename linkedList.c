//배열의 한계 
#include <stdio.h>
#include <stdlib.h>
// 배열: 다닥다닥 붙어있는 아파트. 메모리의 연속된 공간을 차지. > 중간에 넣고싶으면 모두 옆으로 밀어야함. 
// 링크드 리스트: 메모리 빈자리 아무데나 박히는거. 포인터로 지정해주는것임. 
// 

//노드 설계
//linked List 설계
struct Node {
    char songName;
    //다음 노드의 주소를 저장하는 포인터 영역. 
    struct Node *next ;
};

int main(){
    struct Node* head;
    head = addSong(head, "Drowning");
    head = addSong(head, "balckpink");
}

struct Node* addSong(struct Node* head, char* value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> songName = value;
    newNode -> next = NULL;

    //2. 만약 리스트가 비어있다면?
    if(head == NULL){
        return newNode; //새노트가 곧 head가 됨.
    }

    //3.리스트가 비어있지 않다면, 끝까지 이동
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;
    return head;
}

//현재 저장된 모든 곡을 순서대로 출력한다. >
void showPlaylist(struct Node* head){
    struct Node* curr = head;
    if(curr == NULL){
        printf("플리가 비어있습니다.");
    }
    
    int order = 1;
    while(curr != NULL){
        printf("%d. %s", order, curr->songName);
        curr = curr -> next;

        order++;
    }
    //
}

// struct Node* addFromHead(struct Node* head, int value){
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode -> data = value;

//     newNode -> next = head;
//     return newNode;

// }

// struct Node* removeNode(struct Node* head, int target){
//     if(head == NULL){
//         printf("리스트가 비어 있어 삭제할 수 없습니다.\n");
//         return NULL;
//     }

//     struct Node* curr = head;
//     struct Node* prev = NULL;

//     while (curr != NULL && curr->data != target){
//         prev = curr;
//         curr = curr -> next;
//     }

//     if(curr == NULL){
//         printf("값%d를 찾을 수 없습니다.\n",target);
//         return head;
//     }

//     if(prev == NULL){
//         head = curr -> next;
//     }
//     else{
//         prev -> next = curr -> next;
//     }

//     free(curr);
//     printf("노드 삭제완료", target);
//     return head
// }

// struct Node* insert Node(struct Node*head, int index, int value){
//     //노드 사이에 삽입,,
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode -> data = value;
    
//     if(index == 0){
//         newNode -> next = head;
//         return newNode;
//     }

//     struct Node* temp = head;
//     for(int i = 0; i < index - 1; i++){
//         if(temp == NULL){
//             printf("인덱스 범위를 벗어났습니다.\n");
//             free(newNode);
//             return head;
//         }
//         temp = temp -> next;
//     }
//     newNode -> next = temp -> next;
//     temp -> next = newNode;
// }

// void clearList(struct Node* head){
//     struct Node* curr = head;
//     struct Node* nextNode;
//     while(curr != NULL){
//         nextNode = curr -> next;
//         free(curr);
//         curr = nextNode;
//     }
// }