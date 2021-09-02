#include <bits/stdc++.h>
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

// check if a is strictly bigger than b or not
bool bigger(string a, string b) 
{
    int lena = calculateLength(a);
    int lenb = calculateLength(b);
    if (lena > lenb) return true;
    if (lena < lenb) return false;
    for(int i = 0; i < lena; i++)
    {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return false;
}

string add(string str1, string str2) // add strings, took this from geekforgeeks
{
    int n1 = calculateLength(str1), n2 = calculateLength(str2);
    if (n1 > n2){
        swap(str1, str2);
        swap(n1,n2);
    }
    string str = "";
    int diff = n2 - n1;
    int carry = 0;
    for (int i=n1-1; i>=0; i--)
    {
        int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry);
        str += (sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str += (sum%10 + '0');
        carry = sum/10;
    }
    if (carry) str += (carry+'0');
    reverseStr(str);
    while(str.size() > 1 && str[0] == '0')
        str.erase(0, 1);
    return str;
}
		
string sub(string str1, string str2) // substract strings, also from geekforgeeks
{
    if (bigger(str2, str1)) swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
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
    
        str.push_back(sub + '0');
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
    
        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    while (str.size() > 1 && str[0] == '0') str.erase(0, 1);
    return str;
}

int main(){
    string s1, s2;
    cin>>s1>>s2;

    // Calculating the length of the input given
    int len1, len2;
    len1 = calculateLength(s1);
    len2 = calculateLength(s2);

    // finding out the position of decimal in both the inputs
    int posOfdec1=-1, posOfdec2=-1;
    for(int i=0; i<len1; i++){
        if(s1[i]=='.'){
            posOfdec1 = i;
            break;
        }
    }
    for(int i=0; i<len2; i++){
        if(s2[i]=='.'){
            posOfdec2 = i;
            break;
        }
    }

    // if input is given as (eg. 5 i am considering it 5.0000)
    // making the strings of equal length.
    if(posOfdec1==-1){
        for(int i=0;i<=10; i++){
            s1 += '0';
        }
    }else{
        int temp = len1 - posOfdec1;
        for(int i=0;i<10-temp;i++){
            s1 += '0';
        }
    }
    if(posOfdec2==-1){
        for(int i=0;i<=10; i++){
            s2 += '0';
        }
    }else{
        int temp = len2 - posOfdec2;
        for(int i=0;i<10-temp;i++){
            s2 += '0';
        }
    }
    // cout<<s1<<endl;
    // cout<<s2<<endl;

    string ans1 = add(s1,s2);
    string ans2 = sub(s1,s2);
    cout<<ans1<<endl;
    cout<<ans2<<endl;
}
