#include<iostream>
#include<string.h>
#include <bits/stdc++.h>
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
  for (int i = 0; i <= sizeofarray; i++)
    {
      if (array[i] >= 'a' && array[i] <= 'z')
	array[i] -= 32;
    }
     cout<<"Capital Array: ";
  for (int i = 0; i <= sizeofarray; i++)
    cout << array[i];
  cout << endl;

}

