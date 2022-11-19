#include "mySink.h"

Define_Module(mySink);

mySink::mySink() {};
mySink::~mySink() {};

void mySink::initialize()
{
	sinked = 0;
}

void mySink::handleMessage(cMessage *msg)
{
	delete msg;
	sinked++;
	updateDisplay(sinked);
}

void mySink::updateDisplay(int i)
{
	char buf[100];
	sprintf(buf, "%ld", (long) i);
	getDisplayString().setTagArg("t", 0, buf);
}
