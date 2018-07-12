/*
 * abb.h
 *
 *  Created on: Oct 31, 2017
 *      Author: Docente
 */

#ifndef ABB_H_
#define ABB_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/*
  Este archivo contiene la definicion de la estructura Abb
  y funciones utiles para trabajar con esta estructura.
  Las cabeceras de las funciones tienen una descripcion de los parametros
  que recibe y el valor que devuelve, asi como el orden del tiempo medio
  de ejecucion.
 */

/*
  La estructura AbbNode contiene:
  - Un entero que es el elemento alojado en el nodo.
  - Un puntero a struct _abbNode que apunta al subarbol izquierdo del nodo.
  - Un punter a struct _abbNode que apunta al subarbol derecho del nodo
 */
typedef struct _abbNode{
  int elem;
  struct _abbNode *left;
  struct _abbNode *right;
}AbbNode;

/*
  La estructura Abb contiene:
  - Un entero que indica el numero de elementos en la lista (numElems).
  - Un puntero a la estructura _abbNode (root), que es la raiz del arbol.
 */
typedef struct {
  int numElems;
  AbbNode* root;
}Abb;


/*
  Inicializador por defecto de la estructura.
  Se reserva el espacio en memoria dinamica para la estructura y se inicializan
  sus campos.
  La lista se inicializa con un tamanyo de 0 y apuntando a NULL (es un arbol vacio)
  El tiempo de ejecucion es de O(1), asumiendo que el tiempo
  de reserva de memoria es consante.
 */
Abb* abb_init(){
  Abb *tree = (Abb*)malloc(sizeof(Abb));
  tree->numElems  = 0;
  tree->root      = NULL;
  return tree;
}

/*
  Funciones para buscar un nodo en el arbol
  Reciben:
  - Un puntero a la estructura a consultar (tree o n)
  - Un entero indicando el elemento a buscar (elem)

  Devuelven, de existir, al nodo que contiene el elemento buscado
  abb_find es la funcion de acceso que llama a la funcion recursiva sobre
  nodos abb_find.
  El tiempo de ejecucion, si el arbol esta equilibrado es de O(log_2(tree->numElems))
 */
AbbNode *abbNode_find(AbbNode *n, int elem){
  if(n==NULL || n->elem==elem){
    return n;
  }else{
    if(elem<n->elem){
      return abbNode_find(n->left,elem);
    }else{
      return abbNode_find(n->right,elem);
    }
  }
}


AbbNode *abb_find(Abb *tree, int elem){
  return abbNode_find(tree->root, elem);
}


/*
  Funcion iterativa para buscar un nodo en el arbol
  Recibe:
  - Un puntero a la estructura a consultar (t)
  - Un entero indicando el elemento a buscar (elem)

  Devuelve, de existir, al nodo que contiene el elemento buscado, NULL en caso contrario.

  El tiempo de ejecucion, si el arbol esta equilibrado es de O(log_2(tree->numElems))
 */
AbbNode *abb_find_it(Abb*t, int elem){
  AbbNode *aux=t->root;
  while(aux && aux->elem!=elem){
    if(elem<aux->elem) aux = aux->left;
    else aux = aux->right;
  }
  return aux;
}


/*
  Funciones para insertar un nodo en el arbol (no se insertan repetidos)
  Reciben:
  - Un puntero a la estructura a consultar (tree o n)
  - Un entero indicando el elemento a buscar (elem)
  - abbNode_insert recibe, ademas un puntero a entero que se modifica si el nodo se ha insertado (es decir, no habia un nodo con el mismo elemento anteriormente)

  abbNode_insert, devuelve un puntero al subarbol modificado.
  El tiempo de ejecucion, si el arbol esta equilibrado es de O(log_2(tree->numElems))
 */
AbbNode *abbNode_insert(AbbNode *n, int elem, int *inserted){
  if(n==NULL){
    *inserted = 1;
    n = (AbbNode*)malloc(sizeof(AbbNode));
    n->elem  = elem;
    n->left  = NULL;
    n->right = NULL;
  }else{
    if(elem < n->elem){
      n->left = abbNode_insert(n->left, elem, inserted);
    }else{
      if(elem > n->elem){
	n->right = abbNode_insert(n->right, elem, inserted);
      }
    }
  }
  return n;
}

void abb_insert(Abb *tree, int elem){
  int inserted = 0;
  tree->root = abbNode_insert(tree->root, elem, &inserted);

  if(inserted){
    tree->numElems = tree->numElems+1;
  }
}

/*
  Funcion iterativa para insertar un nodo en el arbol (no se insertan repetidos)
  Recibe:
  - Un puntero a la estructura a consultar (tree)
  - Un entero indicando el elemento a buscar (elem)

  El tiempo de ejecucion, si el arbol esta equilibrado es de O(log_2(tree->numElems))
 */
void abb_insert_it(Abb *tree, int elem){
  if(tree->root){
    int flag = 0;
    AbbNode *n = tree->root;
    while(!flag){
      if(elem < n->elem){//Insertar a la izquierda
	if(!n->left){
	  AbbNode *new=(AbbNode*)malloc(sizeof(AbbNode));
	  new->left = new->right = NULL;
	  new->elem = elem;
	  n->left = new;
	  flag = 1;
	  tree->numElems = tree->numElems+1;
	}else{
	  n = n->left;
	}
      }else if(elem > n->elem){//Insertar a la derecha
	if(!n->right){
	  AbbNode *new=(AbbNode*)malloc(sizeof(AbbNode));
	  new->left = new->right = NULL;
	  new->elem = elem;
	  flag = 1;
	  n->right = new;
	  tree->numElems = tree->numElems+1;
	}else{
	  n = n->right;
	}
      }else{//Nodo es igual y no debemos insertar elemento
	flag = 1;
      }
    }
  }else{
    AbbNode *new=(AbbNode*)malloc(sizeof(AbbNode));
    new->left = new->right = NULL;
    new->elem = elem;
    tree->root = new;
    tree->numElems = tree->numElems+1;
  }
}


/*
  Funcion recursiva que devuelve el elemento mas pequenyo de un subarbol
  Recibe:
  - Un puntero a AbbNode (n)

  Devuelve:
  - Un entero que es el elemento menor del subarbol del que n es raiz
  El tiempo de ejecucion, si el arbol esta equilibrado es de O(log_2(tree->numElems))
 */

int abbNode_getSmallest(AbbNode *n){
  if(!n->left){
    return n->elem;
  }else{
    return abbNode_getSmallest(n->left);
  }
}

/*
  Funcion recursiva que devuelve el elemento mas grande de un subarbol
  Recibe:
  - Un puntero a AbbNode (n)
  Devuelve:
  - Un entero que es el elemento mas grande del subarbol del que n es raiz
  El tiempo de ejecucion, si el arbol esta equilibrado es de O(log_2(tree->numElems))
 */
int abbNode_getBiggest(AbbNode *n){
  if(!n->right){
    return n->elem;
  }else{
    return abbNode_getBiggest(n->right);
  }
}

/*
  Funcion que elimina un nodo de un subarbol
  Recibe:
  - Un puntero a AbbNode (n)
  - Un elemento a eliminar (elem)
  - un puntero a entero que sirve de bandera para indicar si ha habido eliminacion (deleted)
  Devuelve:
  - Un puntero al subarbol modificado
  El tiempo de ejecucion, si el arbol esta equilibrado es de O(log_2(tree->numElems))
 */
AbbNode* abbNode_delete(AbbNode *n, int elem, int *deleted){
  if(n->elem == elem){ //Si estamos en el nodo a borrar
    if(!(n->left) && !(n->right)){ //nodo es hoja
      *deleted = 1;
      free(n);
      n = NULL;
    }
	else{
      if(!(n->left) || !(n->right)){ //nodo tiene un solo hijo
		*deleted = 1;
		AbbNode *aux = n;
		n = (!n->left) ? n->right : n->left;
		free(aux);
      }
	  else{ //nodo a borrar con dos hijos
		int forReplace;
		if(elem%2){ //para no desequilibrar, si es par, reemplazamos con el mayor del hijo izquierdo.
		  forReplace = abbNode_getBiggest(n->left);
		  n->elem    = forReplace;
		  n->left    = abbNode_delete(n->left, forReplace, deleted);
		}
		else{ //para no desequilibrar, si es impar, reemplazamos con el menor del hijo derecho.
		  forReplace = abbNode_getSmallest(n->right);
		  n->elem    = forReplace;
		  n->right    = abbNode_delete(n->right, forReplace, deleted);
		}
      }
    }
  }
  else{ //el nodo buscado esta en algun subarbol
    if( elem < n->elem){
      n->left = abbNode_delete(n->left, elem, deleted);
    }
	else{
      n->right = abbNode_delete(n->right, elem, deleted);
    }
  }
  return n;
}

/*
  Funcion para elimina un elemento de un arbol
  Esta funcion utiliza la funcion abbNode_delete.
  Recibe:
  - Un puntero al arbol (tree)
  - Un elemento a eliminar (elem)
  El tiempo de ejecucion, si el arbol esta equilibrado es de O(log_2(tree->numElems))
 */
void abb_delete(Abb *tree, int elem){
  int deleted = 0;
  tree->root = abbNode_delete(tree->root, elem, &deleted);
  if(deleted) tree->numElems = tree->numElems-1;
}

/*
  Funciones para imprimir los valores almacenados en un arbol.
  Recibe:
  - Un puntero a la estructura a imprimir (n o tree).
  El tiempo de ejecucion del arbol es de O(tree->numElems)
 */

void abbNode_print(AbbNode *n){
  if(n){
    printf(" %d(",n->elem);
    abbNode_print(n->left);
    printf(" ,");
    abbNode_print(n->right);
    printf(" )");
  }else{
    printf("NULL");
  }
}

void abb_print(Abb *tree){
  abbNode_print(tree->root);
  printf("\n");
}


#endif /* ABB_H_ */
