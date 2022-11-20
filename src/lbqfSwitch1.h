#ifndef LBQFSWITCH1_H_
#define LBQFSWITCH1_H_

#include <omnetpp.h>

using namespace omnetpp;

class lbqfSwitch1 : public cSimpleModule
{
	public:
		lbqfSwitch1();
		virtual ~lbqfSwitch1();

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual void updateDisplay(int i);

	private:
		int c;
		std::vector<int> usageMM1;
		void fetch_data();
		int least_busy_queue_mm1();
};

#endif
