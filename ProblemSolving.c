#include<stdio.h>
#include<string.h>
#include<time.h> // user to know the time now
#include<limits.h>//use long long
#include<stdlib.h>
#include<conio.h> // use color and getch
typedef struct name
		{
    	char first_name[20];
    		char medil_name[20];
    			char last_name[20];
    				char year_age1[20] ;
    					char month_age1[20];
    						char day_age1[20];
    							char year_r[20];
    								char term_r[20];
    									char number[20];
    										char nationality[20];
   	    										char gender[20];
  	    											long long registration;
                  int year_age ;
    					int month_age;
    						int day_age;
	}name[100];
typedef struct iid
	{
		char type_of_identity[20];
			char ID[20];
				char year_id[20];
					char month_id[20];
						char day_id[20];
							char department[20];
	}iid[100];
typedef struct subjects
	{
		char subjects[6][20];
			char Dr[6][20];
				char code[6][20];
	}subjects[100];
typedef struct addres
	{

		int flat_number;
			int house_number;
				char street_name[20];
					char area_name[20];
						char city_name[20];
							char governorate_name[20];
								char country[20];
									int posta_number;
	}addres[100];
typedef struct addres1
	{

		int flat_number1;
			int house_number1;
				char street_name1[20];
					char area_name1[20];
						char city_name1[20];
							char governorate_name1[20];
								char country1[20];
									int posta_number1;
	}addres1[100];
typedef struct Payments
{
		char type_funding[20];
			int payments_done;
				int paid_far;
					int degree;
						int total;
							char bank_name[20];
								char transaction_num[30];
									int day_t;
										int month_t;
											int year_t;
}Payments[100];
typedef struct Student_contact
{
		char e_mail[20];
			char home_number[20];
				char mobule_number[11];
}Student_contact[100];
typedef struct Credit_hours
{
	 	float maximum;
	 		float finished;
	 			float current;
	 				float remaining;

}Credit_hours[100];
//function Make sure the registration number is correct
int Registration(char year1[20] , char term1[20] , char regNum1[20])
{
	int year , term , regNum;
	int  num1 , num2 , num3 , num4,i,p,c,arr[100],d=0,arrt,arrg[100];
	long long registration;
	p=1;
for(i=0;i<p;i++)
   {
c=strlen(year1);
      if(c==4)
 			{
 				for(i=0;i<4;i++)
 				{
 					arr[i]=year1[i]-'0';
 					if(arr[i]>9||arr[i]<0)
 					{
 						d++;
					}
				}

				if(d!=0)
				{
				puts("There is an error in year\n");
            	printf("enter year : ");
            	scanf("%s",year1);

             	p++;
				}
				else
				{
					year = atoi(year1);
					        if(year <=2019 && year >= 2000)
             					{
              					num1 = year / 1000 ;
              					year = year - (num1 * 1000);
              					num2 = year / 100 ;
              					year = year - (num2 * 100);
                				num3 = year / 10 ;
              					year = year - (num3 * 10);
              					num4 = year ;
             					}
        					else
          	 					{

								puts("There is an error in year\n");
            					printf("enter year : ");
            					scanf("%s",year1);

             					p++;
            					}
				}
			}
        else
          	 {

				puts("There is an error in year\n");
            	printf("enter year : ");
            	scanf("%s",year1);

             	p++;
            }
   }

    p=1;
    d=0;
for(i=0;i<p;i++)
{
					term=atoi(term1);
					    	 if(term == 1)
          						{
           						term = 10 ;

           						}
            					else if (term == 2)
           		 				{
             					term = 20;

				   				}
				   				else
									{

    	            				printf("\nThere is an error in the number of term ");
              						printf("\nenter number of term : ");
              						scanf("%s",term1);
              						p++;
									}



}

p=1;
d=0;
for(i=0;i<p;i++)
{
	c=strlen(regNum1);
		if(c==4)
			{
			for(i=0;i<4;i++)
			{
				arrg[i]=regNum1[i]-'0';
				if(arrg[i]>9||arrg[i]<0)
					{
						d++;
					}
			}
			if(d==0)
			{
				regNum=atoi(regNum1);
			}
			else
			{
		         puts("There is an error in student number\n");
                 printf("\nenter student number : ");
                 scanf("%s",regNum1);
                 p++;
			}

		}
	else
		{
		         puts("There is an error in student number\n");
                 printf("\nenter student number : ");
                 scanf("%s",regNum1);
                 p++;
		}
}

if(num3==0)
   		{

   			registration = (arr[3] * 1000000)+(term*10000)+regNum;
  		 }
		else
   			{

    		registration = (arr[2]*10000000)+(arr[3] * 1000000)+(term*10000)+regNum;
   			}



	return registration;

}
//function The remaining amount is calculated
int Paid_far(int payments_done,int degree)
{
	int i, p=1,total ,paid_far;

	if(degree>=90)
	  {
	  	total=3700;
	  }
	else if (degree < 90 && degree >=80)
	  {
	  	total = 4780 ;
	  }
	  else
	  {
	  	total = 5140 ;
	  }


	  paid_far=total-payments_done;

	return paid_far;
}
int AgeMonth(int month , int m )
{
	month=m-month;
	return month;
}
int AgeYear(int year , int y)
{
	year=y-year;
	return year;
}
int remaining(float max , float f , float c )
{
	float rem;
	rem = (max-f-c);
	return rem;
}

int main()
{
    FILE *mahmoud;
    

    int Choice;
    int maney,i,j;
    int List,year,term,p,d;
    int gpa[100],sum,Subject;
    float avg,per;
    char choice[20];

    while(1)
    {
    system("COLOR 0A")   ;
    printf("\n\t\t**********************************************");
	printf("\n\t\t*          STUDENT REGISTRATION PROGRAM      *");
	printf("\n\t\t*         Done by : MAHMOUD ABO ELFOTOUH     *");
	printf("\n\t\t**********************************************");
	printf("\n");
	printf("\n\t\t\t[1]Add New Student Record  ");
	printf("\n\t\t\t[2]add old Student Record   ");
	printf("\n\t\t\t[3]edit Student Record   ");
	printf("\n\t\t\t[4]Gpa from one term  ");
	printf("\n\t\t\t[5]Gpa Calculator    ");
	printf("\n\t\t\t[6]View information       ");
	printf("\n\t\t\t[7]Exit The Program        ");
	printf("\n\n\t\t\tPlease Enter Your Choice : ");
    scanf("%s",choice);
    Choice = atol(choice);

        switch(Choice)
        {
            case 1:{
            	mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
	printf("enter how maney stedent \n");
	scanf("%d",&maney);
for(i=0;i<maney;i++)
{

	int List,year,term,p,d;
    char IDD[20];
    struct name type[i];
    	struct iid mid[i];
    		struct addres madd[i];
    			struct addres1 madd1[i];
    				struct subjects sub[i];
    					struct Payments pay[i];
    						struct Student_contact con[i];
    							struct Credit_hours cre[i];
//name
      {


     	printf("enter First name : ");
     		scanf("%s",type[i].first_name);
     			printf("\nenter midel name : ");
     				scanf("%s",type[i].medil_name);
     					printf("\nenter last name : ");
     						scanf("%s",type[i].last_name);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
    fprintf(mahmoud,"\n_____________________________________________");
    fprintf(mahmoud,"\n_____________________________________________");
fprintf(mahmoud,"\nfirst name %s",type[i].first_name);
fprintf(mahmoud,"\nmedil name %s",type[i].medil_name);
fprintf(mahmoud,"\nlast name %s",type[i].last_name);
fclose(mahmoud);
 }
printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0B")   ;

// registration number
   {

		printf("\nenter Year of registration : ");
        	scanf("%s",type[i].year_r);
        		printf("\nterm 1 or 2 : ");
       				 scanf("%s",type[i].term_r);
        				printf("\nThe student number consists of 4 numbers : ");
        					scanf("%s",type[i].number);
        						type[i].registration=Registration(type[i].year_r,type[i].term_r,type[i].number);
        							printf("\n%llu",type[i].registration);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nregistration number %llu",type[i].registration);

fclose(mahmoud);

printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0C")   ;
   }
//nationality
	{

     	printf("\nenter your nationality : ");
        	scanf("%s",type[i].nationality);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nnationality  %s",type[i].nationality);

fclose(mahmoud);
    }
//ID
    {
int y, arr2[100];
        printf("\nEnter the type of identity : (Passport / Identity card) :  ");
        scanf("%s",&mid[i].type_of_identity);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\ntype_of_identity  %s",mid[i].type_of_identity);

fclose(mahmoud);
p=1;
       for(j=0;j<p;j++)
	   {
            printf("\nenter your ID number : ");
            scanf("%s",mid[i].ID);
            y=strlen(mid[i].ID);
            if(y==14)
            {
            	for(j=0;j<14;j++)
            	{
            		arr2[j]=mid[i].ID[j]-'0';
            		if(arr2[j]>9||arr2[j]<0)
            		{
            			d++;
					}
				}
				if(d!=0)
				{
				              printf("\nwrong enter ID number : ");
              					p++;
				}
			}
              else
             {
              printf("\nwrong enter ID number : ");
              p++;
             }

       }

mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nID number  %s",mid[i].ID);

fclose(mahmoud);

       int YY,DD,MM;
       p=1;
       printf("Enter the expiration date of the ID (DD/MM/YYYY): ");

       printf("\nEnter the expiration date year YYYY: ");
       scanf("%s",mid[i].year_id);
       printf("\nEnter the expiration date of the ID MM: ");
       scanf("%s",mid[i].month_id);
       printf("\nEnter the expiration date of the ID DD: ");
	   scanf("%s",mid[i].day_id);
	   for(j=0;j<p;j++)
       {

DD = atol(mid[i].day_id);
MM = atol(mid[i].month_id);
YY = atol(mid[i].year_id);

       	if(DD > 31 || DD < 1 || MM >12 || MM < 1 || YY>2050 || YY < 2019)
       	   {
       		printf("\nwrong enter expiration date of the ID : ");
       printf("\nEnter the expiration date year YYYY): ");
       scanf("%s",mid[i].year_id);
       printf("\nEnter the expiration date of the ID MM: ");
       scanf("%s",mid[i].month_id);
       printf("\nEnter the expiration date of the ID DD: ");
	   scanf("%s",mid[i].day_id);
       		p++;
		   }
	   }
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nexpiration ID  %s",mid[i].year_id);

fclose(mahmoud);

	   printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0D")   ;
     }
//address
{

      	printf("\nFlat number : ");
      		scanf("%d",&madd[i].flat_number);
     			 printf("\nHouse number : ");
     				 scanf("%d",&madd[i].house_number);
      					printf("\nStreet name : ");
     						 scanf("%s",madd[i].street_name);
      							printf("\nArea name : ");
     								 scanf("%s",madd[i].area_name);
      									printf("\nCity name : ");
     		 								scanf("%s",madd[i].city_name);
      											printf("\nGovernorate name : ");
     												 scanf("%s",madd[i].governorate_name);
      													printf("\nCountry : ");
      														scanf("%s",madd[i].country);
      															printf("\nPosta number : ");
      																scanf("%d",&madd[i].posta_number);

mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\naddres   %d",madd[i].flat_number);
fprintf(mahmoud,", %d",madd[i].house_number);
fprintf(mahmoud,", %s",madd[i].street_name);
fprintf(mahmoud,", %s",madd[i].area_name);
fprintf(mahmoud,", %s",madd[i].city_name);
fprintf(mahmoud,", %s",madd[i].governorate_name);
fprintf(mahmoud,", %s",madd[i].country);
fprintf(mahmoud,", %d",madd[i].posta_number);
fclose(mahmoud);
printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0E")   ;
}
//address 23
{

      printf("\n Student mailing address");


      	printf("\nFlat number : ");
      		scanf("%d",&madd1[i].flat_number1);
      			printf("\nHouse number : ");
      				scanf("%d",&madd1[i].house_number1);
      					printf("\nStreet name : ");
      						scanf("%s",madd1[i].street_name1);
     							 printf("\nArea name : ");
      								scanf("%s",madd1[i].area_name1);
      									printf("\nCity name : ");
      										scanf("%s",madd1[i].city_name1);
      											printf("\nGovernorate name : ");
     		 										scanf("%s",madd1[i].governorate_name1);
      													printf("\nCountry : ");
     		 												scanf("%s",madd1[i].country1);
      															printf("\nPosta number : ");
     																 scanf("%d",&madd1[i].posta_number1);

      int q1,q2,q3,q4,q5,q6,q7,q8;



      q3=strcmp(madd1[i].street_name1,madd[i].street_name);
      	q4=strcmp(madd1[i].area_name1,madd[i].area_name);
      		q5=strcmp(madd1[i].city_name1,madd[i].city_name);
      			q6=strcmp(madd1[i].governorate_name1,madd[i].governorate_name);
      				q7=strcmp(madd1[i].country1,madd[i].country);



      if(madd1[i].flat_number1!=madd[i].flat_number||madd1[i].house_number1!=madd[i].house_number||q3!=0||q4!=0||q5!=0||q6!=0||q7!=0||madd1[i].posta_number1!=madd[i].posta_number)
      {

	  printf("\nThe address you entered is incorrect, we will take the address in my data");

	  madd1[i].flat_number1 = madd[i].flat_number;
	  	madd1[i].house_number1 = madd[i].house_number ;
	  		strcpy(madd1[i].street_name1,madd[i].street_name);
	  			strcpy(madd1[i].area_name1,madd[i].area_name);
	  				strcpy(madd1[i].city_name1,madd[i].city_name);
	  					strcpy(madd1[i].governorate_name1,madd[i].governorate_name);
	  						strcpy(madd1[i].country1,madd[i].country);
	  							madd1[i].posta_number1 = madd[i].posta_number ;

	  }
	  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0F")   ;
}
int days, month,m,y;
//beithday
{
       printf("Enter the expiration date of the ID (DD/MM/YYYY): ");

       printf("\nEnter the beithday date year YYYY: ");
       scanf("%s",type[i].year_age1);
       printf("\nEnter the beithday date of the ID MM: ");
       scanf("%s",type[i].month_age1);
       printf("\nEnter the beithday date of the ID DD: ");
	   scanf("%s",type[i].day_age1);



 int P=1;
   for(j=0;j<P;j++)
       {
type[i].day_age = atol(type[i].day_age1);
type[i].month_age = atol(type[i].month_age1);
type[i].year_age = atol(type[i].year_age1);
       	if(type[i].day_age>31 || type[i].day_age<1 || type[i].month_age>12 || type[i].month_age < 1 || type[i].year_age>2019 || type[i].year_age<1980)
       	   {
       		printf("\nwrong enter  birthday : ");
       printf("\nEnter the expiration date year YYYY: ");
       scanf("%s",type[i].year_age1);
       printf("\nEnter the expiration date of the ID MM: ");
       scanf("%s",type[i].month_age1);
       printf("\nEnter the expiration date of the ID DD: ");
	   scanf("%s",type[i].day_age1);
       		P++;
		   }
	   }


        time_t ts; //time now
        	struct tm *ct;


        ts = time(NULL);
       	 	ct = localtime(&ts);

        m=ct->tm_mon + 1;
        	y=ct->tm_year + 1900;

        if(type[i].month_age> m)
         {
     	y=y-1;
     	m=m+12;
	    type[i].month_age=AgeMonth(type[i].month_age,m);
	    	type[i].year_age=AgeYear(type[i].year_age,y);
         }
            else
              {
  	           type[i].month_age=AgeMonth(type[i].month_age,m);
	            	type[i].year_age=AgeYear(type[i].year_age,y);
              }

mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nAge  %d",type[i].year_age);

fclose(mahmoud);
}
char  male[20]={"male"},female[20]={"female"};
//gender
{
	int p =1;
	int f , m ;
		printf("\nChoose gender : (Male / Female) :  ");
			scanf("%s",type[i].gender);

for(j=0;j<p;j++)
{
	m = strcmp(male,type[i].gender);
		f = strcmp(female,type[i].gender);
			if(f!=0 && m!=0)
			{
				printf("\nChoose gender : (Male / Female) :  ");
				scanf("%s",type[i].gender);
				p++;
			}

}
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\ngender  %s",type[i].gender);

fclose(mahmoud);
	  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 09")   ;
}
//department
{
char cs[]={"cs"},se[]={"se"},is[]={"is"},md[]={"md"};
int cs1,se1,is1,md1;
	printf("Enter your department\n");
		printf("if Computer Science Choose (cs)\n");
			printf("if Software Engineering Choose (se)\n");
				printf("if System Information  Choose (is)\n");
					printf("if multimedia Choose (md) \n");
						printf("Small litter \n");
	scanf("%s",mid[i].department);
int p=1;
for(j=0;j<p;j++)
  {
      cs1 = strcmp(mid[i].department,cs);
      	se1 = strcmp(mid[i].department,se);
      		is1 = strcmp(mid[i].department,is);
      			md1 = strcmp(mid[i].department,md);
    	if(cs1!=0 && se1!=0 && is1!=0 && md1!=0)
	    {
			printf("\nEnter your department :  ");
			scanf("%s",mid[i].department);
			p++;
    	}
   }
   mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\ndepartment  %s",mid[i].department);

fclose(mahmoud);
}
//Student tutor name and code
{

  printf("\nThe new student will register only 6 subjects");
  int n = 1;
  for(j=0;j<6;j++)
  {
  	printf("\nEnter %d subjects name : ",n);
  		scanf("%s",sub[i].subjects[j]);
  			printf("\nEnter %d name Dr : ",n);
  				scanf("%s",sub[i].Dr[j]);
  					printf("\nEnter %d subjects code : ",n);
  						scanf("%s",sub[i].code[j]);
  	n++;
  }
  	  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0A")   ;
}
//Payments
{
	char self[]={"self"},grant[]={"grant"};
	int s , g ;


	printf("\n if self-funded choose (self) \n if grant-funded choose (grant) ");
	printf("\nWhat Type of funding : ");
	scanf("%s",pay[i].type_funding);

	for(j=0;j<p;j++)
	{
       s=strcmp(self,pay[i].type_funding)	;
       g=strcmp(grant,pay[i].type_funding) ;
       if(s!=0&&g!=0)
       {


        	printf("\n if self-funded choose (self) \n if grant-funded choose (grant) ");
        		printf("\nWhat Type of funding : ");
        			scanf("%s",pay[i].type_funding);
        	p++;
	   }

	}

	if(s==0)
	{
       printf("\nEnter The degree of the student in high school of 100% : ");
   	   scanf("%d",&pay[i].degree);
   	   	for(j=0;j<p;j++)
	    {
	    	if(pay[i].degree>100||pay[i].degree<70)
	    	{
	    	printf("\n error \nEnter The degree of the student in high school of 100% : ");
   	        scanf("%d",&pay[i].degree);
			p++;
			}
		}

		printf("\nWhat Number of payments done (Dollars) : ");
		scanf("%d",&pay[i].payments_done);

char day_t1[20],month_t1[20],year_t1[20];

		if(pay[i].payments_done!=0)
		{

			pay[i].paid_far=Paid_far(pay[i].payments_done,pay[i].degree);
				printf("\nEnter the bank name : ");
					scanf("%s",pay[i].bank_name);
						printf("\nEnter the Transaction number : ");
							scanf("%s",pay[i].transaction_num);
								printf("\nDate of Transaction (DD/MM/YYYY) : ");
								
								printf("\nDate of Transaction year YYYY : ");
								scanf("%s",year_t1);
								printf("\nDate of Transaction month MM : ");
								scanf("%s",month_t1);
								printf("\nDate of Transaction day DD : ");
								scanf("%s",day_t1);
									
            p=1;
			for(j=0;j<p;j++)
            {
            	pay[i].day_t = atol(day_t1);
            	pay[i].month_t = atol(month_t1);
            	pay[i].year_t = atol(year_t1);
            	if(pay[i].day_t>31||pay[i].day_t<1||pay[i].month_t>12||pay[i].month_t<1||pay[i].year_t>2019||pay[i].year_t<2000)
            	{
 		     	  printf("\n error \nDate of Transaction (DD/MM/YYYY) : ");
			      				printf("\nDate of Transaction year YYYY : ");
								scanf("%s",year_t1);
								printf("\nDate of Transaction month MM : ");
								scanf("%s",month_t1);
								printf("\nDate of Transaction day DD : ");
								scanf("%s",day_t1);
				  p++;
				}
			}

		 }
		  else
		  {
		  	if(pay[i].degree>=90)
	          {
	        	pay[i].total=3700;
	          }
	        else if (pay[i].degree < 90 && pay[i].degree >=80)
	          {
	  	     pay[i].total = 4780 ;
	         }
	          else
	           {
	  	      pay[i].total = 5140 ;
	          }
	         pay[i].paid_far= pay[i].total;

	      }
	}
	else if(g==0) //did not take any payment information
	{
		printf("\nPayments is done ");
	}
   mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\ntype_funding  %s",pay[i].type_funding);
fprintf(mahmoud,"\npaid_far  %d",pay[i].paid_far);
fprintf(mahmoud,"\npayments_done  %d",pay[i].payments_done);
fclose(mahmoud);



		  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0B")   ;

 }
//Student contact
{
	printf("\nenter student e-mail : ");
		scanf("%s",con[i].e_mail);
			printf("\nenter student home number : ");
				scanf("%s",con[i].home_number);
					printf("\nenter student phone number : ");
						scanf("%s",con[i].mobule_number);
						mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\ne mail  %s",con[i].e_mail);
fprintf(mahmoud,"\nhome number  %s",con[i].home_number);
fprintf(mahmoud,"\nphone number  %s",con[i].mobule_number);
fclose(mahmoud);


}
//Credit hours
{
	cre[i].maximum=144;
		printf("\nenter how maney hours finish :  ");
			scanf("%f",&cre[i].finished);
				printf("\nenter how maney hours Current :  ");
					scanf("%f",&cre[i].current);
						cre[i].remaining=remaining(cre[i].maximum,cre[i].finished,cre[i].current);

}
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nremaining hours  %lf",cre[i].remaining);

fclose(mahmoud);

printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0C")   ;
}

                break;
            }
            case 2:{
            	mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
	printf("enter how maney stedent \n");
	scanf("%d",&maney);
for(i=0;i<maney;i++)
{

	int List,year,term,p,d;
    char IDD[20];
    struct name type[i];
    	struct iid mid[i];
    		struct addres madd[i];
    			struct addres1 madd1[i];
    				struct subjects sub[i];
    					struct Payments pay[i];
    						struct Student_contact con[i];
    							struct Credit_hours cre[i];
//name
      {


     	printf("enter First name : ");
     		scanf("%s",type[i].first_name);
     			printf("\nenter midel name : ");
     				scanf("%s",type[i].medil_name);
     					printf("\nenter last name : ");
     						scanf("%s",type[i].last_name);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
    fprintf(mahmoud,"\n_____________________________________________");
    fprintf(mahmoud,"\n_____________________________________________");
fprintf(mahmoud,"\nfirst name %s",type[i].first_name);
fprintf(mahmoud,"\nmedil name %s",type[i].medil_name);
fprintf(mahmoud,"\nlast name %s",type[i].last_name);
fclose(mahmoud);
 }
printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0B")   ;

// registration number
   {

		printf("\nenter Year of registration : ");
        	scanf("%s",type[i].year_r);
        		printf("\nterm 1 or 2 : ");
       				 scanf("%s",type[i].term_r);
        				printf("\nThe student number consists of 4 numbers : ");
        					scanf("%s",type[i].number);
        						type[i].registration=Registration(type[i].year_r,type[i].term_r,type[i].number);
        							printf("\n%llu",type[i].registration);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nregistration number %llu",type[i].registration);

fclose(mahmoud);

printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0C")   ;
   }
//nationality
	{

     	printf("\nenter your nationality : ");
        	scanf("%s",type[i].nationality);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nnationality  %s",type[i].nationality);

fclose(mahmoud);
    }
//ID
    {
int y, arr2[100];
        printf("\nEnter the type of identity : (Passport / Identity card) :  ");
        scanf("%s",&mid[i].type_of_identity);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\ntype_of_identity  %s",mid[i].type_of_identity);

fclose(mahmoud);
p=1;
       for(j=0;j<p;j++)
	   {
            printf("\nenter your ID number : ");
            scanf("%s",mid[i].ID);
            y=strlen(mid[i].ID);
            if(y==14)
            {
            	for(j=0;j<14;j++)
            	{
            		arr2[j]=mid[i].ID[j]-'0';
            		if(arr2[j]>9||arr2[j]<0)
            		{
            			d++;
					}
				}
				if(d!=0)
				{
				              printf("\nwrong enter ID number : ");
              					p++;
				}
			}
              else
             {
              printf("\nwrong enter ID number : ");
              p++;
             }

       }

mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nID number  %s",mid[i].ID);

fclose(mahmoud);

       int YY,DD,MM;
       p=1;
       printf("Enter the expiration date of the ID (DD/MM/YYYY): ");

       printf("\nEnter the expiration date year YYYY: ");
       scanf("%s",mid[i].year_id);
       printf("\nEnter the expiration date of the ID MM: ");
       scanf("%s",mid[i].month_id);
       printf("\nEnter the expiration date of the ID DD: ");
	   scanf("%s",mid[i].day_id);
	   for(j=0;j<p;j++)
       {

DD = atol(mid[i].day_id);
MM = atol(mid[i].month_id);
YY = atol(mid[i].year_id);

       	if(DD > 31 || DD < 1 || MM >12 || MM < 1 || YY>2050 || YY < 2019)
       	   {
       		printf("\nwrong enter expiration date of the ID : ");
       printf("\nEnter the expiration date year YYYY): ");
       scanf("%s",mid[i].year_id);
       printf("\nEnter the expiration date of the ID MM: ");
       scanf("%s",mid[i].month_id);
       printf("\nEnter the expiration date of the ID DD: ");
	   scanf("%s",mid[i].day_id);
       		p++;
		   }
	   }
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nexpiration ID  %s",mid[i].year_id);

fclose(mahmoud);

	   printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0D")   ;
     }
//address
{

      	printf("\nFlat number : ");
      		scanf("%d",&madd[i].flat_number);
     			 printf("\nHouse number : ");
     				 scanf("%d",&madd[i].house_number);
      					printf("\nStreet name : ");
     						 scanf("%s",madd[i].street_name);
      							printf("\nArea name : ");
     								 scanf("%s",madd[i].area_name);
      									printf("\nCity name : ");
     		 								scanf("%s",madd[i].city_name);
      											printf("\nGovernorate name : ");
     												 scanf("%s",madd[i].governorate_name);
      													printf("\nCountry : ");
      														scanf("%s",madd[i].country);
      															printf("\nPosta number : ");
      																scanf("%d",&madd[i].posta_number);

mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\naddres   %d",madd[i].flat_number);
fprintf(mahmoud,", %d",madd[i].house_number);
fprintf(mahmoud,", %s",madd[i].street_name);
fprintf(mahmoud,", %s",madd[i].area_name);
fprintf(mahmoud,", %s",madd[i].city_name);
fprintf(mahmoud,", %s",madd[i].governorate_name);
fprintf(mahmoud,", %s",madd[i].country);
fprintf(mahmoud,", %d",madd[i].posta_number);
fclose(mahmoud);
printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0E")   ;
}
//address 23
{

      printf("\n Student mailing address");


      	printf("\nFlat number : ");
      		scanf("%d",&madd1[i].flat_number1);
      			printf("\nHouse number : ");
      				scanf("%d",&madd1[i].house_number1);
      					printf("\nStreet name : ");
      						scanf("%s",madd1[i].street_name1);
     							 printf("\nArea name : ");
      								scanf("%s",madd1[i].area_name1);
      									printf("\nCity name : ");
      										scanf("%s",madd1[i].city_name1);
      											printf("\nGovernorate name : ");
     		 										scanf("%s",madd1[i].governorate_name1);
      													printf("\nCountry : ");
     		 												scanf("%s",madd1[i].country1);
      															printf("\nPosta number : ");
     																 scanf("%d",&madd1[i].posta_number1);

      int q1,q2,q3,q4,q5,q6,q7,q8;



      q3=strcmp(madd1[i].street_name1,madd[i].street_name);
      	q4=strcmp(madd1[i].area_name1,madd[i].area_name);
      		q5=strcmp(madd1[i].city_name1,madd[i].city_name);
      			q6=strcmp(madd1[i].governorate_name1,madd[i].governorate_name);
      				q7=strcmp(madd1[i].country1,madd[i].country);



      if(madd1[i].flat_number1!=madd[i].flat_number||madd1[i].house_number1!=madd[i].house_number||q3!=0||q4!=0||q5!=0||q6!=0||q7!=0||madd1[i].posta_number1!=madd[i].posta_number)
      {

	  printf("\nThe address you entered is incorrect, we will take the address in my data");

	  madd1[i].flat_number1 = madd[i].flat_number;
	  	madd1[i].house_number1 = madd[i].house_number ;
	  		strcpy(madd1[i].street_name1,madd[i].street_name);
	  			strcpy(madd1[i].area_name1,madd[i].area_name);
	  				strcpy(madd1[i].city_name1,madd[i].city_name);
	  					strcpy(madd1[i].governorate_name1,madd[i].governorate_name);
	  						strcpy(madd1[i].country1,madd[i].country);
	  							madd1[i].posta_number1 = madd[i].posta_number ;

	  }
	  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0F")   ;
}
int days, month,m,y;
//beithday
{
       printf("Enter the expiration date of the ID (DD/MM/YYYY): ");

       printf("\nEnter the beithday date year YYYY: ");
       scanf("%s",type[i].year_age1);
       printf("\nEnter the beithday date of the ID MM: ");
       scanf("%s",type[i].month_age1);
       printf("\nEnter the beithday date of the ID DD: ");
	   scanf("%s",type[i].day_age1);



 int P=1;
   for(j=0;j<P;j++)
       {
type[i].day_age = atol(type[i].day_age1);
type[i].month_age = atol(type[i].month_age1);
type[i].year_age = atol(type[i].year_age1);
       	if(type[i].day_age>31 || type[i].day_age<1 || type[i].month_age>12 || type[i].month_age < 1 || type[i].year_age>2019 || type[i].year_age<1980)
       	   {
       		printf("\nwrong enter  birthday : ");
       printf("\nEnter the expiration date year YYYY: ");
       scanf("%s",type[i].year_age1);
       printf("\nEnter the expiration date of the ID MM: ");
       scanf("%s",type[i].month_age1);
       printf("\nEnter the expiration date of the ID DD: ");
	   scanf("%s",type[i].day_age1);
       		P++;
		   }
	   }


        time_t ts; //time now
        	struct tm *ct;


        ts = time(NULL);
       	 	ct = localtime(&ts);

        m=ct->tm_mon + 1;
        	y=ct->tm_year + 1900;

        if(type[i].month_age> m)
         {
     	y=y-1;
     	m=m+12;
	    type[i].month_age=AgeMonth(type[i].month_age,m);
	    	type[i].year_age=AgeYear(type[i].year_age,y);
         }
            else
              {
  	           type[i].month_age=AgeMonth(type[i].month_age,m);
	            	type[i].year_age=AgeYear(type[i].year_age,y);
              }

mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nAge  %d",type[i].year_age);

fclose(mahmoud);
}
char  male[20]={"male"},female[20]={"female"};
//gender
{
	int p =1;
	int f , m ;
		printf("\nChoose gender : (Male / Female) :  ");
			scanf("%s",type[i].gender);

for(j=0;j<p;j++)
{
	m = strcmp(male,type[i].gender);
		f = strcmp(female,type[i].gender);
			if(f!=0 && m!=0)
			{
				printf("\nChoose gender : (Male / Female) :  ");
				scanf("%s",type[i].gender);
				p++;
			}

}
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\ngender  %s",type[i].gender);

fclose(mahmoud);
	  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 09")   ;
}
//department
{
char cs[]={"cs"},se[]={"se"},is[]={"is"},md[]={"md"};
int cs1,se1,is1,md1;
	printf("Enter your department\n");
		printf("if Computer Science Choose (cs)\n");
			printf("if Software Engineering Choose (se)\n");
				printf("if System Information  Choose (is)\n");
					printf("if multimedia Choose (md) \n");
						printf("Small litter \n");
	scanf("%s",mid[i].department);
int p=1;
for(j=0;j<p;j++)
  {
      cs1 = strcmp(mid[i].department,cs);
      	se1 = strcmp(mid[i].department,se);
      		is1 = strcmp(mid[i].department,is);
      			md1 = strcmp(mid[i].department,md);
    	if(cs1!=0 && se1!=0 && is1!=0 && md1!=0)
	    {
			printf("\nEnter your department :  ");
			scanf("%s",mid[i].department);
			p++;
    	}
   }
   mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\ndepartment  %s",mid[i].department);

fclose(mahmoud);
}
//Student tutor name and code
{

  printf("\nThe new student will register only 6 subjects");
  int n = 1;
  for(j=0;j<6;j++)
  {
  	printf("\nEnter %d subjects name : ",n);
  		scanf("%s",sub[i].subjects[j]);
  			printf("\nEnter %d name Dr : ",n);
  				scanf("%s",sub[i].Dr[j]);
  					printf("\nEnter %d subjects code : ",n);
  						scanf("%s",sub[i].code[j]);
  	n++;
  }
  	  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0A")   ;
}
//Payments
{
	char self[]={"self"},grant[]={"grant"};
	int s , g ;


	printf("\n if self-funded choose (self) \n if grant-funded choose (grant) ");
	printf("\nWhat Type of funding : ");
	scanf("%s",pay[i].type_funding);

	for(j=0;j<p;j++)
	{
       s=strcmp(self,pay[i].type_funding)	;
       g=strcmp(grant,pay[i].type_funding) ;
       if(s!=0&&g!=0)
       {


        	printf("\n if self-funded choose (self) \n if grant-funded choose (grant) ");
        		printf("\nWhat Type of funding : ");
        			scanf("%s",pay[i].type_funding);
        	p++;
	   }

	}

	if(s==0)
	{
       printf("\nEnter The degree of the student in high school of 100% : ");
   	   scanf("%d",&pay[i].degree);
   	   	for(j=0;j<p;j++)
	    {
	    	if(pay[i].degree>100||pay[i].degree<70)
	    	{
	    	printf("\n error \nEnter The degree of the student in high school of 100% : ");
   	        scanf("%d",&pay[i].degree);
			p++;
			}
		}

		printf("\nWhat Number of payments done (Dollars) : ");
		scanf("%d",&pay[i].payments_done);



char day_t1[20],month_t1[20],year_t1[20];

		if(pay[i].payments_done!=0)
		{

			pay[i].paid_far=Paid_far(pay[i].payments_done,pay[i].degree);
				printf("\nEnter the bank name : ");
					scanf("%s",pay[i].bank_name);
						printf("\nEnter the Transaction number : ");
							scanf("%s",pay[i].transaction_num);
								printf("\nDate of Transaction (DD/MM/YYYY) : ");
								
								printf("\nDate of Transaction year YYYY : ");
								scanf("%s",year_t1);
								printf("\nDate of Transaction month MM : ");
								scanf("%s",month_t1);
								printf("\nDate of Transaction day DD : ");
								scanf("%s",day_t1);
									
            p=1;
			for(j=0;j<p;j++)
            {
            	pay[i].day_t = atol(day_t1);
            	pay[i].month_t = atol(month_t1);
            	pay[i].year_t = atol(year_t1);
            	if(pay[i].day_t>31||pay[i].day_t<1||pay[i].month_t>12||pay[i].month_t<1||pay[i].year_t>2019||pay[i].year_t<2000)
            	{
 		     	  printf("\n error \nDate of Transaction (DD/MM/YYYY) : ");
			      				printf("\nDate of Transaction year YYYY : ");
								scanf("%s",year_t1);
								printf("\nDate of Transaction month MM : ");
								scanf("%s",month_t1);
								printf("\nDate of Transaction day DD : ");
								scanf("%s",day_t1);
				}
			}

		 }
		  else
		  {
		  	if(pay[i].degree>=90)
	          {
	        	pay[i].total=3700;
	          }
	        else if (pay[i].degree < 90 && pay[i].degree >=80)
	          {
	  	     pay[i].total = 4780 ;
	         }
	          else
	           {
	  	      pay[i].total = 5140 ;
	          }
	         pay[i].paid_far= pay[i].total;

	      }
	}
	else if(g==0) //did not take any payment information
	{
		printf("\nPayments is done ");
	}
   mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\ntype_funding  %s",pay[i].type_funding);
fprintf(mahmoud,"\npaid_far  %d",pay[i].paid_far);
fprintf(mahmoud,"\npayments_done  %d",pay[i].payments_done);
fclose(mahmoud);



		  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0B")   ;

 }
//Student contact
{
	printf("\nenter student e-mail : ");
		scanf("%s",con[i].e_mail);
			printf("\nenter student home number : ");
				scanf("%s",con[i].home_number);
					printf("\nenter student phone number : ");
						scanf("%s",con[i].mobule_number);
						mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\ne mail  %s",con[i].e_mail);
fprintf(mahmoud,"\nhome number  %s",con[i].home_number);
fprintf(mahmoud,"\nphone number  %s",con[i].mobule_number);
fclose(mahmoud);
}
//Credit hours
{
	cre[i].maximum=144;
		printf("\nenter how maney hours finish :  ");
			scanf("%f",&cre[i].finished);
				printf("\nenter how maney hours Current :  ");
					scanf("%f",&cre[i].current);
						cre[i].remaining=remaining(cre[i].maximum,cre[i].finished,cre[i].current);

}
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","a");
fprintf(mahmoud,"\nremaining hours  %lf",cre[i].remaining);

fclose(mahmoud);

printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0C")   ;
}
                        break;
            }
            case 3:{
            	mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
            	printf("enter how maney stedent \n");
	scanf("%d",&maney);
for(i=0;i<maney;i++)
{

	int List,year,term,p,d;
    char IDD[20];
    struct name type[i];
    	struct iid mid[i];
    		struct addres madd[i];
    			struct addres1 madd1[i];
    				struct subjects sub[i];
    					struct Payments pay[i];
    						struct Student_contact con[i];
    							struct Credit_hours cre[i];
//name
      {


     	printf("enter First name : ");
     		scanf("%s",type[i].first_name);
     			printf("\nenter midel name : ");
     				scanf("%s",type[i].medil_name);
     					printf("\nenter last name : ");
     						scanf("%s",type[i].last_name);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
    fprintf(mahmoud,"\n_____________________________________________");
    fprintf(mahmoud,"\n_____________________________________________");
fprintf(mahmoud,"\nfirst name %s",type[i].first_name);
fprintf(mahmoud,"\nmedil name %s",type[i].medil_name);
fprintf(mahmoud,"\nlast name %s",type[i].last_name);
fclose(mahmoud);
 }
printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0B")   ;

// registration number
   {

		printf("\nenter Year of registration : ");
        	scanf("%s",type[i].year_r);
        		printf("\nterm 1 or 2 : ");
       				 scanf("%s",type[i].term_r);
        				printf("\nThe student number consists of 4 numbers : ");
        					scanf("%s",type[i].number);
        						type[i].registration=Registration(type[i].year_r,type[i].term_r,type[i].number);
        							printf("\n%llu",type[i].registration);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\nregistration number %llu",type[i].registration);

fclose(mahmoud);

printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0C")   ;
   }
//nationality
	{

     	printf("\nenter your nationality : ");
        	scanf("%s",type[i].nationality);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\nnationality  %s",type[i].nationality);

fclose(mahmoud);
    }
//ID
    {
int y, arr2[100];
        printf("\nEnter the type of identity : (Passport / Identity card) :  ");
        scanf("%s",&mid[i].type_of_identity);
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\ntype_of_identity  %s",mid[i].type_of_identity);

fclose(mahmoud);
p=1;
       for(j=0;j<p;j++)
	   {
            printf("\nenter your ID number : ");
            scanf("%s",mid[i].ID);
            y=strlen(mid[i].ID);
            if(y==14)
            {
            	for(j=0;j<14;j++)
            	{
            		arr2[j]=mid[i].ID[j]-'0';
            		if(arr2[j]>9||arr2[j]<0)
            		{
            			d++;
					}
				}
				if(d!=0)
				{
				              printf("\nwrong enter ID number : ");
              					p++;
				}
			}
              else
             {
              printf("\nwrong enter ID number : ");
              p++;
             }

       }

mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\nID number  %s",mid[i].ID);

fclose(mahmoud);

       int YY,DD,MM;
       p=1;
       printf("Enter the expiration date of the ID (DD/MM/YYYY): ");

       printf("\nEnter the expiration date year YYYY: ");
       scanf("%s",mid[i].year_id);
       printf("\nEnter the expiration date of the ID MM: ");
       scanf("%s",mid[i].month_id);
       printf("\nEnter the expiration date of the ID DD: ");
	   scanf("%s",mid[i].day_id);
	   for(j=0;j<p;j++)
       {

DD = atol(mid[i].day_id);
MM = atol(mid[i].month_id);
YY = atol(mid[i].year_id);

       	if(DD > 31 || DD < 1 || MM >12 || MM < 1 || YY>2050 || YY < 2019)
       	   {
       		printf("\nwrong enter expiration date of the ID : ");
       printf("\nEnter the expiration date year YYYY): ");
       scanf("%s",mid[i].year_id);
       printf("\nEnter the expiration date of the ID MM: ");
       scanf("%s",mid[i].month_id);
       printf("\nEnter the expiration date of the ID DD: ");
	   scanf("%s",mid[i].day_id);
       		p++;
		   }
	   }
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\nexpiration ID  %s",mid[i].year_id);

fclose(mahmoud);

	   printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0D")   ;
     }
//address
{

      	printf("\nFlat number : ");
      		scanf("%d",&madd[i].flat_number);
     			 printf("\nHouse number : ");
     				 scanf("%d",&madd[i].house_number);
      					printf("\nStreet name : ");
     						 scanf("%s",madd[i].street_name);
      							printf("\nArea name : ");
     								 scanf("%s",madd[i].area_name);
      									printf("\nCity name : ");
     		 								scanf("%s",madd[i].city_name);
      											printf("\nGovernorate name : ");
     												 scanf("%s",madd[i].governorate_name);
      													printf("\nCountry : ");
      														scanf("%s",madd[i].country);
      															printf("\nPosta number : ");
      																scanf("%d",&madd[i].posta_number);

mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\naddres   %d",madd[i].flat_number);
fprintf(mahmoud,", %d",madd[i].house_number);
fprintf(mahmoud,", %s",madd[i].street_name);
fprintf(mahmoud,", %s",madd[i].area_name);
fprintf(mahmoud,", %s",madd[i].city_name);
fprintf(mahmoud,", %s",madd[i].governorate_name);
fprintf(mahmoud,", %s",madd[i].country);
fprintf(mahmoud,", %d",madd[i].posta_number);
fclose(mahmoud);
printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0E")   ;
}
//address 23
{

      printf("\n Student mailing address");


      	printf("\nFlat number : ");
      		scanf("%d",&madd1[i].flat_number1);
      			printf("\nHouse number : ");
      				scanf("%d",&madd1[i].house_number1);
      					printf("\nStreet name : ");
      						scanf("%s",madd1[i].street_name1);
     							 printf("\nArea name : ");
      								scanf("%s",madd1[i].area_name1);
      									printf("\nCity name : ");
      										scanf("%s",madd1[i].city_name1);
      											printf("\nGovernorate name : ");
     		 										scanf("%s",madd1[i].governorate_name1);
      													printf("\nCountry : ");
     		 												scanf("%s",madd1[i].country1);
      															printf("\nPosta number : ");
     																 scanf("%d",&madd1[i].posta_number1);

      int q1,q2,q3,q4,q5,q6,q7,q8;



      q3=strcmp(madd1[i].street_name1,madd[i].street_name);
      	q4=strcmp(madd1[i].area_name1,madd[i].area_name);
      		q5=strcmp(madd1[i].city_name1,madd[i].city_name);
      			q6=strcmp(madd1[i].governorate_name1,madd[i].governorate_name);
      				q7=strcmp(madd1[i].country1,madd[i].country);



      if(madd1[i].flat_number1!=madd[i].flat_number||madd1[i].house_number1!=madd[i].house_number||q3!=0||q4!=0||q5!=0||q6!=0||q7!=0||madd1[i].posta_number1!=madd[i].posta_number)
      {

	  printf("\nThe address you entered is incorrect, we will take the address in my data");

	  madd1[i].flat_number1 = madd[i].flat_number;
	  	madd1[i].house_number1 = madd[i].house_number ;
	  		strcpy(madd1[i].street_name1,madd[i].street_name);
	  			strcpy(madd1[i].area_name1,madd[i].area_name);
	  				strcpy(madd1[i].city_name1,madd[i].city_name);
	  					strcpy(madd1[i].governorate_name1,madd[i].governorate_name);
	  						strcpy(madd1[i].country1,madd[i].country);
	  							madd1[i].posta_number1 = madd[i].posta_number ;

	  }
	  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0F")   ;
}
int days, month,m,y;
//beithday
{
       printf("Enter the expiration date of the ID (DD/MM/YYYY): ");

       printf("\nEnter the beithday date year YYYY: ");
       scanf("%s",type[i].year_age1);
       printf("\nEnter the beithday date of the ID MM: ");
       scanf("%s",type[i].month_age1);
       printf("\nEnter the beithday date of the ID DD: ");
	   scanf("%s",type[i].day_age1);



 int P=1;
   for(j=0;j<P;j++)
       {
type[i].day_age = atol(type[i].day_age1);
type[i].month_age = atol(type[i].month_age1);
type[i].year_age = atol(type[i].year_age1);
       	if(type[i].day_age>31 || type[i].day_age<1 || type[i].month_age>12 || type[i].month_age < 1 || type[i].year_age>2019 || type[i].year_age<1980)
       	   {
       		printf("\nwrong enter  birthday : ");
       printf("\nEnter the expiration date year YYYY: ");
       scanf("%s",type[i].year_age1);
       printf("\nEnter the expiration date of the ID MM: ");
       scanf("%s",type[i].month_age1);
       printf("\nEnter the expiration date of the ID DD: ");
	   scanf("%s",type[i].day_age1);
       		P++;
		   }
	   }


        time_t ts; //time now
        	struct tm *ct;


        ts = time(NULL);
       	 	ct = localtime(&ts);

        m=ct->tm_mon + 1;
        	y=ct->tm_year + 1900;

        if(type[i].month_age> m)
         {
     	y=y-1;
     	m=m+12;
	    type[i].month_age=AgeMonth(type[i].month_age,m);
	    	type[i].year_age=AgeYear(type[i].year_age,y);
         }
            else
              {
  	           type[i].month_age=AgeMonth(type[i].month_age,m);
	            	type[i].year_age=AgeYear(type[i].year_age,y);
              }

mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\nAge  %d",type[i].year_age);

fclose(mahmoud);
}
char  male[20]={"male"},female[20]={"female"};
//gender
{
	int p =1;
	int f , m ;
		printf("\nChoose gender : (Male / Female) :  ");
			scanf("%s",type[i].gender);

for(j=0;j<p;j++)
{
	m = strcmp(male,type[i].gender);
		f = strcmp(female,type[i].gender);
			if(f!=0 && m!=0)
			{
				printf("\nChoose gender : (Male / Female) :  ");
				scanf("%s",type[i].gender);
				p++;
			}

}
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\ngender  %s",type[i].gender);

fclose(mahmoud);
	  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 09")   ;
}
//department
{
char cs[]={"cs"},se[]={"se"},is[]={"is"},md[]={"md"};
int cs1,se1,is1,md1;
	printf("Enter your department\n");
		printf("if Computer Science Choose (cs)\n");
			printf("if Software Engineering Choose (se)\n");
				printf("if System Information  Choose (is)\n");
					printf("if multimedia Choose (md) \n");
						printf("Small litter \n");
	scanf("%s",mid[i].department);
int p=1;
for(j=0;j<p;j++)
  {
      cs1 = strcmp(mid[i].department,cs);
      	se1 = strcmp(mid[i].department,se);
      		is1 = strcmp(mid[i].department,is);
      			md1 = strcmp(mid[i].department,md);
    	if(cs1!=0 && se1!=0 && is1!=0 && md1!=0)
	    {
			printf("\nEnter your department :  ");
			scanf("%s",mid[i].department);
			p++;
    	}
   }
   mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\ndepartment  %s",mid[i].department);

fclose(mahmoud);
}
//Student tutor name and code
{

  printf("\nThe new student will register only 6 subjects");
  int n = 1;
  for(j=0;j<6;j++)
  {
  	printf("\nEnter %d subjects name : ",n);
  		scanf("%s",sub[i].subjects[j]);
  			printf("\nEnter %d name Dr : ",n);
  				scanf("%s",sub[i].Dr[j]);
  					printf("\nEnter %d subjects code : ",n);
  						scanf("%s",sub[i].code[j]);
  	n++;
  }
  	  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0A")   ;
}
//Payments
{
	char self[]={"self"},grant[]={"grant"};
	int s , g ;


	printf("\n if self-funded choose (self) \n if grant-funded choose (grant) ");
	printf("\nWhat Type of funding : ");
	scanf("%s",pay[i].type_funding);

	for(j=0;j<p;j++)
	{
       s=strcmp(self,pay[i].type_funding)	;
       g=strcmp(grant,pay[i].type_funding) ;
       if(s!=0&&g!=0)
       {


        	printf("\n if self-funded choose (self) \n if grant-funded choose (grant) ");
        		printf("\nWhat Type of funding : ");
        			scanf("%s",pay[i].type_funding);
        	p++;
	   }

	}

	if(s==0)
	{
       printf("\nEnter The degree of the student in high school of 100% : ");
   	   scanf("%d",&pay[i].degree);
   	   	for(j=0;j<p;j++)
	    {
	    	if(pay[i].degree>100||pay[i].degree<70)
	    	{
	    	printf("\n error \nEnter The degree of the student in high school of 100% : ");
   	        scanf("%d",&pay[i].degree);
			p++;
			}
		}

		printf("\nWhat Number of payments done (Dollars) : ");
		scanf("%d",&pay[i].payments_done);



	char day_t1[20],month_t1[20],year_t1[20];

		if(pay[i].payments_done!=0)
		{

			pay[i].paid_far=Paid_far(pay[i].payments_done,pay[i].degree);
				printf("\nEnter the bank name : ");
					scanf("%s",pay[i].bank_name);
						printf("\nEnter the Transaction number : ");
							scanf("%s",pay[i].transaction_num);
								printf("\nDate of Transaction (DD/MM/YYYY) : ");
								
								printf("\nDate of Transaction year YYYY : ");
								scanf("%s",year_t1);
								printf("\nDate of Transaction month MM : ");
								scanf("%s",month_t1);
								printf("\nDate of Transaction day DD : ");
								scanf("%s",day_t1);
									
            p=1;
			for(j=0;j<p;j++)
            {
            	pay[i].day_t = atol(day_t1);
            	pay[i].month_t = atol(month_t1);
            	pay[i].year_t = atol(year_t1);
            	if(pay[i].day_t>31||pay[i].day_t<1||pay[i].month_t>12||pay[i].month_t<1||pay[i].year_t>2019||pay[i].year_t<2000)
            	{
 		     	  printf("\n error \nDate of Transaction (DD/MM/YYYY) : ");
			      				printf("\nDate of Transaction year YYYY : ");
								scanf("%s",year_t1);
								printf("\nDate of Transaction month MM : ");
								scanf("%s",month_t1);
								printf("\nDate of Transaction day DD : ");
								scanf("%s",day_t1);
				}
			}

		 }
		  else
		  {
		  	if(pay[i].degree>=90)
	          {
	        	pay[i].total=3700;
	          }
	        else if (pay[i].degree < 90 && pay[i].degree >=80)
	          {
	  	     pay[i].total = 4780 ;
	         }
	          else
	           {
	  	      pay[i].total = 5140 ;
	          }
	         pay[i].paid_far= pay[i].total;

	      }
	}
	else if(g==0) //did not take any payment information
	{
		printf("\nPayments is done ");
	}
   mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\ntype_funding  %s",pay[i].type_funding);
fprintf(mahmoud,"\npaid_far  %d",pay[i].paid_far);
fprintf(mahmoud,"\npayments_done  %d",pay[i].payments_done);
fclose(mahmoud);



		  printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0B")   ;

 }
//Student contact
{
	printf("\nenter student e-mail : ");
		scanf("%s",con[i].e_mail);
			printf("\nenter student home number : ");
				scanf("%s",con[i].home_number);
					printf("\nenter student phone number : ");
						scanf("%s",con[i].mobule_number);
						mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\ne mail  %s",con[i].e_mail);
fprintf(mahmoud,"\nhome number  %s",con[i].home_number);
fprintf(mahmoud,"\nphone number  %s",con[i].mobule_number);
fclose(mahmoud);
}
//Credit hours
{
	cre[i].maximum=144;
		printf("\nenter how maney hours finish :  ");
			scanf("%f",&cre[i].finished);
				printf("\nenter how maney hours Current :  ");
					scanf("%f",&cre[i].current);
						cre[i].remaining=remaining(cre[i].maximum,cre[i].finished,cre[i].current);

}
mahmoud = fopen("hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","w");
fprintf(mahmoud,"\nremaining hours  %lf",cre[i].remaining);

fclose(mahmoud);

printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0C")   ;
}

				break;
			}
            case 4:{
sum =0;
printf("\nHow maney Subject :");
scanf("%d",&Subject);
for(i=0;i<Subject;i++)
{
    printf("Enter marks of Subject %d out of 100 = ",(i+1));
    scanf("%d",&gpa[i]);
    sum = sum + gpa[i];
}
avg = sum / Subject;
per=(sum*100)/(Subject*100);
if(per>=90 && per<=100)
  {
     printf("\nGPA=4.0");
     printf("\nA+");
  }
  else if(per>=85 && per<=89)
  {
      printf("\nGPA=3.7");
      printf("\nA");
  }
  else if(per>=80 && per<=84)
  {
      printf("\nGPA=3.3");
      printf("\nB+");
  }
  else if(per>=75 && per<=79)
  {
      printf("\nGPA=3");
      printf("\nB");
  }
  else if(per>=70 && per<=74)
  {
      printf("\nGPA=2.7");
      printf("\nB-");
  }
  else if(per>=65 && per<=69)
  {
      printf("\nGPA=2.3");
      printf("\nC+");
  }
  else if(per>=60 && per<=64)
  {
      printf("\nGPA=2.0");
      printf("\nC-");
  }
  else if(per>=55 && per<=59)
  {
      printf("\nGPA=1.7");
      printf("\nD+");
  }
  else if(per>=50 && per<=54)
  {
      printf("\nGPA=1.3");
      printf("\nD-");
  }
  else if(per>=0 && per<50)
  {
      printf("\nGPA=0.0");
      printf("\nF");
  }
printf("\nenter any key : ");
getch();
system("cls")   ;
system("COLOR 0A")   ;
                break;
            }
            case 5:{
                int u ,i;
                float ggpa,arr[200],sum;
                printf("\nHow maney term : ");
                scanf("%d",&u);
                for(i=0;i<u;i++)
                {
                    printf("\nenter gpa in term %d : ",(i+1));
                    scanf("%f",&arr[i]);
                    sum = sum + arr[i];
                }
                ggpa = sum / u;
                printf("\nyour Gpa = %lf",ggpa);
                printf("\nEnter any key");
                getch();
                system("cls");
                system("COlOr 09");
            break ;}
            case 7:{

                exit(0); }   // terminates the complete program execution
            case 6:{
            	mahmoud = fopen ("C:\\Users\\Mahmoud\\Desktop\\hhhhhhhhhhhhhhhhhhhhhhhhhhhh.txt","r");
            	char bb[100];
            	int i,s ,k; 
            	printf("\nhow maney student :");
            	scanf("%d",&s);
            	k=s*21;
            	for(i=0;i<k;i++)
            	{
            		fgets(bb,100,(FILE*)mahmoud);
            		printf("\n%s",bb);
				}
            	
            	fclose(mahmoud);
            	printf("\nEnter any key");
                getch();
                system("cls");
                system("COlOr 09");
				break;
			}
			default:{
        printf("wrong Input\n");

                system("cls");
                printf("wrong Input\n");
                system("COlOr 0F");
       break;
    }


        }
    }

return 0;

}
