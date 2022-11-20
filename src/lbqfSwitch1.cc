#include "lbqfSwitch1.h"
#include "myMM1.h"

Define_Module(lbqfSwitch1);

lbqfSwitch1::lbqfSwitch1() {};
lbqfSwitch1::~lbqfSwitch1() {};

void lbqfSwitch1::fetch_data()
{
	usageMM1.clear();
	for (int i = 0; i < c; i++) {
		myMM1 *p = (myMM1 *)(this->gate("out", i)->getNextGate()->getOwner());
		usageMM1.push_back(p->getLength());
	}
}

int lbqfSwitch1::least_busy_queue_mm1()
{
	this->fetch_data();
	int min = 0x7fffffff;
	int imin = -1;
	for (int i = 0; i < c; i++) {
		if (usageMM1[i] < min) {
			min = usageMM1[i];
			imin = i;
		}
	}
	return imin;
}

void lbqfSwitch1::initialize()
{
	c = par("c");
}

void lbqfSwitch1::handleMessage(cMessage *msg)
{
	int sendTo = this->least_busy_queue_mm1();
	send(msg, "out", sendTo);
	updateDisplay(sendTo);
}

void lbqfSwitch1::updateDisplay(int i)
{
	char buf[100];
	sprintf(buf, "to: %d", i);
	getDisplayString().setTagArg("t", 0, buf);
}
