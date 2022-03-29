///Biginteger Sum

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
//    #ifdef utsho
//        freopen("in.txt", "r", stdin);
//    #endif // utsho
    cout<<"\t\t\t\tThis Program will work for Plus."<<endl;
    string st1, st2, ans;
    cout<<"A= "; cin>>st1;
    cout<<"B= "; cin>>st2;
    if(st1.length()<st2.length()) st1.swap(st2);
    int len1=st1.length()-1, ss=0, len2=st2.length(), carry=0;
    int sum=0;
    for(int i=len1; i>=0; i--){
        if(len2){
            sum=0;
            sum=((st1[i]-'0')+(st2[--len2]-'0'))+carry;
            carry=sum/10;
            if(carry!=0) ++ss;
            sum%=10;
            ans.push_back((char)sum+'0');
        }
        else if(carry>0){
            sum=(st1[i]-'0')+carry;
            carry=sum/10;
            if(carry!=0) ++ss;
            sum%=10;
            ans.push_back((char)sum+'0');
        }
        else ans.push_back(st1[i]);
    }
    cout<<ss<<endl;
    return 0;
}
