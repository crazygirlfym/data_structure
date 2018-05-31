//
// Created by 傅妍玫 on 2018/5/31.
//
#include <stdint.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result =0 ;

        for(int i =0; i<32; ++i){
            if( (n & 1) == 1){

                result = (result << 1)  + 1;
                
            }else{
                result = result << 1;
            }
            n = n >> 1;
        }
        return result;
    }
};

int main(){
    uint32_t n =     43261596;
    Solution s;
    cout << s.reverseBits(n) << endl;
}