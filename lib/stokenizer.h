// stokenizer
// Author: Wesley Powell
// January 2013
// string tokenizer that splits a string into an array
// the object can then iterate through each token

#ifndef STOKENIZER_H
#define STOKENIZER_H

#include <algorithm>
#include <string>

using namespace std;

class STokenizer {
	private:
		string stoken;
		char delim;
	public:
		STokenizer(string s, char d = ' ') : stoken(s), delim(d) { }
		~STokenizer() { }
		string nextToken();
		string nextToken(char d);
		unsigned int countTokens();
		bool hasMoreTokens();
};

#endif
