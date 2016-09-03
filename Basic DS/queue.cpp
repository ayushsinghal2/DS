//queue using ll
#include <iostream>
#include <cstdlib>
using namespace std;
class node
{
public: 
	int data;
	node* next;

	node()
	{
		data=-145;
		next=NULL;
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
	void insert(int obj)
	{
		if(start==NULL)
		{
			start = new node;
			end = new node;
			start->data = obj;
			end=start;
		}
		else
		{
			node* create = new node;
			create->data=obj;
			end->next=create;
			end=create;
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
			cout<<start->data<<" , ";
			while(temp->next!=NULL)
			{
				temp=temp->next;
				cout<<temp->data<<" , ";
				
			}
		}
			cout<<endl;
	}
};
int main()
{
	queue s;
	s.insert(22);
	s.insert(45);
	s.show();
	cout<<s.del()<<endl;
	s.show();
	s.insert(23);
	s.show();
}