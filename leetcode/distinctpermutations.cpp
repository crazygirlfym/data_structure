//
// Created by 傅妍玫 on 2018/5/7.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 直接采用现有的方法
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>>result;
//        sort(begin(nums), end(nums));
//
//        do{
//            result.push_back(nums);
//        } while (next_permutation(begin(nums), end(nums)));
//
//        return result;
//
//    }
    // 采用DFS
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;

            helper(nums, 0, result);
            return result;
    }


    void helper(vector<int>& nums, int index, vector<vector<int>> &res){
        if(index >= nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i=index; i< nums.size();i++){
            int temp = nums[index];
            nums[index] = nums[i];
            nums[i] = temp;

            helper(nums, index+1, res);

            temp = nums[index];
            nums[index] = nums[i];
            nums[i] = temp;

        }



    }

    // 和以上的逻辑相同，需要处理重复的数字即可
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        helper_unique(nums, 0, result);
        return result;
    }

    void helper_unique(vector<int>& nums, int index, vector<vector<int>> &res){

        if(index >= nums.size()){
            res.push_back(nums);
            return ;
        }

        for(int i=index; i<nums.size();i++){

            if(i==index || nums[index] != nums[i]){
                int temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;

                helper_unique(nums, index+1, res);

                temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;
            }

        }


    }
};

int main(){
    vector<int> nums{1,1,2};
    Solution s;
    vector<vector<int>>result = s.permuteUnique(nums);

    for(int i=0; i< result.size(); i++){
        for(int j=0; j< result[i].size(); j++){
            cout << result[i][j];
        }
        cout << endl;
    }
}