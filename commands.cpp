#include <iostream>

#include <unistd.h>

#include <string.h>

#include <sys/wait.h>

using namespace std;

int main() {

  int fd[2];
  int fd1[2];
  int fd2[2];
  pipe(fd);
 pipe(fd1);
 pipe(fd2);

  pid_t pid = fork();

  if (pid > 0) {
	    close(fd[1]);
	    wait(NULL);

	    pid_t pid1 = fork();

	    if (pid1 > 0)

	    {
			close(fd[0]);
			 wait(NULL);
			 pid_t pid2 = fork();
			 if (pid2 > 0) {

        close(fd[1]);
        close(fd[0]);
        close(fd1[1]);
        wait(NULL);

        pid_t pid3 = fork();

        if (pid3 > 0)

        {
          close(fd[1]);
          close(fd[0]);
          close(fd1[1]);
          close(fd1[0]);
          close(fd2[1]); close(fd2[0]);
          wait(NULL);
        } else if (pid3 == 0) {
          close(fd[1]);
          close(fd[0]);
          close(fd1[1]);
          close(fd1[0]);
          close(fd2[1]);
          dup2(fd2[0], 0);
      execlp("bash", "bash","-c","wc",NULL);
        }

      } else if (pid2 == 0) {
        close(fd[1]);
        close(fd[0]);
        close(fd1[1]); close(fd2[0]);
        dup2(fd1[0], 0);
        dup2(fd2[1], 1);
          execlp("bash", "bash","-c","sum",NULL);
      }
		  //    close(fd1[0]);
		     
		      
	}

      else if (pid1 == 0)

     {	
	
	      close(fd1[0]);
	      close(fd[1]);
	      close(fd2[0]);
	    close(fd2[1]);
	      dup2(fd[0], 0);
	      dup2(fd1[1], 1);
	     execlp("bash", "bash","-c","sort",NULL);
	   
  	 }
	

  } else if (pid == 0) {
		
	    close(fd[0]);
	      close(fd1[0]);
	   close(fd1[1]);
	   close(fd2[0]);
	   close(fd2[1]);
	    dup2(fd[1], 1);
	  
	    execlp("bash", "bash","-c","grep a *.*",NULL);
	  
  }

}


