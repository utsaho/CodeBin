///Biginteger Minus

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
//    #ifdef utsho
//        freopen("in.txt", "r", stdin);
//    #endif // utsho
    cout<<"\t\t\t\tThis Program will work for Minus."<<endl;
    string st1, st2, ans;
    int f=0;
    long long int sum1=0, sum2=0;
    cout<<"Enter A= ";
    cin>>st1;
    cout<<"Enter B= ";
    cin>>st2;
    reverse(st1.begin(), st1.end());
    reverse(st2.begin(), st2.end());
    int len=st1.length(), check=1;
    while(check) {
        if((st1[--len]-'0')!=0) {
            check=0;
            break;
        } else st1.pop_back();
    }
    len=st2.length(), check=1;
    while(check) {
        if((st2[--len]-'0')!=0) {
            check=0;
            break;
        } else st2.pop_back();
    }
    reverse(st1.begin(), st1.end());
    reverse(st2.begin(), st2.end());
//    cout<<st1<<endl<<st2<<endl;
    if(st1.length()<st2.length()) {
        st1.swap(st2);
        f=1;
    } else if(st1.length()>st2.length()) f=0;
    else {
        for(int i=st1.length()-1; i>=0; i--) {
            sum1+=(st1[i]-'0');
            sum2+=(st2[i]-'0');
        }
        int len1=st1.length()-1, k=0, index=-1;
            while(k<=len1) {
                if(st1[k]!=st2[k]) {
                    index=k;
                    break;
                }
                k++;
            }
//            cout<<index<<endl;
            if(index==-1){
                st2=st1;
            }
            else if(st1[index]<st2[index]) {
                st1.swap(st2);
                f=1;
            }
    }
//    cout<<st1<<endl<<st2;
    int len1=st1.length()-1, len2=st2.length(), carry=0;
    int temp=0;
    for(int i=len1; i>=0; i--) {
        int fn=st1[i]-'0';
        if(len2) {
            int ln=st2[--len2]-'0';
            if(fn>0) {
                fn-=temp;
                temp=0;
            } else if(ln!=0){
                fn=(fn+10)-temp;
                temp=1;
            }
            if(fn>=ln) {
                if(ln>0) ans.push_back((fn-ln)+'0');
                else {
//                    ans.push_back('0');
                    ans.push_back(fn+'0');
                    temp=0;
                }
            } else {
                fn+=10;
                temp=1;
                ans.push_back((fn-ln)+'0');
            }
        } else {
            fn-=temp;
            temp=0;
            ans.push_back(fn+'0');
        }
    }
    len=ans.length(), check=1;
    while(check) {
        if((ans[--len]-'0')!=0) {
            check=0;
            break;
        } else ans.pop_back();
    }
    if(len==-1) ans.push_back('0');
    reverse(ans.begin(), ans.end());
//    cout<<ans;
    cout<<"A-B = ";
    if(f && ans[0]!='0') cout<<"-"<<ans<<endl;
    else cout<<ans<<endl;
    cout<<"B-A = ";
    if(f==0 && ans[0]!='0') cout<<"-"<<ans<<endl;
    else cout<<ans<<endl;
    return 0;
}
