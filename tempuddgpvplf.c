#include <stdio.h>
#include <string.h>
#define FLAG "DLESTX" 
#define END_FLAG "DLEETX" 
#define ESC "DLE"      

void byteStuffing(char *input, char *stuffed) {
    int i = 0, j = 0;
    
    strcpy(stuffed, FLAG);  
    j = strlen(FLAG);

    while (input[i] != '\0') {
        if (input[i] == 'D' && input[i + 1] == 'L' && input[i + 2] == 'E') {
            strcat(stuffed, ESC);  
            j += strlen(ESC);
        }
        stuffed[j++] = input[i++];
    }

    strcat(stuffed, END_FLAG);  
    stuffed[j + strlen(END_FLAG)] = '\0';
}


void byteDeStuffing(char *stuffed, char *original) {
    int i = strlen(FLAG), j = 0; 
    while (stuffed[i] != '\0' && strncmp(&stuffed[i], END_FLAG, strlen(END_FLAG)) != 0) {
        if (strncmp(&stuffed[i], ESC, strlen(ESC)) == 0) {
            i += strlen(ESC);  
        }
        original[j++] = stuffed[i++];
    }

    original[j] = '\0';
}

int main() {
    char input[100], stuffed[200], original[100];

    printf("Enter Data in Uppercase: ");
    scanf("%s", input);

    byteStuffing(input, stuffed);
    printf("\nAfter Stuffing: %s", stuffed);

    byteDeStuffing(stuffed, original);
    printf("\nAfter De-stuffing: %s\n", original);

    return 0;
}
