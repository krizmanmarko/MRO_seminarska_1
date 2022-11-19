simple myMM1
{
	parameters:
		int capacity = default(100);
		volatile double serviceTime @unit(s) = default(truncnormal(3s, 2s));

	gates:
		input in[];
		output out;
}
