#ifndef RANDSWITCH1_H_
#define RANDSWITCH1_H_

#include <omnetpp.h>
#include <random>

using namespace omnetpp;

class randSwitch1 : public cSimpleModule
{
	public:
		randSwitch1();
		virtual ~randSwitch1();

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual void updateDisplay(int i);

	private:
		int c;
};

#endif
