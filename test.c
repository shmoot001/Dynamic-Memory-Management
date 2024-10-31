#include "node.h"



node *head = NULL;

int main(void){
  int val;
  
  do{
    meny();
    scanf("%d", &val);
    printf("----------------------------------------------------------------------------\n");

  }while(val != 0);
  return 0;
}