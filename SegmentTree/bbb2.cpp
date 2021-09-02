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


string mul(string A, string B) // multiply strings
{
    reverseStr(A);
    reverseStr(B);
    int lena = calculateLength(A);
    int lenb = calculateLength(B);

    string C = "";
    for(int i=0; i<lena + lenb; i++)
        C += '0';

    for (int i = 0; i < lena; i++)
    {
        int c = 0;
        for(int j = 0; j<=lenb-1; j++)
        {
            c += ((A[i] - '0') * (B[j] - '0') + C[i + j] - '0');
            C[i + j] = (char)(c%10 + '0');
            c/=10;
        }
        if (c > 0) C[i + B.length()] += c;
    }
    reverseStr(C);
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


int main(){
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
    
    int opt;
    cout<<"Enter 1 for Multiplication and 2 for Division\n";
    cin>>opt;

    if(opt == 1){
        string ans1 = mul(s11,s22);
        int finalPos = pos1+pos2;   // adjusting the decimal
        string ans11 ="";
        int finalPosOfDec1 = finalPos;
        cout<<finalPosOfDec1<<endl;
        for(int i=0;i<calculateLength(ans1); i++){
            if(i==finalPosOfDec1){
                ans11 += '.';
            }
            ans11 += ans1[i];
        }
        cout<<makePreci(ans11, prec)<<endl;
    }else if(opt == 2){

    }else{
        cout<<"Invalid Input"<<endl;
    }
}
