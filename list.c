#include "list.h"
#include "node.h"

int nGetSize(node *head){
  node *temp = head;
  int size = 0;
  for(temp = head; temp != NULL; temp = temp->next) {
      size++;
   }
  return size;
}

int nIsEmpty(node *head){
  return head == NULL; 
}

node* nInsertAtEnd(node *head, int value){
if(head == 0){
    node *newNode = (node *) malloc(sizeof(node)); 
    newNode->el = value;
    newNode->next = NULL;
    newNode->next = head;
    head = newNode; 
    return head;
  }
  node *temp = head;
    while(temp->next != NULL){
      temp = temp->next;
    }
  temp->next = (node *)malloc(sizeof(node *));
  temp->next->el = value;
  temp->next->next = NULL; 
  
  return head;
}

node* nInsertAtPos(node *head, int value, int position){
  if(position < 0 || position > nGetSize(head)){
    printf("Ogiltigt position!\n");
  }
  // insert at the begnning 
  else if (position == 1){
    node *newNode = (node *) malloc(sizeof(node)); 
    newNode->el = value;
    newNode->next = NULL;
    newNode->next = head;
    head = newNode; 
    return head;
  }
  else{
    node * prev = getNode(head, position-1);
    node * n = (node *)malloc(sizeof(node));
    n->el = value;
    n->next = prev->next;
    prev->next = n; 
  }
  return head;
}

int nExist(node *head, int element){
  node *temp = head;
  while(temp != NULL){
    if(temp->el == element){
      return 1;
    }
    temp = temp->next;
  }
  return -1;
}

node *nSort(node *head){
  int k, tempKey, tempData;
  node *current;
  node *next;
  int size = nGetSize(head);
  k = size ;
  for (int i = 0 ; i < size - 1 ; i++, k-- ) {
    current = head;
    next = head->next;
    for (int j = 1 ; j < k ; j++ ) {   
        if ( current->el > next->el ) {
          tempData = current->el;
          current->el = next->el;
          next->el = tempData;
        }
        current = current->next;
        next = next->next;
    }
  }
  return head;
}

node* nEmptyList(node *head){
  node *temp = head;
  node *next; 
  while(temp != NULL){
    next = temp->next;
    free(temp);
    temp = next; 
  }
  head = NULL; 
  return head;
}

node *nRemovAtPos(node *head, int pos){
  pos--;
  if(pos < 0 || pos > nGetSize(head)){
    printf("Ogiltigt position\n");
    return head;
  } 
  // Store head node
  node* temp = head;
  // If head needs to be removed
  if (pos == 0){
      head = temp->next;   // Change head
      free(temp);               // free old head
      return head;
  }
    // Find previous node of the node to be deleted
  for (int i=0; temp!=NULL && i<pos-1; i++)
      temp = temp->next;
  // If position is more than number of nodes
  if (temp == NULL || temp->next == NULL)
    return head;

  // Node temp->next is the node to be deleted
  // Store pointer to the next of node to be deleted
  node *next = temp->next->next;

  // Unlink the node from linked list
  free(temp->next);  // Free memory

  temp->next = next;  // Unlink the deleted node from list
  return head; 
}

node *nRemov(node *head, int value){
  // Store head node
    node *temp = head;
    node *prev;
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->el == value) {
        head = temp->next; // Changed head
        free(temp); // free old head
        return head;
    }
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->el != value) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return head;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp); // Free memory
    return head;
}

node *nShiftLeft(node *head){
int s = nGetSize(head);
  if(s > 1){
    node *n1 = head;
    node *ns = getNode(head, s);
    head = n1->next;
    n1->next = NULL;
    ns->next = n1;
  }
  return head;
}

node * nShiftRight(node * head){
  if(nGetSize(head) > 1){
    int s = nGetSize(head);
    if(s > 1){
      node *n1 = getNode(head, s-1);
      node *ns = n1->next;
      n1->next = NULL;
      ns->next = head; 
      head =ns; 
      }
  }
  return head;
}

node * getNode(node * head, int index) {
  node * n = head;
  for (int i = 1; i < index; i++){
    n = n -> next;
  }
  return n;
}

node *nReverse(node *head){
  if(nGetSize(head) > 1){
    node* prev   = NULL;
    node* current = head;
    node* next;
    while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
      
  }
    head = prev;
  }
  return head;
}

int nPresent(node *head, int element){
  node *temp = head;
  int index = 1;
  while(temp != NULL){
    if(temp->el == element){
      printf("Elementen %d: present first at %d", temp->el , index);
      return 1;
    }
    index++;
    temp = temp->next;
  }
  return -1;
}

node *partation(node *head){
    node *n1 = head;
    node *n2 = (node *)malloc(sizeof(node *));
    node *n3 = (node *)malloc(sizeof(node *));
    node *par = getNode(head,0);
    for(n1=head; n1 != NULL; n1->next){
        if(par < n1->next){
            n2-> next = n1-> next; 
        }
        else{
            n3->next = n1->next;
        }
    }
    return n2,n3;
}