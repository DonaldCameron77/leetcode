/*
	Leetcode Online Judge: Gas Station

Gas Station Total Accepted: 7088 Total Submissions: 29914

There are N gas stations along a circular route, where the amount of gas at
station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel
from station i to its next station (i+1). You begin the journey with an empty
tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once,
otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

/* scaffold input format:
		Each test case comprises three lines.  The first is a list of gas vector elements,
		blank-separated. The second is the corresponding cost list, with the same
		layout. The third line is blank, for ease of comprehension.
		
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "gas.h"

int main(int argc, char * argv[])
{
	if (argc != 2) {
		cout << "usage: " << argv[0] << "<filename>\n";
		return 1;
	}

	ifstream ifs(argv[1]);
	string line;
	Solution s;

	while (getline(ifs, line))
	{
		vector<int> gvec, cvec;
		
		cout << line << endl;
		istringstream gas(line);
		int gtmp;
		while (gas >> gtmp)
			gvec.push_back(gtmp);
			
		getline(ifs, line);
		cout << line << endl;
		istringstream cost(line);
		int ctmp;
		while (cost >> ctmp)
			cvec.push_back(ctmp);
		
		getline(ifs, line); // skip over blank line

		int result = s.canCompleteCircuit(gvec, cvec);
		cout << result << endl;
    }
}













