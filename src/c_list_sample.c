#include <stdio.h>
#include <conio.h>
#include "c_linked_list.h"

int main(void) {
    CList clist = create_list();  // create new circle linked list

    // append items:
    for(int i=0;i < 120000000;i++){
        append(&clist, i % 10000000);  // value = 0 until 9999999
    }
    printf("Attached.\n");

    // find value by index:
    int value = find_with_index(&clist, 3);  
    printf("find_with_index: %i\n", value);

    // find index by value (just first cell):
    int index = find_one(&clist, 1000000);
    if(index != -1){
        printf("find_one: %i\n", index);
    }else{
        printf("find_one: Not Found!\n");
    }

    // find indexes by value (all cells that match with value):
    int *indexes = find_all(&clist, 15);
    int i = 0;
    printf("find_all: ");
    while(indexes[i] != -1){  // end of indexes, there is -1 that means at end of array
        printf("%i, ", indexes[i]);
        i++;
    }
    printf("\n");

    // update value of a cell with index:
    bool result = update_with_index(&clist, 10, 3);  // index = 10 , new_value = 0
    // top expression return True(1) if the value of cell was changed. if not return False(0)
    if(result)
        printf("update_with_index: updated.\n");
    else
        printf("update_with_index: didn't update!\n");
    printf("update_with_index: %i\n", find_with_index(&clist, 10));  // show value of cell that updated(or not)

    // update value of cell with old value(just one):
    index = update_one(&clist, 3000, 3);  // old_value = 3000 , new_value = 3
    if(index != -1)
        printf("update_on: updated and index of cell is: %i\n", index);
    else
        printf("update_on: didn't update!\n");

    // update value of cells with old value(as much as possible):
    indexes = update_all(&clist, 30, 3);  // old_value = 30 , new_value = 3
    i = 0;
    printf("index of cells that was updated: ");
    while(indexes[i] != -1) {
        printf("%i, ", indexes[i]);
        i++;
    }
    printf("\n");

    // remove a cell with index:
    result = remove_with_index(&clist, 9999);  // index = 9999
    if(result)
        printf("remove_with_index: removed.\n");
        
    else
        printf("remove_with_index: didn't remove!\n");

    // remove a cell with value(just one):
    result = remove_one(&clist, 9999999);  // value = 119999999
    if(result)
        printf("remove_one: removed.\n");
        
    else
        printf("remove_one: didn't remove!\n");

    // count of cells:
    printf("lenght: %i\n", lenght(&clist));

    // free memory:
    free_mem(&clist);
    printf("memory cleared.");

    getch();  // wait here!
    return 0;
}
