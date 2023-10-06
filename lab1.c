/*
 * Implement your solution in this file
 *
 */

#include <stdio.h> //Import input and output module
#include <stdlib.h> // Import library module
#include <string.h> //Import strings modules manipulate stringd

#define MAX_LINE_LENGTH 1024

//read string function will take strings from the file
char* readString(char* fileName){

    FILE* file = fopen(fileName, "r"); //f open will open the file in read mode ("r")
    if(file == NULL){
        perror("Error opening file"); //if file is not located it will print an error message
        return NULL;
    }

    char* strings=(char*)malloc(sizeof(char)*100); // This allocates space for the string


    if(strings != NULL){
        if (fscanf(file, "%99[^\n]", strings)== 1){   //fscanf will scan the file an d create a new line at the end of the file
            strings[99]='\0';
        }else{ //This will only happen if the allocation of the string was unsuccessful
            free(strings);  //This empties the contents of string
            strings = NULL; //This sets the string to be NULL
        }
    }

    fclose(file); //closes the file pointer and stops reading
    return strings; //This will return the string that was read from the file
}


char* mysteryExplode(const char* str){ 
    
    int stringLength = strlen(str); //Find length of string
    
    int explodedLength = stringLength*(stringLength + 1)/2 +1; //Formula for lenth of exploded string
   
    char* exploded = (char*)malloc(explodedLength); //Allocation of memory for exploded string
    if(exploded == NULL){
        return NULL;
    }
    
    char* start = exploded; //creates a pointer to the exploded string
    //nested loop that will "explode" the string 
    for(int a=0; a<stringLength; a++){ //Loop that goes through the string
        
        for(int b = 0; b<= a; b++){ //Loop that copies the character(s) with every iteration 
            *start = str[b];
            start++;
        }
    }
    
    *start = '\0';
    
    return exploded; // return exploded
}

