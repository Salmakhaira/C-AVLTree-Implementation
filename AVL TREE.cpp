#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	int height;
	Node *left, *right;
};

int max(int a, int b){
	return(a > b) ? a : b;
}

int getHeight(struct Node* node){
	if(node == NULL)
		return 0;
	return node->height;
}

int getbalanceFactor(struct Node* node){
	if(node == NULL)
		return 0;
	return getHeight(node->left) - getHeight(node->right);
}

struct Node* createNode(int num){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->num = num;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

Node *rightRotate(Node *node){
	Node *left = node->left;
	Node *leftRight = left->right;
	
	left->right = node;
	node->left = leftRight;
	
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	left->height = max(getHeight(left->left), getHeight(left->right)) + 1;
	
	return left;
}

Node *leftRotate(Node *node){
	Node *right = node->right;
	Node *rightLeft = right->left;
	
	right->left = node;
	node->right = rightLeft;
	
	node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
	right->height = max(getHeight(right->right), getHeight(right->left)) + 1;
	
	return right;
}

Node* insertNode(struct Node* node, int num){
	if(node == NULL)
		return createNode(num);
		
	if(num < node->num)
		node->left = insertNode(node->left,num);
	else if(num > node->num)
		node->right = insertNode(node->right,num);
	else
		return node;
	
	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	int balanceFactor = getbalanceFactor(node);	
	
	if(balanceFactor > 1 && num < node->left->num)
		return rightRotate(node);
	if(balanceFactor < -1 && num > node->right->num)
		return leftRotate(node);
	if(balanceFactor > 1 && num > node->left->num){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(balanceFactor < -1 && num < node->right->num){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;	
}

Node* findminValue(struct Node* node){
	struct Node* curr = node;
	while(curr->left != NULL)
		curr = curr->left;
	return curr;
}

Node* deleteNode(struct Node* node, int num){
	if(node == NULL){
		printf("Data not found\n");
		return node;
	}
		
		
	if(num < node->num)
		node->left = deleteNode(node->left,num);
	else if(num > node->num)
		node->right = deleteNode(node->right,num);
	else{
		if((node->left == NULL) || (node->right == NULL)){
			struct Node* temp = node->left ? node->left : node->right;
	
			if(temp == NULL){
				temp = node;
				node = NULL;
			}else
				*node = *temp;
				
			free(temp);	
			printf("Data found\n");
			printf("Value %d was deleted\n", num);
		}else{
			struct Node* temp = findminValue(node->right);
			node->num = temp->num;
			node->right = deleteNode(node->right,temp->num);
		}
	}
	if(node == NULL)
		return node;
	
	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	int balanceFactor = getbalanceFactor(node);	
	
	if(balanceFactor > 1 && getbalanceFactor(node->left) >= 0)
		return rightRotate(node);
	if(balanceFactor > 1 && getbalanceFactor(node->left) < 0){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(balanceFactor < -1 && getbalanceFactor(node->right) <= 0)
		return leftRotate(node);
	
	if(balanceFactor < -1 && getbalanceFactor(node->right) > 0){

		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;	
}

void preOrder(struct Node* node){
	if(node != NULL){
		printf("%d ", node->num);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void inOrder(struct Node* node){
	if(node != NULL){
		inOrder(node->left);
		printf("%d ", node->num);
		inOrder(node->right);
	}
}

void postOrder(struct Node* node){
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		printf("%d ", node->num);
	}
}

int main(){
	struct Node* node = NULL;
	int opt, num;
	
	while(1){
		printf("1. Insertion\n");
		printf("2. Deletion\n");
		printf("3. Traversal\n");
		printf("4. Exit\n");
		printf("Choose: ");
		scanf("%d", &opt);
		
		switch(opt){
			case 1:
				printf("Insert: ");
				scanf("%d", &num);
				node = insertNode(node,num);
				break;
			case 2:
				printf("Delete: ");
				scanf("%d", &num);
				node = deleteNode(node,num);
				break;
			case 3:
				printf("Preorder: ");
				preOrder(node);
				printf("\n");
				printf("Inorder: ");
				inOrder(node);
				printf("\n");
				printf("Postorder: ");
				postOrder(node);
				printf("\n");
				break;
			case 4:
				printf("Thank you\n");
				exit(0);
			default:
				printf("Invalid choice!\n");
		}
	}
	
	return 0;
}
