#include<iostream>

#include<unistd.h>

#include<sys/wait.h>

#include<string.h>


using namespace std;

int main(int argc, char * argv[], char * env[]) {

    char *filename = argv[1];
    
    pid_t pid=fork();
    
    	if ( pid > 0){
    		
    		int status=0;
    		wait(&status);
                cout<<endl;
    		if( status == 0){
    			
    			cout<<"            YOHO!!!....Child 1 executed successfully         "<<endl;
    			cout<<endl;
    			pid_t pid1=fork();
    			if(pid1>0){
				
	    			int status1=0;
	    		        wait(&status1);
	    		        if ( status1 == 0)
	    		                cout<<endl;
	    		        	cout<<"            YOHO!!!....Child 2 executed successfully         "<<endl;
				
			}
	    			
	    		else if ( pid1 == 0)
	    		{
				
		    		execl("/usr/bin/wc","wc",filename,NULL);
		    	        exit(-1);
	    		}
			
    		}
    			
    	}
    	else if ( pid == 0){
    	
    		execl("/bin/cat","cat",filename,NULL);
    		exit(-1);
    	}
}
