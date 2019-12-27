#include "potd.h"
#include <iostream>
#include<string>

using namespace std;

string stringList(Node *head) {
    // your code here!	
    string newString;
	if(head==NULL){
		return"Empty list";
	}
    else{
    newString="Node "+to_string(0)+": "+to_string(head->data_);
    head=head->next_;        
    for(int i=1;head!=NULL;i++){
    newString=newString+" -> "+"Node "+to_string(i)+": "+to_string(head->data_);
    head=head->next_;    
		}
	return newString;
	}
}
