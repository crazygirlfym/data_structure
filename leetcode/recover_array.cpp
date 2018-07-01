//
// Created by 傅妍玫 on 2018/7/1.
//
#include <vector>
#include <iostream>
using namespace std;

// 给一个list range (1, n) ，每个位置上告诉前面有多个数大于他，请还原整个数组
class Solution{
public:
    vector<int> recover(vector<int>& com){
        vector<int> candidate;
        for(int i=1; i<= com.size(); i++){
            candidate.push_back(i);
        }


        vector<int> result(com.size());

        for(int i=com.size()-1;i>=0;i--){
           result[i] = candidate[candidate.size()-1-com[i]];
           candidate.erase(candidate.begin()+candidate.size()-1-com[i], candidate.begin()+candidate.size()-com[i] );
        }

        return result;
    }
};

int main(){
    Solution s;
    vector<int> com {0, 1, 2, 1, 0};
    vector<int> result = s.recover(com);
    for(int i=0;i<result.size();i++){
        cout << result[i] << endl;
    }

    return 0;
}