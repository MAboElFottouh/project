#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>


struct Node {
	int id ;
		char name[30];
			float score;
				Node *next;
};

void addGame(Node *&head){
	head = NULL;
}

void addPlayer(Node *&head ){
	int x ;
		float z;
			char y[30];
				printf("\nEnter player ID :  ");
					scanf("%d",&x);
						printf("\nEnter player name :  ");
							scanf("%s",&y);
								printf("\nEnter player score :  ");
									scanf("%f",&z);
	Node *temp = new Node();
		temp->id = x;
			strcpy(temp->name,y);
				temp->score = z ;
					temp->next = NULL;

	if(head == NULL){
		head = temp ;
		return;
	}

	Node *p = head;
	while(p->next != NULL){
		p=p->next;
	}
	p->next=temp;

}

void scoreE(Node *&head ){
	int n;
		float m;
      		printf("3.Enter Player ID\n");
      			scanf("%d",&n);
      				printf("3.Enter Player score\n");
      					scanf("%f",&m);
	if(head == NULL){
		printf("Empty List");
		return;
	}

	Node *p = head;
	while(p != NULL){
		if(p->id == n){
			p->score = m;
			return;
		}
		p=p->next;
	}

	printf("ID is Not Found");
}

void mix(Node *head){
		float max;
			char nameMax[30];

		if(head== NULL){
		printf("mix score = 0\n");
		return;
	}


	Node *p = head ;
		max = p->score;
			strcpy(nameMax,p->name);

	while(p !=NULL)
	{
		if(p->score >max)
		{
			max=p->score;
			strcpy(nameMax,p->name);
		}
		p=p->next;
	}
		printf("the max score = %f \n",max);
		printf("player name : %s ",nameMax);

}

void del(Node *&head){

	int x ;
		printf("Enter player ID want Remove");
			scanf("%d",&x);

	if(head == NULL){
		printf("Empty List");
		return;
	}

	Node *p = head, *q;

	while(p != NULL && p->id != x){
		q=p;
		p=p->next;
	}

	if(p == head){
		head = p->next;
		delete(p);
	}
			else if(p == NULL){
				printf("ID is not found");
				return;
			}
					else {
						q->next=p->next;
						delete(p);
					}
}

void swap(Node *&x, Node *&y){
	int a ;
		char b[30];
			float c ;

	a = x->id;
		strcpy(b,x->name);
			c = x->score;

	x->id  = y->id;
		strcpy(x->name, y->name );
			x->score = y->score;

	y->id = a;
		y->score=c;
			strcpy(y->name,b);


}

void sortList(Node *&head){
	if(head==NULL){
		return;
	}

	int swapped = 0;

	Node *p,*q, *z = NULL;
	do {
				swapped = 0;
				p = head;
			while(p->next!=z){
					q = p->next;
					if(p->score > q->score){
							swap(p,q);
							swapped = 1;
						}
				p = p->next;
				}
			z = p;
	} while(swapped);
}

void display(Node *head){
	if(head == NULL){
		printf("Empty Linked List");
		return;
	}

	sortList(head);


	Node *p = head;
	while(p != NULL){
		printf("player ID : %d \n",p->id);
			printf("player name : %s \n",p->name);
				printf("player score : %f \n",p->score);
					printf("************************\n");
		p=p->next;
	}
}

void avg(Node *head){

	if(head == NULL){
		return ;
	}
	Node *p = head ;
		float counter = 0 ;
			float sum = 0 ;
				float avvg;
while(p != NULL){
		counter++;
			sum = sum + p->score;
				p=p->next;
}
	avvg = sum / counter;
		printf ("average score = %f ", avvg);
}

int main(){
	int choice;
		Node * game ;
			system("COLOR 0A");
do
{

 	printf("\n\t\t**********************************************");
 		printf("\n\t\t*                  video game    	     *");
 			printf("\n\t\t*         Done by : ABO ELFOTOUH             *");
 				printf("\n\t\t**********************************************");
 					printf("\n");
 						printf("\n\t\t\t1.Start a New Game");
 							printf("\n\t\t\t2.Add a New Player");
 						printf("\n\t\t\t3.Update Player’s score");
 					printf("\n\t\t\t4.the top player score");
 				printf("\n\t\t\t5.Remove a Player");
 			printf("\n\t\t\t6.Print all players");
 		printf("\n\t\t\t7.Calculate average score");
 	printf("\n\t\t\t8.Exit the game");
 printf("\n\t\t\tEnter your choice :->  ");
 scanf("%d",&choice);

 switch (choice)
 {
     case 1 :{

	 addGame(game);
		 system("cls")   ;
	 		system("COLOR 0A");
         		 break;
	}

     case 2 :{
	 	addPlayer(game);
     		system("cls")   ;
     			system("COLOR 0A");
        		  break;
	}

     case 3 : {
     	 scoreE(game);
      		 system("cls")   ;
       			system("COLOR 0E");
         			break;
	}

	 case 4 : {
			mix(game);
					system("COLOR 0D");
						break;
	}

     case 5 : {
     	del(game);
     		system("cls")   ;
     			system("COLOR 0C");
					break;
	}

	 case 6 : {
	 	display(game);
	 		system("COLOR 0B");
				break;
	}
	 case 7 :{
	 		avg(game);
				break;
	 }
	 default:
	 	system("cls")   ;
	 		printf("Wrong Choice. Enter again\n");
                break;
 	}

} while (choice != 8);

	return 0;
}
