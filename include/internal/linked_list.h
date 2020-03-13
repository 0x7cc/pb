//
// Created by 0x7cc on 2020/3/8.
//

#ifndef PB_LINKED_LIST_H
#define PB_LINKED_LIST_H

typedef struct LINKED_LIST_NODE_T
{
  struct LINKED_LIST_NODE_T* next;
} LINKED_LIST_NODE, *PLINKED_LIST_NODE;

#define PB_LINKED_LIST_APPEND(list, node)          \
  {                                                \
    PLINKED_LIST_NODE n = (PLINKED_LIST_NODE)list; \
    while (n->next)                                \
      n = n->next;                                 \
    n->next = node;                                \
  }

#define PB_LINKED_LIST_FOREACH(list) \
  for (PLINKED_LIST_NODE node = ((PLINKED_LIST_NODE)list)->next; node != NULL; node = node->next)

#endif //PB_LINKED_LIST_H
