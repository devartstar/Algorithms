/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Roll   - 19MA20014             	|	
    |    	                            |
    -------------------------------------

    LAB 1 - QUES 2
*/

#include <iostream>
#include <string>
using namespace std;

/*
!!!
Since i have set calculate precision till 300 after decimal
the program might take 2 to 3 seconds to execute
*/

 /*    HELPER FUNCTIONS FROM Prev ques */
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
    if (carry) str += (carry+'0');
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
string div(string number, long long divisor) // divide 1 string with 1 number, the version for divide two strings in down below
{
    string ans = "";
    long long idx = 0;
    long long temp = number[idx] - '0';
    while (temp < divisor) temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx) 
    {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    while (ans.size() > 1 && ans[0] == '0') 
        ans.erase(0, 1);
    if (calculateLength(ans) == 0) return "0";
    return ans;
}
bool bigger2(string a, string b) // check if a >= b, not strictly greater
{
    if (calculateLength(a) > calculateLength(b)) return true;
    if (calculateLength(a) < calculateLength(b)) return false;
    for(int i = 0; i<= calculateLength(a) - 1; i++)
    {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return true;
}
string dv(string a, string b) // divide as two strings, use binary search
{
    if (bigger(b, a)) return "0";
    if (a == "0") return "0";
    string l = "0";
    string r = a;
    string mid, mid2;
    while (bigger2(r, l))
    {
        mid = add(r, l);
        if ((mid[calculateLength(mid) - 1] - '0') % 2 == 1) mid[calculateLength(mid) - 1]--;
        mid = div(mid, 2);
        if (mid == "0") break;
        mid2 = mul(mid, b);
        if (bigger(mid2, a)) r = sub(mid, "1");
        else l = add(mid, "1");
    }
    return r;
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
    string s22 = "";    // s11 is the copy of the string s1 without decimal
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
    pos2 = calculateLength(s2)-pos2-1;
    
    int opt;
    cout<<"Enter 1 for Multiplication and 2 for Division\n";
    cin>>opt;

    if(opt == 1){
        string ans1 = mul(s11,s22);
        int finalPos = pos1+pos2;        // adjusting the decimal
        string ans11 ="";
        int finalPosOfDec1 = finalPos;

        reverseStr(ans1);
        for(int i=0;i<=300;i++){         // 10 to be made to 300
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
        cout<<makePreci(ans11, prec)<<endl;

    }else if(opt == 2){

        /* MY LOGIC FOR DIVISION
                IT WAS NOT THAT DIFFICUT TO CODE TO GET THE INTIGER PART ON DIVISION BY STRINGS
                TO GET THE DECIMAL PART
                    -> REMOVE THE DECIMALS AND COUNT THE DIGITS AFTER DECIMAL TO BE ADJUSTED LATER
                    -> LETS FIRST ADD 300 '0' TO THE END OF STRING
                    -> NO ON OBTAINING THE INTEGER PART 
                        1. THE DECIMAL TO BE MOVED 300 PLACES TO LEFT OF END OF ANS
                        2. ADGUST THE DECIMAL FROM THE POSITIONS CALAC (POS2-POS1)
        */

        for(int i=0;i<300;i++)  s11+='0';    
        // sice the max - precision set to 300 ( so come might take few seconds)
        // decrease from 300 to smaller value to spped it up
        // cout<<s11<<" "<<s22<<endl;
        while (calculateLength(s11) > 1 && s11[0] == '0'){
            for(int i=0; i<calculateLength(s11)-1;i++){
                s11[i] = s11[i+1];
            }
        }
        while (calculateLength(s22) > 1 && s22[0] == '0'){
            for(int i=0; i<calculateLength(s22)-1;i++){
                s22[i] = s22[i+1];
            }
        }
        string ans2 = dv(s11,s22);
        int finalPos = pos2 - pos1;   // adjusting the decimal (if -ve then point moves right) (if +ve then points move left)
        string ans22 ="";

        // calculating the final position of decimal 
        int finalPosOfDec2 = 300 + finalPos; //  300 - as its max precision allowed

        reverseStr(ans2);
        for(int i=0;i<=300;i++){         // 300 - as its max precision allowed
            ans2 += '0';
        }
        for(int i=0;i<calculateLength(ans2); i++){
            if(i==finalPosOfDec2){
                ans22 += '.';
            }
            ans22 += ans2[i];
        }
        reverseStr(ans22);
        while (calculateLength(ans22) > 1 && ans22[0] == '0'){
            for(int i=0; i<calculateLength(ans22)-1;i++){
                ans22[i] = ans22[i+1];
            }
        }
        if(ans22[0]=='.')   ans22 = '0' + ans22;
        cout<<makePreci(ans22,prec)<<endl;
    }else{
        cout<<"Invalid Input"<<endl;
    }
}

