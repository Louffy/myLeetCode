/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //先求环的长度，然后l=环长+入口长，1从环长遍历，2从开头遍历，相遇点为入口
 //数学推理
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1=head,*p2=head;
        if(head==NULL||head->next==NULL)
        	return NULL;
        p1=p1->next;
        p2=p2->next->next;
        int l1=1,l2=2;
        while(1)
        {
        	
        	if(p1==p2)
        	{
        		break;
        	}
        	if(p1->next==NULL)
        		return NULL;
        	else p1=p1->next;
        	if(p2->next==NULL)
        		return NULL;
        	else if(p2->next->next==NULL)
        		return NULL;
        	else p2=p2->next->next;
        	l1+=1;
        	l2+=2;
        }
        int m=l2-l1;
        p1=head;
        p2=head;
        while(m)
        {
        	p1=p1->next;
        	m--;
        }	
        while(1)
        {
        	if(p1==p2)
        		return p1;
        	p1=p1->next;
        	p2=p2->next;
        }
    }
};
