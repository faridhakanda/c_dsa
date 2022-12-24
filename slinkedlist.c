// single linked list implemantation using c language

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int data;
    Node *next;
};

Node *create_list(int A[], int n) {
    int i;
    Node *head = NULL, *temp = NULL, *current = NULL;
    for (i = 0; i < n; i++) {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = A[i];
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            current = temp;
        } else {
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}

void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insert_begining(Node *head, int data) {
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = data;
    current->next = head;
    head = current;
    print_list(head);
}

void insert_end(Node *head, int data) {
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    current->next = node;
    current = node;
    print_list(head);
}
void insert_middle(Node *head, int position, int data) {
    Node *current = head;
    int index = 0;
    while (current != NULL) {
        index++;
        if (index == position) {
            Node *node = (Node *)malloc(sizeof(Node));
            node->data = data;
            node->next = current->next;
            current->next = node;
        }
        current = current->next;
    }
    print_list(head);
}

void delete_before(Node *head) {
    Node *current = (Node *)malloc(sizeof(Node));
    current = head;
    head = head->next;
    free(current);
    print_list(head);
}

void delete_end(Node *head) {
    Node *current, *temp;
    current = head;
    while (current->next != NULL) {
        temp = current;
        current = current->next;
    }
    temp->next = NULL;
    free(current);
    print_list(head);
}

void delete_middle(Node *head, int data) {
    Node *current = (Node *)malloc(sizeof(Node));
    current->next = head;
    Node *temp = current;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            temp->next = temp->next->next;
            break;
        } else {
            temp = temp->next;
        }
    }
    free(current);
    print_list(head);
}

int search(Node *head, int data) {
    int i = 0;
    while (head != NULL) {
        if (head->data == data) {
            return i;
        }
        i++;
        head = head->next;
    }
    return -1;
}

void reverse(Node *head) {
    Node *next = NULL, *prev = NULL;
    while (head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    print_list(head);
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;
    Node *head;
    head = create_list(A, n);
    print_list(head);

    insert_begining(head, 111);
    insert_end(head, 233);
    insert_middle(head, 2, 383);

    //delete_before(head);
    delete_end(head);
    delete_middle(head, 3);

    printf("Index is: %d\n", search(head, 5));
    reverse(head);

    return 0;
}