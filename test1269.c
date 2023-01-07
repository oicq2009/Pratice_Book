#include <stdio.h>

/* 给一个头结点为head的非空链表，返回链表的中间节点
 * 如果有两个中间节点，则返回第二个中间节点。
 * 奇数个：1 2 3 4 5  (3)
 * 偶数个：1 2 3 4 5 6  (3&4, we return 4) 
 * 
 * 求长度法 O(N)
 * 
 * 要求：只能遍历链表1次
 * 快慢指针
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode (
    struct ListNode* head
    )
{
    struct ListNode* slow, *fast; //创建快指针和慢指针
    slow = fast = head;
    while (
        fast != NULL &&           //奇数情况
        fast->next != NULL        //偶数情况
        ) 
    {
        slow = slow->next;        //走一步
        fast = fast->next->next;  //走两步
    }

    return slow;
}

