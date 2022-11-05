/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 210534
 * Submitted at:  2022-04-15 20:16:00
 *
 * User ID:       1595
 * Username:      40137940
 * Problem ID:    862
 * Problem Name:  Card game
 */

#include <iostream>
#include <map>
#include <array>
#include <vector>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        int key;
        Node(int x)
        {
            val = x;
            next = NULL;
            key = -1;
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
        pair<Node*, Node*> searchNode(int x);
        bool isNodeExisted(int x);
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
    if(IsEmpty())
        return 0;
    return size;
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

pair<Node*, Node*> Queue:: searchNode(int x)
{
    Node * temp = front;
    Node * prev = nullptr;
    int index = 0;
    while(temp != NULL)
    {
        if(temp->val == x)
        {
            temp->key= index;
            return make_pair(prev,temp);
        }
            
        prev = temp;
        temp = temp->next;  
        
        index++;
    }
    return make_pair(nullptr,nullptr);
}
bool Queue:: isNodeExisted(int x)
{
    if(searchNode(x).second != nullptr)
    {
        return true;
    }
    return false;
}

void insertWholeQueue(Queue* cardQueue, Queue* playerQ)
{
    if(playerQ->IsEmpty())
    {
        playerQ->setSize(cardQueue->getSize());
        cardQueue->setSize(0);

        playerQ->setFront(cardQueue->getFront());
        playerQ->setEnd(cardQueue->getEnd());

        cardQueue->setEnd(NULL);
        cardQueue->setFront(NULL);
        return;
    }
    playerQ->setSize(cardQueue->getSize()+playerQ->getSize());
    cardQueue->setSize(0);

    playerQ->getEnd()->next = cardQueue->getFront();
    playerQ->setEnd(cardQueue->getEnd());

    cardQueue->setEnd(NULL);
    cardQueue->setFront(NULL);
}

Queue* freeFromXAndAppend(Queue* cardQueue, int x, Queue*playerQ)
{
    
    pair <Node*, Node*> pair = cardQueue->searchNode(x);
    

    Node* xNode = pair.second;
    Node* prev = pair.first;
   
    if(prev == nullptr && xNode != nullptr)
    {
        insertWholeQueue(cardQueue,playerQ);
        return playerQ;
    }
    else if(prev == nullptr && xNode == nullptr)
    {
        return NULL;
    }
    else
    {
        if(playerQ->IsEmpty())
        {
            int curCardQ = cardQueue->getSize();
            int curPlayerQ = playerQ->getSize();
            int index = pair.second->key;

            playerQ->setSize(curCardQ + curPlayerQ -index);
            cardQueue->setSize(index);

            playerQ->setFront(xNode);
            playerQ->setEnd(cardQueue->getEnd());

            cardQueue->setEnd(prev);
            prev->next = NULL;
            cardQueue->setFront(cardQueue->getFront());   
            return playerQ;
        }
        //prev is 1, xnode is 2, at index 2
        //card: 0 1 2 3 4 5 2-> 7
        //2,3,4,5 to playerQ -> x,x,x,x,x,2,3,4,5 2
        //0,1 left in cardqueue
        
        int curCardQ = cardQueue->getSize();
        int curPlayerQ = playerQ->getSize();
        int index = pair.second->key;

        //cout << "size:" << curCardQ << curPlayerQ << index << endl;

        playerQ->setSize(curCardQ + curPlayerQ -index);
        cardQueue->setSize(index);

        playerQ->getEnd()->next = xNode;
        playerQ->setEnd(cardQueue->getEnd());

        cardQueue->setEnd(prev);
        prev->next = NULL;
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
                    insertWholeQueue( cardQueue, playerQ);
                    //std::cout << "After:player " << i << " in round " << r << " at size " << playerQ->getSize() << " :"; playerQ->printQueue();
                    
                    //std::cout << "After:card in round " << r << ": "; cardQueue->printQueue();

                }
                //the card displayed is numbered x
                else if(x != s && cardQueue->isNodeExisted(x)){

                    //std::cout << "Before: card in round " << r << ": "; cardQueue->printQueue();
                    
                    cardQueue->PushBack(x);

                    playerQ->PopFront();
                    
                    playerQ = freeFromXAndAppend(cardQueue,x,playerQ);

                    //std::cout << "After:player " << i << " in round " << r << " at size " << playerQ->getSize() << " :"; playerQ->printQueue();
                    //std::cout << "After:card in round " << r << ": "; cardQueue->printQueue();
                }
                else
                {
                    //std::cout << "Before: card in round " << r << ": "; cardQueue->printQueue();
                    cardQueue->PushBack(x);
                    
                    playerQ->PopFront();
                    
                    //std::cout << "After:player " << i << " in round " << r << " at size " << playerQ->getSize() << " :"; playerQ->printQueue();
                    //std::cout << "After:card in round " << r << ": "; cardQueue->printQueue();
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