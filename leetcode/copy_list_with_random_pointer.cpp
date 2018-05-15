//
// Created by 傅妍玫 on 2018/5/15.
//

#include <iostream>
#include <map>
using namespace std;

//  Definition for singly-linked list with a random pointer.
  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // 本题的难点在于random的那个新节点 可能还没有new出来
        if(head == NULL) return NULL;
        RandomListNode *dummy = (RandomListNode * )malloc(sizeof(RandomListNode));

        map<RandomListNode *,RandomListNode *> m;

        RandomListNode *pre = dummy;
        RandomListNode * p = head;

        RandomListNode * c_head = (RandomListNode * )malloc(sizeof(RandomListNode));
        c_head->label = head->label;
        c_head->next = NULL;
        c_head->random = NULL;
        m.insert(pair<RandomListNode *,RandomListNode *>(p, c_head));
        pre->next = c_head;
        p = p->next;
        pre = pre->next;

        while(p != NULL){

            RandomListNode * tmp = (RandomListNode * )malloc(sizeof(RandomListNode));
            tmp->label = p->label;
            tmp->next=NULL;
            tmp->random=NULL;
            pre->next= tmp;
            m.insert(pair<RandomListNode *,RandomListNode *>(p, tmp));
            pre = pre->next;
            p = p->next;

        }

        // random

        p = head;
        pre = dummy->next;
        while(p != NULL){
            RandomListNode * ori_random = p->random;
            RandomListNode * cur_random = m[ori_random];
            pre->random = cur_random;
            p = p->next;
            pre = pre->next;
        }



        return dummy->next;


    }
};