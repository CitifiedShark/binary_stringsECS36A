
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This program gives us all the possible binary strings that are possible from the given binary string input
*/
void makeBinaryStrings(char* str, int n) {
/*
This function recursively calls itself to give all possible binary strings
@param: str is the binary string given to us from input
@param: n is the index of the string that we are changing and moving along
*/
    if (n == strlen(str)) { // If we are at the end of the string, print it out to the user
        printf("%s\n", str);
        return;
    } else if (str[n] == 'x' || str[n] == 'X') {
        str[n] = '0';
        makeBinaryStrings(str, n + 1); // Makes a string for the rest with a 0 replacing X
        str[n] = '1';
        makeBinaryStrings(str, n + 1); // Makes a string for the rest with a 1 replacing X

        str[n] = 'X'; // Turn it back to an X so it can be created again
    } else {
        makeBinaryStrings(str, n + 1); // Move on if not an X
    }
}

int main(int argc, char** argv) {
/*
This function reads the command and the given binary string
@param: argc is the command
@param: argv consists of the binary string
@returns 0 for completion
*/

    int binary_string_len = strlen(argv[1]);
    char* str = malloc(binary_string_len * sizeof(char));
    str[binary_string_len] = '\0';
    
    for (int i = 0; i < binary_string_len; i++) {
        str[i] = argv[1][i];
    }

    makeBinaryStrings(str, 0);

    free(str);

    return 0;
}