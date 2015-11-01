/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>

typedef struct __List{
    int data;
    struct __List *next;
}ListNode;

ListNode *reverseBetween(ListNode *head,int m,int n){
    if(head==NULL||m>=n||m<1)
	return NULL;
    else{
	ListNode *L1 = head;
	for(int i = 0;L1!=NULL;L1=L1->next){
		if(i==m&&L1->next!=NULL){
			ListNode *L2 = L1;
			for(int j = i;L2!=NULL;L2=L2->next){
				if(j==n-1&&L2->next!=NULL){
					for(int k = 0; k < (j-i+1)/2;k++){
						ListNode *temp1 = L1->next;
						ListNode *temp2 = L2->next;
						L1->next = L2->next;
						L2->next = temp1;
						temp2 = temp1->next;
						temp1->next = L1->next->next;
						L1->next->next = temp2;//swap end
						L1 = L1->next;
						if(L1->next == L2)
							return head;
						temp1 = L1;
						while(temp1->next!=L2){
							temp1 = temp1->next;
						}
						L2 = temp1;
						ListNode *temp = head;
					}
					return head;
				}
				j++;
			}
		}
		i++;
	}
    }
    return NULL;
}

int main(){
    ListNode *root = (ListNode *) malloc(sizeof(ListNode));
    root->next = NULL;
    ListNode *temp = root;
    for(int i=0;i<10;i++){
	ListNode *name = (ListNode*)malloc(sizeof(ListNode));
	name->data = i;
	name->next = NULL;
	temp->next = name;
	temp = name;
    }
    temp = root->next;
    for(int i = 0;i<10;i++){
	printf("%d\n",temp->data);
	temp = temp->next;
    }
    reverseBetween(root,2,8);
    temp = root->next;
    for(int i = 0;i<10;i++){
	printf("%d\n",temp->data);
	temp = temp->next;
    }
    return 0;
}
