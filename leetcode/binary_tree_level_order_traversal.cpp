//
// Created by 傅妍玫 on 2018/5/9.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 层次遍历 ， 用queue实现   每一层用 NULL 表示下结束
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root ==NULL) {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        vector<int> tmp;
        while (q.size() != 1){
            TreeNode * p = q.front();
            q.pop();
            if(p != NULL){
                tmp.push_back(p->val);

                if(p->left != NULL){
                    q.push(p->left);

                }
                if(p->right != NULL){
                    q.push(p->right);
                }
            }else{
                q.push(NULL);
                result.push_back(tmp);
                tmp.clear();
            }


        }
        result.push_back(tmp);

        return result;



    }
        // 在前面的基础上 添加一个变量 判断是否需要逆序
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> result;
            bool flag = false;
            if(root ==NULL) {
                return result;
            }

            queue<TreeNode *> q;
            q.push(root);
            q.push(NULL);

            vector<int> tmp;
            while (q.size() != 1){
                TreeNode * p = q.front();
                q.pop();
                if(p != NULL){
                    tmp.push_back(p->val);

                    if(p->left != NULL){
                        q.push(p->left);

                    }
                    if(p->right != NULL){
                        q.push(p->right);
                    }
                }else{
                    q.push(NULL);

                    if(flag) {
                        int i = tmp.size() - 1;
                        int j = 0;

                        while (j <= i) {
                            int temp = tmp[i];
                            tmp[i] = tmp[j];
                            tmp[j] = temp;
                            i--;
                            j++;
                        }

                    }
                    flag = !flag;
                    result.push_back(tmp);
                    tmp.clear();
                }


            }
            if(flag) {
                int i = tmp.size() - 1;
                int j = 0;

                while (j <= i) {
                    int temp = tmp[i];
                    tmp[i] = tmp[j];
                    tmp[j] = temp;
                    i--;
                    j++;
                }

            }
            result.push_back(tmp);

            return result;

    }
};