// Linked List Created by Aryan Badiee
// https://www.github.com/aryanbadiee

#define True 1
#define False 0
#define bool char

#include <stdlib.h>
#include <stdio.h>

struct CLinkedList {
    /*
        this structure is private don't use it out of this file
    */
    struct Cell *first;
    struct Cell *last;
    int count;
}__attribute__((packed));  // optimize structure, but some compilers optimize automatically(remove padding inside from structure)

struct Cell {
    /*
        this structure is private don't use it out of this file
    */
    int value;
    struct Cell *next;
    struct Cell *before;
} __attribute__((packed));  // optimize structure, but some compilers optimize automatically(remove padding inside from structure)

struct CLinkedList create_list() {
    struct CLinkedList linked_list;
    linked_list.first = NULL;
    linked_list.last = NULL;
    linked_list.count = 0;
    return linked_list;
}

int lenght(struct CLinkedList *linked_list) {
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

bool append(struct CLinkedList *linked_list, int value) {
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

struct Cell * __next_cell(struct CLinkedList *linked_list, int cell_index) {
    /*
        this structure is private don't use it out of this file
    */
    if(cell_index >= lenght(linked_list) || cell_index < 0) {  // if cell_index over than count of cells or lower than zero, we pass 'NULL'
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

int find_with_index(struct CLinkedList *linked_list, int cell_index) {
    struct Cell *cell = __next_cell(linked_list, cell_index);
    if(cell == NULL) {
        printf("Not Found This Cell! - index error");
        return 0;
    }

    int value = cell->value;
    return value;
}

int find_one(struct CLinkedList *linked_list, int value) {
    /*
    find first cell with value and return index of the cell
    */
    int length_of_linked_list = lenght(linked_list);
    struct Cell *cell = linked_list->first;
    int index;  // index = 0
    do{
        if(cell->value == value)
            return index;  // return index of cell that we want ( 'if' with python format:)) )
        index++;
        cell = cell->next;
    }while(index < length_of_linked_list);

    return -1;  // not found!
}

int * find_all(struct CLinkedList *linked_list, int value) {
    /*
    find all cells with value and return array of indexes (there is -1 for end of array)
    */
    int length_of_linked_list = lenght(linked_list);
    struct Cell *cell = linked_list->first;
    int *array_of_indexes = malloc(sizeof(int));  // allocate 4 bytes at the first from memory
    int index = 0, count = 0;  // index for index of cell and count for what number of cells is equal to the value?
    *array_of_indexes = -1;  // if not found any cells
    do{
        if(cell->value == value){
            array_of_indexes[count] = index;
            count++;
            array_of_indexes = realloc(array_of_indexes, sizeof(int) * (count + 1));  // realloc size of array
            array_of_indexes[count] = -1;  // determining the end of the array
        }
        index++;
        cell = cell->next;
    }while(index < length_of_linked_list);

    return array_of_indexes;
}

bool update_with_index(struct CLinkedList *linked_list, int cell_index, int new_value) {
    /*
    update value of cell with index of cell and new value
    */
    struct Cell *cell = __next_cell(linked_list, cell_index);
    if(!cell) {  // not found any cell with this index
        return False;
    }
    cell->value = new_value;
    return True;
}

int update_one(struct CLinkedList *linked_list, int old_value, int new_value) {
    /*
    update value of cell with new value (just effects on the first match)
    */
    struct Cell *cell = linked_list->first;
    int lenght_of_linked_list = lenght(linked_list);
    int index;
    do{
        if(cell->value == old_value){
            cell->value = new_value;
            return index;  // return index of updated cell
        }
        index++;
        cell = cell->next;
    }while(index < lenght_of_linked_list);

    return -1;  // not found any cell with this old_value
}

int * update_all(struct CLinkedList *linked_list, int old_value, int new_value) {
    /*
    update value of cells with new value (effects on all matches) and return array of indexes (there is -1 for end of array)
    */
    struct Cell *cell = linked_list->first;
    int lenght_of_linked_list = lenght(linked_list);
    int index = 0 , count = 0;
    int *indexes = malloc(sizeof(int));
    *indexes = -1;
    do{
        if(cell->value == old_value){
            cell->value = new_value;  // set new value to cell 
            indexes[count] = index;
            count++;
            indexes = realloc(indexes, sizeof(int) * (count + 1));  // reallocation new space for indexes
            indexes[count] = -1;  // set -1 and the end of arrya of indexes
        }
        index++;
        cell = cell->next;
    }while(index < lenght_of_linked_list);

    return indexes;
}

bool remove_with_index(struct CLinkedList *linked_list, int cell_index) {
    /*
    remove cell with index and return True(1), if not return False(0) 
    */
    struct Cell *cell = __next_cell(linked_list, cell_index);
    if(cell == NULL) {
        return False;
    }
    
    cell->next->before = cell->before;  // next cell's before point to previous cell!
    cell->before->next = cell->next;  // previous cell's next point to next cell!
    free(cell);  // clean cell from memory
    return True;
}

void free_mem(struct CLinkedList *linked_list) {
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

typedef struct CLinkedList CList;  // defining 'List' type
