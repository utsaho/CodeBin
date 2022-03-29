#include <bits/stdc++.h>
#define     ed          '\n'
using namespace std;


bool heart(const pair<pair<string, double>, pair<double, double>> &p1, const pair<pair<string, double>, pair<double, double>> &p2){
    return p1.second.second>p2.second.second;
}
int main() {
    int item; double max_weight;
    cout<<"Enter total item/object(s): ";
    cin>>item;
    cout<<"Enter Maximum weight: ";
    cin>>max_weight;
    vector<pair<pair<string, double>, pair<double, double>>>v;
    cout<<"Item's name, item's profit & item's weight: "<<ed;
    for(int i=0; i<item; i++){
        cout<<"Item "<<i+1<<": ";
        string object; double profit, weight;
        cin>>object>>profit>>weight;
        v.push_back({{object, profit}, {weight, (profit/weight)}});
    }
    sort(v.begin(), v.end(), heart);
    double LIST[item+2]={0.0};
    for(int i=0; i<item && max_weight>0; i++){
        if(v[i].second.first<= max_weight){
            max_weight-= (v[i].second.first);
            LIST[i] = 1;
        }
        else{
            LIST[i] = (max_weight/v[i].second.first);
            break;
        }
    }
    cout<<ed<<ed<<"item ->   weight"<<ed<<"---------------------------------------------"<<ed;
    double total_profit = 0.0;
    for(int i=0; i<item && LIST[i]!=0; i++){
        cout<<v[i].first.first<<" ->   " <<LIST[i]*v[i].second.first<<" kg"<<ed;
        total_profit+= (v[i].first.second*LIST[i]);
    }
    cout<<ed;
    cout<<"Max Profit: "<< total_profit<<ed;
    return 0;
}
