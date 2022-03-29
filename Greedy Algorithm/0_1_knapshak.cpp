//  Write a program to find the selected objects from n objects of 0/1 knapsack problem.

#include <bits/stdc++.h>
#define     cout(result)     cout<<result<<ed
#define     ed          '\n'
using namespace std;

void knapsack_01() {
    int n, m;
    cout<<"Enter total objects number: "; cin>>n;
    cout<<"Enter maximum weight: "; cin>>m;
    int TABLE[n+1][m+1];
    memset(TABLE, 0, sizeof(TABLE));
    vector<pair<int, int>>v(n);
    v[0].first = 0;
    v[0].second = 0;
    cout<<ed<<"Enter Profits & Weights."<<ed;
    for(int i=1; i<=n; i++){
        cout<<i<<"'th: ";
        cin>>v[i].first>>v[i].second;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(v[i].second<=j) TABLE[i][j]= max(TABLE[i-1][j], (TABLE[i-1][j-v[i].second]+v[i].first));
            else TABLE[i][j] = TABLE[i-1][j];
        }
    }
    cout<<ed<<"Here is the Table: "<<ed;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout<<TABLE[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ed;
    cout("Maximum Profit is: "<<TABLE[n][m]);
    int copy_n = n;
    int Object_List[n+4]={0}, Profits[m]={0}, Profits_counter = 0;
    int Weights[m]={0}, Weights_counter = 0;
    while(TABLE[n][m]!=0){
        while(TABLE[n][m]==TABLE[n-1][m] && n){
            n--;
        }
        // cout<<s[n][m]<<" ";
        Profits[Profits_counter++] = v[n].first;
        Weights[Weights_counter++] = v[n].second;
        Object_List[n] = 1;
        // cout("Weight: "<<v[n].second);
        int re = TABLE[n][m] - v[n].first;
        if(n>0){
            n--;
        }
        while(--m && TABLE[n][m]!=re);
    }
    cout<<ed;
    cout<<"Maximum profits list: ";
    for(int i=0; i<Profits_counter; i++) cout<<Profits[i]<<" ";
    cout<<ed;
    cout<<"Maximum weights list: ";
    for(int i=0; i<Weights_counter; i++) cout<<Weights[i]<<" ";
    cout<<ed;;
    cout<<"Objects List: ";
    for(int i=1; i<=copy_n; i++) cout<<Object_List[i]<<" ";
    cout<<ed;

}

int main() {
    knapsack_01();
    return 0;
}
