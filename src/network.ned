network MMc
{
	submodules:
		source: mySource;
		mmc: myMMc;
		sink: mySink;
	connections:
		source.out --> mmc.in++;
		mmc.out --> sink.in++;
}

network randkMM1
{
	submodules:
		source: mySource;
		sink: mySink;
		switch1: randSwitch1;
		switch2: switch2;
		mm1[switch1.c]: myMM1;

	connections:
		source.out --> switch1.in++;
		for i = 0..switch1.c-1 {
			switch1.out++ --> mm1[i].in++;
			mm1[i].out --> switch2.in++;
		}
		switch2.out --> sink.in++;
}

network lbqfkMM1
{
	submodules:
		source: mySource;
		sink: mySink;
		switch1: lbqfSwitch1;
		switch2: switch2;
		mm1[switch1.c]: myMM1;

	connections:
		source.out --> switch1.in++;
		for i = 0..switch1.c-1 {
			switch1.out++ --> mm1[i].in++;
			mm1[i].out --> switch2.in++;
		}
		switch2.out --> sink.in++;
}
