//
// Created by 傅妍玫 on 2018/5/24.
//

//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:

    // 可以将该题转换为是否有环的问题


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        // 将其相连后判断是否有环
        ListNode * node = headA;

        while(node->next != NULL){
            node = node->next;
        }
        node->next = headB;


        ListNode *result = listCycle(headA);
        node->next = NULL;  // 还原
        return result;

    }
private:
    ListNode *listCycle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        // 先找到相遇点
        while(slow != fast){
            if(fast == NULL || fast->next ){
                return NULL;

            }
            slow = slow->next;
            fast = fast->next->next;
        }


        slow = head;
        fast = fast->next;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;


    }

};