#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ParseFile(char* filename);
void saveFile(char * data, int size, char * fname);
void appendFile(char * data, int size, char * fname);

int main(){
    
    char homes200File[20] = "homes200.csv";
    char homesFile[20] = "homelistings.csv";
    
    ParseFile(homes200File);
    //ParseFile(homesFile);
    
}

int ParseFile(char* filename)
{
    
    FILE *s;
    s = fopen(filename, "r");
    if (!s)
    {
        printf("Can't read file");
        exit(1);
    }
    
    int zip;
    int id;
    char address[100];
    double price;
    int beds;
    int baths;
    int sqft;
    
    int max = 0;
    int min = 999999999;
    //char maxstate[30];
    //char minstate[30];
    int listings = 0;
    double totalPrice = 0;
    
    char smallFile[20] = "small.txt";
    char medFile[20] = "med.txt";
    char largeFile[20] = "large.txt";
    
    
    while(fscanf(s,"%d,%d,%[^,],%lf,%d,%d,%d ",&zip,&id,address,&price,&beds,&baths,&sqft) != EOF ){
        //printf("%d\n", listings);
        listings++;
        
        //printf("%d,%d,%s,%lf,%d,%d,%d\n", zip,id,address,price,beds,baths,sqft);
        
        totalPrice+=price;
        
        if(price > max){
            max = price;
        }
        if(price < min){
            min = price;
        }
        
        /*
        char* row;
        row = (char*) malloc (255);
        sprintf(row,"%30s: %d",address,sqft);
        
        if(sqft < 1000){
            //small
            appendFile(row , strlen(row), smallFile);
        }else if(sqft >= 1000 && sqft <= 2000){
            //med
            appendFile(row , strlen(row), medFile);
        }else{
            //large
            appendFile(row , strlen(row), largeFile);
        }
        
        
        char* fname;
        fname = (char*) malloc (10);
        sprintf(fname,"%d%s",zip,".txt");
        
        char* addressOutput;
        addressOutput = (char*) malloc (255);
        sprintf(addressOutput,"%s\n",address);
        
        appendFile(addressOutput , strlen(address), fname);
        */
        
    }
    
    int averagePrice = totalPrice / listings;
    
    fclose(s);
    printf("%d %d %d\n",min,max,averagePrice);
    return 1;
}

void saveFile(char * data, int size, char * fname)
{
    FILE *fp = fopen(fname, "wb");
    if (!fp)
    {
        fprintf(stderr, "Can't write to %s\n. Is there a zip directory?", fname);
        exit(1);
    }
    
    fwrite(data, 1, size, fp);
    fclose(fp);   
}

void appendFile(char * data, int size, char * fname)
{
    FILE *fp = fopen(fname, "a+");
    if (!fp)
    {
        fprintf(stderr, "Can't append to %s\n", fname);
        exit(1);
    }
    
    fwrite(data, 1, size, fp);
    char newline[2] = "\n";
    fwrite(newline, 1, 1, fp);
    fclose(fp);   
}