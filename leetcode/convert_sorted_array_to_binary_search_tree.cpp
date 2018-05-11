//
// Created by 傅妍玫 on 2018/5/11.
//

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if( nums.size() == 0){
            return NULL;
        }
        return helper(nums, 0, nums.size()-1);
    }


    TreeNode * helper(vector<int>& nums, int start, int end){
        if(start > end){
            return NULL;
        }
        if(start == end){
            TreeNode *rroot =(TreeNode *) malloc(sizeof(TreeNode));
            rroot->val = nums[start];
            rroot->left = NULL;
            rroot->right =  NULL;
            return rroot;

        }
        int mid = start + (end-start) /2;
        TreeNode *rroot =(TreeNode *) malloc(sizeof(TreeNode));
        rroot->val = nums[mid];


        TreeNode *left = helper(nums, start, mid-1);
        TreeNode *right = helper(nums, mid+1, end);

        rroot->left = left;
        rroot->right = right;

        return rroot;


    }
};