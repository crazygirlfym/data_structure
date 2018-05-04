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

    vector<int> getDP(vector<int>& nums){

        int maxlen = 0;
        std::vector<int>dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            maxlen = max(maxlen, dp[i]);
        }
        return dp;

    }


    // 首先采用的是O(n^2)的方法

    vector<string> sequenceOfLIS(vector<int>& nums){
        vector<int> dp = getDP(nums);

        int maxLen = -1;

        for(int i=0;i<dp.size(); i++){
            if (maxLen < dp[i]){
                maxLen = dp[i];
            }
        }

        vector<string> out_result;

        for(int i=dp.size() -1; i>=0 ;i--){

            if(dp[i] == maxLen){
                vector<int> tmp = {nums[i]};


                helper(nums, dp, tmp, i-1, dp[i], out_result);
            }

        }
        return out_result;

    }


    void helper(vector<int>& nums, vector<int>& dp, vector<int> & tmp, int index, int lastDp, vector<string> & out_result){

        if (lastDp == 1){
            string result;
            for(int i=tmp.size()-1 ; i>=0 ; i--){
                result += to_string(tmp[i]);
                if (i != 0) result += " ";
            }
            out_result.push_back(result);
            return ;
        }
        if(index < 0) return;
        if(dp[index] == lastDp-1 && tmp[tmp.size() -1] > nums[index]){
            tmp.push_back(nums[index]);
            helper(nums, dp, tmp, index -1, dp[index], out_result);
            tmp.pop_back();
        }

        helper(nums, dp, tmp, index -1, lastDp, out_result);
    }


    vector<int> getDP_binary(vector<int> & num){
//        if (num == Null || num.size() == 0) return NULL;

        vector<int> dp(num.size(), 0);
        vector<int> record(num.size(), 0);
        int len = -1;

        for(int i=0;i<num.size(); i++){
            if( len == -1 || num[i] > record[len]){

                record[++len] = num[i];
                dp[i] = len + 1;
            }else{

                int s = 0, e = len;

                while(s <= e){
                    int mid = (s + e) /2;
                    if(num[i] > record[mid]){
                        s = mid + 1;
                    }else{
                        e = mid -1;
                    }
                }

                record[s] = num[i];
                dp[i] = s + 1;


            }
        }

        return dp;


    }


    // 采用O（nlogn）方法回溯最长上升子串，该方法返回其中一种最长上升子串的值
    string sequenceOfLIS_binary(vector<int> & num){
        vector<int> dp =getDP_binary(num);
        int maxIndex = -1;
        int maxValue = INT_MIN;

        for(int i=0; i< dp.size() ; i++){

            if(dp[i] > maxValue){
                maxValue = dp[i];
                maxIndex = i;
            }

        }

        vector<int>res(maxValue, 0);

        int index = maxValue-1;

        res[index] = num[maxIndex];

        int preIndex = maxIndex;

        for(int i=maxIndex-1; i>=0 ;i--){
            if(dp[i] == dp[preIndex] -1 && num[i] < num[preIndex]){
                res[--index] = num[i];
                preIndex = i;
            }

        }
        string result;
        for(int i=0;i<res.size(); i++){
            result += to_string(res[i]);
            if(i != res.size() -1){

                result  += " ";
            }
        }
        return result;
    }


};



int main() {
    Solution s;

    int mynum[8] = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> num(mynum, mynum + 8);
    int maxLen = s.lengthOfLIS(num);


    std::cout << maxLen << std::endl;


    string res = s.sequenceOfLIS_binary(num);

    std::cout << res<< std::endl;
    return 0;
}