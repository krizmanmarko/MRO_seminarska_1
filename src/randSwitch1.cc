#include "randSwitch1.h"

Define_Module(randSwitch1);

static int rng(int a, int b)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(a, b);
	return distr(gen);
}

randSwitch1::randSwitch1()
{
}

randSwitch1::~randSwitch1()
{
}

void randSwitch1::initialize()
{
	c = par("c");
}

void randSwitch1::handleMessage(cMessage *msg)
{
	// randomly assign messages to MM1
	int randnum = rng(0, c-1);
	send(msg, "out", randnum);
	updateDisplay(randnum);
}

void randSwitch1::updateDisplay(int i)
{
	char buf[100];
	sprintf(buf, "to: %d", i);
	getDisplayString().setTagArg("t", 0, buf);
}
