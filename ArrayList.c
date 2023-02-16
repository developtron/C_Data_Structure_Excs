#include <stdio.h>
#include "ArrayList.h"

/*
typedef struct __ArrayList {
    LData arr[LIST_LENGTH];
    int num_of_data;
    int current_pos;
}   ArrayList;
*/
void ListInit(List* plist) {
    plist->num_of_data = 0;
    plist->current_pos = -1;
}

void LInsert(List* plist, LData data) {
    if(plist->arr == NULL || plist->num_of_data < 0) {
        printf("NULL Pointer Exception 또는 IndexOutofBound");
        return;        
    }

    if(plist->num_of_data >= LIST_LENGTH) {
        puts("더 이상 저장이 불가능합니다.");
        return;
    }

    plist->arr[(plist->num_of_data)++] = data;        
}

int LFirst(List* plist, LData* pdata) {
    if(plist->arr == NULL)
        return FALSE;

    plist->current_pos = 0;
    *pdata = plist->arr[0];
    return TRUE;
}

int LNext(List* plist, LData* pdata) {
    if(plist->current_pos >= (plist->num_of_data - 1))
        return FALSE;
    
    *pdata = plist->arr[++(plist->current_pos)];
    return TRUE;
}
 
LData LRemove(List* plist) {
    if(plist->num_of_data <= 0) {
        printf("빈 리스트입니다.");
        return FALSE;
    }

    (plist->current_pos)--;
    (plist->num_of_data)--;
    LData removing_data = plist->arr[plist->current_pos];
    
    int i = 0;
    for(i = plist->current_pos; i < plist->num_of_data - 1; i++) {
        plist->arr[i] = plist->arr[i+1];
    }

    return removing_data;
}

int LCount(List* plist) {
    return plist->num_of_data;
};

