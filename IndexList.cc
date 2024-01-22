#include <iostream>
using namespace std;

#define MAX_SIZE 100

typedef struct list {
    int array[MAX_SIZE];
    int size = 0;
} list;

int insertList(list * p, int value) {
    if (p->size == MAX_SIZE) {
        printf("List full! \n");
        return 0;
    }
    if (p->size == 0) {
        p->array[p->size] = value;
        p->size++;
        return 1;
    } else {
        p->array[p->size] = value;
        p->size++;
        return 1;
    }
}

int removeList(list * p, int removedValue) {
    if (p->size == 0) {
        printf("Empty list! \n");
        return 0;
    }
    int i = 0;
    for (i = 0; i < p->size; i++) {
        if (p->array[i] == removedValue) {
            break;
        }
    }
    if (i == p->size && p->array[i] != removedValue) {
        printf("Value not found! \n");
        return 0;
    }
    for (; i < p->size - 1; i++) {
        p->array[i] = p->array[i + 1];
    }
    p->size--;
    printf("The removed value was [%d]\n", removedValue);
    return removedValue;
}

int printList(list * p) {
    if (p->size == 0) {
        printf("Empty list! \n");
        return 0;
    }
    for (int i = 0; i < p->size; i++) {
        printf("[%d]-> ", p->array[i]);
    }
    printf("\n");
}

int main() {
    list * p = new list;
    int add = 0;
    int navigator = 0;
    int removed_value;

    while (true) {
        printf("Welcome to your list! To view your list, enter '1'. To insert a value into your list, enter '2'. To remove an element from your list, enter '3', and to exit, enter '4'\n");
        scanf("%d", &navigator);
        while (navigator != 1 && navigator != 2 && navigator != 3 && navigator != 4) {
            printf("You did not provide a valid option! Please try again \n");
            scanf("%d", &navigator);
        }
        if (navigator == 1) {
            if (p->size == 0) {
                printf("Your list is empty! \n");
            } else {
                printf("You chose to view the list!\n ");
                printList(p);
            }
        }
        if (navigator == 2) {
            printf("You chose to insert! Please insert the number below: \n");
            scanf("%d", &add);
            insertList(p, add);
        }
        if (navigator == 3) {
            printf("You chose to remove an element, please insert the element to be removed! \n ");
            scanf("%d", &removed_value);
            removeList(p, removed_value);
        }
        if (navigator == 4) {
            printf("You chose to exit the list! \n");
            break;
        }
    }
}
