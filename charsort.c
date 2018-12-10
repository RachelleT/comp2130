#include <stdio.h>
#include <string.h>

int main () {
   char string[30];
   char temp;

   int i, j;
   

   printf("Enter string: \n");
   scanf("%s", string);
   
   int n = strlen(string);

   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (string[i] > string[j]) {
            temp = string[i];
            string[i] = string[j];
            string[j] = temp;
         }
      }
   }
   
   printf("Sorted string: %s\n", string);
   return 0;
}
