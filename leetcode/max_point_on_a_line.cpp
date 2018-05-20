//
// Created by 傅妍玫 on 2018/5/20.
//

#include <vector>
#include <map>
#include<cstdio>
#include <algorithm>
using namespace std;
struct Point{

    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b){}


};

// 判断在一条线上的点
class Solution {
public:

    // 最基本的想法是计算斜率 然后然后判断其他点 是不是共线，时间复杂度为O(n^3)
    int maxPoints(vector<Point>& points) {
        int ans = 0;

        // 去掉最外层的循环 ，只用O(n^2）的时间复杂度
        for(int i = 0; i < points.size(); i++){

            map<pair<int, int>, int> m;
            int overlap = 0, localMax =0;
            for(int j = i + 1; j < points.size(); j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    overlap++; continue;
                }

                pair<int, int> key;
                if(points[i].x == points[j].x) key=make_pair(0, INT_MAX); //vertial points
                else{
                    int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
                    int gcd=__gcd(a, b);  // 注意此处用需要除以一个最大公约数
                    key = make_pair(a/gcd, b/gcd);
                }

                localMax = max(localMax, ++m[key]);
            }

            ans = max(ans, localMax+overlap+1);
        }
        return ans;
    }
};