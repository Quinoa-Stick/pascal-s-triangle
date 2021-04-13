#include <iostream>
//pascal's triangle creator - 4/12/2021

//factorial
int fact(int x) {
  if (x > 0) {
    return x * fact(x - 1);
  } else {
    return 1;
  }
}

int main() {
  //getting the rows
  int size;
  std::cout << "How many layers do you want?" << std::endl;
  std::cin >> size;
  system("clear");
  std::cout << std::endl;

  //creating the square 2D array
  int** pasc = new int* [size];
  for (int i = 0; i < size; i++) {
    pasc[i] = new int[size];
  }

  //populating the array
  for (int i = 0; i < size; i++) {
    int** pascPtr = pasc;
    for (int j = 0 ; j < i || j == i; j++) {
      //pasc[i][j] = i! / (j! * (i - j)!)
      pasc[i][j] = fact(i) / (fact(j) * fact(i - j));
    }
  }

  //printing the array
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d  ", pasc[i][j]);
    }
    std::cout << std::endl;
  }

  //Garbage collection
  delete[] pasc;
}