# MRO - 1. seminarska naloga, Primerjava M/M/c in c - M/M/1

## src

### myMMc
My implementation of MMc system.
* myMMc.h
* myMMc.cc
* myMMc.ned

### myMM1
Hardcoded version of myMMc with c equal to 1. We get MM1 system.
* myMM1.h
* myMM1.cc
* myMM1.ned

### switch1
- random scheduling
  * randSwitch1.h
  * randSwitch1.cc
  * randSwitch1.ned

- priority scheduling using exported number of messages from myMM1
  * lbqfSwitch1.h
  * lbqfSwitch1.cc
  * lbqfSwitch1.ned

### switch2
Pass all received messages to output.
* switch2.h
* switch2.cc
* switch2.ned

## report
Folder for latex sources.

# TODO
- [x] topology
- [x] switch1 random
- [x] switch1 lbqf (least busy queue first)
- [x] switch2
- [ ] logging
- [ ] simulation
- [ ] report
