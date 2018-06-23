//
// Created by 傅妍玫 on 2018/6/23.
//
#include <iostream>
#include <vector>
using namespace std;


// 用最大推可以快速的从一个数据容器中找出最大数，最小堆可以快速的从一个数据容器中找出最小的数。
// 用一个最大堆实现左边的数据容器，用最小堆实现右边的数据容器。

// 为保证数据平均分配道两个堆中，为了实现平均分配，可以在数据的总数目是偶数的时候把新数据插入最小堆，否则插入最大堆
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<double> min_heap;
    vector<double> max_heap;


    MedianFinder() {

    }

    void addNum(int num) {
        //原来是偶数 现在是奇数，将其加入最大堆
        if((min_heap.size() + max_heap.size()) % 2 == 0){
            if(!max_heap.empty() && num < max_heap[0]){
                max_heap.push_back(num);
                push_heap(max_heap.begin(), max_heap.end(), less<int>());
                num = max_heap[0];
                pop_heap(max_heap.begin(),max_heap.end(),less<int>());
                max_heap.pop_back();
            }
            min_heap.push_back(num);
            push_heap(min_heap.begin(), min_heap.end(), greater<int>());
        }
        else{
            // 插入最小堆

            if(!min_heap.empty() && num > min_heap[0]){
                min_heap.push_back(num);
                push_heap(min_heap.begin(), min_heap.end(), greater<int>());

                num = min_heap[0];
                pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
                min_heap.pop_back();
            }

            max_heap.push_back(num);
            push_heap(max_heap.begin(), max_heap.end(), less<int>());


        }
    }

    double findMedian() {

        if((min_heap.size() + max_heap.size()) % 2==0){
            return (min_heap[0] + max_heap[0]) *1.0/ 2;
        }else{
            return min_heap[0];
        }

    }
};

int main(){
    MedianFinder s;
    s.addNum(-1);
    cout<< s.findMedian() << endl;
    s.addNum(-2);
    cout<< s.findMedian() << endl;
    s.addNum(-3);
    cout<< s.findMedian() << endl;

    s.addNum(-4);
    cout<< s.findMedian() << endl;


}