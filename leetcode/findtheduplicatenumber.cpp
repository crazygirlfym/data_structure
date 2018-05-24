//
// Created by 傅妍玫 on 2018/5/24.
//

#include <vector>
using namespace std;

class Solution {
public:

    // 用二分查找法  用到了本身 数组的特性， 数组里的元素是1-n的，如果左边的数比右边的多，说明左边存在重复的
    int findDuplicate(vector<int>& nums) {
            int n = nums.size();
            int low = 1;
            int high = n;
            int mid ;
            while(low < high){
                mid = (low + high ) /2;

                int count = 0;
                for(int num: nums){
                    if(num <= mid){
                        count ++;
                    }

                }

                if(count > mid) high = mid;
                else low = mid +1;

            }
            return low;
    }

    //然后由于存在重复元素，所以一定存在两个以上的下标指向同一个数，这就会造成多次迭代后，快慢指针一定都会进入一个循环中。在环上以不同速度的两个指针一定会在某个位置上相遇
    int findDuplicate2(vector<int>& nums) {
        int fst=0,slow=0;
        do{
            fst=nums[nums[fst]];
            slow=nums[slow];
        }while(fst!=slow);  // 第一次相遇的地方， 在环内
        fst=0;

        // 让一个新的慢指针 和一个旧的慢指针开始走， 第一次相遇的地方 就是重复的数字
        while(fst!=slow){
            fst=nums[fst];
            slow=nums[slow];
        }
        return fst;
    }
};