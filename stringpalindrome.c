#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i=0,j;
    printf("enter string\n");
    gets(str);
    int length = strlen(str)-1;
    j=length;
    while(i<=length/2)
    {
        if(str[i]==str[j])
        {
            i++;
            j--;
        }
        else{
            break;
        }
    }
    if(i>=j)
    {
        printf("palindrome");
    }
    else
    {
        printf("not palindrome");
    }

     return 0;
}