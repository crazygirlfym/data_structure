//
// Created by 傅妍玫 on 2018/5/10.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bulidHelper(preorder, inorder, 0, preorder.size()-1, 0);
    }


    TreeNode* bulidHelper(vector<int>& preorder, vector<int>& inorder, int in_start, int end_start, int pre_start){
        if(in_start > end_start){
            return NULL;
        }

        if(in_start == end_start){
//            TreeNode node = TreeNode(inorder[in_start]);
            TreeNode *rnode = (TreeNode *) malloc(sizeof(TreeNode));
            rnode->val = inorder[in_start];
            rnode->left = NULL;
            rnode->right =NULL;

            return rnode;
        }

        TreeNode *rroot =(TreeNode *) malloc(sizeof(TreeNode));
        rroot->val = preorder[pre_start];

        rroot->left = NULL;
        rroot->right = NULL;

        int index = in_start;
        for(int i=in_start; i<= end_start; i++){
            if(inorder[i] == preorder[pre_start]){
                index = i;
                break;
            }
        }



        TreeNode* left =  bulidHelper(preorder, inorder, in_start, index-1, pre_start + 1 );
        TreeNode* right = bulidHelper(preorder, inorder, index + 1, end_start , pre_start + index - in_start + 1);

        rroot->left = left;
        rroot->right = right;


        return rroot;

    }

};


int main(){
    Solution s;
    vector<int> preorder{-1};
    vector<int> inorder{-1};

    s.buildTree(preorder, inorder);

}