// Linked List Created by Aryan Badiee

#define True 1
#define False 0
#define bool char

#include <stdlib.h>
#include <stdio.h>

struct LinkedList {
    /*
        this structure is private don't use it out of this file
    */
    struct Cell *first;
    struct Cell *last;
    int count;
};

struct Cell {
    /*
        this structure is private don't use it out of this file
    */
    int value;
    struct Cell *next;
};

struct LinkedList create_list() {
    struct LinkedList linked_list;
    linked_list.first = NULL;
    linked_list.last = NULL;
    linked_list.count = 0;
    return linked_list;
}

int lenght(struct LinkedList *linked_list) {
    return linked_list->count;
}

struct Cell * __new_cell(int value) {
    /*
        this function is private don't use it out of this file
    */
    struct Cell *cell;
    cell = malloc(sizeof(struct Cell));
    cell->value = value;
    cell->next = NULL;

    return cell;
}

bool append(struct LinkedList *linked_list, int value) {
    struct Cell *cell = __new_cell(value);  // every time create new cell with new address 
    linked_list->count++;  // increase count of cells

    if(linked_list->first == NULL && linked_list->last == NULL) {
        linked_list->first = cell;  // point to first cell
        linked_list->last = cell;
    }else {
        linked_list->last->next = cell;  // connect to next cell in linked list 
        linked_list->last = cell;  // point to last cell
    }

    return True;
}

struct Cell * __next_cell(struct LinkedList *linked_list, int cell_index) {
    /*
        this structure is private don't use it out of this file
    */
    struct Cell *cell = linked_list->first;
    int i = 0;
    while(i < cell_index) {
        if(cell != NULL){
            cell = cell->next;
        }else {
            break;
        }
        i++;
    }

    return cell;
}

int find_with_index(struct LinkedList *linked_list, int cell_index) {
    struct Cell *cell = __next_cell(linked_list, cell_index);
    if(cell == NULL) {
        printf("Not Found This Cell! - index error");
        return 0;
    }

    int value = cell->value;
    return value;
}

void free_mem(struct LinkedList *linked_list) {
    struct Cell *cell = linked_list->first;

    int count = lenght(linked_list);
    int i = 0;
    while(i < count) {
        if(cell != NULL){
            void *keep = cell;
            cell = cell->next;
            free(keep);
        }else{
            break;
        }
        i++;
    }

    linked_list->first = NULL;
    linked_list->last = NULL;
    linked_list->count = 0;
}
