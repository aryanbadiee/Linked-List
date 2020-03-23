#include <stdio.h>
#include <conio.h>
#include "linked_list.h"


int main() {
    List list = create_list();  // create new linked list

    // append items:
    for(int i=0;i < 120000000;i++){
        append(&list, i % 10000000);  // value = 0 until 9999999
    }

    // find value by index:
    int value = find_with_index(&list, 3);  
    printf("%i\n", value);

    // find index by value (just first cell):
    int index = find_one(&list, 1000000);
    if(index != -1){
        printf("%i\n", index);
    }else{
        printf("Not Found!\n");
    }

    // find indexes by value (all cells that match with value):
    int *indexes = find_all(&list, 15);
    int i = 0;
    while(indexes[i] != -1){  // end of indexes, there is -1 that means at end of array
        printf("%i, ", indexes[i]);
        i++;
    }
    printf("\n");
    
    // count of cells:
    printf("%i\n", lenght(&list));  

    // free memory:
    free_mem(&list);  

    getch();  // wait here!
}
