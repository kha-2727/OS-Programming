#include<iostream>

#include<fstream>

#include <unistd.h>

#include <string.h>

#include<sstream>
 //#include <fcntl.h >  	//must use also while doing file handling
#include <sys/wait.h>

#include<vector>

#include<algorithm>

using namespace std;

string findcomb(char comb[], int size)

{
  vector < string > stringholder;
  comb[size] = '\0';
  for (int i = 0; i < size; i++) {
    if (comb[i] == ',')
      comb[i] = ' ';
  }
  string str, str1;
  str.append(comb);

  for (int i = 0; i < size; i++) {
    if (str[i] == ' ') {
      stringholder.push_back(str1);
      str1 = " ";
    } else
      str1 += str[i];
  }

  int vector_size = stringholder.size();

  int k = 1;
  vector < string > stringholder1;
  // for(int i=0;i<vector_size;i++)             
  //                cout<<stringholder[i];//<<endl;
  string str3 = " ";
  for (int i = 0; i < vector_size; i++) {

    while (k < vector_size) {
      if (stringholder[i] != " " && stringholder[k] != " ") {
        string str2 = stringholder[i] + "," + stringholder[k] + " ";
        str3 += str2;

      }
      k++;
    }
    k = i + 2;
  }

  return str3;

}

int main(int argc, char * argv[]) {

  if (argv[1] == NULL)
    cout << "please enter a file name" << endl;
  char fullfile[500];
  int j = 0, i = 0, count = 0;
  int fd[2];
  int fd1[2];
  pipe(fd);
  pipe(fd1);
  ifstream myfile(argv[1]);
  string fileline;
  float supportthreshold, transaction, threshold;
  pid_t pid = fork();
  if (pid > 0) {
    close(fd[0]);
    close(fd1[0]);
    while (getline(myfile, fileline)) {
      count += 1;
      while (fileline[j] != '\0') {
        fullfile[i] = fileline[j];
        j++;
        i++;
      }
      if (count == 1)
        supportthreshold = stof(fileline);
      else if (count == 2)
        transaction = stof(fileline);
      fullfile[i] = ' ';
      i += 1;
      j = 0;

    }
    fullfile[i] = '\0';
    threshold = supportthreshold * transaction;
    write(fd[1], & threshold, sizeof(threshold));
    write(fd1[1], fullfile, strlen(fullfile) + 1);
    close(fd[1]);
    close(fd1[1]);
    wait(NULL);
  } else if (pid == 0) {
    char fullfile1[500];
    char words[] = " ";
    char fullfile2[500];
    close(fd[1]);
    float threshold1;
    close(fd1[1]);
    read(fd[0], & threshold1, sizeof(threshold1));
    read(fd1[0], fullfile1, sizeof(fullfile1));
    close(fd[0]);
    close(fd1[0]);
    strcpy(fullfile2, fullfile1);

    string word = " ";
    vector < string > stringholder;
    int i = 0, j = 0, k = 0;

    bool flag = 0;

    for (i = 0; fullfile1[i] != '\0'; i++) {
      if (fullfile1[i] == ',')
        fullfile1[i] = ' ';
    }
    string str(fullfile1);
    istringstream is(str);
    while (is >> word) stringholder.push_back(word);

    sort(stringholder.begin(), stringholder.end());
    int vectorsize = stringholder.size();
    int wordcount = 1;
    int size = vectorsize - 2;
    int l = 0;
    word = stringholder[2];
    cout << "Items  Frequency" << endl;
    for (int i = 3; i < vectorsize; i++) {
      if (word != stringholder[i]) {
        cout << word << "    " << wordcount << endl;

        wordcount = 0;
        word = stringholder[i];
      }
      wordcount++;
    }
    cout << word << "   " << wordcount << endl;
    cout << endl;

    cout << "  .......Now displaying items that have frequency greater than " << threshold1 << "........" << endl;
    cout << endl;
    cout << "Items  Frequency" << endl;
    int integer[vectorsize];
    int index = 0;
    wordcount = 1;
    vector < string > str1;
    string str2;
    for (int i = 3; i < vectorsize; i++) {
      if (word != stringholder[i]) {
        if (wordcount >= threshold1) {
          cout << word << "   " << wordcount << endl;
          integer[index] = wordcount;
          index++;
          str2 += word;
          str2 += " ";
        }
        wordcount = 0;
        word = stringholder[i];

      }
      wordcount++;
    }
    if (wordcount >= threshold1) {
      str2 += " ";
      integer[index] = wordcount;
      index++;
      cout << word << "   " << wordcount << endl;
      str2 += word;
    }
    integer[index] = '\0';
    int lengthofarray = index;
    index = 0;
    int length = str2.length();
    char chararr[length + 1];
    chararr[length + 1] = '\0';
    strcpy(chararr, str2.c_str());

    int fd2[2];
    int fd3[2];
    int fd4[2];
    int fd5[2];
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);
    pipe(fd5);

    pid_t pid1 = fork();

    if (pid1 > 0) {

      close(fd2[0]);
      close(fd3[0]);
      close(fd4[0]);
      close(fd5[0]);
      write(fd2[1], fullfile2, strlen(fullfile2) + 1);
      write(fd3[1], & threshold1, sizeof(threshold1));
      write(fd4[1], chararr, strlen(chararr) + 1);
      write(fd5[1], integer, sizeof(integer));
      close(fd2[1]);
      close(fd3[1]);
      close(fd4[1]);
      close(fd5[1]);

      wait(NULL);

    } else if (pid1 == 0) {

      string word1 = " ";
      string word2 = " ";
      vector < string > stringholder2;
      vector < string > stringholder3;
      vector < string > stringholder1;
      char transactions[500];
      float threshold2;
      char f_elements[length + 1];
      int frequencies[lengthofarray]; //felements are that having frequency >3    
      frequencies[lengthofarray] = '\0';
      close(fd2[1]);
      close(fd3[1]);
      close(fd4[1]);
      close(fd5[1]);
      read(fd2[0], transactions, sizeof(transactions));
      read(fd3[0], & threshold2, sizeof(threshold2));
      read(fd4[0], f_elements, sizeof(f_elements));
      read(fd5[0], frequencies, sizeof(frequencies));
      close(fd2[0]);
      close(fd3[0]);
      close(fd4[0]);
      close(fd5[0]);

      int k = 1;
      int jay = 0;
      for (jay = 0; transactions[jay] != '\0'; jay++) {

        if (transactions[jay] == ' ' && transactions[jay - 1] == ',')
          transactions[jay] = ',';
        if (transactions[jay] >= '0' && transactions[jay] <= '9' || transactions[jay] == '.')
          transactions[jay] = ' ';
      }

      istringstream is1(f_elements);
      while (is1 >> word1)
        stringholder1.push_back(word1);
      int vector_size = stringholder1.size();

      for (int i = 0; i < vector_size; i++) {

        while (k < vector_size) {
          string str2 = " " + stringholder1[i] + "," + " " + stringholder1[k];
          stringholder2.push_back(str2);
          string str3 = " " + stringholder1[k] + "," + " " + stringholder1[i];
          stringholder3.push_back(str3);
          k++;
        }
        k = i + 2;
      }
      int strholder2 = stringholder2.size();

      char comb[500] = " ";
      int index = 0;
      int array[strholder2];
      for (int j = 0; j < strholder2; j++)
        array[j] = 0;
      for (jay = 0; transactions[jay] != '\0'; jay++) {

        if (transactions[jay] != ' ') {
          comb[index] = transactions[jay];
          index += 1;
        } else if (transactions[jay] == ' ' && transactions[jay - 1] != ' ') {
          comb[index] = transactions[jay];
          index += 1;
          string str_1 = findcomb(comb, index);
          index = 0;
          vector < string > stringholder4;
          string scr = " ";
          int vindex = 0;

          for (int i = 1; str_1[i] != '\0';) {

            if (str_1[i] == ' ' && str_1[i - 1] != ',') {

              stringholder4.push_back(scr);

              for (int l = 0; l < strholder2; l++) {

                if (stringholder4[vindex] == stringholder2[l] || stringholder4[vindex] == stringholder3[l]) {
                  array[l] += 1;

                }
              }

              vindex += 1;
              scr = " ";
              i++;
            } else {
              scr += str_1[i];
              i++;
            }

          }

        }

      }
      cout << endl;
      cout << endl;
      cout << "     Pair      " << "  Frequency     " << endl;
      for (int i = 0; i < strholder2; i++) {
        cout << stringholder3[i] << "       " << array[i] << endl;
      }

      cout << endl;
      cout << endl;
      cout << "  ......Removing Item Pair Having Frequency below  " << threshold1 << "......." << endl;
      cout << endl;
      cout << "     Pair      " << "  Frequency     " << endl;
      for (int i = 0; i < strholder2; i++) {
        if (array[i] >= threshold1)
          cout << stringholder3[i] << "       " << array[i] << endl;
      }

    }
  }
}
