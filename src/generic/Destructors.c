#include "Destructors.h"

void destroyPoints(const void* data){
	free(data);	
}