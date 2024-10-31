#include "operation.h"
#include "list.h"
#include "node.h"

void meny(){
    
    printf("----------------------------------------------------------------------------\n");
    printf("0: Avsluta\n");
    printf("1: Skriv ut listan\n");
    printf("2: Skriv ut listans storlek\n");
    printf("3: Lägg till ett heltal sist i listan\n");
    printf("4: Lägg till ett heltal (valfri plats)\n");
    printf("5: Ta bort ett givet heltal\n");
    printf("6: Ta bort ett heltal(valfri plats)\n");
    printf("7: Töm listan\n");
    printf("8: Vänd på listan\n");
    printf("9: Skifta listan ett steg åt vänster (och lägg första heltalet sist)\n");
    printf("10: Skifta listan ett steg åt höger (och lägg sista heltalet först)\n");
    printf("11: Sortera listan (Lägsta heltalet först)\n");
    printf("12: Skriv ut startadress för listan\n");
    printf("Gör ditt val : ");    
}
void end(){
    printf("Byeee");
}

void print(node *head){
    if(head == NULL){
        printf("Listan är tom\n");
        return;
    }
    node *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->el);
        temp = temp->next;
    }
    printf("\n");
}

void getSize(node *head){
    if(nIsEmpty(head)){
        printf("Listan är tom\n");
    }else{
        printf("Listans storlek : %d\n", nGetSize(head));
    }
}

node *insertAtEnd(node *head){
    int value;
    printf("Ange ett heltal : ");
    scanf("%d", &value);
    return nInsertAtEnd(head, value);
}

node *insertAtPos(node *head){
    int pos_1;
    int value_2;
    printf("Ange ett heltal : ");
    scanf("%d", &value_2);
    printf("Ange positionen : ");
    scanf("%d", &pos_1);
    return nInsertAtPos(head, value_2, pos_1);
}

node *remov(node *head){
    int value_3;
    printf("Ange heltalet som du vill radera : ");
    scanf("%d", &value_3);
    if(nExist(head,value_3)){
        head = nRemov(head,value_3);
    }
    return head;
}

node *removAtPos(node *head){
    int pos_2;
    printf("Ange postionen du vill radera : ");
    scanf("%d",&pos_2);
    return nRemovAtPos(head, pos_2);
}

node *emptyList(node *head){
  return nEmptyList(head);
}

node *reverse(node *head){
  return nReverse(head); 
}



node *shiftLeft(node *head){
  return nShiftLeft(head); 
}

node *shiftRight(node *head){
  return nShiftRight(head); 
}

node *sort(node *head){
  return nSort(head);
  printf("Listan är nu sorterat!\n");
}

void startAdress(node *head){
  printf("StartAdress: %d\n", &head);
}




