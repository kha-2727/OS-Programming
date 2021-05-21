#include<iostream>
#include<cstring>

using namespace std;
int
main (int argc, char *argv[])
{
  char *array = argv[1];
  int sizeofarray = 0;
  int i = 0;
  
  while (array[i] != '\0')
    {
      sizeofarray += 1;
      i += 1;
    }
  cout <<"Length of string: " <<i;
  cout << endl;

}

