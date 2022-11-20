#include "mySink.h"

Define_Module(mySink);

mySink::mySink() {};
mySink::~mySink() {};

void mySink::initialize()
{
	sinked = 0;
	updateDisplay(sinked);
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
	sprintf(buf, "%d", i);
	getDisplayString().setTagArg("t", 0, buf);
}
