/*
 * =====================================================================================
 *
 *       Filename:  linklist.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2011 11:13:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */
#include "pomme_list.h"
static inline __link_add(struct link_head *new, struct link_head *prev,struct link_head *next)
{
	prev->next = new;
	new->prev = prev;
	new->next = next;
	next->prev = new;
}
inline link_add(struct link_head *new, struct link_head *head)
{
	__link_add(new,head,head->next);
}
static inline __link_del(struct link_head *prev, struct link_head *next)
{
	prev->next = next;
	next->prev = prev;
}
inline link_del(struct link_head *entry)
{
	__link_del(entry->prev, entry->next);
	entry->prev = LIST_POSITION_1;
	entry->next = LIST_POSITION_2;
}