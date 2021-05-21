#include <unistd.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <iostream>

#include <string.h>

using namespace std;

int main() {

  while(1){
  char command[100];
  char * command1[50];
  for (int i = 0; i < 50; i++)
    command1[i] = new char[50];
  cout << "Enter command" << endl;
  cin.getline(command, 100);
  char * store = new char[100];
  int i = 0, l = 0, k = 0;
  while (command[i] != ' ') {
    store[i] = command[i];
    i++;
  }
  int I = i;
  for (I = 0; command[I] != '\0'; I++) {
    k = 0;
    for (int j = 0; command[I] != ' ' && command[I] != '\0'; j++) {
      command1[l][k] = command[I];
      k++;
      I++;
    }
    l++;
    if (command[I] == '\0')
      break;
  }
  command1[l] = NULL;
  for (int m = 0; m < 2; m++)
    cout << command1[m] << endl;
  if (strcmp(store, "quit") == 0) {
    return 0;
  } else {
    pid_t pid = fork();
    if (pid > 0) {
      wait(NULL);
    } 
    else if (pid == 0) {
      execvp(store, command1);
    }
  }
 }
}
