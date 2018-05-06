//
// Created by 傅妍玫 on 2018/5/6.
//


#include <iostream>
#include <vector>
using namespace std;

// 返回最小的k个数
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result ;

        if(input.empty()| k==0 || k> input.size()){
            return result;
        }


        // 初始化堆

        for(int i=input.size()/2-1;i>=0;i--){

            adjustHeap(input,i,k);
        }

        int i=k;


        while(i<input.size()){
            // 维护的是一个最大堆， 如果当前元素比当前最大的还大，则说明不在k个元素中
            if (input[0] > input[i]){  // 比最大的小，所以需要被替换

                int temp=input[i];
                input[i]=input[0];
                input[0]=temp;
                adjustHeap(input,0,k);

                i = k;
            } else{
                i ++;
            }

        }
        for(int i=0 ;i< input.size();i++){
            std::cout <<input[i]<< std::endl;
        }

        for(int i=0 ;i< k;i++){
            result.push_back(input[i]);
        }
        return result;


    }
    // 堆调整

    // zero-based的数组

    // parent(i)  = floor((i-1) /2)
    // left(i)  = i * 2 + 1
    // right(i)  = 2(i+1)

    void adjustHeap(vector<int> &input, int i, int length){

        int child = i * 2 + 1;

        if(child < length){
            if(child + 1 < length && input[child + 1] > input[child]){
                child = child + 1;
            }

            if(input[child] > input[i]){
                int temp=input[i];
                input[i]=input[child];
                input[child]=temp;
            }

            adjustHeap(input,child,length);

        }


    }


};


int main(){

        Solution s;
        int mynum[8] = {4,5,1,6,2,7,3,8};
        vector<int> inputs(mynum,mynum+8);
        vector<int> result = s.GetLeastNumbers_Solution(inputs, 4);

        for (int i=0;i<inputs.size();i++){
//            std::cout <<inputs[i]<< std::endl;
        }



}