
/*	LeetCode: Evaluate Reverse Polish Notation
	First stab at any leetcode problem.  Apparently one cannot access other
	headers in the STL, so eveything must be done by hand.
*/

class Solution {
private:

	long str_to_int(string & nstr, unsigned spos = 0) {
		long num = 0;
		for (unsigned j = spos; j < nstr.size(); ++j)
			num = num * 10 + nstr[j] - '0';
		return num;
	}
	
public:

    int evalRPN(vector<string> &tokens)
	{
		vector<long> numstack; // assume this is available

		for (unsigned i = 0; i < tokens.size(); ++i)
		{
		  	switch (tokens[i][0]) {
				case '0': case '1': case '2': case '3': case '4':
				case '5': case '6': case '7': case '8': case '9': {
					numstack.push_back(str_to_int(tokens[i]));
					break;
				}
				case '-': {
					// handle separately b/c of unary minus
					long expr;
					// check for unary minus
					if (tokens[i].size() > 1) {
						expr = -str_to_int(tokens[i], 1);
					}
					else {
						long left = numstack.back();
						numstack.pop_back();
						long right = numstack.back();
						numstack.pop_back();
						expr = right - left;
					}
					numstack.push_back(expr);
					break;	
				}
				case '+': case '*': case '/': {
					long left = numstack.back();
					numstack.pop_back();
					long right = numstack.back();
					numstack.pop_back();
					switch (tokens[i][0]) {
						case '*' : {
							numstack.push_back(right * left);
							break;
						}
						case '/' : {
							numstack.push_back(right / left);
							break;
						}
						case '+' : {
							numstack.push_back(right + left);
							break;
						}
					} // inner switch
					break;
				} // case +, *, /
			} // outer switch
		}
		return numstack.back();
	} // evalRPN
};
