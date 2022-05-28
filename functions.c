//menu.c
#include "header.h"
#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define FILE_SIZE 1024

void menu()
{
  printf("------------------------------    \n");
  printf("\n            Menu    \n");
  printf("\n  1. Insert New Food    \n");
  printf("\n  2. Rate Food    \n");
  printf("\n  3. Show All    \n");
  printf("\n  4. Quit    \n");
}

int insert_data()
{
  int type;
  printf("\nSelect Menu (1~4): ");
  scanf("%d",&type);
  return type;
}

int checkOutofBound(int rate)
{ 
    if(rate > 10 || rate < 0)
    {
       printf("\n*Error Try Again. Rate(0~10)*    \n");
    return -1;
    }
  return rate;      
}

int insert_information(char food[], int rate, int count)
{
  FILE *food_information;
  FILE *rate_information;
  FILE *counter_in;
  char name[100];

  food_information = fopen("Food_Information.txt","a+");
  rate_information = fopen("Rate_Information.txt","a+");
  counter_in = fopen("Count.txt", "a+");
  
  if(count == 0)
  {
    fprintf(food_information,"%s\n",food);
    fprintf(rate_information,"%d\n",rate);
    fclose(food_information);
    fclose(rate_information);
    fclose(counter_in);
    return 1;
  }
    
  else
  {
    for(int x=0; x<=count; x++)
    {     
      fscanf(food_information, "%s", name);
      
      if(strcmp(name, food)==0)
      {
        printf("*Error. Food already exists, try again*");
        fclose(food_information);
        fclose(rate_information);
        fclose(counter_in);
        return 0;
      }
    }
    fprintf(food_information,"%s\n",food);
    fprintf(rate_information,"%d\n",rate);

  }
 
  fclose(food_information);
  fclose(rate_information);
  fclose(counter_in);
  return 1;
  }

void rating(char food[], int rate, int count)
{
  FILE *food_information;
  FILE *rate_information;
  FILE *temp;
  
  char name[100];
  int result;
  int rates[0];
    
  char information[FILE_SIZE];

  bool can_read = true;
  int current_line = 0;
 
  food_information = fopen("Food_Information.txt","a+");
  rate_information = fopen("Rate_Information.txt","a+");
  temp = fopen("temp.txt", "a+");

  for(int x=0; x<count; x++)
  {     
      fscanf(food_information, "%s", name);
   
    if(strcmp(name, food)==0)
    {

       do 
      {
        fscanf(rate_information, "%d", rates);
    
        if (feof(rate_information)) 
        {
          can_read = false;
          fclose(food_information);
          fclose(rate_information);
          fclose(temp);
          remove("Rate_information.txt");
          rename("temp.txt", "Rate_Information.txt");
          return;
        }
      
        else if (x == current_line)
        {
          result = (rate + rates[0])/2;
          fprintf(temp,"%d\n",result);
        }

        else 
        {
          fprintf(temp,"%d\n",rates[0]);
        }
 
        current_line++;

      } while (can_read);
    }
  }
  printf("*Food does not exists. Select Menu 1 to insert new food*");
  
  fclose(food_information);
  fclose(rate_information);
      }
    



int counterIn(int count)
{
  FILE *counter_in;
        counter_in = fopen("Count.txt", "a+"); // open Counter.txt
        fscanf(counter_in,"%d", &count);// Get count
        fclose(counter_in);
        return count;

}

void counterOut(int count)
{
  FILE *counter_out;
  counter_out = fopen("Count.txt", "w");
        count = count+1;//count++;
        fprintf(counter_out,"%d",count);//add count
         fclose(counter_out);
}

int returnCount()
{
int count;
  FILE *counter_in;
        counter_in = fopen("Count.txt", "r"); // open Counter.txt
        fscanf(counter_in,"%d", &count);// Get count
        fclose(counter_in);
        return count;
}


void print_all()
{
   FILE *food_information;
   FILE *rate_information;
  char name[100];
  int rates;
  
  food_information = fopen("Food_Information.txt","a+");
  rate_information = fopen("Rate_Information.txt","a+");
  if(returnCount()==0)
  {
   printf("\n*No Data is Available*\n");
   printf("\n*Please Insert New Food*\n");
    return;
  }
  printf("\nSHOW: \n");
    for(int x=0; x<returnCount(); x++)
    {     
      fscanf(food_information, "%s", name);
      fscanf(rate_information, "%d", &rates);
      printf("\n%s %d\n",name, rates);
    }
  
  fclose(food_information);
  fclose(rate_information);
  }

