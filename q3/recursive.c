#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct TreeNode{
	int name;
	struct TreeNode *right;
	struct TreeNode *left;
}TreeNode;

TreeNode* append_flatten(TreeNode *head,TreeNode *in){
	if(head==NULL||in==NULL)
		return NULL;
	else if(head->right!=NULL)
		head->right=append_flatten(head->right,in);
	else
		head->right=in;
	return head;
}

void post(TreeNode *root){
	if(root->right!=NULL){
		post(root->right);
	}
	if(root->left!=NULL){
		post(root->left);
	}
	printf("%d  ", root->name);
}

TreeNode* flatten(TreeNode *root){
	if(!root)
		return NULL;
	if(root->left==NULL&&root->right==NULL)
		return root;
	else if(root->right==NULL){
		TreeNode *LTree = flatten(root->left);
		TreeNode *new_node=(TreeNode *) malloc(sizeof(TreeNode));
		new_node=root;
		new_node->right=LTree;
		new_node->left=NULL;
		return new_node;
	}
	else if(root->left==NULL){
		TreeNode *RTree = flatten(root->right);
		TreeNode *new_node=(TreeNode *) malloc(sizeof(TreeNode));
		new_node=root;
		new_node->right=RTree;
		new_node->left=NULL;
		return new_node;
	}
	else{
		TreeNode *LTree = flatten(root->left);
		TreeNode *RTree = flatten(root->right);
		append_flatten(LTree,RTree);
		TreeNode *new_node=(TreeNode *) malloc(sizeof(TreeNode));
		new_node=root;
		new_node->right=LTree;
		new_node->left=NULL;
		return new_node;
	}
}

TreeNode* append(TreeNode *head, int input){
    if(head==NULL){
        head=(TreeNode *) malloc(sizeof(TreeNode));
        head->left=NULL;
        head->right=NULL;
        head->name=input;
        return head;
    }
    TreeNode *root = head;
    while(root!=NULL){
        if(input>root->name){
            if(root->right!=NULL){
                root=root->right;
            }
            else{
                root->right= (TreeNode *) malloc(sizeof(TreeNode));
                root=root->right;
                root->name=input;
                root->right=NULL;
                root->left=NULL;
                return head;
            }
        }
        else{
            if(root->left!=NULL){
                root=root->left;
            }
            else{
                root->left= (TreeNode *) malloc(sizeof(TreeNode));
                root=root->left;
                root->name=input;
                root->right=NULL;
                root->left=NULL;
                return head;
            }
        }
    }
    return head;
}

int main(){
	int a[6] ={4,1,2,3,5,6};
	TreeNode *tree;
	for(int i=0;i<6;i++){
		tree=append(tree,a[i]);
	}
	post(tree);
	flatten(tree);
	printf("\n");
	post(tree);
	printf("\n");
	return 0;
}