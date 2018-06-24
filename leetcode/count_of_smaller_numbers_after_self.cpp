//
// Created by 傅妍玫 on 2018/6/23.
//

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>count(nums.size(), 0);
        vector<pair<int, int>>inums;
        for (int i = 0; i != nums.size(); ++i)
            inums.push_back(make_pair(nums[i], i));
        mergesort(inums, count);
        return count;
    }
    void mergesort(vector<pair<int, int>> &inums, vector<int> &count)
    {
        int n = inums.size();
        if (n <= 1) return;
        vector<pair<int, int>> lpart(inums.begin(), inums.begin() + n / 2);
        vector<pair<int, int>> rpart(inums.begin() + n / 2, inums.end());
        mergesort(lpart, count);
        mergesort(rpart, count);
        int a = 0, l = 0, r = 0;//all, left,right
        while (a<n) {
            if (l<lpart.size() && (r == rpart.size() || lpart[l].first <= rpart[r].first)) {
                count[lpart[l].second] += r;
                //When the element from left part is put in, count the smaller number of elements on the right part which is equal to r;
                inums[a++] = lpart[l++];
            }
            else {
                inums[a++] = rpart[r++];
            }
        }
        return;
    }
};