#include<iostream>

#include<unistd.h>

#include<sys/types.h>

#include<sys/wait.h>

using namespace std;
int main() {

  cout << "let's print my name using fork" << endl;

  pid_t pidK = fork();

  if (pidK > 0) {
    int statusk;
    wait( & statusk);
    statusk = statusk / 256;
    cout << "This node has no parent  " << " node:K " << "Child: H " << "PId: " << getpid() << "  " << "ASCII :75" << endl;
    statusk += 75;

    pid_t pidS = fork();
    if (pidS > 0) {
      int statusK;
      wait( & statusK);
      statusK = statusK / 256;
      statusk = statusK + statusk;
      cout << "This node has no parent  " << " Node:K " << "Child S " << "PId " << getpid() << "  " << "ASCII :75" << endl;

    } else if (pidS == 0)

    {
      pid_t pidT = fork();

      if (pidT > 0)

      {
        int statuss;
        wait( & statuss);
        statuss = statuss / 256;
        cout << "PPID  " << getppid() << " Node:S " << "Child  T" << "PId " << getpid() << "  " << "ASCII :83" << endl;
        statuss += 83;

        pid_t pidN = fork();
        if (pidN > 0) {
          int statusN;
          wait( & statusN);
          statusN = statusN / 256;
          statusN += statuss;
          cout << "PPID: " << getppid() << " " << " Node:S " << "Child N " << "PId: " << getpid() << "  " << "ASCII :83" << endl;
          exit(statusN);
        }

        if (pidN == 0) {
          cout << "PPID  " << getppid() << " Node:N " << "Child none " << "PId: " << getpid() << "  " << "ASCII :78" << endl;
          exit(78);

        }
        exit(statuss);
      } else if (pidT == 0) {
        pid_t pidZ = fork();

        if (pidZ > 0) {
          int statusz;
          wait( & statusz);
          statusz = statusz / 256;
          cout << "This node has no parent  " << " Node:T " << "Child Z" << "PId: " << getpid() << "  " << "ASCII :84" << endl;
          statusz += 84;
          exit(statusz);
        } else if (pidZ == 0) {
          cout << "PPID: " << getppid() << " Node:Z " << "Child none " << "PId: " << getpid() << "  " << "ASCII :90" << endl;
          exit(90);

        }

      }

    }
    cout << "Sum of all ASCII characters = " << statusk;
    cout << endl;
  } else if (pidK == 0) {

    pid_t pidH = fork();

    if (pidH > 0) {
      int statush;
      wait( & statush);
      statush = statush / 256;
      statush += 72;
      cout << "PPID: " << getppid() << " " << " Node:H " << "Child A " << "PId " << getpid() << "  " << "ASCII :72" << endl;

      pid_t pidJ = fork();
      if (pidJ > 0) {
        int statusH;
        wait( & statusH);
        statusH = statusH / 256;
        statush += statusH;
        cout << "PPID: " << getppid() << " " << " Node:H " << "Child J " << "PId " << getpid() << "  " << "ASCII :72" << endl;
        exit(statush);
      }
      if (pidJ == 0) {

        pid_t pidi = fork();

        if (pidi > 0) {
          int statusj;
          wait( & statusj);
          statusj = statusj / 256;
          cout << "PPID: " << getppid() << " " << " Node:J " << "Child I " << "PId " << getpid() << "  " << "ASCII :74" << endl;
          statusj += 74;
          exit(statusj);
        } else if (pidi == 0) {
          cout << "PPID: " << getppid() << " " << " Node:I " << "Child none " << "PId " << getpid() << "  " << "ASCII :73" << endl;
          cout << endl;
          exit(73);
        }
      }
      exit(statush);
    } else if (pidH == 0) {

      pid_t pidA = fork();

      if (pidA > 0) {
        int statusa;
        wait( & statusa);
        statusa = statusa / 256;
        cout << "PPID: " << getppid() << " " << " Node:A " << "Child A " << "PId " << getpid() << "  " << "ASCII :65" << endl;
        statusa += 65;
        exit(statusa);

      } else if (pidA == 0) {
        pid_t pida1 = fork();

        if (pida1 > 0) {
          int statusa1;
          wait( & statusa1);
          statusa1 = statusa1 / 256;
          cout << "PPID: " << getppid() << " " << " Node:A " << "Child A " << "PId " << getpid() << "  " << "ASCII :65" << endl;
          statusa1 += 65;
          exit(statusa1);
        } else if (pida1 == 0) {
          pid_t pida2 = fork();

          if (pida2 > 0) {
            int statusa2;
            wait( & statusa2);
            statusa2 = statusa2 / 256;
            cout << "PPID: " << getppid() << " " << " Node:A " << "Child A " << "PId " << getpid() << "  " << "ASCII :65" << endl;
            statusa2 += 65;
            exit(statusa2);
          } else if (pida2 == 0) {
            pid_t pida3 = fork();

            if (pida3 > 0) {
              int statusa3;
              wait( & statusa3);
              statusa3 = statusa3 / 256;
              cout << "PPID: " << getppid() << " " << " Node:A " << "Child A " << "PId " << getpid() << "  " << "ASCII :65" << endl;
              statusa3 += 65;
              exit(statusa3);
            } else if (pida3 == 0) {
              pid_t pida4 = fork();

              if (pida4 > 0) {
                int statusa4;
                wait( & statusa4);
                statusa4 = statusa4 / 256;
                cout << "PPID: " << getppid() << " " << " Node:A " << "Child B " << "PId " << getpid() << "  " << "ASCII :65" << endl;
                statusa4 += 65;
                exit(statusa4);
              } else if (pida4 == 0) {
                cout << "PPID: " << getppid() << " " << " Node:B " << "Child none " << "PId " << getpid() << "  " << "ASCII :66" << endl;
                cout << endl;
                exit(66);

              }
            }

          }
        }

      }
    }
  }
}
