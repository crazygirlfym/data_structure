//
// Created by 傅妍玫 on 2018/5/31.
//

#include <vector>
#include <iostream>
using namespace std;


// 旋转数组   类似于求逆运算
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        k = k % nums.size() ;
        int n = nums.size();
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);





    }

private:
    void reverse(vector<int>& nums, int low, int high){
        while(low <= high){
            int tmp = nums[low];
            nums[low] = nums[high];
            nums[high] = tmp;
            low ++;
            high --;
        }
    }
};