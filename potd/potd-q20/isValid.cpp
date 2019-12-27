#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> s;
    int length=input.length();
    for(int i=0;i<length;i++){
      if((input.at(i)!='[')&&(input.at(i)!='{')&&(input.at(i)!='(')&&(input.at(i)!=']')&&(input.at(i)!=')')&&(input.at(i)!='}')){
        continue;
      }
      else if((input.at(i)=='[')||(input.at(i)=='{')||(input.at(i)=='(')){
        s.push(input.at(i));
        continue;
      }
      // else if((input.at(i)==']')||(input.at(i)=='}')||(input.at(i)==')'))
      else
      {
        if(s.empty()){return false;}
        // char tmp=s.top();
        else if((s.top()=='[')&&(input.at(i)==']')){
          s.pop();
          continue;
        }
        else if((s.top()=='(')&&(input.at(i)==')')){
          s.pop();
          continue; }
        else if((s.top()=='{')&&(input.at(i)=='}')){
          s.pop();
          continue;    }
        else{return false;}
        }
    }
    if(s.empty()){return true;}
    else {return false;}

    // return true;    // modify this!
}
