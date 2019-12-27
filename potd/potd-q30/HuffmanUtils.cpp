#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>
#include<vector>

using std::string;
using std::vector;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    char curr_char;
    string result="";
    HuffmanNode* curr_node=huffmanTree;
    for(unsigned i=0;i<binaryString.length();i++){
    	curr_char=binaryString[i];
    	if(curr_char=='0'){
    		curr_node=curr_node->left_;
    	}
    	else if(curr_char=='1'){
    		curr_node=curr_node->right_;
    	}
    	if(curr_node->left_==NULL&&curr_node->right_==NULL){
    		result=result+curr_node->char_;
    		curr_node=huffmanTree;
    	}

    }
    return result;
}

void getPath(vector<char> d, vector<vector<char>> &path, const HuffmanNode* huffmanTree){
	if(huffmanTree==NULL){
		return;
	}
	if(huffmanTree->left_==NULL&&huffmanTree->right_==NULL){
		d.push_back(huffmanTree->char_);
		path.push_back(d);
		return;
	}
	else{
		if(huffmanTree->left_!=NULL){
			d.push_back('0');
			getPath(d,path,huffmanTree->left_);
            d.pop_back();
		}
		if(huffmanTree->right_!=NULL){
			d.push_back('1');
			getPath(d,path,huffmanTree->right_);
		}
	}
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    vector<vector<char>> path;
    vector<char> d;
    char curr_char;
    getPath(d,path,huffmanTree);
    string result="";
    for(unsigned i=0;i<charString.length();i++){
    	curr_char=charString[i];
    	for(unsigned j=0;j<path.size();j++){
    		if(path[j].back()==curr_char){
    			for(unsigned k=0;k<path[j].size()-1;k++){
    				result=result+path[j][k];
    			}
    			break;
    		}
    	}
    }
    return result;
}
