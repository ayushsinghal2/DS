//simple binary search tree creation with traversals
#include <iostream>
#include <cstdlib>
using namespace std;
class bt
{
public:
	bt* parent;
	bt* left;
	bt* right;
	int data;
	bt()
	{
		parent=left=right=NULL;
		data = 1025;
	}
};
class tree
{
	bt* head;
public:
	tree()
	{
		head=NULL;
	}
	void insert(int a)
	{
		bt* temp = head;
		bt* create = new bt;
		create->data = a;
		if(head==NULL)	
		{
			head=create;
		}
		else
		{
			while(!haschild(temp))
			{
				cout<<"haschild loop"<<endl;
				if(temp->data>a)
				{
					if(temp->left==NULL)
					{
						temp->left=create;
						create->parent=temp;
						break;
					}	
					temp=temp->left;
				}
				else
				{
					if (temp->right==NULL)
					{
						temp->right=create; 
						create->parent=temp;
						break;	
					}
					temp = temp->right; 
				}
			}
			
		}
	}
	int haschild(bt* ptr)
	{
		if(ptr->left!=NULL || ptr->right!=NULL)
			return 1;
		else
			return 0;
	}
	void show(bt* temp)
	{//preorder showing
			cout<<temp->data<<" , " ;
			if(temp->left!=NULL)
			show(temp->left);
			if(temp->right!=NULL)
			show(temp->right);
		    cout<<endl;
	}
	bt* rethead()
	{
		return head;
	}
};
int main()
{
	int a;
	tree t;
	//t.insert(1);
	t.insert(2);
	t.insert(5);
	t.show(t.rethead());
}