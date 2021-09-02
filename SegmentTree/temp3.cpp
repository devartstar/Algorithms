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
    while(calculateLength(str) > 1 && str[0] == '0'){
        for(int k=0; k<calculateLength(str)-1; k++)
            str[k] = str[k+1];
    }
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
    // Performing s1 + s2
    // Performing s1 - s2
    
    bool negativeOnSubtraction = false;
    if(bigger(s2,s1))   // checks if s2 is bigger in value than s1
        negativeOnSubtraction = true;

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
        s1 += '.';
        for(int i=0;i<=10; i++){
            s1 += '0';
        }
    }else{
        int temp = len1 - posOfdec1;
        for(int i=0;i<=10-temp;i++){
            s1 += '0';
        }
    }
    if(posOfdec2==-1){
        s2 += '.';
        for(int i=0;i<=10; i++){
            s2 += '0';
        }
    }else{
        int temp = len2 - posOfdec2;
        for(int i=0;i<=10-temp;i++){
            s2 += '0';
        }
    }

    // cout<<s1<<endl;
    // cout<<s2<<endl;


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

    string s22 = "";    // s11 is the copy of the string s1
    int pos2;
    for(pos2=0; pos2<calculateLength(s2); pos2++){
        if(s2[pos2]=='.'){
            break;
        }
        s22 += s2[pos2];
    }
    for(int i = pos2+1; i<calculateLength(s2); i++){
        s22 += s2[i];
    }
    cout<<s11<<" "<<s22<<endl;

    string ans1 = add(s11,s22);
    string ans11 ="";
    int finalPosOfDec1 = calculateLength(ans1) - 10;
    for(int i=0;i<calculateLength(ans1); i++){
        if(i==finalPosOfDec1){
            ans11 += '.';
        }
        ans11 += ans1[i];
    }
    cout<<ans11<<endl;




    string ans2 = sub(s11,s22);
    string ans22 ="";
    int finalPosOfDec2 = calculateLength(ans2) - 10;
    for(int i=0;i<calculateLength(ans2); i++){
        if(i==finalPosOfDec2){
            ans22 += '.';
        }
        ans22 += ans2[i];
    }
    cout<<negativeOnSubtraction<<endl;
    if(negativeOnSubtraction)
        ans22 = '-'+ans22;
    cout<<ans22<<endl;
}
