#include <iostream>
#include <stack>
#include <cmath>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

class Point
{
    public:
        long x;
        long y;
        
        Point()
        {
            x = -10;
            y = -10;
            angle = 0.00;
        }

        long getx(){
            return x;
        }

        long gety(){
            return y;
        }

    
};
int checkPos(Point* o, Point* a, Point *b);
long disSquare (Point* a, Point* b);
int compareFunc(Point*a, Point *b);

Point * nextTop(stack<Point*> s)
{
    Point * temp = s.top();
    s.pop();
    Point * second = s.top();
    s.push(temp);
    return second;
}
Point* origin;
bool compareFunc2(Point *a, Point *b)
{
    if(atan2(a->y - origin->y, a->x - origin->x) != atan2(b->y - origin->y, b->x - origin->x))
        return (atan2(a->y - origin->y,a->x - origin->x) < atan2(b->y - origin->y, b->x - origin->x));
    //return disSquare(origin,a) < disSquare(origin,b);
    return a->x < b->x;
}

/* bool compareFunc1(Point *a, Point *b)
{
    if(a->y == b->y)
        return a->x < b->x;
    else
        return a->y < b->y;
}
 */
bool compareFunc3(Point *a, Point *b)
{
    if(a->x == b->x)
        return a->y < b->y;
    else
        return a->x < b->x;
}

int main()
{
    //how many test cases
    int tCases,nPoints;
    scanf("%d",&tCases);

    for ( int t = 0 ; t < tCases; t++)
    {
        scanf("%d",&nPoints);
       
        //create an array of points to store input
        Point* *pArr = new Point* [nPoints];

        int i = 0;
        //how many points = how many '\n' it reads
        while(i < nPoints)
        {   
            Point* p = new Point();
            long x,y;
            scanf("%ld%ld",&x,&y);
            p->x = x;
            p->y = y;
            pArr[i] = p;
            //cout << pArr[i] <<endl;
            i++;
        }
    
        //iterate array to find the left-most point
        long minY= pArr[0]->gety();
        int pos = 0;

        sort(pArr, pArr+nPoints, compareFunc3);  
        origin = pArr[0];

        //cout << origin << endl;
        sort(pArr+1, pArr+nPoints, compareFunc2);  
        //cout << "............." <<endl;
        /* for(int x = 0; x < nPoints; x++)
        {
            cout << pArr[x]->x <<" "<< pArr[x]->y << endl;
        }  */
        //-------------------------finished sorting------------------------//
 
        int size = 1;
        for(int y = 1; y < nPoints; y++)
        {
            while(y < nPoints - 1 && checkPos(origin, pArr[y], pArr[y+1]) == 0)
            {
                y++;
            }
            pArr[size] = pArr[y];
            size++;
        }
      /*    cout << "............." << size<<endl;
        for(int x = 0; x < size; x++)
        {
            cout << pArr[x]->x <<" "<< pArr[x]->y << endl;
        }
         */
        //cout << size << endl;
        if(size < 3)
        {
            cout << "impossibile" << endl;
        }

        /* cout << "............." <<endl;
        for(int x = 0; x < size; x++)
        {
            cout << pArr[x]->x <<" "<< pArr[x]->y << endl;
        }  */
         
        
        stack <Point*> s;
        s.push(pArr[0]);
        s.push(pArr[1]);
        //s.push(pArr[2]);

        for(int x = 2; x < size; x++)
        {
            //Point* second = nextTop(s);
            while(s.size() >1  && checkPos(nextTop(s), s.top(), pArr[x]) != 1)
            {
                s.pop();
            }
            s.push(pArr[x]);
        } 

        //cout << "........" << endl;
        int res = s.size();
        cout << res << endl;
        
        int d = 0;
        while(!s.empty())
        {
            Point* p = s.top();
            pArr[d] = p;
            /* cout << p->getx() << " ";
            cout << p->gety() << endl; */
            s.pop();
            d++;
        }

        sort(pArr,pArr+res,compareFunc3);
        origin = pArr[0];
        sort(pArr+1,pArr+res,compareFunc2);
        for(int x = 0; x < res; x++)
        {
            cout << pArr[x]->x <<" "<< pArr[x]->y << endl;
        }  
        delete[] pArr;
    }
    return 0;
}


//distance^2 between two points
long disSquare (Point* a, Point* b)
{
    long x1 = a->getx();
    long y1 = a->gety();

    long x2 = b->getx();
    long y2 = b->gety();

    long result = pow((x2-x1),2) + pow((y2-y1),2);

    return result;
}
int checkPos(Point* o, Point* a, Point *b)
{
    // >0 b is above a; <0 b is below a; =0 colinear
    double val = (a->getx() - o->getx())*(b->gety() - o->gety()) -
              (a->gety()-o->gety())*(b->getx()-o->getx());

    if (val > 0.0)
        return 1;
    else if (val < 0.0)
        return -1;
    else
        return 0;

    //return val;
    // > 0 means oa->0b is counterclockwise o->a->b
    //    b
    //          a
    //  o
}

/* int compareFunc(Point *a, Point *b) 
{
    int dir = checkPos(origin, a, b);

    if(dir == 0)
    {
        return disSquare(origin,a) < disSquare(origin,b);
    }
    return (dir == 1);
    
} */

/*
1
8
1 0
0 1
0 -1
-1 0
2 0
0 2
0 -2
-2 0

1
5
1 1
1 -1
0 0
-1 -1 
-1 1


1
10
903128659 737752480
247204474 524447636
397250207 768655297
345958597 544777379
717390723 703567504
98540955 639806170
310949594 897075435
553076168 785114336
842858132 7486323
54152514 510865358

*/