//
// Created by 傅妍玫 on 2018/5/6.
//
#include <iostream>

using namespace std;



class MaxHeap {
public:

    // 插入一个元素是O（logn）
    void heapAdjust(int *data, int length, int k){
        int tmp = data[k];
        // zero-based的数组

       // parent(i)  = floor((i-1) /2)
      // left(i)  = i * 2 + 1
              // right(i)  = 2(i+1)
    int i = 2*k + 1;
    while(i < length) {


        if (i + 1 < length && data[i] > data[i + 1])  // 选取最小的节点位置
            i++;

        if (tmp < data[i]) // 不用交换
            break;

        data[k]  = data[i];
        k = i; // 继续查找

        i = 2* i + 1;

    }

    data[k] = tmp;


    }


    // 堆排序  时间复杂度为O(nlogn) 非稳定排序， 采用原地排序的方法，所以空间复杂度为O（1）

    void heapSort(int data[], int length){

        if(data == NULL || length <= 0){
            return ;
        }

        // 完全二叉树的最后一个非叶子结点，也就是最后一个最后一个节点的父节点是 length/2 -1 ， 因为最后一个节点的索引为len-1, 那么最后一个非叶子节点的父节点为 (length-1-1)/2

        // 建堆（初始化 + 调整堆, 时间复杂度为O(n）
        for(int i=length/2-1;  i>=0 ;i--){
            heapAdjust(data, length, i);
        }


        // 每次堆排序得到的最大元素和当前规模的最后一个数组元素交换
        // 时间复杂度为 O（nlogn）
        for(int i=length-1; i>=0; i--){
            int tmp = data[0];
            data[0] = data[i];
            data[i] = tmp;
            heapAdjust(data, i, 0);   //从顶点开始建堆，忽略最后一个

        }

        return;

    }





};
int main (void)
{
    MaxHeap h;
    int data[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int length = 8;
    h.heapSort(data, length);
    for (int i=0; i<length; ++i) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}
