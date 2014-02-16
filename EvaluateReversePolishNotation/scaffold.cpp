// test scaffold for leetcode: Evaluate Reverse Polish Notation
//
//  == file to be submitted is eval.h

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "eval.h"

int main(int argc, char *argv[]) {

	if (argc != 2) {
    		cout << "usage: " << argv[0] << "<filename>\n";
    		return 1;
	}

	ifstream ifs(argv[1]);
	string line;

	while (getline(ifs, line))
	{
		// cout << line << endl;

		// We have to tokenize the input and convert it to an
		// vector<string>, one element per token.  The good
		// news is that this process is entirely under our contral,
		// as our evalRPN function will be called by leetcode's scaffold
		// with the vector already set up.
		//
		// So let's keep it simple, and let the input be in a file
		// with one complete expression per line, with the tkens
		// whitespace separated

		istringstream iss(line);
		string tok;
		vector<string> tokens;
		

		while (iss >> tok) {
			tokens.push_back(tok);
			// cout << tok << " ";
		}
		// cout << endl;


		Solution s;
		int result = s.evalRPN(tokens);
		cout << result << "\n";
	} // while getline
}
