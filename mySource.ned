simple mySource
{
	parameters:
		int maxJobs = default(100);
		int numJobs = default(2);
		volatile double interArrivalTime @unit(s) = default(uniform(0s, 3s));
		double startTime @unit(s) = default(10s);
		double stopTime @unit(s) = default(3600s);

	gates:
		output out;
}
