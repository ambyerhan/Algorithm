#pragma once

# ifndef _LIST_H_
# define _LIST_H_

typedef int ElemType;

struct ListNode
{
	ElemType data;
	ListNode *next;
};

ListNode *createEmptyList();
ListNode *createList(ElemType *a, int len);

# endif