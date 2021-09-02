/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Roll   - 19MA20014             	|	
    |    	                            |
    -------------------------------------

    LAB 1 - QUES 1
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

string add(string str1, string str2) // add strings, took this from geekforgeeks
{
    if (calculateLength(str1) > calculateLength(str2))
        swap(str1, str2);
    string str = "";
    int n1 = calculateLength(str1), n2 = calculateLength(str2);
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
    if (carry) str.push_back(carry+'0');
    reverseStr(str);
    while (calculateLength(str) > 1 && str[0] == '0'){
        for(int i=0; i<calculateLength(str)-1;i++){
            str[i] = str[i+1];
        }
    }
    return str;
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

int main(){
    cout<<"Input two Decimals :- \n";
    string s1, s2;
    cin>>s1>>s2;
    cout<<"Precision to be followed : - \n";
    int prec;  cin>>prec;
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
    if(posOfdec2==-1){
        s2 += '.';
        for(int i=0;i<=300; i++){
            s2 += '0';
        }
    }else{
        int temp = len2 - posOfdec2;
        for(int i=0;i<=300-temp;i++){
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
    // cout<<s11<<" "<<s22<<endl;

    int opt;
    cout<<"Enter 1 for Addition and 2 for Subtraction\n";
    cin>>opt;

    if(opt==1){
        string ans1 = add(s11,s22);
        string ans11 ="";
        int finalPosOfDec1 = calculateLength(ans1) - 300;   // 300 since initially number of elements after decimal is 300
        for(int i=0;i<calculateLength(ans1); i++){
            if(i==finalPosOfDec1){
                ans11 += '.';
            }
            ans11 += ans1[i];
        }
        cout<<makePreci(ans11,prec)<<endl;
    }else if(opt==2){
        string ans2 = sub(s11,s22);
        string ans22 ="";
        int finalPosOfDec2 = calculateLength(ans2) - 300;
        for(int i=0;i<calculateLength(ans2); i++){
            if(i==finalPosOfDec2){
                ans22 += '.';
            }
            ans22 += ans2[i];
        }
        cout<<makePreci(ans22,prec)<<endl;
    }else{
        cout<<"Invalid option choosen"<<endl;
    }
}
