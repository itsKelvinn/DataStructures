#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
    char name[30];
    int id;

    data *next;
    data *prev;
};

data *head = NULL;
data *tail = NULL;

// Constructors
data *newData(char *name, int id){
    data *newData = (data*)malloc(sizeof(data));
    strcpy(newData->name,name);
    newData->id = id;
    newData->next = NULL;
    newData->prev = NULL;
    return newData;
}

// PushHead
void pushHead(char *name, int id){
    if(head == NULL){
        head = tail = newData(name,id);
    }
    else{
        data *temp = newData(name,id);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Inserting Function for pushHead
void InsertPushHead(){
    char name[30];
    int id;
    char op = 'n';
    while(op == 'n'){
        system("cls");
        printf("Name : ");
        scanf("%s",&name);
        getchar();

        printf("Id   : ");
        scanf("%d",&id);
        getchar();

        printf("Are u sure? (y/n): ");
        scanf("%c",&op);
        getchar();
    }
    
    pushHead(name,id);
}

// PushTail
void pushTail(char *name, int id){
    if(head == NULL){
        head = tail = newData(name,id);
    }
    else{
        data *temp = newData(name,id);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Inserting Function for pushTail
void InsertPushTail(){
    char name[30];
    int id;
    char op;
    while(op == 'n'){
        system("cls");
        printf("Name : ");
        scanf("%s",&name);
        getchar();
        
        printf("Id   : ");
        scanf("%d",&id);
        getchar();

        printf("Are u sure? (y/n): ");
        scanf("%c",&op);
        getchar();
    }
    
    pushTail(name,id);
}

// popHead
void popHead(){
    if(head == NULL){
        printf("There is no Head :(\n");
        printf("Back to menu (ENRTER)\n");
        getchar();
    }
    else{
        data *temp = head->next;
        temp->prev = NULL;
        head->next = NULL;
        free(head);
        head = temp;
    }
}

// popTail
void popTail(){
    if(tail == NULL){
        printf("There is no tail :(\n");
        printf("Back to menu (ENRTER)\n");
        getchar();
    }
    else{
        data *temp = tail->prev;
        tail->prev = NULL;
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

// popMid
void popMid(char *name){
    if(strcmp(head->name,name) == 0){
        popHead();
    }
    else if(strcmp(tail->name,name) == 0){
        popTail();
    }
    else{
        data *curr = head;
        while( curr->next != NULL && strcmp(curr->next->name,name) != 0){
            curr = curr->next;
        }

        if(curr->next != NULL && strcmp(curr->next->name,name) == 0){
            data *temp = curr->next;
            curr->next = temp->next;
            temp->next->prev = curr;
            temp->next = NULL;
            temp->prev = NULL;
            free(temp);
        }
        else{
            printf("We can find data that u want popMid() :(\n");
            printf("Back to menu (ENRTER)\n");
            getchar();
        }
    }
}

// Inserting for popMid
void InsertPopMid(){
    char name[30];
    char op;

    while(op == 'n'){
        printf("Name : ");
        scanf("%s",&name);
        getchar();

        printf("Are u sure ? (y/n): ");
        scanf("%c",&op);
        getchar();
    }

    popMid(name);
}

// PrintFromTail
void printFromTail(){
    printf("Print From Tail\n");
    printf("+==================================+\n");
    printf("|     Name        |       id       |\n");
    printf("+==================================+\n");
    data *curr = tail;
    while(curr != NULL){
    printf("|  %-10s     |    %5d       |\n",curr->name,curr->id);
        curr = curr->prev;
    }
    printf("+==================================+\n");

    char option;
    printf("Back to menu (ENRTER)\n");
    getchar();
}

// PrintFromHead
void printFromHead(){
    printf("Print From Head\n");
    printf("+==================================+\n");
    printf("|     Name        |       id       |\n");
    printf("+==================================+\n");
    data *curr = head;
    while(curr != NULL){
    printf("|  %-10s     |    %5d       |\n",curr->name,curr->id);
        curr = curr->next;
    }
    printf("+==================================+\n");

    char option;
    printf("Back to menu (ENRTER)\n");
    getchar();
}

// Menu
void menu(){
    printf("+========================+\n");
    printf("| =======  Menu  ======= |\n");
    printf("+========================+\n");
    printf("| 1 -> Push Head         |\n");
    printf("| 2 -> Push Tail         |\n");
    printf("| 3 -> Pop Head          |\n");
    printf("| 4 -> Pop Tail          |\n");
    printf("| 5 -> Pop Mid           |\n");
    printf("| 6 -> Print From Head   |\n");
    printf("| 7 -> Print From Tail   |\n");
    printf("| 8 -> Exit              |\n");
    printf("+========================+\n");
    printf("_> ");
}



int main(){
    pushHead("Kelvin",1);
    pushHead("Ollie",2);
    pushHead("Reine",3);
    pushHead("Moona",4);
    pushHead("Risu",15);
    

    int choice;
    while(true){
        menu();
        scanf("%d",&choice);
        getchar();
        switch (choice){
            case 1:
                InsertPushHead();
                system("cls");
                break;
            case 2:
                InsertPushTail();
                system("cls");
                break;
            case 3:
                system("cls");
                popHead();
                system("cls");
            case 4:
                system("cls");
                popTail();
                system("cls");
                break;
            case 5:
                system("cls");
                InsertPopMid();
                system("cls");
                break;
            case 6:
                system("cls");
                printFromHead();
                system("cls");
                break;
            case 7:
                system("cls");
                printFromTail();
                system("cls");
                break;
            case 8:
                system("cls");
                printf("See u later :)");
                return 1;
        }
    }
    
}