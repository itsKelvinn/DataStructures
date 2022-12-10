#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int num;
    node *left = NULL;
    node *right = NULL;
};

node *root;

// constructor
node *newNode(int num){
    node *newNode = new node();
    newNode->num = num;
    return newNode;
}

// insert
node *insertNode(node *curr,int num){
    if(curr == NULL){
        curr = newNode(num);
    }
    else if(curr->num > num){
        curr->left = insertNode(curr->left,num);
    }
    else if(curr->num < num){
        curr->right = insertNode(curr->right,num);
    }
    return curr;
}

void insert(int num){
    root = insertNode(root,num);
}

// delete
node *delNode(node *curr, int num){
    if(curr != NULL && curr->num == num){
        node *temp = curr;
        if(curr->left != NULL){
            printf("left");
            curr = curr->left;
        }
        else if(curr->right != NULL){
            printf("right");
            curr = curr->right;
        }
        free(temp);
        temp = NULL;
    }
    else if(curr->num > num){
        curr->left = delNode(curr->left,num);
    }
    else if(curr->num < num){
        curr->right = delNode(curr->right,num);
    }
    
    return curr;
}

void del(int num){
    root = delNode(root,num);
}

// Display 
void inOrder(node *curr){
    if(curr != NULL){
        inOrder(curr->left);
        printf("%d\n",curr->num);
        inOrder(curr->right);
    }
    return;
}

void pre_Order(node *curr){
    if(curr != NULL){
        printf("%d\n",curr->num);
        pre_Order(curr->left);
        pre_Order(curr->right);
    }
    return;
}

void post_Order(node *curr){
    if(curr != NULL){
        post_Order(curr->left);
        post_Order(curr->right);
        printf("%d\n",curr->num);
    }
}

int main(){
    insert(50);
    insert(20);
    insert(15);
    insert(13);
    insert(10);
    insert(40);
    insert(17);
    insert(56);
    insert(80);
    insert(86);
    insert(87);
    insert(54);
    insert(67);
    insert(83);

    del(56);

    inOrder(root);
}
