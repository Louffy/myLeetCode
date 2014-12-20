/*
Notes:
1,new,delete,delete[]
2,const method,mutable
3,constructor, member initializer list
4,size_t
5,nulptr
6,destructor,copy constructor, copy assignment operator
*/

#include <iostream>
using namespace std;

template <class Type1,class Type2>
Type2 mymax(Type1 a,Type2 b)
{
	return a>b?a:b;
}

template <class Type>
class Mystack
{
private:
	struct Node
	{
		Type e;
		Node * next;
		//c++11: nulptr = NULL
		Node(Type x):e(x),next(NULL)
		{}
		Node():next(NULL)
		{}
	};
	Node * head;
	//size_t = unsigned int
	std::size_t count;

public:

	// member initializer list
	Mystack():head(NULL),count(0){}

	//Mystack ms;
	//Mystack ms1 = Mystack(ms) ? copy constructor
	//Mystack ms2 = ms; ? copy assignment operator
	// ? destructor
	// The rule of three : problem about variable pointer
	// Default constructor is only copy value of pointer, not contain the memory of pointer, so overload
	Mystack(const Mystack &that):head(NULL),count(0)
	{
		count=that.count;
		Node *p=that.head;
		Node *q=NULL;
		while(p)
		{
			//this is a pointer of class self
			Node *n=new Node(p->e);
			if(head==NULL)
			{
				head=n;
				q=n;
			}
			else
			{
				q->next=n;
				q=q->next;
			}
			p=p->next;
		}
	}
	/*
	Mystack & operator=(const Mystack &that)
	{
		if(this != &that)
		{
			
			count = that.count;

			// ERROR !!! delete[] head;
			// delete[] is used to delete Arrays
			// delete old stack
			Node *l=this.head;
			while(l)
			{
				Node *n=l;
				l=l->next;
				delete n;
			}
			head=NULL;

			//copy new stack
			Node *p=that.head;
			Node *q=NULL;
			while(p)
			{
				//this is a pointer of class self
				Node *n=new Node(p->e);
				if(head==NULL)
				{
					head=n;
					q=n;
				}
				else
				{
					q->next=n;
					q=q->next;
				}
				p=p->next;
			}

		}
		return *this;
	}
	*/
	// But for x = x, former does not work, it would delete the source stack, this->head and that.head is the same pointer
	// so introduce local variable and copy
	Mystack & operator=(const Mystack &that)
	{		
			
		Mystack n(that);
		this->~Mystack();

		this->head=n.head;
		this->count=n.count;
		
		
		return *this;
	}
	void push(Type e)
	{

		//Initialization of class/struct
		//C c={0}
		//C c=C();
		//C *c=new C();
		//C c; //members are random
		//C *c=new C; //members are random
		Node* n = new Node(e);
		n->next=head;
		head=n;
		count++;
	}
	void pop()
	{
		if(count==0)
			return;

		Node * n= head;
		head=head->next;
		delete n;
		count--;
	}
	Type top() const
	{
		return head->e;
	}
	std::size_t size() const
	{
		return count;
	}

	//const: const method
	//const class only can call const method, beacuse it is const instance. of course, you can implement two similar methods by const, and auto select method
	//cannot change the instance members in const method
	//const instance can change mutable variable
	void print() const
	{
		Node *p=head;
		while(p)
		{
			cout<<p->e<<" ";
			p=p->next;
		}
		cout<<endl;
	}
	bool empty() const
	{
		return count==0;
	}
	//delete ptr -> memory
	//delete ptr
	~Mystack()
	{
		while(head)
		{
			pop();
		}

		head=NULL;
		
	}
};

// min stack
class MinStack
{
public:
	MinStack()
	{
	}
	void push(int x)
	{
		stack.push(x);
		if(min_stack.empty())
		{
			min_stack.push(x);
			cout<<"dddd"<<endl;
		}
		else
		{
			if(x <= min_stack.top())
			{
				min_stack.push(x);
				cout<<"xxx"<<endl;
			}
		}
	}
	void pop()
	{
		if(stack.empty())
			return;
		int x=stack.top();
		stack.pop();
		if(x==min_stack.top())
		{
			cout<<"dddd"<<endl;
			min_stack.pop();
		}
	}
	int top()
	{
		return stack.top();
	}
	int getMin()
	{
		return min_stack.top();
	}
private:
	Mystack<int> min_stack;
	Mystack<int> stack;
};
int main()
{
	cout<<mymax(4, 5)<<endl;
	cout<<mymax(5.6,7.6)<<endl;
	cout<<mymax(5,6.7)<<endl;
	cout<<mymax(5.9,3)<<endl;
	if (5.6<5)
	{
		cout<<"yes"<<endl;
		/* code */
	}

	//Mystack<int> ms;
	//Mystack<int> ms = Mystack<int>();
	//ms.push(9)
	Mystack<int> *ms= new Mystack<int>();
	const Mystack<int> *mss=ms;
	ms->push(9);
	ms->push(0);
	ms->push(3);
	ms->print();
	mss->print();

	Mystack<int> ms1(*ms);
	ms1.print();

	Mystack<int> ms2=ms1;
	ms2.print();

	MinStack mins;
	mins.push(2147483646);
	mins.push(2147483646);
	mins.push(2147483647);
	cout<<mins.top()<<endl;
	mins.pop();
	cout<<mins.getMin()<<endl;
	mins.pop();
	cout<<mins.getMin()<<endl;
	mins.pop();
	mins.push(2147483647);
	cout<<mins.top()<<endl;
	cout<<mins.getMin()<<endl;
	return 0;
}