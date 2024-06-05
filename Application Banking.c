#include<stdio.h>
#include<conio.h>
#include<string.h>
int check(int);                         // Function Check information 
void command(int);                      // Function use to command
void data();                            // Function Input information user
void file();                            // Function: Enter user data and store in FILE
struct information                      
{
	char Name_in[50];                   // username
	float money;                        // money
	int password;                       // password
	int id;                             // id banking
};
struct information iu[3];               // support 3 user
void main()
{
    int H;
	int id_in,index;
	printf("\t\t1 = Have an account / 0 = don't have an account \n\n");
	printf("Do you have a bank account? (1/0) : ");                             
    scanf("%d",&H);                                                               // Select 1/0 to indicate the status
    if(H == 1)                                                                    // Condition you have a bank account
    {
		printf("ID Bnking : ");
    	scanf("%d",&id_in);                                                      // Input ID banking
    	index = check(id_in);                                                    // check id banking through function
    	command(index);                                                         //  run command  
	}
	else if(H==0)                                                               // Condition you don't have a bank account
	{
		printf("\nUsed to Fuction create id bank \n");
		data();                                                             // user input information through function
		main();                                                             // start working again
	}else{
		printf("you input data error \n\n");                                // User Input does not match the condition.
		end();
	}
}
int check(int id_in)                                                        // function check 
{
	int pass_in;
	int index;
	int i;
   if(id_in == iu[0].id)                                                    // 1rd user id
   {                                                  
   	index = 0;
   }
   else if(id_in == iu[1].id)                                              // 2rd user id
   {
   	index = 1;
   }
   else if(id_in == iu[2].id)                                             // 3rd user id
   {
   	index = 2;
   }else{                                                                 // id banking not found
   	printf("\t ID not found please check id banking again !!!! \n");
   	getch();
   	main();
   }
   printf("Password : ");
   scanf("%d",&pass_in);
   if(pass_in == iu[index].password)                                     // check password to user id
   {  
       return index;
   }
   else{
   	printf("\t Password error please check again !!!! \n");             // enter wrong password
   	i=0;
	do                                                                  // You can enter the password 3 more times.
   	{
   	   	printf("Password : ");
        scanf("%d",&pass_in);
        i++;
        if(pass_in == iu[index].password)
        {
        	i=4;
			return index;
		}  
    }while(i<3);
   end();
   }
}
void file()                                                            // function File
{
	FILE *fin;
	int i,j=0;
	fin = fopen("Information.txt","w");                                // create a file named information.txt with mode write
	for(i=0;i<3;i++)
	{
		fprintf(fin,"Information[%d]\n",j+1);                            
		fprintf(fin,"Username : %s\n",iu[i].Name_in);
		fprintf(fin,"Password : %d\n",iu[i].password);
		fprintf(fin,"ID BANK  : %d\n",iu[i].id);
		fprintf(fin,"---------------------------------\n\n");
		j++;
	}
	fclose(fin);                                                      // close file information.txt
}
void data()                                                           // function data
{
	int i;
	char password;
	srand(time(NULL));
	for(i=0;i<3;i++)                                                  // input data 3 user
	{
		iu[i].id = rand()+10000;                                      // random number 10000-99999
	    printf("User     : ");
	    scanf("%s",&iu[i].Name_in);                                  // input username
	    printf("Password : ");
	    scanf("%d",&iu[i].password);                                 // input password
	}
	printf("-------------------------------\n\n");
	file();
}
void command(int index)                                             // function command
{
	char c_in[5];
	float m;
	int pass_o,id_o;
	for(;;)                                                         // infinity loop
	{
		printf("account ID : %s  \n\n",iu[index].Name_in);          // show username of the account holder.
		printf("\n\t\t    Command[Dm]   = Deposit money\n");        // show shortcut command          
		printf("\t\t    Command[Cp]   = Change password\n");
		printf("\t\t    Command[Wm]   = Withdraw money \n");
		printf("\t\t    Command[Cm]   = Check money \n");			
		printf("\t\t    Command[Tm]   = Transfer money\n");
		printf("\t\t    Command[Quit] = Quit Bank\n\n");
		printf("Enter your command: ");
		scanf("%s",&c_in);                                                // input command
		strlwr(c_in);
		printf("------------------------------------------\n\n");
		if(!strcmp(c_in,"quit"))                                         // quit      
		{
		    main();      
		}  // else if quit 
		else if(!strcmp(c_in,"dm"))                                      // Deposit money 
		{
			printf("Money in Bank = %.2f $\n",iu[index].money); 
		    printf("Deposit Money : ");		       
			scanf("%f",&m);                                              // input number to deposit
			iu[index].money+=m;
			printf("Money in bank = %.2f $\n\n",iu[index].money);        // show money in bank
			printf("------------------------------------------\n");
		}  // else if dm 
		else if(!strcmp(c_in,"cp"))                                      // Change password
		{
			printf("Original password : ");
			scanf("%d",&pass_o);                                 
			printf("--------------------------\n");
			if(pass_o == iu[index].password)                             // check original password
			    {
			    printf("\nQriginal password : %d \n",pass_o);
				printf(" New password :");
				scanf("%d",&iu[index].password);                         // new password 
				file();
				main();
				}else{                                                   // enter wrong password
				printf("\t >>> Error password <<< \n\n");        
				}		 
		} // else if cp  
		else if(!strcmp(c_in,"cm"))                                      // Check money
		{
			printf("Deposit in bank : %.2f \n",iu[index].money);
		}// else cm
		else if(!strcmp(c_in,"wm"))                                      // Withdrow money
		{
			printf("amount withdraw money = ");
			scanf("%f",&m);                                              // input number to deposit
			if(iu[index].money>=m)                                       // check the balance is enough for withdrawal 
			{
				iu[index].money-=m;
			}else{
				printf("Not enough money \n");                           // not enough money in the account
			}
			printf("Deposit in bank : %.2f \n",iu[index].money);	
		}  // else if to
	    else if(!strcmp(c_in,"tm"))                                      // Transfer money
	    {
	    	printf("Account number to be transferred to ");
			scanf("%d",&id_o);
			if(id_o == iu[index].id)                                     // check Don't match your own id
			{
				printf("Error to transferred \n\n");
			}else{
				if(id_o == iu[0].id)                                     // tranferred  1rd user id
				{
					printf("amount transferred money = ");
					scanf("%f",&m);
					if(iu[index].money>=m)                              // check the amount of the account 
					{
					   	iu[index].money-=m;
						iu[0].money+=m;		
					}else{
						printf("Not enough money \n");	
					}
				}
				else if(id_o == iu[1].id)                                // tranferred  2rd user id
				{
					printf("amount transferred money = ");
					scanf("%f",&m);
					if(iu[index].money>=m)                              // check the amount of the account 
					{
					   	iu[index].money-=m;
						iu[1].money+=m;	
					}else{
						printf("Not enough money \n");	
					}
				}
				else if(id_o == iu[2].id)                                // tranferred  3rd user id
				{
					printf("amount transferred money = ");
					scanf("%f",&m);
					if(iu[index].money>=m)                              // check the amount of the account 
					{
					   	iu[index].money-=m;
						iu[2].money+=m;	
					}else{
						printf("Not enough money \n");	
					}
				}else{                                                  // id banking not found
					printf("Bank account number not found please check your number !!! \n");      
				}	
			} // id_o == iu[index].id
		}// else if tm
	} // for(;;)
}// command()

