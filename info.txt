#include <stdio.h>
 
#define MAXCHAR 1024
int main() {
    FILE *fp;
    char str[MAXCHAR];
    char* filename = ".\\test.txt";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Não foi possível abrir o arquivo: %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    fclose(fp);
    return 0;
}
