#ifndef MYMMC_H_
#define MYMMC_H_

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
		int c;	// stevilo streznikov v SE
		jobsProcessingList jobsProcessing;
	    simsignal_t queueLengthSignal;
	    simsignal_t utilSignal;


	public:
		myMMc();
		virtual ~myMMc();

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual void updateDisplay(int i);
};

#endif
