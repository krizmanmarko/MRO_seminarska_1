simple myMMc
{
	parameters:
	    
	    @signal[queueLength](type=long);
        @signal[util](type=float);
	    
	    @statistic[queueLength](title="queue length";record=vector;interpolationmode=none);
        @statistic[util](title="resources";record=vector;interpolationmode=none);
	    
		int capacity = default(10000);
		int c = default(2);
		volatile double serviceTime @unit(s) = default(truncnormal(3s, 2s));

	gates:
		input in[];
		output out;
}
