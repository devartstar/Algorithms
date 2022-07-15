#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void display(struct node *head) {
    struct node *ptr = head;
    while(ptr != NULL) {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void insert_at_begin(struct node** head, int data) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = *head;
    *head = ptr;
}

void insert_at_end(struct node *head, int data) {
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void insert_at_pos(struct node *head, int data, int pos) {
    struct node *ptr = head, *ptr2;
    ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->next = NULL;
    
    pos--;
    while(pos != 1) {
        ptr = ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;
}

void delete_at_begin(struct node **head) {
    if(*head == NULL) {
        cout<<"List empty"<<endl;
        return;
    }
    struct node *ptr = *head;
    *head = ptr->next;
    free(ptr);
    ptr = NULL;
}

void delete_at_pos(struct node **head, int pos) {
    struct node *prev, *curr;
    prev = curr = *head;
    // current -> node we want to delete
    // prev -> node before we want to delete
    if(*head == NULL) {
        cout<<"List Empty"<<endl;
        return;
    } else if(pos == 1) {
        *head = curr->next;
        free(curr);
        curr = NULL;
    } else {
        while(pos != 1) {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        free(curr);
        curr = NULL;
    }
}

int main() {
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 27;
    head->next = NULL;
    insert_at_end(head, 67);
    insert_at_end(head, 34);
    insert_at_end(head, 56);
    insert_at_end(head, 12);    
    insert_at_end(head, 24);
    insert_at_begin(&head, 30);
    // should have 23 at position 4
    insert_at_pos(head, 23, 4);
    //display(head);
    delete_at_begin(&head);
    //display(head);
    delete_at_pos(&head, 2);
    //display(head);
}
