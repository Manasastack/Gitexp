#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE 100
typedef struct TreeNode{
	int data;
	struct TreeNode*left;
	struct TreeNode*right;
}TreeNode;
TreeNode*createNode(int val){
	TreeNode*newNode=(TreeNode*)malloc(sizeof(TreeNode));
	newNode->data=val;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
TreeNode*createTree(){
	int n,val;
	printf("enter the number of nodes to insert:");
	scanf("%d",&n);
	if(n<=0){
		printf("invalid noe count!\n");
		return NULL;
	}
	printf("enter value of node1(root):");
	scanf("%d",&val);
	TreeNode*root=createNode(val);
	TreeNode*queue[MAX_QUEUE];
	int front=0,rear=0;
	queue[rear++]=root;
	int count=1;
	while(front<rear&&count<n){
		TreeNode*curr=queue[front++];
		if(count<n){
			printf("enter left child of %d:",curr->data);
			scanf("%d",&val);
			curr->left=createNode(val);
			queue[rear++]=curr->left;
			count++;
		}
		if(count<n){
		    printf("enter right child of %d:",curr->data);
			scanf("%d",&val);
			curr->right=createNode(val);
			queue[rear++]=curr->right;
			count++;
		}
	}
	printf("\nBinary tree created successfully with %d nodes.\n",n);
	return root;
}
void preorder(TreeNode*root){
	if(root!=NULL){
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(TreeNode*root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
    }
}
void postorder(TreeNode*root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
}
}
void freeTree(TreeNode*root){
	if(root!=NULL){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}
int main()
{
	TreeNode*root=NULL;
	int choice;
		printf("\n---BINARY TREE MENU---\n");
		printf("1.create biinary tree\n");
		printf("2.Display preorder traversal\n");
		printf("3.Display inorder traversal\n");
		printf("4,Display postorder traversal\n");
		printf("5.exit\n");
		while(1){
		printf("enter your choice(1-5):");
		if(scanf("%d",&choice)!=1){
			printf("invalid input!exiting program\n");
			break;
		}
		switch(choice){
			case 1:
				if(root!=NULL){
					freeTree(root);
					root=NULL;
				}
				root=createTree();
				break;
			case 2:
				if(root==NULL){
					printf("\nTRee is empty:please create a tree first.\n");
				}else{
					printf("\n PReorder traversal:");
					preorder(root);
					printf("\n");
				}
				break;
			case 3:
				if(root==NULL){
					printf("\n TRee is empty:plesae create a tree first\n");
				}else{
					printf("\nINorder traversal\n");
					inorder(root);
					printf("\n");
				}
				break;
			case 4:
				if(root==NULL){
					printf("\nTree is empty:please create a tree first\n");
				}else{
					printf("\nPOstorder traversal:");
					postorder(root);
					printf("\n");
				}
				break;
			case 5:
				if(root!=NULL){
					freeTree(root);
				}
				printf("Exiting the program.goodbye!\n");
				return 0;
			default:
				printf("Invalid choice");
		}
    }
	if(root!=NULL)
	{
		freeTree(root);
	}
	return 0;
}
