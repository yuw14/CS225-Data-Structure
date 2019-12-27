#include <iostream>
#include "potd.cpp"

using namespace std;

int main() {
    unordered_map<string, int> mapA({
                                    {"common", 13}, 
                                    {"unique_a", 13},
                                    });
    unordered_map<string, int> mapB({
                                    {"common", 17}, 
                                    {"unique_d", 13}
                                    });

    unordered_map<string, int> common = common_elems(mapA, mapB);

    // check your outputs here
   for(unordered_map<string,int>::iterator it1=common.begin();it1!=common.end();it1++){
            cout<<it1->first<<" "<<it1->second<<" "<<endl;
        } 
       for(unordered_map<string,int>::iterator it2=mapA.begin();it2!=mapA.end();it2++){
            cout<<it2->first<<" "<<it2->second<<" "<<endl;
        } 
           for(unordered_map<string,int>::iterator it3=mapB.begin();it3!=mapB.end();it3++){
            cout<<it3->first<<" "<<it3->second<<" "<<endl;
        } 
}