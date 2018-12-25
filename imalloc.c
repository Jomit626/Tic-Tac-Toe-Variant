#include "imalloc.h"
#include <stdlib.h>

void *Base,*End;
char* Poiter;
int size = 0;
void imallocInit(size_t isize)
{
	Base = malloc(isize);
	Poiter =(char*)Base;
	End = Poiter + isize;
	size = isize;
}
void * imalloc(size_t isize) {
	void* t = (void*)Poiter;
	Poiter += isize;
	if ((void*)Poiter > End) return NULL;
	return t;
}
void ifree() {
	free(Base);
	Base = End = NULL;
	Poiter = NULL;
	size = 0;
}
void reInit(){
	Poiter = (char*)Base;
}
int getSize(){
	return size;
}

