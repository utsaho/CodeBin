///Biginteger Multiplication

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string dosum(string st1, string st2) {
    string ans;
    if(st1.length()<st2.length()) {
        string temp=st2;
        st2=st1;
        st1=temp;
    }
    int len1=st1.length()-1, len2=st2.length(), carry=0;
    int sum=0;
    for(int i=len1; i>=0; i--) {
        if(len2) {
            sum=0;
            sum=((st1[i]-'0')+(st2[--len2]-'0'))+carry;
            carry=sum/10;
            sum%=10;
            ans.push_back((sum+'0'));
        }
        else if(carry>0){
            sum=(st1[i]-'0')+carry;
            carry=sum/10;
            sum%=10;
            ans.push_back((char)sum+'0');
        }
        else ans.push_back(st1[i]);
    }
    if(carry>0) ans.push_back(carry+'0');
    reverse(ans.begin(), ans.end());
    return ans;
}
 string mul(string st1, string st2) {
    // cout<<"\t\t\t\tThis Program will work for multiplication."<<endl;
    string ans;
    int len1=st1.length()-1, len2=st2.length(), carry=0;
    int sum=0, times=0;;
    for(int i=len2-1; i>=0; i--) {
        string tempans;
        for(int j=len1; j>=0; j--) {
            sum=(st2[i]-'0')*(st1[j]-'0')+carry;
            carry=sum/10;
            tempans.push_back((sum%10)+'0');
        }
        if(carry>0){
            tempans.push_back(carry+'0');
            carry=0;
        }
        reverse(tempans.begin(), tempans.end());
        if(len2==1) {
            ans=tempans;
        } else {
            for(int j=times; j>0; j--) tempans.push_back('0');
            times++;
            ans=dosum(tempans, ans);
        }
    }
    return ans;
}

int main(){
    int b; cin>>b;
    
    int a; cin>>a;
    string aa, ans="1", aaa;
    if(a<=9) aa.push_back(a+'0');
    else {
        aa.push_back(a/10 +'0');
        aa.push_back(a%10 +'0');
    }
    string ll="1";
    while(aa!=aaa){
        aaa=dosum(aaa, ll);
        ans = mul(ans, aaa);
        // cout<<ans<<endl;
        // cout<<aaa<<endl;
        // break;
    }
    cout<<ans;
    return 0;
}
