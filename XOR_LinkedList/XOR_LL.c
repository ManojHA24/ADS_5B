#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct node{
	int data;
	struct node *npx;
};
typedef struct node *NODE;

NODE XOR(NODE x,NODE y){
	return (NODE)((uintptr_t)x ^ (uintptr_t)y);
}

NODE insertFront(NODE head,int data){
	struct node* newNODE = (struct node*)malloc(sizeof(struct node));
	newNODE->data = data;
	
	newNODE->npx = XOR(head,NULL);
	if(head){
		head->npx = XOR(newNODE,XOR(head->npx,NULL));
	}
	head = newNODE;
	return head;
}
NODE delete_front(NODE head){
	NODE temp=head->npx;
	if(head==NULL){
		return NULL;
	}
	temp->npx=XOR(head,temp->npx);
	free(head);
	return temp;
}
	
NODE insertRear(NODE head,int data){
	NODE cur = head;
	NODE temp ;
	NODE prev = NULL;
	struct node* newNODE = (NODE)malloc(sizeof(struct node));
	newNODE->data = data;
	if(head==NULL){
		newNODE->npx=head;
		return newNODE;
	}
	while(cur->npx!=prev){
		temp = XOR(prev,cur->npx);
		prev=cur;
		cur=temp;
	}
	cur->npx=XOR(prev,newNODE);
	newNODE->npx=cur;
	return head;
}

NODE delete_rear(NODE head){
	NODE cur=head;
	NODE prev=NULL;
	NODE temp;
	while(cur->npx!=prev){
		temp=XOR(prev,cur->npx);
		prev=cur;
		cur=temp;
	}
	prev->npx=XOR(prev->npx,cur);
	free(cur);
	return head;
}
	
void Display(NODE head){
	NODE prev=NULL;
	NODE cur=head;
	NODE temp;
	
	while(cur!=NULL){
		printf("%d->",cur->data);
		temp = XOR(prev,cur->npx);
		prev=cur;
		cur=temp;
	}
	printf("NULL");
}
int main(void){
	
	NODE head=NULL;
	
	head=insertFront(head,1);
	head=insertFront(head,2);
	head=insertFront(head,3);
	printf("After Inserting at Front\n");
	Display(head);
	head=insertRear(head,4);
	printf("After Inserting at Rear\n");
	Display(head);
	head=delete_front(head);
    	printf("After deleting at front\n");
    	Display(head);
	head=delete_rear(head);
    	printf("After deleting at Rear\n");
	Display(head);
}
