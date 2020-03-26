#include <stdio.h>
#include <conio.h>
#include "c_linked_list.h"

int main(void) {
    CList clist = create_list();  // create new circle linked list

    // append items:
    for(int i=0;i < 120000000;i++){
        append(&clist, i % 10000000);  // value = 0 until 9999999
    }

    // find value by index:
    int value = find_with_index(&clist, 3);  
    printf("%i\n", value);

    // find index by value (just first cell):
    int index = find_one(&clist, 1000000);
    if(index != -1){
        printf("%i\n", index);
    }else{
        printf("Not Found!\n");
    }

    // find indexes by value (all cells that match with value):
    int *indexes = find_all(&clist, 15);
    int i = 0;
    while(indexes[i] != -1){  // end of indexes, there is -1 that means at end of array
        printf("%i, ", indexes[i]);
        i++;
    }
    printf("\n");

    // update value of a cell with index:
    bool result = update_with_index(&clist, 10, 3);  // index = 10 , new_value = 0
    // top expression return True(1) if the value of cell was changed. if not return False(0)
    if(result)
        printf("updated.\n");
    else
        printf("didn't update!\n");
    printf("%i\n", find_with_index(&clist, 10));  // show value of cell that updated(or not)

    // update value of cell with old value(just one):
    index = update_one(&clist, 3000, 3);  // old_value = 3000 , new_value = 3
    if(index != -1)
        printf("updated and index of cell is: %i\n", index);
    else
        printf("didn't update!\n");

    // update value of cells with old value(as much as possible):
    indexes = update_all(&clist, 30, 3);  // old_value = 30 , new_value = 3
    i = 0;
    printf("index of cells that was updated: ");
    while(indexes[i] != -1) {
        printf("%i, ", indexes[i]);
        i++;
    }
    printf("\n");

    // count of cells:
    printf("%i\n", lenght(&clist));  

    // free memory:
    free_mem(&clist);  

    getch();  // wait here!
    return 0;
}
