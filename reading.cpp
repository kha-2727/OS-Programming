#include<iostream>

#include<string.h>

#include<unistd.h>

#include<sys/types.h>

#include<sys/stat.h>

#include<errno.h>

#include<fcntl.h>

using namespace std;
int main() {
  int fd = open("pipe", O_RDONLY);
  int fd1 = open("pipe1", O_RDONLY);
  int fd2 = open("pipe2", O_RDONLY);
  float ass[2];
  float exam[2];
  float lab[2];
  float project[2];
  char grade;
  int fd3 = open("pipe3", O_RDONLY);
  read(fd, ass, sizeof(ass));
  read(fd1, exam, sizeof(exam));
  read(fd2, lab, sizeof(lab));
  read(fd3, project, sizeof(project));
  float ass_obt = ass[0] / ass[1];
  ass_obt = ass_obt * 15;
  float exam_obt = exam[0] / exam[1];
  exam_obt = exam_obt * 40;
  float lab_obt = lab[0] / lab[1];
  lab_obt = lab_obt * 30;
  float project_obt = project[0] / project[1];
  project_obt = project_obt * 15;
  cout << "Assignment " << ass_obt << "/" << ass[1] << endl;
  cout << "Final Exam " << exam_obt << "/" << exam[1] << endl;
  cout << "Labwork " << lab_obt << "/" << lab[1] << endl;
  cout << "Project " << project_obt << "/" << project[1] << endl;
  float total_abs = ass_obt + exam_obt + lab_obt + project_obt;
  cout << "Total " << total_abs << "/100" << endl;
  int totalabs = total_abs;
  if (totalabs >= 90)
    cout << "Grade A+" << endl;
  else if (totalabs >= 86 && totalabs <= 89)
    cout << "Grade A" << endl;
  else if (totalabs >= 82 && totalabs <= 85)
    cout << "Grade A-" << endl;
  else if (totalabs >= 78 && totalabs <= 81)
    cout << "Grade B+" << endl;
  else if (totalabs >= 74 && totalabs <= 77)
    cout << "Grade B" << endl;
  else if (totalabs >= 70 && totalabs <= 73)
    cout << "Grade B-" << endl;
  else if (totalabs >= 66 && totalabs <= 69)
    cout << "Grade C+" << endl;
  else if (totalabs >= 62 && totalabs <= 65)
    cout << "Grade C" << endl;
  else if (totalabs >= 58 && totalabs <= 61)
    cout << "Grade C-" << endl;
  else if (totalabs >= 54 && totalabs <= 57)
    cout << "Grade D+" << endl;
  else if (totalabs >= 50 && totalabs <= 53)
    cout << "Grade D" << endl;
  else if (totalabs <= 49)
    cout << "Grade F" << endl;
  close(fd);
  close(fd1);
  close(fd2);
  close(fd3);
}
