// link list
#include <iostream>
#include <cstdlib>
using namespace std;
class node
{
public: 
	int value;
	node* next;

	node()
	{
		value = -654;
		next = NULL;
	}
};
class ll
{
	node* head;	
public:
	ll()
	{
		head = NULL;

	}
	void insert(int pos , int obj)
	{
		if(pos==0)
		{
			if(head == NULL)
			{
				head = new node;
				head->value = obj;
				//cout<<head->value;
			}
			else
			{
				node* create = new node;
				create->value = obj;
				create->next = head;
				head=create;
			}
		}
	}
	void remove(int pos)
	{
		node* temp = head;
		if(pos==0)
		{
			head = temp->next;
			free(temp);
		}
		else
		{
			for (int i = 0; i < pos-1; ++i)
			{
				temp=temp->next;
			}
			if(temp->next->next==NULL)
			{
				temp->next=NULL;
			}
			else
				temp->next = temp->next->next;
			free(temp->next);
		}
	}
	int get(int pos)
	{
		node* temp = head;
		for (int i = 0; i < pos; ++i)
		{
			temp = temp->next;
		}
		return temp->value;
	}
	int find(int obj)
	{
		node * temp = head;
		int count=0;
		if(head->value==obj)
		{
			return 0;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
				count++;
				if(temp->value == obj)
					return count;
				
			}
		}
		return -11;
	}
	int size()
	{
		if(head==NULL)
			return 0;
		node* temp = head;
		int count=1;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			count++;
		}
		return count;
	}
	void clear()
	{
		node* temp = head;
		while(temp->next!=NULL)
		{
			node * del = temp;
			temp = temp->next;
			free(del);
		}
		free(temp);
		head=NULL;
	}
	void append(int obj)
	{
		if(head==NULL)
		{
			insert(0,obj);
		}
		else
		{
			node* temp = head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			node* create = new node;
			create->value=obj;
			temp->next=create;
		}
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
			cout<<head->value<<" , ";
			while(temp->next!=NULL)
			{
				temp=temp->next;
				cout<<temp->value<<" , ";
				
			}
		}
			cout<<endl;
	}
}; 
int main()
{
	ll p;
	p.append(4);
	p.append(5);
	p.clear();
	p.show();
}