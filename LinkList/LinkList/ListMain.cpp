#include "ListFun.h"
#include "BasicFunc.h"

using std::cin; using std::cout; using std::endl;

int main(void)
{
	Link p, h;
	LinkList L;
	Status i;
	int j;

	InitList(L);
	for(j = 1; j <= 2; j++){
		MakeNode(p, j);
		InsFirst(L, L.tail, p);
	}
	OrderInsert(L, 0, comp);

	for(j=0; j<=3; j++){
		i = OrderLocateElem(L, j, p, comp);
		if(i)
			cout << "There is element valued at " << p->data 
				<< " in the list!" << endl; 
		else
			cout << "There is no element valued at " << j 
			<< " in the list!" << endl; 
	}

	cout << "Print linklist out:" <<endl;
	ListTraverse(L, printfun);

	for(j=1; j<=4; j++){
		cout << "Delete list head node: " << endl;
		DelFirst(L, L.head, p);
		if(p)
			cout << GetCurElem(p) << endl;
		else
			cout << "Empty list, cannot delete " << p << endl;
	}
	cout << "Number of nodes in L = " << ListLength(L) << endl;
	if(ListEmpty(L))
		cout << "L is empty" << endl;
	else
		cout << " L is not empty" << endl;

	MakeNode(p, 10);		/*this step must done outside for loop*/
	p->next = NULL;
	for(j=4; j>=1; j--){
		MakeNode(h, j*2);
		h->next = p;
		p = h;
	}
	Append(L, h);
	OrderInsert(L, 12, comp);
	OrderInsert(L, 7, comp);
	cout << "Print linklist out:" <<endl;
	ListTraverse(L, printfun);

	for(j=1; j<=2; j++){
		p = LocateElem(L, j*5, equal);
		if(p)
			cout << "There is node got value " << j*5 << " in L." << endl;
		else
			cout << "There is no node got value " << j*5 << " in L." << endl;	
	}
	for(j=1; j<=2; j++){
		LocatePos(L, j, p);
		h = PriorPos(L, p);
		if(h)
			cout << p->data << "'s previous data is " << h->data << endl;
		else
			cout << p->data << " has no previous data." << endl;
	}

	getchar();

	return 0;
}