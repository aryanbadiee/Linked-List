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
    printf("find_with_index -> %i\n", value);

    // find index by value (just first cell):
    int index = find_one(&clist, 1000000);
    if(index != -1){
        printf("find_one -> %i\n", index);
    }else{
        printf("find_one -> Not Found!\n");
    }

    // find indexes by value (all cells that match with value):
    int *indexes = find_all(&clist, 15);
    int i = 0;
    printf("find_all -> ");
    while(indexes[i] != -1){  // end of indexes, there is -1 that means at end of array
        printf("%i, ", indexes[i]);
        i++;
    }
    printf("\n");

    // update value of a cell with index:
    bool result = update_with_index(&clist, 10, 3);  // index = 10 , new_value = 0
    // top expression return True(1) if the value of cell was changed. if not return False(0)
    if(result) {
        printf("update_with_index -> updated and new value is: ");
        printf("%i\n", find_with_index(&clist, 10));  // show value of cell that updated(or not)
    }
    else
        printf("update_with_index -> didn't update!\n");

    // update value of cell with old value(just one):
    index = update_one(&clist, 3000, 3);  // old_value = 3000 , new_value = 3
    if(index != -1)
        printf("update_one -> updated and index of cell is: %i\n", index);
    else
        printf("update_one -> didn't update!\n");

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
        printf("remove_with_index -> removed.\n");
        
    else
        printf("remove_with_index -> didn't remove!\n");

    // remove a cell with value(just one):
    result = remove_one(&clist, 9999999);  // value = 9999999
    if(result)
        printf("remove_one -> removed.\n");
        
    else
        printf("remove_one -> didn't remove!\n");

    // remove cells with value(any cell that possible):
    int count = remove_all(&clist, 333);  // value = 333
    if(count)
        printf("remove_all -> removed %i cell[s].\n", count);
    else
        printf("remove_all -> didn't remove any cell!\n");
    // 'remove_all' return 0 if didn't remove any cell.

    // count of cells:
    printf("lenght -> %i\n", lenght(&clist));

    // show cells with your desired count (if count=0 function show all cells)
    result = show(&clist, 1000);
    // 'result' is boolean variable (True(1) or False(0))

    // reverse linked list:
    reverse(&clist);
    printf("reverse -> %i\n", find_with_index(&clist, 0));

    // free memory:
    free_mem(&clist);
    printf("memory cleared.");

    getch();  // wait here!
    return 0;
}
