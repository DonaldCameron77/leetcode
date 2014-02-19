class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	int nstations = gas.size();
    	for (int spos = 0; spos < nstations; ++spos) // trying each starting point
    	{
    		int tank = gas[spos] - cost[spos];   //current amount of gas in our vehicle
    		if (tank < 0) continue; // can't start here
    		
    		for (int step = (spos + 1) % nstations;
    			 step != spos; // have we circled all the way back?
    			 step = (step + 1) % nstations)
    		{
    			tank += gas[step] - cost[step];
    			if (tank <0) goto next_spos;
    		}
    		return spos;
    		
    next_spos: ;
    	}
        return -1;
    }
};
