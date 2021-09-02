/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Roll   - 19MA20014             	|	
    |    	                            |
    -------------------------------------

    LAB 1 - QUES 3
*/

#include <iostream>
#include <string>
using namespace std;

int calculateLength(string s){
    int i;
    for(i = 0; s[i] != '\0'; ++i);
    return i;
}

void reverseStr(string& str)
{
    int n = calculateLength(str);
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

bool bigger(string a, string b) // check if a is strictly bigger than b or not
{
    if (calculateLength(a) > calculateLength(b)) return true;
    if (calculateLength(a) < calculateLength(b)) return false;
    for(int i = 0; i < calculateLength(a); i++)
    {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return false;
}

string mul(string A, string B) // multiply strings
{
    reverseStr(A);
    reverseStr(B);
    string C;
    C.resize(calculateLength(A) + calculateLength(B),'0');
    for (int i = 0; i < calculateLength(A); i++)
    {
        int c = 0;
        for(int j = 0; j<=calculateLength(B)-1; j++)
        {
            c += ((A[i] - '0') * (B[j] - '0') + C[i + j] - '0');
            C[i + j] = (char)(c%10 + '0');
            c/=10;
        }
        if (c > 0) C[i + B.length()] += c;
    }
    reverseStr(C);
    while (C.size() > 1 && C[0] == '0') 
        C.erase(0, 1);
    return C;
}

string makePreci(string s, int k){
    int pos;
    string finans ="";
    for(int i=0;i<calculateLength(s);i++){
        if(s[i]=='.'){
            pos = i;
            break;
        }
        finans += s[i];
    }
    int j=0;
    for(int i=0;i<=k;i++){
        finans += s[pos+i];
    }
    return finans;
}

string sub(string str1, string str2) // substract strings, also from geekforgeeks
{
    if (bigger(str2, str1)) swap(str1, str2);
    string str = "";
    int n1 = calculateLength(str1), n2 = calculateLength(str2);
    reverseStr(str1);
    reverseStr(str2);
    int carry = 0;
    for (int i = 0; i < n2; i++) 
    {
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
    
        str += (sub + '0');
    }
    for (int i = n2; i < n1; i++) 
    {
        int sub = ((str1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
    
        str += (sub + '0');
    }
    reverseStr(str);
    while (calculateLength(str) > 1 && str[0] == '0'){
        for(int i=0; i<calculateLength(str)-1;i++){
            str[i] = str[i+1];
        }
    }
    return str;
}

int main(){
    cout<<"Input two Decimals :- \n";
    string s1;
    double s2;
    cin>>s1>>s2;
    string a11 = s1;
    cout<<"Precision to be followed : - \n";
    int prec;  cin>>prec;

    // Calculating the length of the input given
    int len1;
    len1 = calculateLength(s1);
    
    // finding out the position of decimal in both the inputs
    int posOfdec1=-1, posOfdec2=-1;
    for(int i=0; i<len1; i++){
        if(s1[i]=='.'){
            posOfdec1 = i;
            break;
        }
    }


    // if input is given as (eg. 5 i am considering it 5.0000)
    // making the strings of equal length.
    // !!! initially taking 10 for easy debugging alter to be changed to 300(as given by sir)
    if(posOfdec1==-1){
        s1 += '.';
        for(int i=0;i<=300; i++){
            s1 += '0';
        }
    }else{
        int temp = len1 - posOfdec1;
        for(int i=0;i<=300-temp;i++){
            s1 += '0';
        }
    }

    // Removing the decimals for easier operation
    // will put back the decimals at the end
    string s11 = "";    // s11 is the copy of the string s1
    int pos1;
    for(pos1=0; pos1<calculateLength(s1); pos1++){
        if(s1[pos1]=='.'){
            break;
        }
        s11 += s1[pos1];
    }
    for(int i = pos1+1; i<calculateLength(s1); i++){
        s11 += s1[i];
    }
    pos1 = calculateLength(s1)-pos1-1;
    
    
    string temp = s11, ans1 = s11;
    long long calcDeci = pos1;
    int cnt = (int)s2;
    while (cnt>=2)
    {
        ans1 = mul(s11,temp);
        s11 = ans1;
        calcDeci += pos1;
        cnt--;
    }

    int finalPos = calcDeci;        // adjusting the decimal
    string ans11 ="";
    int finalPosOfDec1 = finalPos;

    reverseStr(ans1);
    for(int i=0;i<=300;i++){         // since 300 is Considered Upper Limit
        ans1 += '0';
    }
    for(int i=0;i<calculateLength(ans1); i++){
        if(i==finalPosOfDec1){
            ans11 += '.';
        }
        ans11 += ans1[i];
    }
    reverseStr(ans11);
    while (calculateLength(ans11) > 1 && ans11[0] == '0'){
        for(int i=0; i<calculateLength(ans11)-1;i++){
            ans11[i] = ans11[i+1];
        }
    }
    if(ans11[0]=='.')   ans11 = '0' + ans11;
    cout<<"Answer of "<<a11<<" power "<<(int)s2<<" greater than ";
    cout<<makePreci(ans11, prec)<<endl;

    // SO NOW THE ONLY THING LEFT IS TO APPROXIMATE THE SOLUTION WITH
    // RAISING IT TO DECIMAL POWER AND MULTIPLY WITH PREV ANS
        
}

