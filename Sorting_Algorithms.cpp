#include <iostream>
#include <vector>
#include <sys/time.h>
using namespace std;

void SelectionSort(vector<int>& sortList) {
  int indexSmallest;
  int temp;
  int vectSize = sortList.size();

  for (int i = 0; i < vectSize - 1; ++i) {
   indexSmallest = i;
   for (int j = i + 1; j < vectSize; ++j) {

      if (sortList.at(j) < sortList.at(indexSmallest)) {
         indexSmallest = j;
      }
   }

   temp = sortList.at(i);
   sortList.at(i) = sortList.at(indexSmallest);
   sortList.at(indexSmallest) = temp;
  }
}

void InsertionSort(vector<int>& sortList) {
  int temp;
  int vectSize = sortList.size();

  for (int i = 1; i < vectSize; i++) {
    int j = i;
    while (j > 0 && sortList.at(j) < sortList.at(j - 1)) {
      temp = sortList.at(j);
      sortList.at(j) = sortList.at(j - 1);
      sortList.at(j - 1) = temp;
      j--;
    }
  }
}

void Merge(vector<int>& sortList, int i, int j, int k) {
  int size = k - i + 1;
  int mergePos;
  int left;
  int right;
  vector<int> mergedNumbers(size);

   mergePos = 0;
   left = i;
   right = j + 1;

   while (left <= j && right <= k) {
      if (sortList.at(left) < sortList.at(right)) {
         mergedNumbers.at(mergePos) = sortList.at(left);
         ++left;
      }
      else {
         mergedNumbers.at(mergePos) = sortList.at(right);
         ++right;

      }
      ++mergePos;
   }

   while (left <= j) {
      mergedNumbers.at(mergePos) = sortList.at(left);
      ++left;
      ++mergePos;
   }

   while (right <= k) {
      mergedNumbers.at(mergePos) = sortList.at(right);
      ++right;
      ++mergePos;
   }

   for (mergePos = 0; mergePos < size; ++mergePos) {
      sortList.at(i + mergePos) = mergedNumbers.at(mergePos);
   }
}

void MergeSort(vector<int>& sortList, int i, int k) {
  int j;
  if (i < k) {
    j = (i + k) / 2;

    MergeSort(sortList, i, j);
    MergeSort(sortList, j + 1, k);

    Merge(sortList, i, j, k);
  }
}

int Partition(vector<int>& sortList, int i, int k) {
  int l;
   int h;
   int mid;
   int pivot;
   int temp;
   bool finish;

   mid = i + (k - i) / 2;
   pivot = sortList.at(mid);

   finish = false;
   l = i;
   h = k;

   while (!finish) {

      while (sortList.at(l) < pivot) {
         ++l;
      }

      while (pivot < sortList.at(h)) {
         --h;
      }

      if (l >= h) {
         finish = true;
      }
      else {
         temp = sortList.at(l);
         sortList.at(l) = sortList.at(h);
         sortList.at(h) = temp;

         ++l;
         --h;
      }
   }
  return h;
}

void QuickSort(vector<int>& sortList, int i, int k) {
  int j;

  if (i >= k) {
    return;
  }

  j = Partition(sortList, i, k);

  QuickSort(sortList, i, j);
  QuickSort(sortList, j + 1, k);
}

int main() {
cout << "Selection Sort Times: " << endl;
for (int j = 1000; j <= 100000; j+=10000){
  vector<int> array1(j);
   for(int i=0;i<j;i++)
      array1[i]=rand()%100;  //Generate number between 0 to 99

  timeval timeBefore, timeAfter; // timeval type defined in sys/time.h
  long diffSeconds, diffUSeconds; // elapsed seconds and microseconds
  gettimeofday(&timeBefore, NULL); // get the time before
  SelectionSort(array1);
  gettimeofday(&timeAfter, NULL); // get the time after
  diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec; // elapsed seconds
  diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
  double time = diffSeconds + diffUSeconds / 1000000.0; // total elapsed time
  cout << time << endl;
}
cout << endl;
cout << "Insertion Sort Times: " << endl;
for (int j = 1000; j <= 100000; j+=10000){
  vector<int> array1(j);
   for(int i=0;i<j;i++)
      array1[i]=rand()%100;  //Generate number between 0 to 99

  timeval timeBefore, timeAfter; // timeval type defined in sys/time.h
  long diffSeconds, diffUSeconds; // elapsed seconds and microseconds
  gettimeofday(&timeBefore, NULL); // get the time before
  InsertionSort(array1);
  gettimeofday(&timeAfter, NULL); // get the time after
  diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec; // elapsed seconds
  diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
  double time = diffSeconds + diffUSeconds / 1000000.0; // total elapsed time
  cout << time << endl;
}
cout << endl;
cout << "Merge Sort Times: " << endl;
for (int x = 1000; x <= 100000; x+=10000){
  vector<int> array1(x);
   for(int i=0;i<x;i++)
      array1[i]=rand()%100;  //Generate number between 0 to 99

  timeval timeBefore, timeAfter; // timeval type defined in sys/time.h
  long diffSeconds, diffUSeconds; // elapsed seconds and microseconds
  gettimeofday(&timeBefore, NULL); // get the time before
  MergeSort(array1, 0, x-1);
  gettimeofday(&timeAfter, NULL); // get the time after
  diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec; // elapsed seconds
  diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
  double time = diffSeconds + diffUSeconds / 1000000.0; // total elapsed time
  cout << time << endl;
}
cout << endl;
cout << "Quick Sort Times: " << endl;
for (int x = 1000; x <= 100000; x+=10000){
  vector<int> array1(x);
   for(int i=0;i<x;i++)
      array1[i]=rand()%100;  //Generate number between 0 to 99

  timeval timeBefore, timeAfter; // timeval type defined in sys/time.h
  long diffSeconds, diffUSeconds; // elapsed seconds and microseconds
  gettimeofday(&timeBefore, NULL); // get the time before
  QuickSort(array1, 0, x-1);
  gettimeofday(&timeAfter, NULL); // get the time after
  diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec; // elapsed seconds
  diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
  double time = diffSeconds + diffUSeconds / 1000000.0; // total elapsed time
  cout << time << endl;
}

}
