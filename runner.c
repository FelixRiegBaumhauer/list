#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next;};
// out declaration

//iternate through, stop if we hit a 0
void print_list(struct node *ptr){
  printf("{");
  while(ptr){
    printf("%d, ", ptr->i);
    ptr=ptr->next;
  }
  printf("}\n");
}

//add a new one to the top
struct node * insert_front(struct node *ptr, int newData){
  struct node *newNode;
  newNode = (struct node *)calloc(1, sizeof(struct node));
  newNode->i=newData;
  newNode->next=ptr; 
  return newNode;
}

//iterate through, set to 0
struct node * free_list(struct node *ptr){
  struct node * place = ptr;
  while(ptr){
    ptr->i=0;
    struct node * holder = ptr->next;   
    ptr->next=0;
    ptr=holder;
  }
  ptr =place;
  ptr=0;
  place = 0;
  return place;
}

int main(){
  struct node *a;
  a = (struct node *)calloc(1, sizeof(struct node));
  //gives us some clean menory in which to work
  a->i=2;

  struct node *b;
  b = (struct node *)malloc(sizeof(struct node));
  b->i=3;

  a->next = b;
  b->next = 0;

  printf("this is list a: ");
  print_list(a);
  //insert_front(a,69);
  struct node *aPrime = insert_front(a,56);
  printf("this is the result of inserting 56 infront of a : ");
  print_list(aPrime);
  //print_list(a);

  printf("this is the result of freeing list a : ");
  struct node *emp = free_list(a);
  print_list(emp);
  //print_list(a);
  //print_list(aPrime);
    

  return 0;
}
