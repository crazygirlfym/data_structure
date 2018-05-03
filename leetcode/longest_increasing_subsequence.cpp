//
// Created by 傅妍玫 on 2018/5/3.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    //  时间复杂度  Time (O^2)
//    int lengthOfLIS(vector<int>& nums) {
//        int maxlen = 0;
//        std::vector<int>dp(nums.size(), 1);
//        for(int i = 0; i < nums.size(); i++){
//            for(int j = 0; j < i; j++)
//                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
//            maxlen = max(maxlen, dp[i]);
//        }
//        return maxlen;
//    }


    // 实现时间复杂度为 nlogn

    int lengthOfLIS(vector<int>& nums){

        if (nums.empty()) return 0;

        vector<int> ends {nums[0]};

        for (auto a : nums){
            // 如果比当前的首元素还小，则直接替换首元素
            if(a < ends[0]) ends[0] = a;
            // 如果比栈顶的元素大，则直接进栈
            else if( a > ends.back()) ends.push_back(a);
            // 二分查找 ，找到第一个不小于(大于等于）该数的值然后替换
            else{

                int left = 0;
                int right = ends.size();
                while(left < right){
                    int mid = left + (right - left)/2;
                    if(ends[mid] < a) left = mid + 1;
                    else right = mid;
                }

                ends[right] = a;


            }
        }

       return ends.size();

    }

    // 首先采用的是O(n^2)的方法

    string sequenceOfLIS(vector<int>& nums){

    }

};



int main() {
    Solution s;

    int mynum[8] = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> num(mynum, mynum + 8);
    int maxLen = s.lengthOfLIS(num);


    std::cout << maxLen << std::endl;
    return 0;
}