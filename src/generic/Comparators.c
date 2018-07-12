#include "Comparators.h"

int compareInt(const void *lhs, const void *rhs){
	const int *llhs = (const int*)lhs;
	const int *lrhs = (const int*)rhs;

	if (*llhs < *lrhs) {
		return -1;
	}
	else {
		if (*llhs > *lrhs) {
			return 1;
		}
	}

	return 0;
}

int comparePoints(const void* p1, const void* p2){
	const Point* llhs = (const Point*) p1;
	const Point* lrhs = (const Point*) p2;

	if ((llhs->x + llhs->y) < (lrhs->x + lrhs->y)) {
		return -1;
	}
	else {
		if ((llhs->x + llhs->y) > (lrhs->x + lrhs->y)) {
			return 1;
		}
	}
		
	return 0;
}