#include <iostream>
#include <queue>
using namespace std;

class Person
{
    public:

        int arrivalTime;
        int startTime;
        int serviceTime;
        int maxPerson;
        int endTime;

        Person(int a,int o, int l)
        {
            arrivalTime = a;
            serviceTime = o;
            maxPerson = l;
            endTime = -10000;
            startTime = -10000;
        }
};

int main()
{
    int n,a,o,l;
    queue <int> res;
    while(scanf("%d",&n)!=EOF)
    {
        
        Person * arr[n];
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&a,&o,&l);
            Person *per = new Person(a,o,l);
            arr[i] = per;
        }

        if(n == 1)
        {
            res.push(arr[0]->arrivalTime);
            //cout << "Time: " << arr[0]->arrivalTime << endl;
            continue;
        }

        queue <Person*> q;
        int qSize = 0;
        for(int i = 0; i < n - 1; i++)
        {
            Person* curCustomer = arr[i];
            
            if(q.empty())
            {
                curCustomer->startTime = curCustomer->arrivalTime;
                curCustomer->endTime = curCustomer->startTime + curCustomer->serviceTime;
                
                q.push(curCustomer);
                qSize ++;
            }
            else
            {
                //if anything is running - no pop
                if(curCustomer->arrivalTime < q.front()->endTime)
                {
                    if(curCustomer->maxPerson >= qSize)
                    {
                        curCustomer->startTime = q.back()->endTime;
                        curCustomer->endTime = curCustomer->startTime + curCustomer->serviceTime;
                        q.push(curCustomer);
                        qSize++;
                    }
                    
                }
                //if nothing is under running status - something has finished their task
                //pop completed task from front
                if(curCustomer->arrivalTime >= q.front()->endTime)
                {
                    //iterate queue to pop all completed tasks
                    if(curCustomer->arrivalTime >= q.front()->endTime)
                    {
                        q.pop();
                        qSize--;
                    }     
                    //curcustomer can wait
                    if(curCustomer->maxPerson >= qSize)
                    {
                        //between back
                        if(curCustomer->arrivalTime > q.back()->startTime && curCustomer->arrivalTime < q.back()->endTime)
                        {
                            curCustomer->startTime = q.back()->endTime;
                            curCustomer->endTime = curCustomer->startTime + curCustomer->serviceTime;
                        }
                        else if(curCustomer->arrivalTime >= q.back()->endTime)
                        {
                            curCustomer->startTime = curCustomer->arrivalTime;
                            curCustomer->endTime = curCustomer->startTime + curCustomer->serviceTime;
                        }
                        else if(curCustomer->arrivalTime <= q.back()->endTime)
                        {
                            curCustomer->startTime = q.back()->endTime;
                            curCustomer->endTime = curCustomer->startTime + curCustomer->serviceTime;
                        }

                        q.push(curCustomer);
                        qSize++;
                    }
                }
                
            }
        }

        Person * curCustomer = arr[n-1];
        
        //if anything is running - no pop
        if(curCustomer->arrivalTime < q.front()->endTime)
        {
            if(curCustomer->maxPerson >= qSize)
            {
                res.push(q.back()->endTime);

                //cout << "1Time: " <<q.back()->endTime <<endl;
            }
            else
            {
                res.push(-1);
                //cout << "2Time: " << "cant wait" <<endl;
            }
            
        }
        //if nothing is under running status - something has finished their task
        //pop completed task from front
        if(curCustomer->arrivalTime >= q.front()->endTime)
        {
            //iterate queue to pop all completed tasks
            if(curCustomer->arrivalTime >= q.front()->endTime)
            {
                q.pop();
                qSize--;
            } 
            //curcustomer can wait
            if(curCustomer->maxPerson >= qSize)
            {
                //between back
                if(curCustomer->arrivalTime >= q.back()->startTime && curCustomer->arrivalTime < q.back()->endTime)
                {
                    res.push(q.back()->endTime);
                    //cout << "3Time: " << q.back()->endTime <<endl;
                    
                }
                else if(curCustomer->arrivalTime >= q.back()->endTime)
                {
                    res.push(curCustomer->arrivalTime);
                    //cout << "4Time:" << curCustomer->arrivalTime <<endl;
                    
                }
                else if(curCustomer->arrivalTime <= q.back()->endTime)
                {
                    res.push(q.back()->endTime);
                    //cout << "6Time:" << q.back()->endTime <<endl;
                }
                
            }
            else
            {
                res.push( -1);
                //cout << "5Time: " << "cant wait" << endl;
            }
        }
    }

    while (!res.empty())
    {
        int front = res.front();
        cout << front << endl;
        res.pop();
    }

}