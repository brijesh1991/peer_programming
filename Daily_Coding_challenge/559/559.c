// read files

// iterate over the list

//sort the ll integrate to single ll
#include "559.h"


ll * convert_file_to_ll(char *str) {
    printf("\n\n%s\n\n",__FUNCTION__);
    FILE *fp= NULL;
    fp= fopen(str,"r");
    ll *lst = gen_ll();
    lst->data=10;
    int number;

    // Loop to read each number
    while (fscanf(fp, "%d", &number) == 1) {
        // Process the number
        printf("Number: %d\n", number);
    }    
    fclose(fp);
    return NULL;
}



int main() {
    printf("testing\n");
    convert_file_to_ll("temp");
    return 0;
}
