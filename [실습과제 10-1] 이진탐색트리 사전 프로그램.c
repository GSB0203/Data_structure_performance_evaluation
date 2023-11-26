#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
typedef struct {
	char word[100];
	char meaning[200];
}element;

typedef struct TNode{
	element key;
	struct TNode *left, *right;
}TNode;

int compare(element e1, element e2){
	return strcmp(e1.word,e2.word);  //e1<e2:-1,==:0,>1
}

//이진탐색트리 출력함수
void display(TNode* p){
	if(!p) return;
	display(p->left);//
	printf("(%s:%s)",p->key.word, p->key.meaning);
	display(p->right);//
} 
//이진탐색트리 탐색함수
TNode* search(TNode* root, element key){
	if(root == NULL) return NULL;
	if(compare(key, root->key) == 0)
		return root;
	else if(compare(key, root->key) < 0)
		return search(root->left, key);
	else return search(root->right, key);
} 

TNode* new_node(element item){
	TNode* temp = (TNode*)malloc(sizeof(TNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TNode* insert_node(TNode* root, element key){
	//트리가 공백이면 새로운 노드를 반환
	if(root == NULL) return new_node(key);
	else if(compare(key, root->key) < 0)
		root->left = insert_node(root->left, key);
	else if(compare(key, root->key) > 0)
		root->right = insert_node(root->right, key);
	return root;
	//순환적으로 트리를 내려가서 삽입 
}

TNode* minNode(TNode* node){
	TNode* cur = node;
	while(cur->left != NULL)
		cur = cur->left;
	return cur;
}

//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트노드반환 
TNode* deleteNode(TNode* root, element key){
	if(root == NULL) return root;
	if(compare(key, root->key) < 0)
		root->left = deleteNode(root->left, key);
	else if(compare(key, root->key) > 0)
		root->right = deleteNode(root->right, key);
	else if(compare(key, root->key) == 0) {
		if(root->left == NULL) {
			TNode* temp = root->right;
			free(root);
			return temp;
		}
		if(root->right == NULL) {
			TNode* temp = root->left;
			free(root);
			return temp;
		}
		TNode* temp = minNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}



int main(){
	char command;
	element e;
	TNode* root = NULL;
	TNode* tmp;
	do{
		printf("\n ****i: 입력, d: 삭제,s: 탐색,p: 출력,q:종료****:\n");
		command = getchar();
		getchar();
		switch(command){
			case 'i':
				printf("단어:\n");
				gets(e.word);//단어 한줄 e.word에 입력받음
				printf("의미:\n");
				gets(e.meaning);//의미 한줄 e.meaning에 입력받음
				root = insert_node(root, e); //구조체변수 e입력하는 함수 실행
				break; 
			case 'd':
				printf("단어:");
				gets(e.word);
				root = deleteNode(root, e);// 삭제 함수 실행
				break; 
			case 's':
				printf("단어:");
				gets(e.word);
				tmp = search(root, e);//탐색함수 실행
				if(tmp !=NULL){
					printf("의미: %s\n",tmp->key.meaning);
				}
				break;
			case 'p':
				display(root);// 출력 함수 실행
				printf("\n");
				break;
		} 
	}while(command != 'q'/*q를 입력하지 않은 경우 반복*/);

	return 0; 
}

