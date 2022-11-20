#include "randSwitch1.h"

Define_Module(randSwitch1);

randSwitch1::randSwitch1()
{
}

randSwitch1::~randSwitch1()
{
}

void randSwitch1::initialize()
{
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(25, 63);
	//distr(gen)
	c = par("c");
	updateDisplay(c);
}

void randSwitch1::handleMessage(cMessage *msg)
{
	// randomly assign messages to MM1
}

void randSwitch1::updateDisplay(int i)
{
	char buf[100];
	sprintf(buf, "c = %ld", (long) i);
	getDisplayString().setTagArg("t", 0, buf);
}
