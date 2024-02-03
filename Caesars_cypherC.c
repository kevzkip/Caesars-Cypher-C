#include <stdio.h>
#include <ctype.h>

void caesarCipher(char text[], int shift);

int main() {
    char inputText[100];
    int shiftValue;

    // Input from the user
    printf("Enter the text to encrypt: ");
    scanf("%s", inputText);

    printf("Enter the shift value: ");
    scanf("%d", &shiftValue);

    // Encrypt and decrypt the text using the Caesar Cipher
    caesarCipher(inputText, shiftValue);

    return 0;
}

void caesarCipher(char text[], int shift) {
    int i = 0;
    while (text[i]) {
        // Check if the character is a letter
        if (isalpha(text[i])) {
            // Determine if it is uppercase or lowercase
            char base = isupper(text[i]) ? 'A' : 'a';
            
            // Apply the Caesar Cipher formula
            text[i] = (text[i] - base + shift) % 26 + base;
        }
        // Check if the character is a digit
        else if (isdigit(text[i])) {
            // Apply the Caesar Cipher formula for digits
            text[i] = (text[i] - '0' + shift) % 10 + '0';
        }
        i++;
    }

    // Display the encrypted text
    printf("Encrypted Text: %s\n", text);

    // Decrypt the text using the same shift
    i = 0;
    while (text[i]) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base - shift + 26) % 26 + base; // Ensure the result is positive
        } else if (isdigit(text[i])) {
            text[i] = (text[i] - '0' - shift + 10) % 10 + '0'; // Ensure the result is positive
        }
        i++;
    }

    // Display the decrypted text
    printf("Decrypted Text: %s\n", text);
}
