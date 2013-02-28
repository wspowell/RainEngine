// stokenizer
// Author: Wesley Powell
// January 2013
// string tokenizer that splits a string into an array
// the object can then iterate through each token

#include "stokenizer.h"

string STokenizer::nextToken() {
	return nextToken(delim);
}

string STokenizer::nextToken(char d) {
	if(stoken.length() == 0) { return ""; }
	size_t found = stoken.find(delim);
	if(found == string::npos) { found = stoken.length(); }
	string next = stoken.substr(0,found);
	if((stoken.length()-found) > 0) { stoken = stoken.substr(found+1); }
	else { stoken = ""; }
	return next;
}

unsigned int STokenizer::countTokens() {
	unsigned int num = count(stoken.begin(),stoken.end(),delim);
	if(num == 0 && stoken.length() > 0) { num = 1; }
	return num;
}

bool STokenizer::hasMoreTokens() {
	return (countTokens() > 0) ? true : false;
}
