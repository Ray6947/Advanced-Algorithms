#include <bits/stdc++.h>
using namespace std;

string LCS(string s1, string s2) {
    int n=s1.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    int max=0;
    int end=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;

                if(dp[i][j]>max){
                    max=dp[i][j];
                    end=i-1;
                }
            }
        }
    }


    cout<<"\nLookup Table:\n";
    cout<<"    ";
    for(int j=0; j<n; j++){
        cout<<s2[j]<<" ";
    }
    cout<<"\n";

    for(int i=0; i<=n; i++){
        if(i>0){
            cout<<s1[i-1]<<" ";
        }
        else{
            cout<<"  ";
        }
        for(int j=0; j<=n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    return s1.substr(end-max+1,max);
}

int main(){
    string s1,s2;
    cout<<"Enter the first string: ";
    cin>>s1;
    cout<<"Enter the second string: ";
    cin>>s2;

    string res=LCS(s1,s2);
    cout<<"Length of the Longest Common Substring: "<<res.length()<<"\n";
    cout<<"The Common Substring is: "<<res<<"\n";
    return 0;
}
