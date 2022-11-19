#ifndef MYMM1_H_
#define MYMM1_H_

#include <omnetpp.h>

using namespace omnetpp;

typedef std::list<cMessage *> jobsProcessingList;

class myMMc : public cSimpleModule
{
	private:
		cQueue queue;
		cMessage *currentJob;
		cMessage *endServiceMsg;
		int capacity, length;
		simtime_t serviceTime;
		jobsProcessingList jobsProcessing;

	public:
		myMM1();
		virtual ~myMM1();

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual void updateDisplay(int i);
};

#endif
