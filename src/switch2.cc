#include "switch2.h"

Define_Module(switch2);

switch2::switch2() {}
switch2::~switch2() {}

void switch2::initialize()
{
	count = 0;
	updateDisplay(count);
}

void switch2::handleMessage(cMessage *msg)
{
	send(msg, "out");
	count++;
	updateDisplay(count);
}

void switch2::updateDisplay(int i)
{
	char buf[100];
	sprintf(buf, "%d", i);
	getDisplayString().setTagArg("t", 0, buf);
}
