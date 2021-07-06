#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void search(char word[],char txt[]);
#define a 256
#define prime 257
int main()
{
   char ch, file_name[50];
   FILE *fp;
   char word[50];

   printf("Enter name of a file you wish to see\n");
   gets(file_name);
   printf("enter word");
   gets(word);


   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   #include <stdio.h>

int main()
{
    char *filename = "readme.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // read one character at a time and
    // display it to the output
    char ch;
    char[strlen(fp)+1] txt;
    while ((ch = fgetc(fp)) != EOF)
        txt

    

   search(word,ch);
 
   fclose(fp);
}
void search(char word[],char txt[])
{
   int wlen = strlen(word);
   int txtlen = strlen(txt);
   int i,j;
   int hw=0;
   int ht=0;
   int h=1;
   //h value 
   for (i =0;i<wlen;i++)
   {
      h=(h*a)%prime;
   }
   //calc hash values of word and rolling txt
   for(i=0;i<wlen;i++)
   {
      hw = (a*hw + word[i])%prime;
      ht = (a*ht + txt[i])%prime;

   }
   //sliding
   for(i=0;i<=txtlen-wlen;i++)
   {
      if(hw==ht)
      {
         //check letter by letter
         for(j=0;j<wlen;j++)
         {
            if(txt[i+j]!=word[j])
            {
               break;
            }
         }
      }
      if(j==wlen)
      {
         printf("%s found at index %d",word,i);
      }
      if(i<(txtlen-wlen))
      {
         ht = (a*(ht - txt[i]*h)+ txt[i+wlen]%prime);//skip and append
         if(ht<0)
         {ht+=prime;}
            
      }
      else{
         printf("word not found");
      }

   }



}
}