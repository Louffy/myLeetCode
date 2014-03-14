#include<iostream>
using namespace std;
/*Solution for singly-linked list.*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
	public:
		ListNode *sortList(ListNode *head){
						          
		}
		ListNode* mergesort(ListNode *p,int l){
			if(l==1)return NULL;
			ListNode *h=p,*m=p,*s=p,*m1,*m2;
			for(int i=0;i<l-1;i++){
				if(i==l/2)m=h;
				h=h->next;
			}
			m1=mergesort(p,l/2);
			m2=mergesort(m->next,l-(l/2));
			s=merge(m1,m,m2,h);
			return s;
		}
		ListNode* merge(ListNode *p,ListNode *pe,ListNode *q,ListNode *qe){
			int temp;
			ListNode* l=NULL,*h=NULL;
			while(p!=pe&&q!=qe){
				if(p->val>q->val){
					l->next=q;
					q=q->next;
				}
				else{
					l->next=p;
					p=p->next;
				}
				if(h==NULL)h=l;
				l=l->next;
			}
			if(p==pe)
				while(q!=qe){
					l->next=q;
					q=q->next;
				}
			else if(q==qe)
				while(p!=pe){
					l->next=p;
					p=p->next;
				}
			return h->next;
		}
};
int main()
{
	ListNode* h,*s,*p,u(5),v(7),w(4);
	u.next=&v;
	v.next=&w;
	Solution so;
	cout<<u.next->val;
	cout<<endl;
	p=so.mergesort(&u,3);
	while(p!=NULL){
		cout<<p->val<<" ";
		p=p->next;
	}
}
