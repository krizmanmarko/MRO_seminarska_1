simple myMMc
{
	parameters:
		int capacity = default(100);
		int c = default(2);
		volatile double serviceTime @unit(s) = default(truncnormal(3s, 2s));

	gates:
		input in[];
		output out;
}
