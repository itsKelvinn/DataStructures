#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char name[30];
    data *next = NULL;
};

data *table[5] = {NULL};

// Constructor 
data *newNode(char *name){
    data *newNode = (data*)malloc(sizeof(data));
    strcpy(newNode->name,name);
    newNode->next = NULL;
    return newNode;
}

// hashKey
int hashKey(char *name){
    return name[0] % 5;
}


// Insert
data *insertData(data *curr , char *name){
    if(curr == NULL){
        return newNode(name);
    }
    else{
        curr->next = insertData(curr->next,name);
    }
}

void insert(char *name){
    int key = hashKey(name);
    table[key] = insertData(table[key],name);
}

// Delete
data *removeData(data *curr ,char *name){
    if(curr != NULL && strcmp(curr->name,name)){
        data *temp = curr;
        curr = curr->next;
        free(temp);
        temp = NULL;
        return curr;
    }
    else{
        curr->next = removeData(curr->next,name);
    }
}

void del(char *name){
    int key = hashKey(name);
    table[key] = removeData(table[key],name); 
}

// Search
void search(char *name){
    int key = hashKey(name);
    data *curr = table[key];
    int index = 0;
    
    while(curr != NULL && strcmp(curr->name,name) != 0){
        index++;
        curr = curr->next;
    }

    printf("Lokasi Value berada di table[%d] pada index %d\n",key,index);

}

// display
void display(){
    for(int i = 0; i < 5; i++){
        data *curr = table[i];
        printf("Table Key [%d] : ",i);

        if (table[i] == NULL){
            printf("[Table Null]");
        }

        while(curr != NULL){
            printf("%s",curr->name);

            if(curr->next != NULL){
                printf(" -> ");
            }
            curr = curr->next;
        }
        puts("");
    }
}

// Delete all data 
data *delAllData(data *curr){
    if(curr == NULL){
        return curr;
    }
    else{
        curr->next = delAllData(curr->next);
        curr = NULL;
        free(curr);
        return curr;
    }
}

void delAll(){
    for(int i = 0; i < 5; i++){
        table[i] = delAllData(table[i]);
        printf("done\n");
    }
}

// Main 
int main(){
    insert("Kelvin");
    insert("Kevin");
    insert("Kobo");
    insert("Marvin");
    insert("Melisa");
    insert("Manda");
    insert("Dedi");
    insert("Danjis");
    insert("Dadu");
    delAll();
    display();

    search("Kelvin");

    
    return 0;
}
