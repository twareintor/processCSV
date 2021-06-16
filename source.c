
// // // /Below is the program as I have it had on onlinegdb.com (direct link: https://www.onlinegdb.com/edit/Sy1PX36Fv but this part is no more there)
// TO MOVE FROM SINGLE SOURCE TO AN USUAL C PROJECT
////////////////////////////// processCsv.h /////////////////////////////////////
// module intended to process Csv - files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
 * NOTE: Header without qualifiers
 * 
 */
void getTableFromCsvFile();


/**
 * 
 * 
 */
// void getTableFromCsvFile(const char* szFNm, char**** pppszTable, int* rows, int* columns);


void TEST__getTableFromCsvFile();




////////////////////////////// processCsv.h /////////////////////////////////////

#include "processCsv.h"

#define LINE_MAX_LEN    0x100

void TEST__getTableFromCsvFile()
{
    char*** table;
    int rows = 40;
    int columns = 80;
    getTableFromCsvFile("test001");
    
    // 
}

void getTableFromCsvFile(const char* szFNm)
{
    int i = 0; // count lines
    int j = 0; // count columns
    char* str = (char*)malloc(LINE_MAX_LEN);
    FILE* f;
    int result;
    int chunk;
    
    f = fopen(szFNm, "r");
    do{
        memset(str, 0, LINE_MAX_LEN);
        result = fscanf(f, "%[^\n]", str);
        // ppszTable[j] = (char**)malloc(256*sizeof(char*));
        // memset(ppszTable[j], 0, LINE_MAX_LEN*sizeof(char*));
        if(!result)
        {
            printf("\n");
            result = fscanf(f, "%*c");
            i++;
        }
        else
        {
            //whatever you want to do with your value
            // printf("%s", str);
            char* tmp = str;
            char* nxt;
            if(0==i) nxt = strstr(tmp, ";"); else nxt = strstr(tmp, "\";");
            j = 0;
            // printf("%d ", i);
            printf("|");
            while(nxt)
            {
                int len = nxt - tmp;
                // printf("%d ", j);
                printf("%.*s|", len - 2*(i>0) + (i>0)*(j==0), tmp + 2*(i>0) - (i>0)*(j==0));
                // sprintf(ppszTable[i][j], "%.*s|", len - 2*(i>0) + (i>0)*(j==0), tmp + 2*(i>0) - (i>0)*(j==0));
                j++;
                tmp = nxt + 1;
                if(tmp-strlen(str)<1) break;
                if(0==i) nxt = strstr(tmp, ";"); else nxt = strstr(tmp, "\";");
                // free(ppszTable[j][i]);
            }
        }
    }while(result != EOF);
    fclose(f);
    free(str);
}


