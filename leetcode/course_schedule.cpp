//
// Created by 傅妍玫 on 2018/6/3.
//
#include <vector>

#include <queue>
using namespace std;

// 实际上就是构造图后，判断图中是否有环
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> pre(numCourses);

        vector<int> inDegress(numCourses, 0);
        //构造图
        for (int i=0;i<prerequisites.size();i++){
            auto p = prerequisites[i];

            inDegress[p.first] ++;
            pre[p.second].push_back(p.first);

        }


    //dfs方法
        queue<int> que;

        for(int i=0;i<numCourses;++i){
            if(inDegress[i] == 0) que.push(i);
        }



        int count = 0;
        while(!que.empty()){
            int tmp = que.front();
            que.pop();
            count ++;

            for(auto st: pre[tmp]){
                if(inDegress[st] == 1){
                    que.push(st);
                }

                inDegress[st] --;
            }
        }
        return count == numCourses;


    }
};