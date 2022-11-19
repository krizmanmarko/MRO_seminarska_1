#ifndef MYSINK_H_
#define MYSINK_H_

#include <omnetpp.h>

using namespace omnetpp;

class mySink : public cSimpleModule
{
	public:
		mySink();
		virtual ~mySink();

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual void updateDisplay(int i);
		int sinked;
};

#endif
