#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

int partition(vector<float> & a, int left, int right) {
  int i = left;
  float pivot = a[left];
   for(int j = left + 1; j < right; j++) {
    if(a[j] <= pivot) {
      i++;
      swap(a[i],a[j]);
    }
  }
  swap(a[i],a[left]);
  return i;
}

void quickSort(vector<float> & a, int left, int right) {
  if(left < right) {
    int s = partition(a, left, right);
    quickSort(a, left, s);
    quickSort(a, s + 1, right);
}
}

void readFiles(int size, ofstream& output, ofstream& averageTable) {
  double average;
  for(int i = 1; i < 101; i++) {
    vector<float> inputVector;
    ifstream input;
    input.open("InputFiles/" + to_string(size) + "/output_" + to_string(i) + "/");
    float j;
    while(input >> j) {
      inputVector.push_back(j);
    }
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    quickSort(inputVector, 0, inputVector.size());
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    output << size << "\t" << "\t" << duration.count() << "\n";
    input.close();
    average += duration.count();
  }
  average = average / 100;
  averageTable << size << "\t" << "\t" << average << "\n";
}

int main() {
  ofstream output, averageTable;
  output.open("Cox_Jacob_executionTime.txt", ios_base::app);
  output << "Input Size" << "\t" << "execution Time\n";
  averageTable.open("Cox_Jacob_averageExecutionTime.txt", ios_base::app);
  averageTable << "Input Size" << "\t" << "Average Execution Time\n";
  readFiles(10, output, averageTable);
  readFiles(100, output, averageTable);
  readFiles(1000, output, averageTable);
  readFiles(10000, output, averageTable);
  readFiles(100000, output, averageTable);
  output.close();
  averageTable.close();
  return 0;
}
