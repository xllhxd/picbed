#include <stdio.h>
int push(int stack[],int *top,int element);//��ջ���� 
int pop(int stack[],int *top,int *element);//��ջ���� 
void ShowStack(int stack[],int length);//չʾջ��Ԫ�غ��� 
int main(){
	int stack[100];//�洢ջ��Ԫ�ص����� 
	int top=0;//ջ����������ջ��Ԫ�صĸ��� 
	int element;//��ջԪ�غͳ�ջԪ�� 
	int command;//ָ��ѡ���� 
	while(1){
		printf("��ѡ��Ҫִ�еĲ�����1.��ջ��2.��ջ��3.�Ƴ�����");
		scanf("%d",&command);
		if(command==3) return 0;
		else if(command==1){
			printf("��������ջԪ�أ�");
			printf("\n"); 
			scanf("%d",&element);
			if(push(stack,&top,element)==0){
				printf("ջ��Ԫ��Ϊ��");
				ShowStack(stack,top);
			}
			else printf("ջ����");printf("\n");//ջ�����޷���ջ 
		}
		else if(command==2){
			if(pop(stack,&top,&element)==0){
				printf("��ջԪ��Ϊ��%d",element);
				printf("\n");
				printf("ջ��Ԫ��Ϊ��");
				ShowStack(stack,top); 
			}
			else printf("ջ�գ�");printf("\n");//ջ�����޷���ջ 
		}
		else printf("����ָ�����"); printf("\n");
	}
}
int push(int stack[],int *top,int element){//stack��ʾ�洢ջ�����飬topָ��ջ����element��ʾ��ջԪ�� 
	if((*top)>=100){//ջ�����Ϊ100�������δ��ջʱջ��Ϊ100������ջ������Խ�磬�ʴ˴�Ϊ>= 
		return 1;
	}
	stack[*top]=element;//��Ԫ�ز��������ĩβ��Ҳ����ջ�� 
	(*top)++;//��ջ������ 
	return 0;
}
int pop(int stack[],int *top,int *element){
	if(*top==0) return 1;
	(*top)--;//ջ�����ƣ���ʱ��ָ��ջ���������Ԫ�أ���������ShowStack�в��õ���length-1�����Դ�ʱջ�Ĺ�ϽҪ��ջ���λԪ�صĵ�һλ 
	*element=stack[*top];//����ջ�����λԪ�� 
	return 0; 
}
void ShowStack(int stack[],int length){//���ű������� ���ջ��Ԫ�� 
	for(int i=length-1;i>=0;i--) printf("%d ",stack[i]);
}
 
