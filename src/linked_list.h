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
    struct Cell *before;
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
    cell->before = NULL;

    return cell;
}

bool append(struct LinkedList *linked_list, int value) {
    struct Cell *cell = __new_cell(value);  // every time create new cell with new address 
    linked_list->count++;  // increase count of cells

    if(linked_list->first == NULL && linked_list->last == NULL) {
        linked_list->first = cell;  // point to first cell
        linked_list->last = cell;
    }else {
        linked_list->last->next = cell;  // old last cell connects to next cell in linked list
        cell->before = linked_list->last;  // new cell connects to before cell in linked list
        linked_list->last = cell;  // point to last cell

        linked_list->last->next =  linked_list->first;  // 'next' of last cell point to first cell
        linked_list->first->before = linked_list->last;  // 'before' of first cell point to last cell
    }

    return True;
}

struct Cell * __next_cell(struct LinkedList *linked_list, int cell_index) {
    /*
        this structure is private don't use it out of this file
    */
    if(cell_index >= lenght(linked_list)) {  // if cell_index over than count of cells, we pass 'NULL'
        return NULL;
    }

    struct Cell *cell = linked_list->first;
    int i = 0;
    int loop = 0;
    while(i < cell_index) {
        if(cell != linked_list->first){
            cell = cell->next;
        }else {
            loop++;
            if(loop > 1) {
                return NULL;
            }
            cell = cell->next;
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
    int loop = 0;
    while(i < count + 100) {
        if(cell != linked_list->first){
            void *keep = cell;
            cell = cell->next;
            free(keep);
        }else{
            loop++;
            if(loop > 1) {
                break;
            }
            void *keep = cell;
            cell = cell->next;
            free(keep);
        }
        i++;
    }

    linked_list->first = NULL;
    linked_list->last = NULL;
    linked_list->count = 0;
}
