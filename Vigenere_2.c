#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* read_cipher(char* filename) {
    FILE *file;
    file = fopen(filename, "r");

    if(file == NULL) {
        printf("Error opening the file.");
        return NULL;
    }

    char* cipher = (char*) malloc(MAXN * sizeof(char));
    if(fgets(cipher, MAXN, file) == NULL) {
        printf("Error reading from file.");
        return NULL;
    }

    fclose(file);

    return cipher;
}

void write_cypher(char* encrypted_text) {
    char filename[MAXN];
    printf("Enter filename: \n");
    scanf("%s", filename);
    
    FILE* file = fopen(filename, "w");

    fprintf(file, "%s", encrypted_text);

    fclose(file);
}

char* vigenere_encrypt(char* plaintext, char* key)
{
    int length = strlen(plaintext);
    int key_length = strlen(key);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));
    int index = 0;
    while(plaintext[index] != '\0')
    {
        int shift = tolower(key[index % key_length]) - 'a';
        
        if(islower(plaintext[index]))
        {
            cipher[index] = 'a' + (plaintext[index] - 'a' + shift) % 26;
        }
        else if(isupper(plaintext[index]))
        {
            cipher[index] = 'A' + (plaintext[index] - 'A' + shift) % 26;
        }
        else
        {
            cipher[index] = plaintext[index];    
        }
        index++;
    }
    cipher[index] = '\0';
    return cipher;
}

char* vigenere_decrypt(char* cipher, char* key)
{
    int length = strlen(cipher);
    int key_length = strlen(key);
    char* plaintext = (char*) malloc(sizeof(char) * (length + 1));
    int index = 0;
    while(cipher[index] != '\0')
    {
        int shift = tolower(key[index % key_length]) - 'a';
        
        if(islower(cipher[index]))
        {
            plaintext[index] = 'a' + (cipher[index] - 'a' - shift + 26) % 26;
        }
        else if(isupper(cipher[index]))
        {
            plaintext[index] = 'A' + (cipher[index] - 'A' - shift + 26) % 26;
        }
        else
        {
            plaintext[index] = cipher[index];    
        }
        index++;
    }
    plaintext[index] = '\0';
    return plaintext;
}

int main()
{
    char filename[MAXN];
    printf("Enter filename: \n");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';
    
    char* plaintext = read_cipher(filename);
    
    char key[MAXN];
    printf("Insert key file: \n");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    
    char* keytext = read_cipher(key);
    
    char* result = vigenere_decrypt(plaintext, keytext);
    
    write_cypher(result);

    printf("Result: %s", result);
    return EXIT_SUCCESS;
}
