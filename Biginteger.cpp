#include <bits/stdc++.h>
using namespace std;
void INPUT();
void bigSum() {
//    #ifdef utsho
//        freopen("in.txt", "r", stdin);
//    #endif // utsho
    cout<<"\t\t\t\tThis Program will work for Plus."<<endl;
    string st1, st2, ans;
    cout<<"A= "; cin>>st1;
    cout<<"B= "; cin>>st2;
    if(st1.length()<st2.length()) st1.swap(st2);
    int len1=st1.length()-1, len2=st2.length(), carry=0;
    int sum=0;
    for(int i=len1; i>=0; i--){
        if(len2){
            sum=0;
            sum=((st1[i]-'0')+(st2[--len2]-'0'))+carry;
            carry=sum/10;
            sum%=10;
            ans.push_back((char)sum+'0');
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
    cout<<"A+B= "<<ans<<endl;
}


void bigMinus() {
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
}


string dosumm(string st1, string st2) {
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
void bigMulty() {
//    #ifdef utsho
//        freopen("in.txt", "r", stdin);
//    #endif // utsho
    cout<<"\t\t\t\tThis Program will work for multiplication."<<endl;
    string st1, st2, ans;
    cout<<"A= "; cin>>st1;
    cout<<"B= "; cin>>st2;
//    if(st1.length()<st2.length()) {
//        st1.swap(st2);
//    }
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
            ans=dosumm(tempans, ans);
        }
    }
    cout<<"A*B= "<<ans<<endl;
}

string dosum(string st1, string st2) {
    string ans;
    if(st1.length()<st2.length()) st1.swap(st2);
    int len1=st1.length()-1, len2=st2.length(), carry=0;
    int sum=0;
    for(int i=len1; i>=0; i--) {
        if(len2) {
            sum=0;
            sum=((st1[i]-'0')+(st2[--len2]-'0'))+carry;
            carry=sum/10;
            sum%=10;
            ans.push_back((char)sum+'0');
        } else if(carry>0) {
            sum=(st1[i]-'0')+carry;
            carry=sum/10;
            sum%=10;
            ans.push_back((char)sum+'0');
        } else ans.push_back(st1[i]);
    }
    if(carry>0) ans.push_back(carry+'0');
    reverse(ans.begin(), ans.end());
    return ans;
}

string domulty(string st1, string st2) {
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
        if(carry>0) {
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

string dominus(string st1, string st2) {
    string ans;
    int f=0;
    long long int sum1=0, sum2=0;
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
        if(index==-1) {
            st2=st1;
        } else if(st1[index]<st2[index]) {
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
            } else if(ln!=0) {
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
    if(f) ans.push_back('-');
    reverse(ans.begin(), ans.end());
    return ans;
}

void bigDivide() {
//#ifdef utsho
//    freopen("in.txt", "r", stdin);
//#endif // utsho
    cout<<"\t\t\t\t\tThis program will work for divide"<<endl;
    string st1, st2, ans;
    cout<<"Y= ";cin>>st1; cout<<"X= ";cin>>st2;
    int f=0;
    long long int sum1=0, sum2=0;
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
        if(index==-1) {
            st2=st1;
        } else if(st1[index]<st2[index]) {
            st1.swap(st2);
            f=1;
        }
    }
    st1.swap(st2);
    string tempsum, llll="1", sub1;
    string temp=st1;
    f=1;
    do {
        string sub;
        sub1=tempsum;
        tempsum=dosum(tempsum, llll);
        temp=domulty(st1, tempsum);
//        cout<<temp<<endl;
        sub=dominus(st2, temp);
        if(sub[0]=='-') {
            f=0;
        }
    } while(f);
    ans+=sub1;
    sub1=dominus(st2, domulty(sub1, st1));
//    cout<<sub1<<endl;
    if(sub1[0]=='0') cout<<"X/Y= "<<ans<<endl;
    else {
        sub1.push_back('0');
//        cout<<sub1<<endl;
        st1=sub1;
        temp=st1;
        ans.push_back('.');
        do {
            string sub, ssub;
            sub1=tempsum;
            tempsum=dosum(tempsum, llll);
            temp=domulty(st1, tempsum);
//        cout<<temp<<endl;
            sub=dominus(st2, temp);
            if(sub[0]=='-') {
                f=0;
            }
        } while(f);
        ans+=sub1;
        cout<<ans<<endl;
    }
}

void caller(int a) {
    switch (a) {
    case 1:
        bigSum();
        break;
    case 2:
        bigMinus();
        break;
    case 3:
        bigMulty();
        break;
    case 4:
        bigDivide();
        break;
    }
    INPUT();
   // cout<<endl<<"1. Big-integer Plus\n\n2. Big-integer Minus\n\n3. Big-integer Multiplication\n\n4. Big-integer Divide\n\n0. Exit"<<endl;
    //return a;
}


void INPUT(){
    cout<<endl<<"1. Big-integer Plus\n\n2. Big-integer Minus\n\n3. Big-integer Multiplication\n\n4. Big-integer Divide\n\n0. Exit"<<endl;
    int a;
    do {
        cin>>a;
        if(a==0) exit(0);
        else if(a<1 || a>4) cout<<"Try Again!"<<endl;
    } while(a<1 || a>4);
    caller(a);
}


int main() {
    cout<<"\t\t\t\t\t\t\tBIG-INTEGER"<<endl;
    INPUT();
    return 0;
}
