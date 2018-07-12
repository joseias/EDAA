#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "Recursion.h"

// Numeros de Wirth
void testWirth(){
	int n=43;

	if(isWirth(n)){
		printf("%d es Wirth\n",n);
	}
	else{
		printf("%d no es Wirth\n",n);
	}
}
bool isWirth(int n){
    int m;
    if(n<1){
        return false;
    }
    else{
        if(n==1){
            return true;
        }
        else{
            m=n-1;
            if(m%2==0 && isWirth(m/2)){
                return true;
            }
            else{
                if(m%3==0 && isWirth(m/3)){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
}

// Torres de Hanoi
void testHanoiTowers(){
	int step=1;
    hanoiTowers(4,"Izquierda", "Centro", "Derecha", &step);
}
void hanoiTowers(int cantDisc, char *origen, char* aux, char* destino, int* step){
	if(cantDisc==1){
		printf("%d %s -> %s\n",*step, origen,destino);
		*step=*step+1;
	}
	else{
		hanoiTowers(cantDisc-1,origen,destino,aux, step);
		printf("%d %s -> %s\n",*step, origen,destino);
		*step=*step+1;
		hanoiTowers(cantDisc-1,aux,origen,destino, step);
	 }
}

// Paridad de un numero. Joyanes 4.1 pp 62
void testParity(){
	 int value=876;
	 if(isEven(value)){
		 printf("Es par");
	 }
	 else{
		 printf("Es impar");
	 }
}
int isOdd(int n){
	if(n==0){
		return 0;
	}
	else{
		return isEven(n-1);
	}
}
int isEven(int n){
	if(n==0){
		return 1;
	}
	else{
		return isOdd(n-1);
	}
}

// Tour del Caballo de Ajedrez Joyanes 4.3 pp 64
void testKnightTour(){
	int f, c, sizeX, sizeY, startX, startY;
	sizeX=5;
	sizeY=5;

	int** board;
	board=malloc(sizeX*sizeof(int*));
	for(f=0;f<sizeX;f++){
		board[f]=malloc(sizeY * sizeof(int));
		for(c=0;c<sizeY;c++){
			board[f][c]=-1;
		}
	}

	startX=0;
	startY=0;
	board[startX][startY]=1;

	bool solutionFound=findKnightTour(startX,startY, 2, sizeX, sizeY, board);

	if(solutionFound){
		for(f = 0; f < sizeX; f++){
			for(c = 0; c < sizeY; c++){
				printf("%d %c", board[f][c],(c < sizeY-1 ? ' ' : '\n'));
			}
		}
		printf("\n");
	}
	else{
		printf("No solution for %d %d board and start in %d %d\n", sizeX, sizeY, startX, startY);
	}
}
bool findKnightTour(int startX, int startY, int step, int sizeX, int sizeY,  int** board){
	bool solutionFound=false;
	int possibleMoves=8;
	int movX[]={2, 2,-2,-2, 1,-1, 1,-1};
	int movY[]={1,-1, 1,-1, 2, 2,-2,-2};
	int move,newX,newY;
	if(board[startX][startY]==sizeX*sizeY){
		solutionFound=true;
	}
	else{
		move=0;
		while(move<possibleMoves && !solutionFound){
			newX=startX+movX[move];
			newY=startY+movY[move];

			if(newX>=0 && newX<sizeX && newY>=0 && newY<sizeY && board[newX][newY]==-1){
				board[newX][newY]=step;
				solutionFound=findKnightTour(newX,newY,step+1,sizeX,sizeY,board);
				if(!solutionFound){
					board[newX][newY]=-1;
				}
			}
			move++;
		}
	}

	return solutionFound;
}

// N-Reinas Joyanes 4.4 pp 74
void testNQueens(){
	int i;
	int bsize=6;
	int queens[bsize];
	bool columns[bsize];
	bool lrdiags[2*bsize];
	bool rldiags[2*bsize];

	for(i=0;i<bsize;i++){
		queens[i]=-1;
		columns[i]=true;
	}

	for(i=0;i<bsize*2;i++){
		lrdiags[i]=true;
		rldiags[i]=true;
	}

	bool solutionFound=nQueens(0, bsize, queens, columns, lrdiags, rldiags);

	if(solutionFound){
		for(i=0;i<bsize;i++){
			printf("Reina en fila %d columna %d \n", i, queens[i]);
		}
	}
	else{
		printf("Solucion no encontrada para las N-Reinas en tablero de %d x %d \n", bsize, bsize);
	}
}
bool nQueens(int currentQueen, int bsize, int queens[], bool columns[], bool lrdiags[], bool rldiags[]){
	int c=0;
	bool solutionFound=false;

	if(currentQueen==bsize){
		solutionFound=true;
	}
	else{
		for(c=0;c<bsize && !solutionFound; c++){
			if(isValid(currentQueen, c, bsize, queens, columns, lrdiags, rldiags)){
				check(currentQueen,c,bsize, queens, columns, lrdiags, rldiags);
				solutionFound= nQueens(currentQueen+1,bsize, queens, columns, lrdiags, rldiags);
				if(!solutionFound){
					unCheck(currentQueen,c,bsize, queens, columns, lrdiags, rldiags);
				}
			}
		}
	}

	return solutionFound;
}
bool isValid(int f, int c, int bsize, int queens[], bool columns[], bool lrdiags[], bool rldiags[]){
	return columns[c] && lrdiags[f-c+bsize] && rldiags[f+c-1] ;
}
void check(int f, int c, int bsize, int queens[], bool columns[], bool lrdiags[], bool rldiags[]){
	queens[f]=c;
	columns[c]=false;
	lrdiags[f-c+bsize]=false;
	rldiags[f+c-1]=false;

}
void unCheck (int f, int c, int bsize, int queens[], bool columns[], bool lrdiags[], bool rldiags[]){
	queens[f]=-1;
	columns[c]=true;
	lrdiags[f-c+bsize]=true;
	rldiags[f+c-1]=true;
}

//Numeros Polidivisibles Joyanes 4.8 pp 74
void testPoliDivNumbers(){
	int i,size,m;
	size=9;
	m=4;

	bool used[size+1];
	int digits[size+1];

	for(i=0;i<=size;i++){
		digits[i]=0;
		used[i]=false;
	}

	poliDivNumbers(digits, size, m, 1, used);
}
void poliDivNumbers(int digits[], int size,int m,int cpos,bool used[]){
	int i,cdi;

	if(cpos == m+1){
		/*Imprimir numero*/
		for(i=1;i<=m;i++){
			printf("%d", digits[i]);
		}
		printf("\n");
	}
	else{
		for(cdi=1;cdi<=size;cdi++){
			digits[cpos]=cdi;
			if(used[cdi]==false && divisible(digits, size, cpos)){
				used[cdi]=true;
				poliDivNumbers(digits, size, m, cpos+1,used);
				used[cdi]=false;
			}
		}
	}
}
bool divisible(int digits[], int size, int divisor){
	int i,sum;
	switch(divisor){
		case 1: return true;
		case 2: return digits[2]%2==0;
		case 3:{
			sum=0;
			for(i=1;i<=3;i++){
				sum=sum+digits[i];
			}
			return sum % 3 == 0;
		}
		case 4: return ((10 * digits[3] + digits[4]) % 4 == 0);
		case 5: return (digits[5] == 5);
		case 6:{
			sum=0;
			for(i=1;i<=6;i++){
				sum=sum+digits[i];
			}
			return (sum % 3==0) && (digits[6] % 2==0);
		}
		case 7:{
			sum = digits[1] - digits[4] + digits[7] + 3 * (digits[6] - digits[3]) + 2 * (digits[5] - digits[2]);
			return abs(sum) % 7 == 0;
		}
		case 8: return ((100 * digits[6] + 10 * digits[7] + digits[8]) % 8 == 0);
		case 9: return true;
		default: return false;

	}
}

// Variaciones Joyanes 4.12 pp 74
void testVariations(){
	int n=10;
	int m=4;
	int i;
	char elements[]={'a','b','c','d','e','f','g','h','i','j'};

	/* Misma longitud que 'elements', indica si un elemento ha sido utilizado*/
	bool disp[n];

	/* Contiene los 'indices de los elementos en la variacion actual, ej:
	 * variation={4, 2, 0, 5} representa la variacion 'e c a f'*/
	int variation[m];

	/*Inicializacion de arreglos auxiliares */
	for(i=0;i<n;i++){ disp[i]=true; }
	for(i=0;i<m;i++){ variation[i]=-1; }

	int currentPos=0;
	generateVariations(n,m,currentPos,elements,disp,variation);
}
void generateVariations(int n, int m, int currentPos,char elements[], bool disp[], int variation[]){
	int i;
	if(m==0){ /*Imprimir la variacion*/
		for(i=0;i<currentPos;i++){
			printf("%c", elements[variation[i]]);
		}
		printf("\n");
	}
	else{
		for(i=0;i<n; i++){
			if(disp[i]==true){ /*Elemento no incluido en la variacion*/
				disp[i]=false;
				variation[currentPos]=i;
				generateVariations(n,m-1,currentPos+1,elements,disp,variation);
				disp[i]=true;
				variation[currentPos]=-1;
			}
		}
	}
}


void testArraySum(){
	int size=10000;
	long long start, end;
	long long sumHead, sumTail;

//	int a[]={1,2,3,4,5};
	int *a=(int*) malloc(size*sizeof(int));

	int i;
	for(i=0;i<size;i++){
		a[i]=rand() % 20;
	}


	struct timeval tp;
	struct timezone tz;


	gettimeofday(&tp, &tz);
	start = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	sumHead=arraySumHead(a,size,0);

	gettimeofday(&tp, &tz);
	end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	printf("%d %llu\n",sumHead, (end-start));

	gettimeofday(&tp, &tz);
	start = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	sumTail=arraySumTail(a,size,0, 0);

	gettimeofday(&tp, &tz);
	end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	printf("%d %llu\n",sumTail, (end-start));

}
long long arraySumHead(int a[],int size, int pos){
	if(pos==size-1){
		return a[pos];
	}

	return a[pos]+arraySumHead(a,size,pos+1);
}
long long arraySumTail(int a[],int size, int pos, long long sum){
	if(pos==size){
		return sum;
	}

	return arraySumTail(a,size,pos+1, sum +a[pos]);
}


void testArrayMin(){
	int i, m;
	int size=7; /*Igual a la cantidad de elementos en a*/
	int a[]={4,6,2,5,3,5,1};

	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	printf("\n");

	m=arrayMin(a, size-1);
	printf("El minimo es -> %d \n", m);

}

int arrayMin(int a[], int pos){
	if(pos==0){
		return a[0];
	}
	else{
		return min(a[pos], arrayMin(a, pos-1));
	}
}

int min(int a, int b){
	return a<b? a:b;
}
