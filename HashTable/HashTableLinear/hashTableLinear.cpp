#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 5

struct data{
    char name[30];
    data *next = NULL;
};

data *table[SIZE] = {NULL};

data *newNode(char *name){
    data *newNode = new data();
    strcpy(newNode->name,name);
    return newNode;
}

int hashKey(char *name){
    return name[0] % SIZE;
}

void insert(char *name){
    int key = hashKey(name);
    if(table[key] == NULL){
        table[key] = newNode(name);
    }
    else{
        int keyHolder = (key + 1) % SIZE;
        while(table[keyHolder % 5] != NULL && keyHolder % SIZE != key){
            keyHolder++;
        }
        table[keyHolder] = newNode(name);
    }
}

void display(){
    for(int i = 0; i < SIZE; i++){
        printf("table[%d] : %s\n",i,table[i]->name);
    }
}

int main(){
    insert("Kelvin");
    insert("Kobo");
    insert("Kontol");
    display();
}