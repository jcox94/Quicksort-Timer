#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;

float randFloat() {
  float random = ((float) rand()) / (float) RAND_MAX;
  return random;
}

void genFiles(int size) {
  ofstream output;
  for(int i = 1; i < 101; i++) {
    std::string name = "output_" + std::to_string(i) + ".txt";
    output.open("InputFiles/" + std::to_string(size) + "/" + name);
    for(int i = 0; i < size; i++){
      output << randFloat() << " ";
    }
    output.close();
  }
}

int main() {
  srand (time(NULL));
  genFiles(10);
  genFiles(100);
  genFiles(1000);
  genFiles(10000);
  genFiles(100000);
  return 0;
}

