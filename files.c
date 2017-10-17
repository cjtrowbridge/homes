#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    FILE *s;
    s = fopen("states.csv", "r");
    if (!s)
    {
        printf("Can't read file");
        exit(1);
    }
    
    char name[100];
    char capitol[100];
    int population;
    int area;
    int max = 0;
    int min = 999999999;
    char maxstate[30];
    char minstate[30];
    
    while(fscanf(s,"%[^,],%[^,],%d,%d ",name,capitol,&population,&area) != EOF ){
    
        //printf("%15s:(%2d)%s\n",channel,time, show);
        
        if(population > max){
            max = population;
            strcpy(maxstate,name);
        }
        if(population < min){
            min = population;
            strcpy(minstate,name);
        }
        
    }
    
    fclose(s);
    printf("Max: %d\nMin: %d\n",max,min);
}