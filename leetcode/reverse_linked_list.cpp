//
// Created by 傅妍玫 on 2018/5/5.
//
//
#include <iostream>
#include <vector>

using namespace std;


 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;

     ListNode(int x) : val(x), next(NULL) {}
 };


//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//
//    }
//};

// 翻转Linked List
class Solution {
public:
    ListNode* helper(ListNode* cur, ListNode* pre){

        ListNode * res(NULL);

        if(cur){
            res = helper(cur->next, cur);
            cur->next = pre;

        }else{
            res = pre;
        }

        return res;
    }
    // 采用递归的方法
//    ListNode* reverseList(ListNode* head) {
//        return helper(head, NULL);
//    }


    //采用非递归的方法
    ListNode* reverseList(ListNode* head){
        ListNode * p1(NULL),  * p2(head);


        while(p2){

            ListNode *node = p2->next;

            p2->next = p1;
            p1 = p2;
            p2 = node;

        }
        return p1;


    }

    // 将m, n之间的list 翻转  可参考上述非递归的方式
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode * result =(ListNode*) malloc(sizeof(ListNode));
        result->next=head;
        result->val = 0;


        ListNode * pre = NULL;


        int i = 1;
        // 找到当前的 头节点和 前一个节点
        while(i< m){
            pre = head;
            head = head->next;
            i++;
        }


        int j = 0;

        ListNode *p2 = head;

        ListNode *p1 = NULL;
        ListNode *ne = head;
        while(j < n-m + 1){
            ne = p2->next;
            ListNode *node = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = node;

            j++;
        }

        if(pre != NULL)
            pre->next = p1;
        else{
            result->next = p1;
        }

        head->next = ne;


        return result->next;

    }
    // K组进行一次

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode * result =(ListNode*) malloc(sizeof(ListNode));
        result->next=head;
        result->val = 0;

        int len = getLinkLen(head);

            for(int i=0;i<len/k;i++){
                ListNode *tmp= reverseBetween(result->next,i*k+1, (i+1)*k);
                result->next = tmp;
            }


            return result->next;

    }


    int getLinkLen(ListNode*head){

        int result = 0;
        ListNode * node = head;
        while(node != NULL){
            node = node->next;
            result ++;
        }

        return result;
    }


};




int main(){
    Solution s;
    ListNode * l1 = (ListNode*) malloc(sizeof(ListNode));
    l1 ->val = 1;


    ListNode * l2 = (ListNode*) malloc(sizeof(ListNode));
    l2 ->val = 2;

    ListNode * l3 = (ListNode*) malloc(sizeof(ListNode));
    l3->next = NULL;
    l3 ->val = 3;

    ListNode * l4 = (ListNode*) malloc(sizeof(ListNode));
    l4->next = NULL;
    l4 ->val = 4;

    ListNode * l5 = (ListNode*) malloc(sizeof(ListNode));
    l5->next = NULL;
    l5 ->val = 5;



    ListNode * l6 = (ListNode*) malloc(sizeof(ListNode));
    l6->next = NULL;
    l6 ->val = 6;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;




//    while(l1 != NULL){
//        std::cout << l1->val<< std::endl;
//        l1 = l1->next;
//    }
////    const ListNode &node = ListNode(1);
//    ListNode l11 = ListNode(1);
//    ListNode l12 = ListNode(2);
//    ListNode l13 = ListNode(3);
//    l11.next = &l12;
//    l12.next = &l13;
//
//
//
//    std::cout << l11.val<< std::endl;
//
//    ListNode *node = l11.next;
//
//    while(node != NULL){
//        std::cout << node->val<< std::endl;
//        node = node->next;
//    }


//    ListNode *l1 = ListNode(1);
//    ListNode *l2 = ListNode(2);
//    ListNode *l3 = ListNode(3);
//    l1.next = & l2;
//    l2.next = & l3;

    ListNode l11  = ListNode (1);
    ListNode l22 = ListNode (2);
    ListNode l33= ListNode(3);
    l11.next = &l22;
    l22.next = &l33;


//    ListNode * tmp = & l11;
//    while(tmp != NULL){
//        std::cout << tmp->val<< std::endl;
//        tmp = tmp->next;
//    }
////
//    l1.next = &l2;
//    l2.next = &l3;
//
//



//    ListNode *result = s.reverseList(l1);

//    ListNode *result = s.reverseBetween(l1, 1, 5);
//
        ListNode *result = s.reverseKGroup(l1,2);
    while(result!= NULL){
        std::cout << result->val<< std::endl;
        result = result->next;


    }

//    ListNode *result = s.reverseList(&l1);

//
//    while(result != NULL){
//        std::cout << result->val<< std::endl;
//        result = result->next;
//
//    }

    return 0;
}
