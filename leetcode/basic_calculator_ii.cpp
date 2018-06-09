//
// Created by 傅妍玫 on 2018/6/9.
//

#include <stack>
#include <string>
using namespace std;
class Solution {
    public:
        int calculate(string s) {
            stack<int> stk;
            char sign = '+';

            int res = 0, tmp = 0;

            for(int i=0; i<s.size();i++){
                if (isdigit(s[i])){
                    tmp = tmp * 10 + s[i] - '0';
                }
                // 只有乘除的时候 先计算再放入栈中
                if(!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1){
                    if (sign == '-'){
                        stk.push(-tmp);
                    }else if(sign == '+'){
                        stk.push(tmp);
                    }else{
                        int num;
                        if(sign == '*'){
                            num = stk.top() * tmp;
                        }
                        else{
                            num = stk.top() /tmp;
                        }
                        stk.pop();
                        stk.push(num);
                    }

                    sign = s[i];
                    tmp = 0;


                }


            }

            while(!stk.empty()){
                res += stk.top();
                stk.pop();
            }
            return res;
        }
};