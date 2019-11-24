#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>


typedef struct Node
{
  char *data;
  struct Node nextNode;
}Node;

typedef struct Liststack
{
  Node* List;
  Node* Top;
}Liststack;

void  CreateStack(Liststack** Stack)
{
  (*Stack) = (Liststck)malloc(sizeof(Liststck));
  (*Stack)->List = NULL;
  (*Stack)->Top = NULL;
}

void  DestroyStack(Liststack* Stack)
{
  while( !IsEmpty(Stack) ){
    Node* Popped = Pop( Stack );  
    DestroyNode(Pepped);
  }
  free(Stack);
}

Node* CreateNode(char* newData)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = (char*)malloc(strlen(newData)+1);

  strcpy(newNode->data, newData);
  newNode->nextNode = NULL;

  return newNode;
}


void  DestroyNode(Node* Node)
{
  free(Node->data);
  free(Node);
}

void Push(ListStack* Stack, Node* newNode)
{
  if( Stack->List == NULL){
    Stack->List = newNode;
  }
  else{
    Node* oldTop = Stack->List;
   
    while( oldTop -> nextNode != NULL){
       oldTop = oldTop->nextNode;
    }
    
    oldTop->nextNode = newNode;
  }
  
  Stack->Top = newNode;

}


Node* Pop(LinkedListStack* Stack)
{
  Node* topNode = Stack->Top;
  if( Stack->List == Stack->Top){
    Stack->List = NULL;
    Stack->Top = NULL;
  }
  else
  {
  }
}

Node* LLS_Top(LinkedListStack* Stack);
int   LLS_GetSize(LinkedListStack* Stack);
int   LLS_IsEmpty(LinkedListStack* Stack);

int Isnumber( char ch )
{
  if( isdigit(ch) || ch =='.') return 1;
  else return 0;
  
}

int Getnextteoken( char* ex, char *token, int type )
{
  int i =0;
  
  for( i=0; 0 !=ex[i]; i++){
    token[i] = ex[i];
    if ( Isnumber(ex[i]) == 1 )
 

}

int main(int argc, char* argv)
{
 


}


