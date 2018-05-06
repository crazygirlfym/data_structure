//
// Created by 傅妍玫 on 2018/5/6.
//

#include <ostream>
#include <string>
using namespace std;
class Solution {
public:

    // 仅求编辑距离, 空间复杂度O（n^2）
    int minDistance(string word1, string word2) {

        int m = word1.length(), n = word2.length();
        int dp[m+1][n+1];

        for(int i=0; i<m+1;i++){
            dp[i][0] = i;
        }

        for(int j=0; j< n+1; j++){
            dp[0][j] = j;
        }


        for(int i=1; i< m+1; i++){

            for(int j=1; j< n+1; j++){

                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]) + 1);
                }else{
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]) + 1, dp[i-1][j-1] +1);
                }

            }
        }

        return dp[m][n];

    }

    // O(n)空间  每一次我们其实只需要知道上一行的值
    int minDistance_2(string word1, string word2){


        int m = word1.length();
        int n = word2.length();
        int dp[n+1];
        for(int i=0;i<m+1; i++){
            int temp[n+1];
            for(int j=0;j<n + 1; j++){

                if(i == 0){
                    temp[j] = j;
                }else if(j == 0){
                    temp[j] = i;
                }else{

                    if(word1[i-1] == word2[j-1]){
                        temp[j] = min(min(dp[j-1], temp[j-1] + 1), dp[j]+1);
                    } else{
                        temp[j] = min(min(temp[j-1], dp[j]) , dp[j-1])  + 1;
                    }


                }

            }
            for(int k=0;k<n+1; k++){
                dp[k] = temp[k];
            }
        }




        return dp[n];



    }






};

int main(){
    Solution s;
    string word1 = "horse";
    string word2 = "ros";
    int result = s.minDistance_2(word1, word2);
    printf("%d", result);
}