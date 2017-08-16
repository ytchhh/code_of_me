#include <string.h>

#include <iostream>
using namespace std;

#define P 7
#define NULL_DATA -1

struct bucket_node
{
		int data[3];
		struct bucket_node* next;
};

bucket_node* hash_table[P] = {0};
//memset(hash_table,0,sizeof(bucket_node));

int insert_new_element(int new_element)
{
		int index,i,k;
		bucket_node *s = NULL,*front = NULL,*t = NULL;
		index = new_element%P;
		t = hash_table[index];
		
		while(t != NULL)
		{
				for(i = 0; i < 3; ++i)
				{
						if(t->data[i] == NULL_DATA)
						{
								t->data[i] = new_element;
								return 0;
						}
				}
				front = t;
				t = t->next;
		}
		if(t == NULL)
		{
				s = new bucket_node;
				s->next = NULL;
				for(k = 0; k < 3; ++k)
						s->data[k] = NULL_DATA;
				s->data[0] = new_element;
				if(front != NULL)
					front->next = s;
				else
					hash_table[index] = s;
				return 0;
		}
}

int main()
{	
		int arr[] = {11,22,5,7,9,6,1,2,14};
		for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
			insert_new_element(arr[i]);
		bucket_node * temp;
		for(int i = 0; i < P; ++i)
		{
			if(hash_table[i] != NULL)
			{
				cout<<i<<":";
				temp = hash_table[i];
				while(temp != NULL)
				{
					for(int k = 0; k < 3; ++k)
						cout<<temp->data[k]<<" ";
					temp = temp->next;
				}
				cout<<endl;
			}
		}
		return 0;
}
