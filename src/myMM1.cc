#include "myMM1.h"

Define_Module(myMM1);

myMM1::myMM1()
{
	currentJob = NULL;
	endServiceMsg = NULL;
}

myMM1::~myMM1()
{
	delete currentJob;
	cancelAndDelete(endServiceMsg);
	jobsProcessingList::iterator msgIt;
	for (msgIt = jobsProcessing.begin(); msgIt != jobsProcessing.end(); msgIt++) {
		cancelAndDelete(*msgIt);
	}
}

void myMM1::initialize()
{
	endServiceMsg = new cMessage("end");
	capacity = par("capacity");
	serviceTime = par("serviceTime");
	jobsProcessing.clear();
	length = 0;
	updateDisplay(length);
}

void myMM1::handleMessage(cMessage *msg)
{
	if (msg->getKind() == 0) {
		if (jobsProcessing.size() < 1) {
			jobsProcessing.push_back(msg);
			msg->setKind(10);
			scheduleAt(simTime() + serviceTime, msg);
		} else {
			bool hasMoreCapacity = capacity < 0 || length < capacity;
			if (hasMoreCapacity) {
				queue.insert(msg);
				length++;
			} else {
				delete msg;
			}
		}
	} else {
		jobsProcessingList::iterator msgIt;
		for (msgIt = jobsProcessing.begin(); msgIt != jobsProcessing.end(); msgIt++) {
			if ((*msgIt)->getId() == msg->getId()) {
				jobsProcessing.erase(msgIt);
				break;
			}
		}
		send(msg, "out");
		if (queue.isEmpty() == false) {
			msg = check_and_cast<cMessage *>(queue.pop());
			length--;
			msg->setKind(10);
			jobsProcessing.push_back(msg);
			scheduleAt(simTime() + serviceTime, msg);
		}
	}
	updateDisplay(length);
}

void myMM1::updateDisplay(int i)
{
	char buf[100];
	sprintf(buf, "qlen: %d", i);
	getDisplayString().setTagArg("t", 0, buf);
}
