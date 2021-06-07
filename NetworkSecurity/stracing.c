#include <stdio.h>

#define MAX_STRINGS    10
#define STRING_LENGTH    50
/*
Juan Bermudez
20158030
4/23/19
*/
void urname1(int a,  char b, int c); 
void urname2(int *ptr, size_t length);  

int main()
{
    urname1(2, 'J', 5 );
    return 0;
}
void urname1(int a,  char b, int c)
{
 
 printf("%d\n",a);
  printf("%c\n",b);
   printf("%d\n",c);
   
    int array[6] = {2,4,6,8,10};   
    
    printf("Urname2 function call\n");
    urname2(array, 6);
   
}
void urname2(int *ptr, size_t length)           
{         
    //for statement to print values using array             
    size_t i = 0;
    for( ; i < length; ++i )      
    printf("%d\n", ptr[i]); 
    
} 