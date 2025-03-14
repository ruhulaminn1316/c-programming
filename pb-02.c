#include <stdio.h>
#include <string.h>

#define MAX 100
#define FLAG "01111110"

// Function for Bit Stuffing
void bitStuffing(char *input, char *output) {
    int count = 0, j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i];
        if (input[i] == '1') {
            count++;
            if (count == 5) { // Insert '0' after five consecutive '1's
                output[j++] = '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    output[j] = '\0';
}

// Function for Bit De-Stuffing
void bitDeStuffing(char *input, char *output) {
    int count = 0, j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i];
        if (input[i] == '1') {
            count++;
            if (count == 5 && input[i + 1] == '0') {
                i++; // Skip the stuffed '0'
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    output[j] = '\0';
}

int main() {
    char data[] = "1111111111";  // Input data between flags
    char stuffed[MAX], destuffed[MAX];
    char frame[MAX];
    
    // Creating the frame with flag sequences
    sprintf(frame, "%s%s%s", FLAG, data, FLAG);
    
    printf("Original Frame: %s\n", frame);
    
    // Bit Stuffing
    bitStuffing(data, stuffed);
    char stuffedFrame[MAX];
    sprintf(stuffedFrame, "%s%s%s", FLAG, stuffed, FLAG);
    printf("Stuffed Frame: %s\n", stuffedFrame);
    
    // Bit De-Stuffing
    bitDeStuffing(stuffed, destuffed);
    char destuffedFrame[MAX];
    sprintf(destuffedFrame, "%s%s%s", FLAG, destuffed, FLAG);
    printf("De-Stuffed Frame: %s\n", destuffedFrame);
    
    return 0;
}
