#pragma once
#ifndef _LISTFUNC_H
#define _LISTFUNC_H

#include "HeaderNeed.h"


struct LNode{
	ElemType data;
	struct LNode *next;
};
typedef struct LNode *Link, *Position;

struct LinkList{
	Link head,tail;
	int len;
};
typedef struct LinkList LinkList;

void MakeNode(Link &p, ElemType e);
void FreeNode(Link &p);
void InitList(LinkList &L);
void DestroyList(LinkList &L);
void ClearList(LinkList &L);
void InsFirst(LinkList &L, Link h, Link s);
Status DelFirst(LinkList &L, Link h, Link &s);
void Append(LinkList &L, Link s);
Position PriorPos(const LinkList &L, Link s);
inline Position NextPos(Link s);
Status Remove(LinkList &L, Link &q);
void InsBefore(LinkList &L, Link &p, Link s);
void InsAfter(LinkList &L, Link &p, Link s);
inline Status SetCurElem(Link &p, ElemType e);
inline ElemType GetCurElem(Link p);
Status ListEmpty(const LinkList &L);
inline int ListLength(const LinkList &L);
inline Position GetHead(const LinkList &L);
inline Position GetTail(const LinkList &L);
Status LocatePos(const LinkList &L, int i, Link &p);
Position LocateElem(const LinkList &L, ElemType e, Status (*compare)(ElemType, ElemType));
void ListTraverse(const LinkList &L, void (*visit)(ElemType));
void OrderInsert(LinkList &L, ElemType e, int (*comp)(ElemType, ElemType));
Status OrderLocateElem(LinkList L, ElemType e, Position &q, int (*compare)(ElemType,ElemType));

inline Position NextPos(Link s){
	return s->next;
}

inline Status SetCurElem(Link &p, ElemType e){
	p->data = e;
}

inline ElemType GetCurElem(Link p){
	return p->data;
}

inline int ListLength(const LinkList &L){
	return L.len;
}

inline Position GetHead(const LinkList &L){
	return L.head;
}

inline Position GetTail(const LinkList &L){
	return L.tail;
}


#endif