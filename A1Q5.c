#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void main()
{
    FILE *fp;
    fp=fopen("s1p5.txt","w");
    int i,n,size_t,size,length=10,stringLen;

    static int mySeed = 25011984;
    char *string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    stringLen = strlen(string);
    char *randomString = NULL;


    if (length < 1) {
        length = 1;
    }
    if(fp==NULL)
    {printf("file does not exists");
    }
    else
    {


        randomString = malloc(sizeof(char) * (length +1));
        for(i=0;i<100000;i++)
        {

            if (randomString) {
                short key = 0;

                for ( n = 0;n < length;n++) {
                    key = rand() % stringLen;
                    randomString[n] = string[key];
                }
                fprintf(fp,"%s\n",randomString);

                randomString[length] = '\0';
            }

        }
        fclose(fp);
    }}
