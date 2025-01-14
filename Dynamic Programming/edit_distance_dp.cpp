/*
    Given two strings str1 and str2 and following three operations that can performed on str1. 
    1) Insert
    2) Remove
    3) Replace
    Find minimum number of operations required to convert ‘str1’ into ‘str2’. 
    For example if input strings are CAT AND CAR the edit distance is 1.

    Input  :  s1 : saturday  s2 : sunday 
    Output :  3  
*/
// Dynamic Programming Solution : TC O(n^2)
// Porgram Author : Abhisek Kumar Gupta
#include<bits/stdc++.h>
using namespace std;
int find_edit_distance(string s1, string s2, int l1, int l2){ 
    int dp[100][100] = {};
    for(int i = 0; i <= l1; i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= l2; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1];
            else{
                int del = dp[i][j - 1];
                int replace = dp[i - 1][j - 1];
                int insert =  dp[i - 1][j];
                dp[i][j] = min(del, min(replace, insert)) + 1;
            }
        }
    }
    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            cout << setw(5) <<dp[i][j] << " ";
        }
        cout << "\n";
    }
    return dp[l1][l2];
}
int main(){
    string s1 = "abhisek";
    string s2 = "tsunade";
    int l1 = s1.length() - 1;
    int l2 = s2.length() - 1;
    int result = find_edit_distance(s1, s2, l1, l2);
    cout << result;
    return 0;
}
