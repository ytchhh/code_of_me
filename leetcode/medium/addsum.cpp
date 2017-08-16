#include <iostream>
using namespace std;

struct ListNode 
{
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
};

ListNode* initList(int arr[],int n)
{
		ListNode *head = NULL,*cur = NULL;
		for(int i = 0; i < n; ++i)
		{
				ListNode* nodes = new ListNode(arr[i]);
				if(head == NULL)
						head = nodes;
				if(cur != NULL)
						cur->next = nodes;
				cur = nodes;
		}
		return head;
}

ListNode* addSum(int num1,int num2,int &sign)
{
	int num = num1 + num2 + sign;
	if(num >= 10)
	{
		num -= 10;
		sign = 1;
	}
	else
	{
		sign = 0;
	}
	ListNode *nodes = new ListNode(num);
	return nodes;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
		if(l1 == NULL || l2 == NULL)
				return NULL;
		ListNode* list1 = l1,*list2 = l2;
		ListNode* head = NULL,*cur = NULL,*last = NULL;
		int sign = 0,num;
		while(list1 != NULL && list2 != NULL)
		{
				ListNode* nodes = addSum(list1->val,list2->val,sign);
				if(head == NULL)
						head = nodes;
				if(cur != NULL)
						cur->next = nodes;
				cur = nodes;
				list1 = list1->next;
				list2 = list2->next;
		}
		while(list1 != NULL)
		{
				ListNode* nodes = addSum(list1->val,0,sign);
				if(cur != NULL)
						cur->next = nodes;
				cur = nodes;
				list1 = list1->next;
		}
		while(list2 != NULL)
		{
				ListNode* nodes = addSum(0,list2->val,sign);
				if(cur != NULL)
						cur->next = nodes;
				cur = nodes;
				list2 = list2->next;
		}
		if(sign)
		{
				ListNode* nodes = new ListNode(sign);
				cur->next= nodes;
		}
		return head;
}


ListNode* addTwoNumbers1(ListNode *l1,ListNode *l2)
{
	ListNode *list1 = l1;
	ListNode *list2 = l2;
	ListNode *head = new ListNode(0);
	ListNode *d = head;
	int sum = 0;
	while(list1 != NULL || list2 != NULL)
	{
		sum /= 10;
		if(list1 != NULL)
		{
			sum += list1->val;
			list1 = list1->next;
		}
		if(list2 != NULL)
		{
			sum += list2->val;
			list2 = list2->next;
		}
		d->next = new ListNode(sum % 10);
		d = d->next;
	}
	if(sum / 10 == 1)
		d->next = new ListNode(1);
	return head->next;
}

int main()
{
		int arr1[] = {2,4,3};
		int arr2[] = {5,6,4};
		ListNode *l1 = initList(arr1,sizeof(arr1)/sizeof(arr1[0]));
		ListNode *l2 = initList(arr2,sizeof(arr2)/sizeof(arr2[0]));
		ListNode *l3 = addTwoNumbers1(l1,l2);
		return 0;
}
