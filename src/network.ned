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

network kMM1
{
	submodules:
		source: mySource;
		sink: mySink;
	connections:
		source.out --> sink.in++;
}
