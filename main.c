#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
int value;
char food[100];
int rate; 
int count=0;
  
  do
  {
    menu();
    value = insert_data();
    switch(value)
      {
        case 1:
        printf("Enter the name of Food: "); //Instruction
        scanf("%s", food);
        int j= 0; 
          
        while (food[j]) 
        {
        char ch = food[j];
        food[j]=toupper(ch);
        j++;
        }

        printf("Rate it(0~10): ");
        scanf("%d", &rate);
          
        count = counterIn(count);

        if(checkOutofBound(rate)==-1)
        {
          break;
        }
          
        if(insert_information(food, rate, count)==1) //If Data added
       {
        counterOut(count);
        printf("\n*Data is added*\n");
       }
          
        break;
          
        case 2:
          printf("Enter the name of the food: %s", " ");
          scanf("%s", food);

          int k= 0;
          while (food[k]) 
          {
          char ch = food[k];
          food[k]=toupper(ch);
          k++;
          }
          
          printf("Rate it(0~10): ");
          scanf("%d", &rate);
          
          if(checkOutofBound(rate)==-1)
          {
            break;
          }
          
          rating(food, rate, returnCount());
          printf("\n*Updated*\n");
        break;
        
        case 3:
          print_all();
        break;
        
        case 4:
          printf("QUIT. GOOD BYE\n");
        break;

        default:
          printf("\n*Error Try Again*    \n");
          break;
      }
  } while(value!=4);
}


