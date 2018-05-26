//
// Created by 傅妍玫 on 2018/5/26.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:


    // 找到数组中 出现次数超过一半的数


    // 方法一  排序的方法
    int majorityElement(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            return nums[nums.size() /2];
    }
    // 方法二 Moore Voting Algorithm 每找到两个不同的element, 就成对删除，最后剩下的就是所求

    int majorityElement_2(vector<int>& nums) {
        int elem = 0;
        int count = 0;

        for(int i=0;i<nums.size();i++){
            if(count == 0){
                elem = nums[i];
                count  = 1;
            }else{
                if (elem == nums[i]){
                    count ++;
                }else{
                    count --;
                }
            }
        }

        return elem;

    }

};