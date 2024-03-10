#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MAXN = 1000;
    
char* caesar_encrypt(char* cypher, int key)
{
    int length = strlen(cypher);
    char* str = (char*) malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while(cypher[i] != '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = ((cypher[i] - 'A' + key + 26) % 26) + 'A';
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = ((cypher[i] - 'a' + key + 26) % 26) + 'a';
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            str[i] = ((cypher[i] - '0' + key + 10) % 10) + '0';
        }
        
        i++;
    }
    str[i] = '\0';
    
    return str;
}


char* caesar_decrypt(char* cypher, int key){
    int length = strlen(cypher);
    char* str = (char*) malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while(cypher[i] != '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = ((cypher[i] - 'A' - key + 26) % 26) + 'A';
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = ((cypher[i] - 'a' - key + 26) % 26) + 'a';
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            str[i] = ((cypher[i] - '0' - key + 10) % 10) + '0';
        }
        
        i++;
    }
    str[i] = '\0';
    
    return str;
}


int read_cypher(char* filename, char* cypher)
{
    FILE *file;
    
    file = fopen(filename, "r");
    
    if(file == NULL)
    {
        printf("Error opening the file.");
        
        return EXIT_FAILURE;
    }
    
    if(fgets(cypher, MAXN, file) == NULL)
    {
        printf("Error reading from file.");
        
        return EXIT_FAILURE;
    }
    
    fclose(file);
    
    return EXIT_SUCCESS;
}


int write_cypher(char* filename)
{
    FILE* file = fopen(filename, "w");
    
    if(file == NULL){
      printf("Error opening the file.");
      return EXIT_FAILURE;
    }
    
    getchar();
    
    char sentence[1000];
    printf("Enter sentence: \n");
    fgets(sentence, sizeof(sentence), stdin);
    
    fprintf(file, "%s", sentence);
    
    fclose(file);
    
    return EXIT_SUCCESS;
}


int main() {
    char filename[MAXN];
    printf("Enter filename: \n");
    scanf("%s", filename);
    
    char option[MAXN];
    printf("Choose read or write: \n");
    scanf("%s", option);
    
    if(strcmp(option, "read") == 0){

        char cypher[MAXN];

        if( read_cypher(filename, cypher) == EXIT_SUCCESS)
        {
            int key;
            printf("Enter key:");
            scanf("%d", &key);
            
            char* result = caesar_encrypt(cypher, key);
            
            printf("%s", result);
            
            return EXIT_SUCCESS;
        }
        else
        {
            return EXIT_FAILURE;
        }
    }
    
    else if(strcmp(option, "write") == 0){
        write_cypher(filename);
    }
    
}
