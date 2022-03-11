#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
int main(){
	int choice;
	int n , i ;
	printf("how many employees?\n"); 
  	scanf("%d",&n);
    int arr[n][2];
	while(1)
    {
    printf("\n\t\t**********************************************");
	printf("\n\t\t*          STUDENT REGISTRATION PROGRAM      *");
	printf("\n\t\t*         Done by : ????????????????????     *");
	printf("\n\t\t**********************************************");
	printf("\n");
	printf("\n\t\t\t[1]ADD ID AND SALARIE  ");
	printf("\n\t\t\t[2]PRINT THE ID OF EMPLOYEES WHOSE salaries exceed a user specified value.  ");
	printf("\n\t\t\t[3]Giving a pay rise to a selected group of employees. ");
	printf("\n\t\t\t[4]Print out salaries of all employees");
	printf("\n\t\t\t[5]Exit The Program        ");
	printf("\n\n\t\t\tPlease Enter Your Choice : ");
    scanf("%d",&choice);

        switch(choice)
        {
        case 1 : {

        	for(i=0;i<n;i++)
        	{
        		printf("\nenter id : ");
        		scanf("%d",&arr[i][0]);
        		printf("\nenter salaries : " );
        		scanf("%d",&arr[i][1]);
			}
			printf("\nEmployees Added Successfully!");
			break;
		}
		case 2 : {
			int s;
			printf("\nenter salary : ");
			scanf("%d",&s);
			for(i=0;i<n;i++)
			{
				if(s<arr[i][1])
				{
					printf("\n employee ID %d salary %d",arr[i][0],arr[i][1]);
				}
			}
			break;
		}
		case 3 : {
			int m ,j , ss , idd;
				printf("how many employees?\n");
  				scanf("%d",&m);
  				printf("\nenter pay rise : ");
  				scanf("%d",&ss);
  				for(i=0;i<m;i++){
  					printf("\nenter ID : ");
  					scanf("%d",&idd);
  					for(j=0;j<n;j++)
  					{
  						if(arr[j][0]==idd)
  						{
  							arr[j][1]=arr[j][1]+ss;
  							printf("\n employee ID %d salary %d",arr[i][0],arr[i][1]);
						}
					}
  					
				  }
			
			break;
		}
		case 4 : {
			for(i=0;i<n;i++)
			{
				printf("\n employee ID %d salary %d",arr[i][0],arr[i][1]);
			}
			break;
		}
		
		
		
		
			
        	
        	
        	
        	
        	case 5:{
                exit(0); }  
        		default:{
        
		printf("wrong Input\n");

                printf("wrong Input\n");
       break;
    }


        }
    }
	
	
	
	
	
	
	return 0;
}
