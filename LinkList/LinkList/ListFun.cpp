#include "ListFun.h"
#include <iostream>
using std::cout; using std::cin; using std::endl;

void MakeNode(Link &p, ElemType e){
	p = (Link)malloc(sizeof(LNode));
	if(!p)
		exit(ERROR);
	p->data = e;
}

void FreeNode(Link &p){
	free(p);
	p = NULL;
}

void InitList(LinkList &L){
	Link p;
	p = (Link)malloc(sizeof(LNode));
	if(p){
		p->next = NULL;
		L.head = L.tail = p;
		L.len = 0;
	}
	else
		exit(ERROR);
}

void ClearList(LinkList &L){
	Link p, q;
	if(L.head != L.tail){
		 p = q = L.head->next;
		 L.head->next = NULL;
		 while (p != L.tail){
			 p = q->next;
			 free(q);
			 q = p;
		 }
		 free(q);
		 L.tail = L.head;
		 L.len = 0;
	}
}

void DestroyList(LinkList &L){
	ClearList(L);
	FreeNode(L.head);
	L.tail = NULL;
}

void InsFirst(LinkList &L, Link h, Link s){
	s->next = h->next;
	h->next = s;
	if(h == L.tail)
		L.tail = s;
	L.len++;
}

Status DelFirst(LinkList &L, Link h, Link &s){
	s = h->next;
	if(s){
		h->next = s->next;
		if(!h->next)
			L.tail = h;
		L.len--;
		return OK;
	}
	else
		return FALSE;
}

void Append(LinkList &L, Link s){
	int i = 1;
	L.tail->next = s;	//Don't forget modify this!
	while (s->next){
		s = s->next;
		i++;
	}
	L.tail = s;
	L.len += i;
}

Position PriorPos(const LinkList &L, Link s){
	Link q;
	q = L.head->next;
	if(q == s)
		return NULL;
	else{
		while(q->next != s)
			q = q->next;
		return q;
	}
}

Status Remove(LinkList &L, Link &q){
	if (L.len == 0){
		q = NULL;
		return FALSE;
	}
	q = PriorPos(L, L.tail);
	if(!q){
		L.tail = q;
		L.len--;
		return OK;
	}
	else
		return FALSE;
}

void InsBefore(LinkList &L, Link &p, Link s){
	Link q;
	q = PriorPos(L,p);
	if(!q)
		q = L.head;
	s->next = p;
	q->next = s;
	p = s;		//p indicate the newly inserted element
	L.len++;
}

void InsAfter(LinkList &L, Link &p, Link s){
	if(p == L.tail)
		L.tail = s;
	s->next = p->next;
	p->next = s;
	p = s;
	L.len++;
}


Status ListEmpty(const LinkList &L){
	if(L.len == 0)		/*if write if(L.len), then the result will be totally different, why? Just exchange TRUE and FALSE!*/
		return TRUE;
	else
		return FALSE;
}


Status LocatePos(const LinkList &L, int i, Link &p){
	int j;
	if(i<0 || i>L.len)
		return ERROR;
	else{
		p = L.head;
		for(j=1; j<=i; j++)
			p = p->next;
		return OK;
	}
}

Position LocateElem(const LinkList &L, ElemType e, Status (*compare)(ElemType, ElemType)){
	Link p = L.head;
	do 
		p = p->next;
	while (p && !(compare(p->data, e)));
	return p;
}

void ListTraverse(const LinkList &L, void (*visit)(ElemType)){
	Link p = L.head;
	int j;
	for(j=1; j<=L.len; j++){
		p = p->next;
		visit(p->data);
	}
	cout << endl;
}

void OrderInsert(LinkList &L, ElemType e, int (*comp)(ElemType, ElemType)){
	Link o, p, q;
	q = L.head;
	p = q->next;
	while(p && (comp(p->data, e)<0)){
		q = p;
		p = p->next;
	}
	o = (Link)malloc(sizeof(LNode));
	o->data = e;
	q->next = o;
	o->next = p;
	L.len++;
	if(!p)		/*this means inserted at the end of the list*/
		L.tail = o;
}

Status OrderLocateElem(LinkList L, ElemType e, Position &q, int (*compare)(ElemType,ElemType)){
	Link cp = L.head, pp;
	do {
		pp = cp;
		cp = cp->next;
	} while (cp && (compare(cp->data, e) < 0));
	if(!cp || (compare(cp->data, e)>0)){
		q = pp;
		return FALSE;
	}
	else{
		q = cp;
		return TRUE;
	}
}