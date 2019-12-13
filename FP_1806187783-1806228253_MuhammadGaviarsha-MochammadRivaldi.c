#include <stdio.h>
#include <malloc.h>
#include <string.h>
void clearInput(void);
void addNewcontact(void);
void listAll(void);
void deletecontact(void);
void modifycontact(void);
int findcontact(void);
int prompt(void);
int findnum (int);

typedef struct contact {   
    int number;        
    char name [20];      
    char phone[15];    
    char email[20];  
    char address[20];   
    struct contact *next;  
    int count;      
    } Contact;
Contact *firstc,*currentc,*newc; 
int cnum = 0;
int main()
{
    FILE *datafile;
    char *filename = "contactdatabase.dat"; 
    char ch;
    firstc = NULL;
    datafile = fopen(filename,"r");
    
    if(datafile)	 
    {
	    firstc = (struct contact *)malloc(sizeof(struct contact));
	    currentc = firstc;       
	    while(1) 
     	    {
		    newc = (struct contact *)malloc(sizeof(struct contact));
		    fread(currentc,sizeof(struct contact),1,datafile);
		    if(currentc->next == NULL)   
			 break;
		    currentc->next = newc;       
            	    currentc->count=0;           
		    currentc = newc;            
	    }
	    fclose(datafile);               
	    cnum = currentc->number;         
        
    }
        
    do
    {
	fflush(stdin);
        puts("\nWelcome To The Contact Database");
        puts("-- -----------------------------");
        puts("1 - Add a new contact");     
		puts("2 - Delete contact");          
		puts("3 - List all contacts");       
		puts("4 - Modify contact");          
		puts("5 - Find a contact by name");  
		puts("-- -----------------------------");
        puts("Q - Save and quit\n");         
        printf("\tYour choice:");            
        ch = getchar();
	    ch = toupper(ch);
        switch(ch)     
        {
            case '1':
                puts("Add a new contact\n");
	    	fflush(stdin);
                addNewcontact();
                break;
	    case '2':
		puts("Delete a contact\n");
		deletecontact();
		break;
	    case '3':
		puts("List all contacts\n");
		listAll();
		break;
    	    case '4':
		puts("Modify a contact\n");
		modifycontact();
		break;
	    case '5':
		puts("Find a contact by name\n");
		findcontact();
		break;
            case 'Q':
                puts("Save and quit\n");
                default:
                break;
        }
    }
    while(ch != 'Q');
    currentc = firstc;
    
    if(currentc == NULL)
	    return(0);		
				  
    datafile = fopen(filename,"w");   
    
    if(datafile == NULL)
    {
	    printf("Error writing to %s\n",filename);
	    return(1);
    }
    while(currentc != NULL)
    {
	    fwrite(currentc,sizeof(struct contact),1,datafile);
	    currentc = currentc->next;
    }
    fclose(datafile);             
    return(0);
}
void addNewcontact(void) 
{
    newc = (struct contact *)malloc(sizeof(struct contact)); 
    if(firstc==NULL)
        firstc = currentc = newc;

    else
    {
        currentc = firstc;                
        while(currentc->next != NULL)currentc = currentc->next;
        currentc->next = newc; 
        currentc = newc;  
    }
    cnum++;
    printf("%27s: %5i\n","contact number",cnum);
    currentc->number = cnum;    
    
    printf("%27s: ","Enter contact name");
    gets(currentc->name);
    printf("%27s: ","Enter contact Phone number");
    gets(currentc->phone);
    printf("%27s: ","Enter contact email");
    gets(currentc->email);
    printf("%27s: ","Enter contact address");
    gets(currentc->address);
    
    printf("contact added!");
    currentc->count=0;
    currentc->next = NULL;
}
void listAll(void)
{
    if(firstc==NULL)
        puts("There are no contacts to display!"); 
        
    else
    {
	printf("%6s %-20s %-15s %-15s %-15s\n","Acct#","Name","Phone","Email","Address");
        puts("------ -------------------- ------------- -------------------");           
        currentc=firstc;
        
        do
        {
                printf("%6d: %-20s %-15s %-20s %-20s\n",\
                currentc->number,\
                currentc->name,\
                currentc->phone,\
                currentc->email,\
                currentc->address);        
        }
        
        while((currentc=currentc->next) != NULL);
    }
}
void deletecontact(void)          
{
    int record;
    struct contact *previousa;
    if(firstc==NULL)
    {
        puts("There are no contacts to delete!");
	return;
    }
    
    listAll();		  
    printf("Enter contact account number to delete: ");
    scanf("%d",&record);
    currentc = firstc;
    
    while(currentc != NULL)
    {
        if(currentc->number == record)
	{
	if(currentc == firstc)	
		firstc=currentc->next; 
	else
		previousa->next = currentc->next;
        	free(currentc);
	    	printf("contact %d deleted!\n",record);
	    return;
	}
	
	else
	{
        previousa = currentc;
	    currentc = currentc->next;
	}
    }
    printf("contact %d not found!\n",record);
 }
void modifycontact(void)  
{
    int record, result;
    if(firstc==NULL)
    {
        puts("There are no contacts to modify!");
	return;
    }
    
    listAll();		
    printf("Enter contact account number to modify or change: ");
    scanf("%d",&record);
    result = findnum(record);
    
    if( result >0 ){
	    printf("Contact %d:\n",currentc->number);
	    printf("Name: %s\n",currentc->name);
	    if(prompt())
		    gets(currentc->name);
	    printf("Phone: %s\n",currentc->phone);
	    if(prompt())
		    gets(currentc->phone);
	    printf("Email: %s\n",currentc->email);
	    if(prompt())
		    gets(currentc->email);
		printf("address: %s\n",currentc->address);
	    if(prompt())
		    gets(currentc->address);
	    return;
	}
    printf("contact %d was not found!\n",record);
}
int findnum (int recordnum)
{
    int record;
    record = recordnum;
    currentc = firstc;
    while(currentc != NULL)
    {
                   
        if(currentc->number == record)
	     {
           return 1;
         }
         
	else
	{
	    currentc = currentc->next;
	}
    }
    return -1;   
}
int findcontact(void)
{
     char buff[20];
     
     if(firstc==NULL)
	{
        puts("There are no contacts to find!");
	    return 1;
    }
    
    printf("Enter contact name: ");
    fflush(stdin);
    gets(buff);
    
    currentc = firstc;
    while(currentc != NULL)
    {
        if( strcmp(currentc->name, buff) == 0 )
	    {
	    printf("%6s %-20s %-15s %-15s\n","Acct#","Name","Phone","Email");
            printf("%6d: %-20s %-15s %-20s %-20s \n",\
            currentc->number,\
            currentc->name,\
            currentc->phone,\
            currentc->email,\
            currentc->address);			
			return 0;
	    }
		else
		{
			currentc = currentc->next;
		}
    }
    printf("contact %s was not found!\n",buff);
          return 1;
}   
int prompt(void)
{
	char ch;
    	fflush(stdin);
	printf("Update? (Y to update any other key to not)");
	ch = getchar();
	ch = toupper(ch);
	fflush(stdin);
	if(ch == 'Y')
	{
		printf("Enter new value: ");
		return(1);
	}
	else
		return(0);
}
