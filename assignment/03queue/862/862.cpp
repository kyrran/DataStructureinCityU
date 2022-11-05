
#include <iostream>
#include <map>
#include <array>
#include <vector>
#include <set>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node *prev;
      
        Node(int x)
        {
            val = x;
            next = NULL;
            prev = NULL;
        }
};

class Queue{
    private:
        Node *front;
        Node *end;
        int size;
    public:
        Queue()
        {
            front = NULL;
            end = NULL;
            size = 0;
        }
        void PushBack(int x);
        
        void PopFront();
        
        
        Node* getFront();
        Node* getEnd();
        void setFront(Node * node);
        void setEnd(Node * node);
        
        bool IsEmpty();
        int getSize();
        void printQueue();
        void freeQueue();
        void setSize(int x);

        //int searchNodeIndex(int x);
        //pair<Node*, Node*> searchNode(int x);
        //bool isNodeExisted(int x);
};

void Queue::PushBack(int x){

    Node * newNode = new Node(x);
    if (IsEmpty()) {
        front = newNode;
        //end = front = newnode
        end = front;
        size++;
        return;
    }

    newNode->prev = end;
    end->next = newNode;
    //newnode is new end
    end = newNode; 
    size++;
}

void Queue::setSize(int x)
{
    size = x;
}
void Queue::PopFront(){

    if (IsEmpty()) {
        //cout << "1empty" << endl;
        return;
    }

    Node *node = front;
    //new front
    front = front->next;
    if(front == NULL)
    {
       end = NULL; 
    }
    else
    {
        front->prev = NULL;
    }
    delete node;
    size--;
}

Node* Queue::getFront(){

    if (IsEmpty()) {
        //cout << "3empty" << endl;;
        return NULL;
    }

    return front;
}

void Queue::setFront(Node * node){
    front = node;
}

void Queue:: setEnd(Node * node)
{
    end = node;   
}
Node* Queue::getEnd()
{
    if (IsEmpty()) 
    {
        //cout << "2empty" << endl;
        return NULL;
    }

    return end;
}
bool Queue::IsEmpty()
{
    //both null -> true?
    return (front == NULL && end == NULL);
}
int Queue::getSize()
{
    int counter = 0;

    if (IsEmpty()) 
    {
        return 0;
    }
    Node * temp = front;
    
    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}
void Queue::printQueue()
{
    if (IsEmpty()) 
    {
        cout << endl;
        return;
    }
    Node * temp = front;
    while(temp != NULL)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << endl;
}
void Queue:: freeQueue()
{
    end = NULL;
    while(front != NULL)
    {
        Node * temp = front;
        front = front->next;
        free(temp);
    }
    size = 0;
}
Node * pivot;

bool isNodeExisted(int x, Queue* cardQueue,map<int, set<Node*> >& mapOfSet)
{
    map<int, set<Node*> >::iterator it = mapOfSet.find(x);

    if(it == mapOfSet.end())
    {
        return false;
    }
    else
    {
        set<Node*> st = it->second;
        pivot = *(st.begin());
        return true;
    }
    /* if(searchNode(x,cardQueue).second != nullptr)
    {
        return true;
    }
    return false; */
}

void insertWholeQueue(Queue* cardQueue, Queue* playerQ,map<int, set<Node*> >& mapOfSet)
{
    if(playerQ->IsEmpty())
    {
        playerQ->setFront(cardQueue->getFront());
        playerQ->setEnd(cardQueue->getEnd());

        cardQueue->setEnd(NULL);
        cardQueue->setFront(NULL);

       
        return;
    }
   

    playerQ->getEnd()->next = cardQueue->getFront();
    cardQueue->getFront()->prev = playerQ->getEnd();
    playerQ->setEnd(cardQueue->getEnd());

    cardQueue->setEnd(NULL);
    cardQueue->setFront(NULL);
    
}
void show(map<int, set<Node*> >& mapOfSet)
{
	// Using iterator to access
	// key, value pairs present
	// inside the mapOfSet
	for (map<int, set<Node*> > ::iterator it = mapOfSet.begin();
		it != mapOfSet.end();
		it++) {

		// Key is integer
		cout << it->first << " => ";

		// Value is a set of string
		set<Node*> st = it->second;

		// Strings will be printed
		// in sorted order as set
		// maintains the order
		for (set<Node*> ::iterator it = st.begin();
			it != st.end(); it++) {
			cout << (*it)->val << ' ';
		}
		cout << '\n';
	}
}
Queue* freeFromXAndAppend(Queue* cardQueue, int x, Queue*playerQ,map<int, set<Node*> >& mapOfSet)
{
    
    Node* xNode = pivot;
    Node* prev2 = pivot->prev;
   
    if(prev2 == nullptr && xNode != nullptr)
    {
        insertWholeQueue(cardQueue,playerQ,mapOfSet);
        return playerQ;
    }
    else if(prev2 == nullptr && xNode == nullptr)
    {
        return NULL;
    }
    else
    {
        if(playerQ->IsEmpty())
        {

            playerQ->setFront(xNode);
            playerQ->setEnd(cardQueue->getEnd());

            cardQueue->setEnd(prev2);
            prev2->next = NULL;
            cardQueue->setFront(cardQueue->getFront()); 


            return playerQ;
        }
        //prev is 1, xnode is 2, at index 2
        //card: 0 1 2 3 4 5 2-> 7
        //2,3,4,5 to playerQ -> x,x,x,x,x,2,3,4,5 2
        //0,1 left in cardqueue

        //cout << "size:" << curCardQ << curPlayerQ << index << endl;


        playerQ->getEnd()->next = xNode;
        xNode->prev = playerQ->getEnd();
        playerQ->setEnd(cardQueue->getEnd());

        cardQueue->setEnd(prev2);
        prev2->next = NULL;
        cardQueue->setFront(cardQueue->getFront());  
        
        return playerQ;
    }
       

    //cout << "to: ";playerQ->printQueue();
    
    //cout << "from: ";cardQueue->printQueue();

    return playerQ;
}


Queue* players[105]; //n*l=10000,every element ramges up tp 10^9

int main()
{
    map <int, set<Node*> > mapOfSet;
    int n,m,l,s,t;
    map<int,int> player_size;
    map<int,Queue*> player_card;
   
    while(scanf("%d%d%d%d%d",&n,&m,&l,&s,&t),(n != -1 || m != -1 || l != -1 || s != -1 || t != -1))
    {
        
        for (int i = 0; i < n; i++)
        {
            Queue* q = new Queue();
            for(int j = 0; j < l; j++)
            {
                int cardVal;
                scanf("%d",&cardVal);
                q->PushBack(cardVal);
            }
            players[i] = q;
        }

        int curN = n;
        Queue* cardQueue = new Queue();
        for(int r = 1; r <= t; r++)
        { 
            for(int i = 0; i < n; i++)
            {
                //clear then cardmap and update
                mapOfSet.clear();
                if(!cardQueue->IsEmpty())
                {
                    Node * temp = cardQueue->getFront();
                    while(temp != NULL)
                    {
                        mapOfSet[temp->val].insert(temp);
                        temp = temp->next;
                    }
                }
                else
                {
                    mapOfSet.clear();
                }
                
                if(players[i]->IsEmpty())
                    continue;
                Queue * playerQ= players[i];
                Node* firstCard = playerQ->getFront();
                int x = firstCard->val ;
                
                //std::cout << "player " << i << " in round " << r << " first card: "<< x << endl;
                //cout << "hi" << endl;
                //If the card displayed is numbered s
                if(x == s && !cardQueue->IsEmpty()){
                    //std::cout << "Before: card in round " << r << ": "; cardQueue->printQueue();

                    cardQueue->PushBack(x);
                    
                   

                    playerQ->PopFront();
                    
                    //Node* temp = cur->next;
                    insertWholeQueue( cardQueue, playerQ, mapOfSet);
                    //std::cout << "After:player " << i << " in round " << r << " at size " << playerQ->getSize() << " :"; playerQ->printQueue();
                    
                    //std::cout << "After:card in round " << r << ": "; cardQueue->printQueue();
                    //show(mapOfSet);
                }
                //the card displayed is numbered x
                
                else if(x != s && isNodeExisted(x,cardQueue,mapOfSet)){

                    //std::cout << "Before: card in round " << r << ": "; cardQueue->printQueue();
                    
                    cardQueue->PushBack(x);
                    

                    playerQ->PopFront();
                    
                    playerQ = freeFromXAndAppend(cardQueue,x,playerQ,mapOfSet);

                    //std::cout << "After:player " << i << " in round " << r << " at size " << playerQ->getSize() << " :"; playerQ->printQueue();
                    //std::cout << "After:card in round " << r << ": "; cardQueue->printQueue();
                    //show(mapOfSet);
                }
                else
                {
                    //std::cout << "Before: card in round " << r << ": "; cardQueue->printQueue();
                    cardQueue->PushBack(x);
                    
                    playerQ->PopFront();
                    
                    //std::cout << "After:player " << i << " in round " << r << " at size " << playerQ->getSize() << " :"; playerQ->printQueue();
                    //std::cout << "After:card in round " << r << ": "; cardQueue->printQueue();
                    //show(mapOfSet);
                }
                
                players[i] = playerQ;

                player_card[i] = players[i];

                if(playerQ->IsEmpty())
                {
                    //std::cout << "player " << i << " in round " << r << " over " << endl;
                    curN--;
                    //-r
                    //blank line
                    player_size[i] = -r;
                    
                    //cout << "-r:" << player_size[i] << endl;
                }
                else if(curN <= 1)
                {
                    //game over
                    //all others - blank
                    //this one - blank or print playerQ
                    player_size[i] = playerQ->getSize();  
                }
                else
                {   
                    player_size[i] = playerQ->getSize();
                    
                }

                //std::cout << "-------------" << endl;
            }
            
        }

        //store 
        //key : test case -> value: queue, node is card number for every player 0 -n
        //key : test case -> queue arr[n], card value
        
       
        map<int, int>::iterator it = player_size.begin();
        // Iterating over the map using Iterator till map end.
        while (it != player_size.end())
        {
            cout << it->second << " ";
            it++;
        }
        cout << endl;

        map<int, Queue*>::iterator i = player_card.begin();
        // Iterating over the map using Iterator till map end.
        while (i != player_card.end())
        {
            //cout << i -> first << ":";
            i->second->printQueue();
            i++;
        }

        player_size.clear();
        player_card.clear();

        cardQueue->freeQueue();
        for (int i = 0; i < n; i++)
            players[i]->freeQueue();

    }
}