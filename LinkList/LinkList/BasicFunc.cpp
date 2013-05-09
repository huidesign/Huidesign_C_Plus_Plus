#include "BasicFunc.h"

Status equal(ElemType a, ElemType b){
	if(a == b)
		return TRUE;
	else
		return FALSE;
}

int comp(ElemType a, ElemType b){
	if(a == b)
		return 0;
	else
		return (a-b) / abs(a-b);
}

void printfun(ElemType a){
	std::cout << a << " ";
}