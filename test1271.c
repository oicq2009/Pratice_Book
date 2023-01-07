#include <stdio.h>

/* 合并两个有序链表
 * 将两个升序链表合并为一个新的升序链表并返回。
 * 新链表是通过拼接给定的两个链表的所有结点组成的
 * 1->2->4
 * 1->3->4
 * 1->1->2->3->4->4
 * 
 * 1.依次比较链表中的结点，每次取小的节点，尾插到新链表即可
 * 
 * 取节点，迭代遍历再尾插
 * 记录tail可以避免每次都找尾
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists (struct ListNode* l1, struct ListNode* l2) {
    // 如果其中一个链表为空，返回另一个
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    struct ListNode* head = NULL, *tail = NULL;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            if (head == NULL) {
                head = tail = l1;
            } else {
                tail->next = l1;
                tail = l1;
            }
            l1 = l1->next;
        } else {
            if (head == NULL) {
                head = tail = l2;
            } else {
                tail->next = l2;
                tail = l2;
            } 
            l2 = l2->next;
        } 
    }
    if (l1) tail->next = l1; 
    if (l2) tail->next = l2;

    return head;
}


