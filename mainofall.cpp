#include<iostream>

#include<unistd.h>

#include<sys/wait.h>

#include<string.h>


using namespace std;

int
main(int argc, char * argv[], char * env[]) {

  char input[30] = " ";
  cout << "Enter a string " << endl;
  cin >> input;

  pid_t str = fork();

  if (str > 0) {

    wait(NULL);

  } else if (str == 0) {
    pid_t str1 = fork();

    if (str1 > 0) {
      wait(NULL);
        execl("./size", "./size", input, NULL);

    } else if (str1 == 0) {

      pid_t str2 = fork();

      if (str2 > 0)

      {
        wait(NULL);
         execl("./reverse", "./reverse", input, NULL);
      } else if (str2 == 0) {

        pid_t str3 = fork();
        if (str3 > 0) {
          wait(NULL);
           execl("./capital", "./capital", input, NULL);
        } else if (str3 == 0) {
          pid_t str4 = fork();
          if (str4 > 0) {
            wait(NULL);
           execl("./add2", "./add2", input, NULL);
          } else if (str4 == 0) {
             execl("./sort", "./sort", input, NULL);

           
          }

         
        }

      }
     
    }

  }


}


