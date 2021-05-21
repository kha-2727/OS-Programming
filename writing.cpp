#include<iostream>

#include<string.h>

#include<unistd.h>

#include<sys/types.h>

#include<sys/stat.h>

#include<errno.h>

#include<fcntl.h>

using namespace std;
int main() {
  if (mkfifo("pipe", 0666) < 0) {
    if (errno != EEXIST)
      cout << "mkfifo failed" << endl;
  }
  if (mkfifo("pipe1", 0666) < 0) {
    if (errno != EEXIST)
      cout << "mkfifo failed" << endl;
  }
  if (mkfifo("pipe2", 0666) < 0) {
    if (errno != EEXIST)
      cout << "mkfifo failed" << endl;
  }
  if (mkfifo("pipe3", 0666) < 0) {
    if (errno != EEXIST)
      cout << "mkfifo failed" << endl;
  }

  float assignment[2];
  float finalexam[2];
  float labwork[2];
  float project[2];
  cout << "Enter sum of all assignments obtained marks" << endl;
  cin >> assignment[0];
  cout << "Enter sum of total marks of all assignments" << endl;
  cin >> assignment[1];
  cout << "Enter final exam obtained marks" << endl;
  cin >> finalexam[0];
  cout << "Enter total marks of finalexam " << endl;
  cin >> finalexam[1];
  cout << "Enter sum of all labwork obtained marks" << endl;
  cin >> labwork[0];
  cout << "Enter sum of all labwork total marks  " << endl;
  cin >> labwork[1];
  cout << "Enter obtained marks of Project" << endl;
  cin >> project[0];
  cout << "Enter  total marks of Project " << endl;
  cin >> project[1];

  int fd = open("pipe", O_WRONLY);
  int fd1 = open("pipe1", O_WRONLY);
  int fd2 = open("pipe2", O_WRONLY);
  int fd3 = open("pipe3", O_WRONLY);
  write(fd, assignment, sizeof(assignment));
  write(fd1, finalexam, sizeof(finalexam));
  write(fd2, labwork, sizeof(labwork));
  write(fd3, project, sizeof(project));

  close(fd);
  close(fd1);
  close(fd2);
  close(fd3);

}
