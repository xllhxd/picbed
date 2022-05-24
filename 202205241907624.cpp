#include <stdio.h>
int push(int stack[],int *top,int element);//入栈函数 
int pop(int stack[],int *top,int *element);//出栈函数 
void ShowStack(int stack[],int length);//展示栈内元素函数 
int main(){
	int stack[100];//存储栈内元素的数组 
	int top=0;//栈顶并代表着栈内元素的个数 
	int element;//入栈元素和出栈元素 
	int command;//指令选择器 
	while(1){
		printf("请选择要执行的操作：1.入栈；2.出栈；3.推出程序");
		scanf("%d",&command);
		if(command==3) return 0;
		else if(command==1){
			printf("请输入入栈元素：");
			printf("\n"); 
			scanf("%d",&element);
			if(push(stack,&top,element)==0){
				printf("栈内元素为：");
				ShowStack(stack,top);
			}
			else printf("栈满！");printf("\n");//栈满则无法入栈 
		}
		else if(command==2){
			if(pop(stack,&top,&element)==0){
				printf("出栈元素为：%d",element);
				printf("\n");
				printf("栈内元素为：");
				ShowStack(stack,top); 
			}
			else printf("栈空！");printf("\n");//栈空则无法出栈 
		}
		else printf("输入指令错误！"); printf("\n");
	}
}
int push(int stack[],int *top,int element){//stack表示存储栈的数组，top指向栈顶，element表示入栈元素 
	if((*top)>=100){//栈顶最多为100，但如果未入栈时栈顶为100，则入栈后数组越界，故此处为>= 
		return 1;
	}
	stack[*top]=element;//将元素插入数组的末尾，也就是栈顶 
	(*top)++;//将栈顶上移 
	return 0;
}
int pop(int stack[],int *top,int *element){
	if(*top==0) return 1;
	(*top)--;//栈顶下移，此时虽指向栈中最上面的元素，但由于在ShowStack中采用的是length-1，所以此时栈的管辖要在栈最高位元素的低一位 
	*element=stack[*top];//保存栈中最高位元素 
	return 0; 
}
void ShowStack(int stack[],int length){//倒着遍历数组 输出栈中元素 
	for(int i=length-1;i>=0;i--) printf("%d ",stack[i]);
}
 
