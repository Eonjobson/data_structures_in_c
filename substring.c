//program to extract substring from a given string
#include<stdio.h>
#include<string.h>
int main()
{ 
    int i=0,j=0;
    int  n,m;
    char str[100],substr[100];
    printf("enter main string");
    gets(str);
    printf("enter position of substring");
    scanf("%d",&m);
    printf("enter length of substring");
    scanf("%d",&n);
    i=m;
    while(str[i]!='\0' && n>0)
    {
        substr[j]=str[i];
        i++;
        j++;
        n--;

    }
    substr[j]='\0';
    printf("\n substring is:\n");
    puts(substr);



    return 0;
}