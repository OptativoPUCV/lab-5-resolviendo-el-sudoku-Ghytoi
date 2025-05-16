#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

    int control1, control2, num, boxRow, boxCol ;
    
    for (control1 = 0; control1 < 9; control1++)
    {
      int seen[10] = {0}; // contador de aparición de los números
      for (control2 = 0; control2 < 9; control2++)
      {
        num = n->sudo[control1][control2];
        if (num != 0 && seen[num] != 0) return 0;
        else seen[num] = 1;
      }
    }

    for (control1 = 0; control1 < 9; control1++)
    {
      int seen[10] = {0}; // contador de aparición de los números
      for (control2 = 0; control2 < 9; control2++)
      {
        num = n->sudo[control2][control1];
        if (num != 0 && seen[num] != 0) return 0;
        else seen[num] = 1;
      }
    }

    for (boxRow = 0; boxRow < 3; boxRow++) {
        for (boxCol = 0; boxCol < 3; boxCol++) {
            int seen[10] = {0}; // contador de aparición de los números
            for (control1 = 0; control1 < 3; control1++) {
                for (control2 = 0; control2 < 3; control2++) {
                    int num = n->sudo[boxRow * 3 + control1][boxCol * 3 + control2];
                    if (num != 0 && seen[num] != 0) return 0;
                    else seen[num] = 1;
                }
            }
        }
    }
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list = createList();

    int control1, control2, control3;

    for (control1 = 0; control1 < 9; control1++)
    {
      for (control2 = 0; control2 < 9; control2++)
      {
        if (n->sudo[control1][control2] == 0 )
        {
          for (control3 = 0; control3 < 9; control3++)
          {
            Node *nodoNuevo = createNode();
            nodoNuevo = copy(n);
            nodoNuevo->sudo[control1][control2] = control3 + 1;
            if (is_valid(nodoNuevo)) pushBack(list, nodoNuevo);
            else free(nodoNuevo);
          }
          return list;
        }
      }
    }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/