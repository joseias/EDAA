#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main2(void)
{
	unsigned char i=5;
	unsigned char j=~i;
	printf("%d\n", sizeof(unsigned short));
	printf("%lu", j);
//
//    unsigned long N=0, L=0, U=0, MAX=0, MAXM=0;
//
//    while(scanf("%lu %lu %lu", &N, &L, &U) != EOF){
//
//    	//printf("%lu %lu %lu\n", N, L, U);
//
//        MAX=0;
//        MAXM=L;
//        for(unsigned long M=L;M<=U;M++){
//            if((N|M) > MAX ){
//                MAX=N|M;
//                MAXM=M;
//            }
//        }
//        printf("%lu\n",MAXM);
//
//    }

	return 0;
}
