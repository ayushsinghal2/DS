//dynamic stack using ll
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
class stack
{
	node* head;
	node* top;
public:
	stack()
	{
		head = NULL;
		top = NULL;

	}
	void push(int obj)
	{
		if(head==NULL)
		{
			head = new node;
			top = new node;
			head->data = obj;
			top=head;
		}
		else
		{
			node* create = new node;
			create->data=obj;
			top->next=create;
			top=create;
		}
	}
	int pop()
	{
		int ele=0;
		if(head==NULL)
		{
			cout<<"EMPTY"<<endl;
		}
		else if(head->next==NULL)
		{
			ele = head->data;
			head=NULL;
			top=head;
		}
		else
		{
			node* temp = head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			ele=top->data;
			top=temp;
			free(temp->next);
		}
		return ele;
	}
	void show()
	{
		if(head==NULL)
		{
			cout<<"EMPTY";
		}
		else
		{
			node* temp = head;
			cout<<head->data<<" , ";
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
	stack s;
	s.push(22);
	cout<<s.pop()<<endl;
	s.push(23);
	s.show();
}