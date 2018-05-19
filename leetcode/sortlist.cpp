
//
// Created by 傅妍玫 on 2018/5/19.
//
#include <iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  // 用O(nlogn)实现 linkedlist的排序算法

class Solution {
public:
    ListNode* sortList(ListNode* head) {


        // 用归并排序， 最重要的是找到中间位置在哪里 用快慢表找中间位置 同时要记录mid的前一个节点
        ListNode* start = head ;
        if(start == NULL|| start->next == NULL){
            return start;
        }


        ListNode *slow = start;
        ListNode *fast = start;
        ListNode *pre = start;
        while(fast != NULL && fast->next != NULL){

            pre = slow;
            slow = slow->next;
            fast = fast->next->next;

        }
        pre->next = NULL;  // 保证和原来的链表断开
        ListNode* left = sortList(start);

        ListNode* right = sortList(slow);
//        merge(start, end, pre);
        ListNode *dummy = new ListNode(-1);
        ListNode * tail = dummy;
        while(left != NULL && right != NULL){
            if (left->val < right->val){
                tail->next = left;
                left = left->next;
            }else{
                tail->next = right;
                right = right->next;
            }


            tail = tail->next;
            tail->next = NULL;
        }

        while (left != NULL) {
            tail->next = left;
            left = left->next;
            tail = tail->next;
        }
        while (right != NULL) {
            tail->next = right;
            right = right->next;
            tail = tail->next;
        }


        ListNode* return_head = dummy->next;
        delete dummy;
        dummy = NULL;
        return return_head;



    }

//    void merge( ListNode * left, ListNode * right, ListNode*dummy){
//
//
//
//
//
//
//    }





};


//class Solution {
//public:
//
//    // 采用快速排序的方式
//    void sortListHelper(ListNode * head, ListNode * tail){
//            if(head -> next == tail){
//                return;
//            }
//
//            ListNode * pre = head;
//            ListNode * cur = head->next;
//
//            ListNode * pivot = cur;
//
//            while(cur->next && cur->next != tail){
//                if(pivot->val > cur->next->val){
//                    ListNode* tmp = pre->next;
//                    cur->next = cur->next->next;
//                    pre->next->next = tmp;
//                }else{
//                    cur = cur->next;
//                }
//            }
//
//            sortListHelper(head, pivot);
//
//        /* Here is the trick. */
//        while (pivot -> next != tail && pivot -> next -> val == pivot -> val)
//            pivot = pivot -> next;
//        if (pivot -> next != tail) sortListHelper(pivot, tail);
//        }
//
//        ListNode* sortList(ListNode* head) {
//            ListNode * dummy = new ListNode(0);
//
//            dummy->next  = head;
//
//    }
//};

int main(){
    ListNode * l1 = (ListNode *) malloc(sizeof(ListNode));
    l1->val = 4;
    l1->next=NULL;


    ListNode * l2 = (ListNode *) malloc(sizeof(ListNode));
    l2->val = 2;
    l2->next=NULL;


    ListNode * l3 = (ListNode *) malloc(sizeof(ListNode));
    l3->val = 1;
    l3->next=NULL;


    ListNode * l4 = (ListNode *) malloc(sizeof(ListNode));
    l4->val = 3;
    l4->next=NULL;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution s;
    s.sortList(l1);

    return 0;
}