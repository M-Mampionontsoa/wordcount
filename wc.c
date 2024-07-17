#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"
#define TAILLE_MAX 1000


void Open_File(FILE **file,int argc,char *argv[])
{
    *file = fopen(argv[2], "r");
    if (*file == NULL)
    {
        exit (1);
    }   
}

void wc(FILE *file)
{
    int countligne = 0;
    int countword = 0;
    char ligne[TAILLE_MAX];
    int word=0;


    do  // lit le fichier ligne par ligne jusqu'à la fin
    {
        fgets(ligne,sizeof(ligne),file);
        countligne++;       //Incrémente une variable à chaque retour à la ligne          
    }
    while(!feof(file));
    printf("Lines: %d\n", countligne);          // Affiche le nombre de lignes
    

    rewind(file);

    do
    {
        word=fgetc(file);
        if(word==' ' ||word=='\t'||word=='\n')      //A chaque espace retour à la ligne et tabulation on fait
        {                                           //Incrémenter une  variable countword
            countword++;
        }
    }
    while(word!=EOF);
    printf("Words: %d\n", countword);     // Affiche le nombre de mots

}

       
void Option_l(FILE *file)
{
    rewind(file);
    int countligne = 0;
    char ligne[TAILLE_MAX];
    do  // lit le fichier ligne par ligne
    {
        fgets(ligne, sizeof(ligne), file);
         countligne++;         //Incrémente une variable à chaque retour à la ligne    
        
           
                  
    }
    while(!feof(file));
    printf("Lines: %d\n", countligne);    // Affiche le nombre de lignes
}

void Option_w(FILE *file)
{
    rewind(file);
    int countword = 0;
    int word=0;
    do // lit le fichier ligne par ligne
    {
        word=fgetc(file);
        if(word==' '  ||word=='\t'||word=='\n')
        {
            countword++;        //On incrémente une variable à chaque espace tabulation et retour à la ligne
        }
    }
    while(word!=EOF);
    printf("Words: %d\n", countword);     // Affiche le nombre de mots  
}

void Option_m(FILE *file)
{   
    rewind(file);
    int caract=0;
    int countcaract=0;
    int i;
    do
    {
        caract=fgetc(file);
        countcaract++;          //On incrémente une variable à chaque caractère lue par la fonction                
    } 
    while (caract!=EOF);
    printf("Caractere:%d\n",countcaract);
}

void Option_c(FILE *file)
{

    rewind(file);
    int byte;
    int countbyte = 0;

    while ((byte = fgetc(file)) != EOF) {
        countbyte++;
    }

    printf("%d bytes\n", countbyte);
}


void Option_L(FILE *file)
{
    rewind(file);
    int max=0;
    char line[TAILLE_MAX];
    while (fgets(line, sizeof(line), file)) {
        int length = strlen(line);
        if (length > max) {
            max = length;
        }
    }
    printf("Max : %d\n", max);
}



void option(FILE *file, int argc, char *argv[])
{
    if (argc == 2)
    {
        wc(file);
    }
    else if (argc == 3 && strcmp(argv[1], "-l") == 0)
    {
        Option_l(file);
    }
    else if (argc == 3 && strcmp(argv[1], "-w") == 0)
    {
        Option_w(file);
    }
    else if(argc == 3 && strcmp(argv[1], "-m") == 0)
    {
        Option_m(file);
    }
    else if(argc == 3 && strcmp(argv[1], "-c") == 0)
    {
        Option_c(file);
    }
    else if(argc == 3 && strcmp(argv[1], "-L") == 0)
    {
        Option_L(file);
    }
   
}

void Close_File(FILE *file)
{
    fclose(file);
}