/*

LeetCode challenge: Gas Stations

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

*/

/*
A program will hit the time limit if it's O(n^2).  There is a linear approach, based
on the observation that, for a given travel segment starting at index s, if you run
out of gas at gas station g, no starting point between s and g would yield a solution.
Proof (sort of): 
- if g is one step from s, then our premise we ran out of gas trying to get to g.
- if g is some number of steps n from s, and we made it as far as g-1, the station
before g, then the sum of the costs[s..g] must have been greater than the fuel
available (gas[s..g]). Therefore, no starting point between s and g would have gotten
us to g, so we may as well not even try them, and instead begin again one step beyond
g.
- if g is the last position in the vector, then in determining the next starting point
we will wrap around.  But ... we have already determined that starting with s = 0
is not a solution.  Similarly, if we began at some station k and wrapped around before
running out of gas, we can quit and signal failure, because any stations with indexes
less than k have already been determined to not provide a solution.
- we can terminate with success starting from s if, upon trying the last station before
s (that is, going from s-1 back to s) we still have not run out.

The following code embodies these considerations.  It's tricky if you don't really
understand the foregoing remarks.
*/

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
	{
		int nstations = (int) gas.size();
		int start_pos = 0; // starting index for next attempt - initially zero

		while (true) { // loop on starting points
			int pos = start_pos; // pos indexes current gas station
			int tank = 0;
			
			while (true) { // loop on gas stations
				tank += gas[pos] - cost[pos];
				pos = (pos + 1) % nstations;
			
				if (tank >= 0) {
					if (pos == start_pos)
						return start_pos;
				}
				else {
					if (pos <= start_pos)
						// if we had wrapped around and then run out,
						// fail (see above remarks)
						return -1; 
					else {
						// skip to next iteration of outer loop,
						// but beware wrapping back to zero
						start_pos = pos;
						if (start_pos == 0) return -1;
						break;
					}
				}
			}
		}
	}
};
				
