//priority queue using ll
#include <iostream>
#include <cstdlib>
using namespace std;
class node
{
public: 
	int data;
	int priority;
	node* next;

	node()
	{
		data=-145;
		next=NULL;
		priority=-1;
	}
};
class queue
{
	node* start;
	node* end;
public:
	queue()
	{
		start = NULL;
		end = NULL;

	}
	void insert(int obj,int p)
	{
		if(start==NULL)
		{
			start = new node;
			end = new node;
			start->data = obj;
			start->priority=p;
			end=start;
		}
		else
		{
			node* temp = start;
			node* create = new node;
			create->data=obj;
			create->priority=p;
			if(start->priority < p)
			{
				create->next = start;
				start=create;
			}
			else
			{
				while(temp->next!=NULL && temp->next->priority > p )
				{
					temp=temp->next;
				}
				if(temp->next==NULL)
				{
					temp->next=create;
					create->next=NULL;
					end=create;
				}
				else
				{
					create->next=temp->next;
					temp->next=create;
				}
			}
		}
	}
	int del()
	{
		int ele=0;
		if(start==NULL)
		{
			cout<<"EMPTY"<<endl;
		}
		else
		{
			node* temp = start;
			ele=temp->data;
			start = start->next;
			free(temp);
		}
		return ele;
	}
	void show()
	{
		if(start==NULL)
		{
			cout<<"EMPTY";
		}
		else
		{
			node* temp = start;
			cout<<" data : "<<start->data<<" priority : "<<start->priority<<" , ";
			while(temp->next!=NULL)
			{
				temp=temp->next;
				cout<<" data : "<<temp->data<<" priority : "<<temp->priority<<" , " ;
				
			}
		}
			cout<<endl;
	}
};
int main()
{
	queue s;
	s.insert(22,5);
	s.insert(45,3);
	s.show();
	s.del();
	s.show();
	s.insert(23,4);
	s.show();
}