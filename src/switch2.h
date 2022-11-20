#ifndef SWITCH2_H_
#define SWITCH2_H_

#include <omnetpp.h>

using namespace omnetpp;

class switch2 : public cSimpleModule
{
	public:
		switch2();
		virtual ~switch2();

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual void updateDisplay(int i);
};

#endif
