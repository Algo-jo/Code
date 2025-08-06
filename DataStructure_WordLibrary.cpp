#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Johannes Aaron Framon (2802428223)

struct data{ 
    struct data *children[26]; 
    bool isAWord;
    char description[200];
};

struct data *createNode(){
    struct data *node = (struct data*)malloc(sizeof(struct data));
    node->isAWord = false;
    for(int i = 0; i < 26; i++){
        node->children[i] = NULL;
    }
    return node;
}
struct data *root = createNode(); 
char enter;

void insert(struct data *root, const char *word, char desc[]){
    struct data *curr = root;
    for(int i = 0; i < strlen(word); i++){
        int index = word[i] - 'a';
        if(curr->children[index] == NULL){ 
            curr->children[index] = createNode();
        }
        curr = curr->children[index];
    }
    curr->isAWord = true;
    strcpy(curr->description, desc);
}

struct data *search(struct data *root, const char *word){
    struct data *curr = root;
    for(int i = 0; i < strlen(word); i++){
        int index = word[i] - 'a';
        if(curr->children[index] == NULL){
            return NULL;
        }
        curr = curr->children[index];
    }
    return curr;
}

void newSlang(){
    char word[200] = {0};
    char desc[200] = {0};
    do{
        int exit = 1;
        printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
        scanf("%[^\n]", word); getchar();
        int len = strlen(word);
        for(int i = 0; i < len; i++){
            if(word[i] == ' '){
                exit = -1;
                break;
            }
        }
        if(exit == 1) break;
    }while(true);
    do{
        int space = -1;
        
        printf("Input a new slang word description [Must be more than 1 word]: ");
        scanf("%[^\n]", desc); getchar();
        int len = strlen(desc);
        for(int i = 0; i < len; i++){
            if(desc[i] == ' ' && space == -1){
                space = i;
                break;
            }
        }
        if(space != -1 && desc[space + 1] != NULL && desc[space - 1] != NULL){
            break;
        }    
    }while(true);

    struct data *res = search(root, word);
    if(res == NULL){
        insert(root, word, desc);
        printf("\nSuccesfully added a new slang word\n");
    }else{
        strcpy(res->description, desc);
        printf("\nSuccesfully updated a slang word\n");
    }
    printf("Press enter to continue...");
    scanf("%c", &enter);
    printf("\n");
    return;
}

void searchSlang(){
    char word[200] = {0};
    do{
        int exit = 1;
        printf("Input a slang word to be searched[Must be more than 1 characters and contains no space]: ");
        scanf("%[^\n]", word); getchar();
        int len = strlen(word);
        for(int i = 0; i < len; i++){
            if(word[i] == ' '){
                exit = -1;
                break;
            }
        }
        if(exit == 1){
            struct data *res = search(root, word);
            if(res == NULL){
                printf("There is no prefix \"%s\" in the dictionary", word);
                printf("\nPress enter to continue...");

                scanf("%c", &enter);
                printf("\n");
            }else{
                printf("Slang word: %s\n", word);
                printf("Description: %s\n", res->description);

                printf("\nPress enter to continue...");
                scanf("%c", &enter);
                printf("\n");
            } 
            break;
        } 
    }while(true);
}

int numbering = 1;
void printWord(struct data *node, char *buffer, int depth){
    if(node->isAWord){ 
        buffer[depth] = '\0';
        printf("%d. %s\n", numbering, buffer);
        numbering++;
    }
    for(int i = 0; i < 26; i++){
        if(node->children[i]){
            buffer[depth] = 'a' + i; 
            printWord(node->children[i], buffer, depth + 1);
        }
    }
}

void viewPrefix(){
    char word[200] = {0};
    printf("Input a prefix to be searched: ");
    scanf("%[^\n]", word); getchar();

    struct data *node = search(root, word);
    if(node == NULL){
        printf("There is no slang word in the dictionary yet\n");
        printf("Press enter to continue...");
        scanf("%c", &enter);
        printf("\n");
        return;
    }
    numbering = 1;
    printf("Words that start with \"%s\":\n", word);
    char buffer[200];
    strcpy(buffer, word);
    printWord(node, buffer, strlen(word));
    printf("\n");
}

void viewAll(){
    numbering = 1;
    char buffer[200];
    printWord(root, buffer, 0);
    printf("\n");
}

void menu(){
    int option = -1;
    do{
        printf("Boogle\n");
        printf("Select Menu Below\n");
        printf("1. Release a new slang word\n");
        printf("2. Search a slang word\n");
        printf("3. View all slang word starting with a certain prefix word\n");
        printf("4. View all slang word\n");
        printf("5. Exit\n");
        printf(">> ");
        scanf("%d", &option); getchar();
        switch (option){
        case 1:
            newSlang();
            break;
        case 2:
            searchSlang();
            break;
        case 3:
            viewPrefix();
            break;
        case 4:
            viewAll();
            break;
        }
    }while(option != 5);
    printf("Thank you... Have a nice day!\n");
    printf("Goodbye\n\n");
    printf("Johannes Aaron Framon - 2802428223\n");
}

int main(){
    menu();
    return 0;
}