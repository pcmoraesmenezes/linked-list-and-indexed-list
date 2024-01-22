#include <iostream>
using namespace std;

typedef struct node {
    int value;
    node * next_node;
} node;

node * InitializeList() {
    node * head_node = new node;
    head_node->next_node = NULL;
    return head_node;
}

int InsertList(node * p, int value) {
    if (!p) {
        return -1;
    }
    node * new_node = new node;
    if (!new_node) {
        return -2;
    }
    new_node->value = value;
    new_node->next_node = p->next_node;
    p->next_node = new_node;
    return 1;
}

int RemoveList(node * p, int removedValue) {
    if (!p) {
        printf("List not initialized! \n");
        return -1;
    }
    if (!p->next_node) {
        printf("Empty list! \n");
        return -2;
    }
    node * previous = p;
    node * current = p->next_node;
    while (current != NULL && current->value != removedValue) {
        previous = current;
        current = current->next_node;
    }
    if (!current) {
        printf("Value not found! \n");
        return -3;
    }
    previous->next_node = current->next_node;
    delete current;
    return 1;
}

void PrintList(node * p) {
    if (!p) {
        printf("List not initialized \n");
        return;
    }
    node * current = p->next_node;
    if (!current) {
        printf("Empty list! \n");
        return;
    }
    while (current != NULL) {
        printf("[%d] -> ", current->value);
        current = current->next_node;
    }
    printf("\n");
}

int main() {
    node * p = InitializeList();
    int navigator;
    int add = 0;
    int remove = 0;
    while (true) {
        printf("Welcome to your list! To print the values on the screen, enter '1'. To add an element to your list, enter '2'. To remove an element of your choice, enter '3', and to exit the menu, enter '4' \n");
        scanf("%d", &navigator);
        while (navigator != 1 && navigator != 2 && navigator != 3 && navigator != 4) {
            printf("You did not provide a valid option! Please try again \n");
            scanf("%d", &navigator);
        }
        if (navigator == 1) {
            if (!p) {
                printf("Empty list! \n");
            }
            else {
                printf("You chose to view the list!\n ");
                PrintList(p);
            }
        }
        if (navigator == 2) {
            printf("You chose to insert! Please insert the number below: \n");
            scanf("%d", &add);
            InsertList(p, add);
        }
        if (navigator == 3) {
            if (!p) {
                printf("Empty list! \n");
            }
            else {
                printf("You chose to remove an element, please insert the element to be removed! \n ");
                scanf("%d", &remove);
                RemoveList(p, remove);
            }
        }
        if (navigator == 4) {
            printf("You chose to exit the list! \n");
            break;
        }
    }
}
