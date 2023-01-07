#include <stdio.h>

/* 链表中倒数第k个结点
 * 输入一个链表，输出该链表中倒数第k个结点
 * 要求：只能遍历一次
 * 
 * 1 2 3 4 5;
 * 
 * 仍然使用快慢指针：
 * 但是这个快慢指针和之前有些许不一样
 * 1. fast先走k步
 * 2. slow和fast再一起走，fast == NULL时，slow 就是倒数第k个
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* FindKthToTail (
    struct ListNode* pListHead,
    int k
    )
{
    struct ListNode* fast, *slow;
    slow = fast = pListHead;
    while (k--)
    {
        //printf("fast:%p, k:%d\n", fast, k);
        //如果fast提前就到空了，说明k大于链表的长度
        if (fast == NULL) 
        {
            return NULL;
        }  
        fast = fast->next;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

