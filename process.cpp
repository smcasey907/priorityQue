#include <QString>
#include <QApplication>
#include <QTextEdit>
#include "process.h"


using namespace std;


//adds new process to appropriate priority queue
void Prio::addProcess (int prio)
{
    process p;
    pNo += 1;
    p.processNo = pNo;
    p.priority = prio;
    p.ptime = rand() % 5 + 1;

    if (p.priority == 1)
        hp.push_back(p);
    else if (p.priority == 2)
        mp.push_back(p);
    else if (p.priority == 3)
        lp.push_back(p);
}

void Prio::terminateProcess()
{
    if(!running.empty())
        if(running.front().ptime == 0)
            ended.push_back(running.front());
    running.clear();
}

void Prio::blockProcess()
{
    if(!running.empty())
    {
        if(running.front().ptime == 0)
            terminateProcess();
        else
        {
            block.push_back(running.front());
            running.clear();
        }
    }
}

void Prio::unblockProcess()
{
    if (!block.empty())
    {
        if(block.front().priority == 1)
            hp.push_back(block.front());
        else if (block.front().priority == 2)
            mp.push_back(block.front());
        else if (block.front().priority == 3)
            lp.push_back(block.front());
        block.pop_front();
    }
}

void Prio::setProcess()
{
    if (!running.empty())
    {
        if(running.front().ptime == 0)
            terminateProcess();
        else
        {
            if (running.front().priority == 1)
                hp.push_back(running.front());
            else if (running.front().priority == 2)
                mp.push_back(running.front());
            else if (running.front().priority == 3)
                lp.push_back(running.front());
        running.clear();
        }
    }

    if (!hp.empty())
    {
        running.push_back(hp.front());
        hp.pop_front();
    }
    else if (!mp.empty())
    {
        running.push_back(mp.front());
        mp.pop_front();
    }
    else if (!lp.empty())
    {
        running.push_back(lp.front());
        lp.pop_front();
    }

    running.front().ptime--;
}

void Prio::printState()
{


    list<process>::const_iterator it;

    QString str;

    QTextEdit *txt = new QTextEdit();
    txt->resize(400, 800);
    txt->setWindowTitle("Current State");
    txt->setText("<h2>Current process states:</h2>");
    txt->append("<h3>Ready Queues:</h3>");
    txt->append("<b>High Priority Queue:<b>");
    if (hp.empty())
        txt->append("<i>Queue Empty</i>");
    else
        for (it = hp.begin(); it != hp.end(); it++)
        {
            str.setNum(it->processNo);
            txt->append("<i>Process " + str);
        }
    txt->append("<b>Medium Priority Queue:<b>");
    if (mp.empty())
        txt->append("<i>Queue Empty</i>");
    else
        for (it = mp.begin(); it != mp.end(); it++)
        {
            str.setNum(it->processNo);
            txt->append("<i>Process " + str);
        }
    txt->append("<b>Low Priority Queue:<b>");
    if (lp.empty())
        txt->append("<i>Queue Empty</i>");
    else
        for (it = lp.begin(); it != lp.end(); it++)
        {
            str.setNum(it->processNo);
            txt->append("<i>Process " + str);
        }

    txt->append("<h3>Current Running Process: </h3>");
    if (running.empty())
        txt->append ("<i>none</i>");
    else
    {
        str.setNum(running.front().processNo);
        txt->append ("<i>Process " + str);
    }

    txt->append("<h3>Current Blocked Process(es):</h3>");
    if(block.empty())
        txt->append ("<i>none</i>");
    else
        for(it = block.begin(); it != block.end(); it++)
        {
            str.setNum(it->processNo);
            txt->append ("<i>Process " + str);
        }

    txt->append("<h3>Terminated Process(es): </h3>");
    if (ended.empty())
        txt->append("<i>None Terminated</i>");
    else
        for (it = ended.begin(); it != ended.end(); it++)
        {
            str.setNum(it->processNo);
            txt->append("<i>Process " + str);
        }



    txt->show();

}
