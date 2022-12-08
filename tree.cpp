#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}

struct node* insert(struct node* node,int data){
	
	if(node==NULL){
		return newNode(data);
	}
	
	if(data<node->data){
		node->left=insert(node->left,data);
	}
	
	if(data>node->data){
		node->right=insert(node->right,data);
	}
	
	return node;
}

struct node* minValueNode(struct node* node){
	struct node* current=node;
	
	while(current && current->left!=NULL){
		current=current->left;
	}
	
	return current;
	
}


struct node* deleteNode(struct node* node,int data){
	if(node==NULL){
		return node;
	}
	
	if(data<node->data){
		node->left=deleteNode(node->left,data);
	}
	
	if(data>node->data){
		node->right=deleteNode(node->right,data);
	}
	
	else{
		
		if(node->left=NULL){
			struct node* temp=node->right;
			free(node);
			return temp;
		}
		
		if(node->right=NULL){
		struct node* temp=node->left;
		free(node);
		return temp;
   	}
	   
	   
	   struct node* temp=minValueNode(node->right);
	   
	   node->data=temp->data;
	   
	   node->right=deleteNode(node->right,temp->data);
	   
}


return node;	   
	   
	   	
		
		
		
}


void preorder(struct node* node){
	if(node!=NULL){
		printf("%d ",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}


void inorder(struct node* node){
	if(node!=NULL){
		inorder(node->left);
		printf("%d ",node->data);
		inorder(node->right);
	}
}

void postorder(struct node* node){
	if(node!=NULL){
		postorder(node->left);
		postorder(node->right);
		printf("%d ",node->data);
	}
}

int main(){
	
	struct node* node=NULL;
	node=insert(node,50);
	node=insert(node,40);
	node=insert(node,30);
	node=insert(node,20);
	node=insert(node,10);
	node=insert(node,5);
	
	inorder(node);
	
	node=deleteNode(node,50);
	
	inorder(node);
	
}




