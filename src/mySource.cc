#include "mySource.h"

Define_Module(mySource);

mySource::mySource()
{
	generateJobMsg = NULL;
}

mySource::~mySource()
{
}

void mySource::initialize()
{
	generateJobMsg = new cMessage("generate");
	startTime = par("startTime");
	stopTime = par("stopTime");
	numJobs = par("numJobs");
	maxJobs = par("maxJobs");

	jobCounter = 0;
	scheduleAt(startTime, generateJobMsg);
}

void mySource::handleMessage(cMessage *msg)
{
	if (generateJobMsg == msg) {
		bool canDoMoreJobs = maxJobs < 0 || jobCounter < maxJobs;
		bool hasMoreTime = simTime() < stopTime || stopTime < 0;
		if (canDoMoreJobs && hasMoreTime) {
			scheduleAt(simTime() + par("interArrivalTime").doubleValue(), msg);
			for (int i = 0; i < numJobs; i++) {
				cMessage *job = new cMessage();
				send(job, "out");
				jobCounter++;
			}
			updateDisplay(jobCounter);
		} else {
			delete msg;
		}
	} else {
		delete msg;
	}
}

void mySource::updateDisplay(int i)
{
	char buf[100];
	sprintf(buf, "%ld", (long) i);
	getDisplayString().setTagArg("t", 0, buf);
}
