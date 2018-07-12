/*
 * Search.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Docente
 */

#ifndef SEARCH_H_
#define SEARCH_H_
#endif /* SEARCH_H_ */

#include <stdbool.h>


// Numeros de Wirth
void testWirth();
bool isWirth(int n);

// Torres de Hanoi
void testHanoiTowers();
void hanoiTowers(int cantDisc, char *origen, char* aux, char* destino, int* step);

// Paridad de un numero. Joyanes 4.1 pp 62
void testParity();
int isOdd(int n);
int isEven(int n);

// Tour del Caballo de Ajedrez Joyanes 4.3 pp 64
void testKnightTour();
bool findKnightTour(int startX, int startY, int step, int sizeX, int sizeY,  int** board);

// N-Reinas Joyanes 4.4 pp 74
void testNQueens();
bool nQueens(int currentQueen, int bsize, int queens[], bool columns[], bool lrdiags[], bool rldiags[]);
bool isValid(int f, int c, int bsize, int queens[], bool columns[], bool lrdiags[], bool rldiags[]);
void check(int f, int c, int bsize, int queens[], bool columns[], bool lrdiags[], bool rldiags[]);
void unCheck (int f, int c, int bsize, int queens[], bool columns[], bool lrdiags[], bool rldiags[]);

//Numeros Polidivisibles Joyanes 4.8 pp 74
void testPoliDivNumbers();
void poliDivNumbers(int digits[], int size,int m,int cpos,bool used[]);
bool divisible(int digits[], int size, int divisor);

// Variaciones Joyanes 4.12 pp 74
void testVariations();
void generateVariations(int n, int m, int currentPos,char elements[], bool disp[], int variation[]);

void testArraySum();
long long arraySumHead(int a[],int size, int pos);
long long arraySumTail(int a[],int size, int pos, long long sum);

void testArrayMin();
int arrayMin(int a[], int pos);
int minInt(int a, int b);
