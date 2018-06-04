

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASSWORT "BACHMANN"
#define MAX 80

char * keywords[] = {
        "IF",
        "THEN",
        "ELSE",
        "ELSIF",
        "END_IF",
        "FOR",
        "TO",
        "DO",
        "BY",
        "END_FOR"
};
int keywordCount = sizeof(keywords)/sizeof(keywords[0]);

char * operators[] = {
        "*",
        "/",
        "%",
        "+",
        "-"
};
int operatorCount = sizeof(operators)/sizeof(operators[0]);

char * specialKeys[] = {
        ":",
        ";",
        "(",
        ")"
};
int specialKeyCount = sizeof(specialKeys)/sizeof(specialKeys[0]);

char  whiteSpaces[] = {
        ' ',
        '\n',
        '\t'
};
int whiteSpaceCount = sizeof(whiteSpaces)/sizeof(whiteSpaces[0]);


void chomp(char *str) {
   size_t p=strlen(str);
   /* '\n' mit '\0' überschreiben */
   str[p-1]='\0';
}



int strToUpper(char str[]){
    int i = 0;
    while(str[i]) {
       str[i] = toupper(str[i]);
       i++;
    }
    return i;
}

unsigned char isKeyword(char *token){
    int i = 0;
    for (i = 0; i < keywordCount; i++) {
        if(strcmp(keywords[i], token) == 0){
            return 1;
        }
    }
    return 0;
}

unsigned char isOperator(char *token){
    int i = 0;
    for (i = 0; i < operatorCount; i++) {
        if(strcmp(operators[i], token) == 0){
            return 1;
        }
    }
    return 0;
}

unsigned char isSpecialKey(char *token){
    int i = 0;
    for (i = 0; i < specialKeyCount; i++) {
        if(strcmp(specialKeys[i], token) == 0){
            return 1;
        }
    }
    return 0;
}

unsigned char isWhiteSpace(char token){
    int i = 0;
    for (i = 0; i < whiteSpaceCount; i++) {
        if(whiteSpaces[i] == token){
            return 1;
        }
    }
    return 0;
}


unsigned char tokenizer(char *line){
    int i = 0;
    char tokenSpace[30];
    char *token = tokenSpace;
    int tokenPointer = 0;

    for(i = 0; i < strlen(line); i++){
        if(isWhiteSpace(line[i]) == 1){
            token[tokenPointer+1] = '\0';
            printf("%s\n", token);
            bfill(token, sizeof(tokenSpace),' ');
            tokenPointer = 0;
        } else {
            token[tokenPointer++] = line[i];
            //printf("%s\n", token);
        }
    }
    return 0;
}

int ps_main(void) {
   char pswd[MAX];
   int exitFlag = 0;

   while(exitFlag == 0){
       printf("C> ");
       fgets(pswd, MAX, stdin);
       chomp(pswd);
       strToUpper(pswd);

       if(strcmp(PASSWORT, pswd) == 0){
          printf("Willkommen\n");
       } else if(strcmp("EXIT", pswd) == 0){
           printf("Auf Wiedersehen\n");
           return EXIT_SUCCESS;
/*       } else if(isKeyword(pswd) == 1){
           printf("Keyword <%s>\n", pswd);
       } else if(isOperator(pswd) == 1){
           printf("Operator <%s>\n", pswd);
       } else if(isWhiteSpace(pswd) == 1){
           printf("WhiteSpace <%s>\n", pswd);
       } else if(isSpecialKey(pswd) == 1){
           printf("SpecialKey <%s>\n", pswd);
       } else
          printf("Id <%s>\n", pswd);
*/

       } else
           tokenizer(pswd);
   }
   return EXIT_SUCCESS;
}
