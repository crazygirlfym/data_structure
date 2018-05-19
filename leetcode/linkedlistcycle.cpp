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

  // 不使用额外的空间，判断一个linked list 是否有环

class Solution {
public:
    bool hasCycle(ListNode *head) {

        // 利用快慢表  如果慢表能追上 则说明有环
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast != NULL && slow != NULL && fast->next  != NULL){
            if(fast->next == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }

        return false;


    }
};