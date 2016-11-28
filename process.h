#ifndef PROCESS_H_
#define PROCESS_H_
#include <list>

using namespace std;

class Prio
{
public:

    Prio()
      :pNo(0){}

    void addProcess(int prio);
    void terminateProcess();
    void blockProcess();
    void unblockProcess();
    void setProcess();

    void printState();

private:
    struct process
    {
        int processNo;
        int priority;	//high, med, low
        int ptime;		//time needed in running--each visit to cpu decrements by 1
    };

    list <process> hp;
    list <process> mp;
    list <process> lp;
    list <process> block;
    list <process> running;
    list <process> ended;
    int pNo;

};





#endif /* PROCESS_H_ */
