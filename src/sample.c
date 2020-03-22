#include <stdio.h>
#include <conio.h>
#include "linked_list.h"


int main() {
    struct LinkedList linked_list = create_list();  // create new linked list

    // append items:
    for(int i=0;i < 120000000;i++){
        append(&linked_list, i);
    }

    int value = find_with_index(&linked_list, 3);  // find value by index 
    printf("%i\n", value);

    int index = find_one(&linked_list, 1000000000);  // find index by value (just first cell)
    if(index != -1){
        printf("%i\n", index);
    }else{
        printf("Not Found!\n");
    }
    

    printf("%i\n", lenght(&linked_list));  // count of cells

    free_mem(&linked_list);  // free memory

    getch();
}
