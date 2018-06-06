//
// Created by 傅妍玫 on 2018/6/5.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;


// 实现前缀树
class TrieNode{

public:
    TrieNode *next[26];

    bool is_word;


    TrieNode(bool b = false){
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie {
public:
    TrieNode * root;

    /** Initialize your data structure here. */
    Trie() {

        root = new TrieNode();

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;


        for(int i=0;i<word.size();i++){

            if(p->next[word[i] -'a'] == NULL){
                p->next[word[i]-'a'] = new TrieNode();
            }

            p = p->next[word[i] - 'a'];
        }

        p->is_word =true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = find(word);
        return p != NULL && p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }

private:

    TrieNode *find(string key){
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i) {

            p = p->next[key[i] - 'a'];
        }
        return p;
    }

};

class Solution {
public:

    // 是word search 的变型  在这个里面加入前缀树，判断是不是在前缀树中，如果不在前缀树就break

    // 遇到的坑 一个点在一个单词中只能被用一次
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 构建前缀树

        vector<string> result;
        Trie obj;
        for(int i=0;i<words.size();i++){
            obj.insert(words[i]);
        }

        for(int i=0;i<board.size();i++){
            for(int j=0; j<board[0].size();j++){
//                cout << board[i][j] << endl;
                string temp ;
//                cout << temp + (board[i][j])<< endl;
                helper(board, i, j, temp, obj, result);
            }
        }


        return result;

    }

    void helper(vector<vector<char>> &board,  int x, int y, string temp, Trie obj, vector<string> &result){

        if(obj.search(temp)){
            if(find(result.begin(), result.end(), temp) == result.end()){
                result.push_back(temp);


            }


        }


        if(!obj.startsWith(temp) && temp != ""){
            return;
        }

        if(x >= board.size() || x<0 || y>= board[0].size() || y<0){
            return;
        }
        if(board[x][y]=='.')
            return;
//        cout<< "test"<< endl;
//        cout<< temp <<endl;
        char tt = board[x][y];
        temp += board[x][y];
        board[x][y] = '.';
        helper(board, x+1, y, temp, obj, result);
        helper(board, x-1, y, temp, obj, result);
        helper(board, x, y-1, temp, obj, result);
        helper(board, x, y+1, temp, obj, result);
        temp = temp.substr(0, temp.size());
        board[x][y] = tt;
    }


};


int main(){
    Solution s;
    vector<string> words{"oath", "pea", "eat", "rain"};
    vector<vector<char>>board {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
//    vector<string> words{"a"};
//    vector<vector<char>>board{{'a'}};
    vector<string> result = s.findWords(board, words);

    for(int i=0;i<result.size(); i++){
        cout << result[i] << endl;
    }
}