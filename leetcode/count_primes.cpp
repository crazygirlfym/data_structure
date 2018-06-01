//
// Created by 傅妍玫 on 2018/6/1.
//


#include <vector>
#include <math.h>
#include< numeric>
#include <iostream>
using namespace std;

// 用空间换时间  埃拉脱丝特尼筛选法 时间复杂度为NLOGNLOGN
class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        vector<unsigned char> f(n, 1);

        for(long i=2; i<sqrt(n); ++i){
            if(!f[i]) continue;
            for(long j = i* i ; j< n; j+= i){  // 把倍数去掉
                f[j]  = 0;
            }
        }

        int ans = accumulate(f.begin(), f.end(), 0);  // 求和
        return ans;
    }
};