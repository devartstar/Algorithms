/*
    -------------------------------------
    |									|
    |	Author - Devjit Choudhury		|
    |	Roll   - 19MA20014             	|	
    |    	                            |
    -------------------------------------

    LAB 5 : Ques :-
    2.) Check if the given expression is correct or not.

*/

/*
    LOGIC :- 
        The following has to be checked for invalid expression - 
            1.  forbidden characters, D
            2.  bracket mismatch, D
            3.  consecutive mathematical operators, D
            4.  coefficients occurring after variables, D
            5.  non integer powers, D
            6.  leading plus symbols within a bracket, D
            7.  empty brackets etc. D
            8.  expression of form (+) (-) (^) are invalid
            9.  expression staring and ending with integer
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Expression{
    public:
        bool isMathematicalOperator(char);
        bool checkForbiddenCharacter(string, int);
        bool checkBracketMismatching(string, int);
        bool checkConsMathOperations(string, int);
        bool checkIfInt(string, int);
        bool checkNonIntPow(string, int);
        bool coefAfterVar(string, int);
        bool mathOpnWithBrac(string, int);
        bool emptyBrac(string, int);
        bool mathOpnBwBrac(string, int);
};

////////////////////////////////////////////////////////////////////////////////////////
// check if the character is mathematical operation
bool Expression::isMathematicalOperator(char ch){

    if(ch=='+' || ch=='-' || ch=='^'){
        return true;
    }else{
        return false;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
// true = expression valid
// false = expression invalid
bool Expression::checkForbiddenCharacter(string s, int len){
    // forbidden characters like @, #, $ are not allowed ( even '*' is invalid according to ques)
    // addition (+), subtraction (-), multiplication (without symbol), and power (^), characters from 'a' to 'z' and integers '0' to '9'

    for(int i=0; i<len; i++){
        char ch = s[i];
        if(isMathematicalOperator(ch) || ch=='(' || ch==')' || (ch-'a'>=0 && ch-'a'<26) || (ch-'0'>=0 && ch-'0'<10)){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////
// check if brackets matching or not
// true = expression valid
// false = expression invalid
bool Expression::checkBracketMismatching(string s, int len){
    // LOGIC - have a temp variable 
    // then we have '(' do temp++
    // if we have ')' temp--
    // if temp < 0 at any point of time return false

    int temp = 0;
    for(int i=0; i<len; i++){
        if(s[i]=='('){
            temp = temp + 1;
        }else if(s[i]==')'){
            temp = temp - 1;
        }

        if(temp < 0){
            return false;
        }
    }
    if(temp!=0){
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////
// check if consecutive math opns
// true = expression invalid
// false = expression valid
bool Expression::checkConsMathOperations(string s, int len){
    // "+ +" "- -" "/ /" and other combination not allowed

    for(int i=0; i<len-1; i++){
        if(isMathematicalOperator(s[i]) && isMathematicalOperator(s[i+1])){
            return true;
        }
    }
    return false;

}

////////////////////////////////////////////////////////////////////////////////////////
bool Expression::checkIfInt(string s, int len){
    for(int i=0; i<len; i++){
        if(s[i]-'0'>=0 && s[i]-'0'<10){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////
// check if power is integer ( given in ques only integer power valid)
// true = expression invalid - it has non int pow
// false = expression valid
bool Expression::checkNonIntPow(string s, int len){

    for(int i=0; i<len; i++){
        // continue if the current character is not an alphabet
        if(s[i]-'a' < 0 || s[i]-'a' >= 26){
            continue;
        }

        if(i<len-1 && s[i+1]=='^'){
            string temp = "";
            int templength = 0;
            for(int j = i+3 ; j<len; j++){
                if(s[j] == ')'){
                    // i=j; // we can optimize the code a bit by doing this
                    break;
                }
                temp = temp + s[j];
                templength = templength + 1;
            }
            if(checkIfInt(temp, templength)==false){
                return true;    // it has non int power
            }
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////
// if we have coef after variable like x6 instead of 6x
// true = expression invalid
// false = expression valid
bool Expression::coefAfterVar(string s, int len){
    // we cannot have a5 -> 5a is valid
    
    for(int i=0; i<len-1; i++){
        if((s[i]-'a'>=0 && s[i]-'a'<26) && (s[i+1]-'0'>=0 && s[i+1]-'0'<10)){
            return true;
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////
// some math opns cannot be followe by bracket and vice berse
// (-3x) is valid but (^3) is invalid and such cases
// true = expression invalid
// false = expression valid
bool Expression::mathOpnWithBrac(string s, int len){
    // when we have a mathematical opn just before or after bracket

    for(int i=0; i<len-1; i++){
        if( 
            (s[i]=='(' && ( s[i+1]=='^' || s[i+1]=='+')) || 
            ((s[i]=='^') && s[i+1]=='(') || 
            ((s[i]=='+' || s[i]=='^' || s[i]=='-') && s[i+1]==')')
            ){
                return true;
            }
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////
// Empty bracket pair is invalid ()
// true = expression invalid - has empty brackets
// false = expression valid
bool Expression::emptyBrac(string s, int len){
    for(int i=0; i<len-1; i++){
        if(s[i]=='(' && s[i+1]==')'){
            return true;
        }
    }
    return false;
}


// true = expression invalid - has empty brackets
// false = expression valid
bool Expression::mathOpnBwBrac(string s, int len){
    for(int i=0; i<len-2; i++){
        if(s[i]=='(' && isMathematicalOperator(s[i+1]) && s[i+2]==')'){
            return true;
        }
    }
    return false;
}


int main(){

    Expression exp; 

    fstream myfile;
    myfile.open("input2.txt");
    char c;

    string expression = "";
    int length = 0;

    myfile.get(c);
    while(c!='\n'){
        expression = expression + c;
        length = length + 1;
        myfile.get(c);
    }


    // If any one of the condition dosent holds then the expression is invalid

            // cout<< checkForbiddenCharacter(expression, length) <<endl;
            // cout<<checkBracketMismatching(expression, length)<<endl;
            // cout<<checkConsMathOperations(expression, length)<<endl;
            // cout<<checkNonIntPow(expression, length)<<endl;
            // cout<<coefAfterVar(expression, length)<<endl;
            // cout<<mathOpnWithBrac(expression, length)<<endl;
            // cout<<emptyBrac(expression, length)<<endl;

    if(
            exp.checkForbiddenCharacter(expression, length) == false ||
            exp.checkBracketMismatching(expression, length) == false ||
            exp.checkConsMathOperations(expression, length) == true ||
            exp.checkNonIntPow(expression, length) == true ||
            exp.coefAfterVar(expression, length) == true ||
            exp.mathOpnWithBrac(expression, length) == true ||
            exp.emptyBrac(expression, length) == true ||
            exp.mathOpnBwBrac(expression, length) == true
        )
    {
        cout<<"Expression : "<<expression<<" is Incorrect"<<endl;
    }else{
        cout<<"Expression : "<<expression<<" is Correct"<<endl;
    }
}



/*
SAMPLE INPUT :- 
6d+5z(81+7t++)

^^ Incorrect

3d+((7f) -> Incorrect
4s+5t(6d+f) -> Correct
(2s+f5) ->Incorrecr
(2s+4r)+(3s) -> Correct
(^3s+4r+df)(43+f) -> Incorrect
(3d+5s)() -> Incorrect
(3^)2s+t -> Incorrect
-(3x+4y) -> Correct
(2x+y)(3c+d) -> Correct
(-3x$+4y) -> Incorrect
*/