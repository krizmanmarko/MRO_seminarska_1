#include "myMMc.h"

Define_Module(myMMc);

myMMc::myMMc()
{
	currentJob = NULL;
	endServiceMsg = NULL;
}

myMMc::~myMMc()
{
	delete currentJob;
	cancelAndDelete(endServiceMsg);
	jobsProcessingList::iterator msgIt;
	for (msgIt = jobsProcessing.begin(); msgIt != jobsProcessing.end(); msgIt++) {
		cancelAndDelete(*msgIt);
	}
}

void myMMc::initialize()
{
    queueLengthSignal = registerSignal("queueLength");
    utilSignal = registerSignal("util");

	endServiceMsg = new cMessage("end");
	capacity = par("capacity");
	serviceTime = par("serviceTime");
	c = par("c");	// MMc
	jobsProcessing.clear();
	length = 0;
	updateDisplay(length);

	emit(queueLengthSignal,0);
    emit(utilSignal,0.0);
}

void myMMc::handleMessage(cMessage *msg)
{
	if (msg->getKind() == 0) {
		if (jobsProcessing.size() < c) {
			jobsProcessing.push_back(msg);
			msg->setKind(10);
			scheduleAt(simTime() + serviceTime, msg);
		} else {
			bool hasMoreCapacity = capacity < 0 || length < capacity;
			if (hasMoreCapacity) {
				queue.insert(msg);
				length++;
				emit(queueLengthSignal, length);
			} else {
				delete msg;
			}
		}
	} else {
		jobsProcessingList::iterator msgIt;
		for (msgIt = jobsProcessing.begin(); msgIt != jobsProcessing.end(); msgIt++) {
			if ((*msgIt)->getId() == msg->getId()) {
                emit(utilSignal, (jobsProcessing.size() / c));
				jobsProcessing.erase(msgIt);
				break;
			}
		}
		send(msg, "out");
		if (queue.isEmpty() == false) {
			msg = check_and_cast<cMessage *>(queue.pop());
			length--;
			emit(queueLengthSignal, length);
			msg->setKind(10);
			jobsProcessing.push_back(msg);
			scheduleAt(simTime() + serviceTime, msg);
		}
	}
	updateDisplay(length);
}

void myMMc::updateDisplay(int i)
{
	char buf[100];
	sprintf(buf, "qlen: %d jobsProc: %d", i, jobsProcessing.size());
	getDisplayString().setTagArg("t", 0, buf);
}
