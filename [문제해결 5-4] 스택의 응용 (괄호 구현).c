#include<stdio.h>
#include<stdbool.h>
typedef char element;
#define MAX_SIZE 200
typedef struct {
	element data[MAX_SIZE];
	int top;
}Stack;

void init(Stack *s) {
	s->top = -1;
}

bool isEmpty(Stack *s) {
	return s->top == -1;
}

bool isFull(Stack *s) {
	return s->top == MAX_SIZE - 1;
}

void push(Stack *s, element data) {
	if(isFull(s)) return;
	else s->data[++s->top] = data;
}

element pop(Stack *s) {
	if(isEmpty(s)) return 0;
	return s->data[s->top--];
}

bool test(element expr[]) {
	element ch;
	Stack s;
	init(&s);
	for(int i = 0; expr[i] != '\0'; i++) {
		switch(expr[i]) {
			case '(':
			case '{':
			case '[':
				push(&s, expr[i]);
				break;
				
			case ')':
			case '}':
			case ']':
				if(isEmpty(&s)) return 0;
				ch = pop(&s);
				if(ch == '(' && expr[i] != ')' || ch != '{' && expr[i] == '}' || ch != '[' && expr[i] == ']') return 0;
				break;
				
			default:
				continue;
		}
	}
	if (!isEmpty(&s)) return 0;
	return 1;
}


int main() {
	char expr[20]; 
	scanf("%s", expr);
	if(test(expr)) printf("괄호포함 수식 입력 : 성공");
	else printf("괄호포함 수식 입력 : 실패");
	
	return 0;
}