#include <stdio.h>
#include <string.h>
#include <math.h>

void binToHex(char bin[]) {
    int len = strlen(bin);
    int i, hexValue = 0;
    
    // Make sure the binary number's length is a multiple of 4
    while (len % 4 != 0) {
        // Pad the binary number with leading zeros if needed
        memmove(bin + 1, bin, len + 1);
        bin[0] = '0';
        len++;
    }
    
    // Iterate through the binary string in groups of 4 bits
    printf("Hexadecimal equivalent: ");
    for (i = 0; i < len; i += 4) {
        hexValue = 0;
        // Convert the next group of 4 bits to a decimal value
        if (bin[i] == '1') hexValue += 8;
        if (bin[i + 1] == '1') hexValue += 4;
        if (bin[i + 2] == '1') hexValue += 2;
        if (bin[i + 3] == '1') hexValue += 1;
        
        // Print the corresponding hexadecimal character
        if (hexValue < 10)
            printf("%d", hexValue);
        else
            printf("%c", 'A' + (hexValue - 10));
    }
    printf("\n");
}

int main() {
    char binary[65];  // Assuming the input binary number will not exceed 64 bits

    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Check if the input binary string is valid
    int isValid = 1;
    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            isValid = 0;
            break;
        }
    }

    if (isValid)
        binToHex(binary);
    else
        printf("Invalid binary input!\n");

    return 0;
}
