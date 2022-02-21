#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Asu Simla Ayduran 260822715 
 int main(int argv,char *argc[])   
	                   {
	if((strcmp(argc[1],"SHOW") != 0) && (strcmp(argc[1],"DELETE") != 0) && (strcmp(argc[1],"ADD") != 0))
		 {
	     printf("The Command you requested is invalid please select from one of these SHOW,DELETE,ADD\n");
	         }
	FILE *fo;        
	char c[100];      
	if (strcmp(argc[1],"SHOW") == 0)
		 {
	      fo = fopen("database.csv","r");
	      int i = 1;
              float gpa;
	      int  a;
	while(fgets(c,sizeof(c),fo) != NULL)
	     {
	      char* token = strtok(c, ",");
	      printf("Record %d: ",i );
	      printf("ID=%s ",token );
	      token = strtok(NULL, ",");
	printf("NAME=%s ",token );
	token = strtok(NULL, ",");
        sscanf(token,"%d",&a);
        printf("Age=%d ",a );
        token = strtok(NULL, ",");
        gpa = strtof(token,NULL);
        printf("GPA=%.2f \n",gpa );
         i++;
            }
         fclose(fo);
     }
	 if (strcmp(argc[1],"DELETE") == 0) 
		  {
                  fo = fopen("database.csv","r");
		int flag = 0;	
                FILE *fp3 = fopen("database.tmp","w+"); 
	if(argc[2] == NULL) 
		  {
		printf("Name Of Record to Delete is Missing\n");
		  }
	while(fgets(c,sizeof(c),fo) != NULL)
	{ 
	char temp[100];      
	strcpy(temp,c);    
        char* token = strtok(c, ",");
	if (flag ==0 && strcmp(token,argc[2]) == 0) 									                                                                                       {
		flag = 1;
	}													                      
	else{								  
		fputs(temp,fp3 );					
	            }	
	}
if(flag == 0){
	       printf("Sorry, that user was not found. Nothing was deleted\n");
					                            }
                         fclose(fo); 
			 fclose(fp3); 
			 remove("database.csv"); 
			 rename("database.tmp","database.csv"); 
					                            }
	  if (strcmp(argc[1],"ADD") == 0) 
	{
		fo = fopen("database.csv","a+"); 
		if(argv < 6){      										                      
      	        printf("Missing ID, Name, Age, and GPA arguements\n");																                                           }  
		else{        
			fprintf(fo,"%s,%s,%s,%s\n",argc[2],argc[3],argc[4],argc[5]);
               		}
		fclose(fo);
	}
        }
