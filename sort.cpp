#include<iostream>

#include<cstring>

using namespace std;
int
main(int argc, char * argv[]) {

  char * array = argv[1];

  int sizeofarray = 0;
  int i = 0;
  while (array[i] != '\0') {
    sizeofarray += 1;
    i += 1;
  }
  char temp;
  for (int j = 0; j < sizeofarray; j++) {
    for (int i = 0; i < sizeofarray - 1; i++) {
      if (array[i] > array[i + 1]) {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      } else
        continue;
    }
  }
  cout << "Sorted array:   ";
  for (int i = 0; i < sizeofarray; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
