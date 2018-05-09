//
// Created by 傅妍玫 on 2018/5/9.
//

#include <iostream>
#include <queue>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:


    bool isSymmetric(TreeNode* root) {


        // 非递归
        TreeNode *left, *right;

        if(root==NULL) return true;
        queue<TreeNode*> q1, q2;

        q1.push(root->left);
        q2.push(root->right);


        while(!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();

            if(left == NULL && right == NULL){
                continue;
            }
            if(left == NULL || right == NULL){
                return false;
            }

            if(left->val != right->val){
                return false;
            }
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }

        return true;


//        if(root==NULL)
//            return true;
//        return helper(root->left, root->right);
//
//        return true;
    }

    // 递归
    bool helper(TreeNode * node1, TreeNode * node2){
        if (node1 == NULL && node2 == NULL)
            return true;
        if(node1 == NULL || node2 == NULL) return false;

        if(node1->val  != node2->val)
            return false;

        return helper(node1->left, node2->right) && helper(node1->right, node2->left);
    }
};


