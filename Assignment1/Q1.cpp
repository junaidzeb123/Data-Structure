#pragma once
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<cmath>

using namespace std;
/*
    Question #1b
    note:The time for falling array with random value is also included here.
       Size         timewBySwap     TimeByrightShift
       100          1ms             1ms
       1000         3ms             3ms
       5000         58ms            67ms
       10000        247ms           370ms

       so from the chart above we can see that upto the size of 4000/4500 the time taken by both of the
       functions reamain same. however  above this maxsortwithSwap performs very better.
       hence the crossOver size is almost 5000
        
    */

/*
    Question # 2b

    if r < n^2 then we will not the items in B which are greater the n^2 because the num of number greater then n^2 can 
    never be less than n^2.
    The algorihm ramains same as i am still not checking the items which are greater then r.


*/

template<class T>
bool isSortedDescending(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] < arr[i]) {
            return false; 
        }
    }
    return true; 
}
template<class T>
class ArrayBasics
{
public:
    ArrayBasics();
    ~ArrayBasics();

  
    static T findMax(T A[], int i, int j);
    static T findMin(T A[], int i, int j);
    static T findMinPos(T A[], int i, int j);
    static T findMaxPos(T A[], int i, int j);
    static void swap(T A[], int i, int j);
    static void shiftRight(T A[], int i, int j);
    static void shiftLeft(T A[], int i, int j);
    static T* createRandomArray(int size, int min, int max);
    static T** createRandomMatrix(int rows, int cols, int min, int max);
    static T* copyArray(T A[], int size);
    static T** copyMatrix(T **A, int rows, int cols);
    static T findInArray(T A[], T q, int size);
    static T findInSortedArray(T A[], T q, int size);
    static T findFirstInSortedArray(T A[], T q, int size);
private:

};

template<class T>
ArrayBasics<T>::ArrayBasics()
{
}

template<class T>
ArrayBasics<T>::~ArrayBasics()
{
}

template<class T>
T ArrayBasics<T>::findMax(T A[], int i, int j) {
    T max = A[i];
    for (int counter = i+1; counter <= j; counter++) {
        if (A[counter] >= max)
            max = A[counter];
    }
    return max;
}


template<class T>
T ArrayBasics<T>::findMaxPos(T A[], int i, int j) {
    T max = A[i];
    T maxIndex = i;
    for (int counter = i + 1; counter <= j; counter++) {
        if (A[counter] >= max) {
            max = A[counter];
            maxIndex = counter;
        }
    }
    return maxIndex;
}


template<class T>
T ArrayBasics<T>::findMin(T A[], int i, int j) {
    T min = A[i];
    for (int counter = i + 1; counter <= j; counter++) {
        if (A[counter] < min)
            min = A[counter];
    }
    return min;
}

template<class T>
T ArrayBasics<T>::findMinPos(T A[], int i, int j) {
    T min = A[i];
    T minIndex = i;
    for (int counter = i + 1; counter <= j; counter++) {
        if (A[counter] < min) {
            min = A[counter];
            minIndex = counter;
        }
    }
    return minIndex;
}

template<class T>
void ArrayBasics<T>::swap(T A[], int i, int j) {
    T temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template<class T>
void ArrayBasics<T>::shiftRight( T A[], int i, int j) {
    for (int counter = j ; counter > i; counter--) {
        A[counter] = A[counter - 1];
    }
}

template<class T>
void ArrayBasics<T>::shiftLeft(T A[], int i, int j) {
   
   
    for (int counter = i; counter < j; counter++) {
        A[counter] = A[counter + 1];
       
    }

  
}

template<class T>
T* ArrayBasics<T>::createRandomArray(int size, int min, int max) {
    srand(time(0));
    T* arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % max;
        if (arr[i] < min && arr[i] > (max - min)) {
            arr[i] = arr[i] + (max - min);
        }
        else if (arr[i] < min) {
            arr[i] = arr[i]+ (min);
        }
    }
    return arr;
 }

template<class T>
 T** ArrayBasics<T>:: createRandomMatrix(int rows, int cols, int min, int max) {
     T** arr = new T * [rows];
     for (int i = 0; i < rows; i++) {
         arr[i] = new T[cols];
         for (int j = 0; j < cols; j++) {
             arr[i][j] = rand() % max;
             if (arr[i][j] < min && arr[i][j] > (max - min)) {
                 arr[i][j] = arr[i][j] + (max - min);
             }
             else if (arr[i][j] < min) {
                 arr[i][j] = arr[i][j] + ( min);
             }
         }
     }
     return arr;
}

 template<class T>
 T* ArrayBasics<T>::copyArray(T A[], int size) {
     T* arr = new T[size];
     for (int i = 0; i < size; i++)
         arr[i] = A[i];
     return arr;
  }
 template<class T>
 T** ArrayBasics<T>::copyMatrix(T **A, int rows, int cols) {
     T** arr = new T * [rows];
     for (int i = 0; i < rows; i++) {
         arr[i] = new T[cols];
         for (int j = 0; j < cols; j++) {
             arr[i][j] = A[i][j];
         }
     }
     return arr;
 }

 template<class T>
 T ArrayBasics<T>::findInArray(T A[], T q, int size) {
      for (int i = 0; i < size; i++) {
          if (A[i] == q)
              return i;
      }
      return -1;
 }

 template<class T>
  T ArrayBasics<T>::findInSortedArray(T A[], T q, int size) {
     
      int left = 0;
      int right = size - 1;
      while (left < right)
      { 
          int mid = (left + right) / 2;
          if (A[mid] == q)
              return mid;
          else if (q < A[mid])
              right = mid - 1;
          else
              left = mid + 1;


      }
      return -1;
      

 }

   template<class T>
   T ArrayBasics<T>::findFirstInSortedArray(T A[], T q, int size) {
       int left = 0;
       int right = size - 1;
       int result = -1;
       while (left < right)
       {
           int mid = (left + right) / 2;
           if (A[mid] == q) {
               result = mid;
               right = mid ;
           }
             
           else if (q < A[mid])
               right = mid - 1;
           else
               left = mid + 1;


       }
       return result;
   }





   template <class T>
   void shiftRight(T A[], int i, int j) {
        int temp = A[j];
       for (int k = j -1; k >= i; k--) {
           A[k + 1] = A[k];
       }
       A[i] = temp;
   }

   template <class T>
   void swap(T A[], int i, int j) {
       T temp = A[i];
       A[i] = A[j];
       A[j] = temp;
   }
   template <class T>
   class ArrayUtility{
   public:
       static void maxSortWithShiftRight(T A[], int size);
       static void maxSortWithSwap(T A[], int size);
   };

  
   template <class T>
   void ArrayUtility<T>::maxSortWithShiftRight(T A[], int size) {
      
       for (int i = 0; i < size; i++) {
           T max = A[i];
           int maxIndex = i;
           int j = i+1;
           for (; j < size; j++) {
               if (A[j] > max) {
                   max = A[j];
                   maxIndex = j;
               }
           }
           shiftRight(A, i, maxIndex);
           
       }
      
    }

   template <class T>
   void ArrayUtility<T>::maxSortWithSwap(T A[], int size) {

       for (int i = 0; i < size; i++) {
           T max = A[i];
           int maxIndex = i;
           int j = i + 1;
           for (; j < size; j++) {
               if (A[j] > max) {
                   max = A[j];
                   maxIndex = j;
               }
           }
       
           shiftRight(A, i, maxIndex);
          
       }

   }



   template <class T>
   class WarehouseAlgorithm {
   public:
       static bool hasClosePair(int B[], int n, int r);
   };

   template <class T>
   bool WarehouseAlgorithm<T>::hasClosePair(int B[], int n, int r) {
       T* values = new T[r+1];

       for (int i = 0; i <= r; i++) {
           values[i] = -1;
       }


       for (int i = 0; i < n; i++) {
           if (B[i] <= r) {
               values[B[i]] = i;
           }
       }
   
      
       for (int i = 0; i <= r; i++) {
           if (values[i] >= 0 ) {
               int sum = values[i] - (  values[r-i]);
               if (sum < 0) {
                   sum = -1 * sum;
               }
        
               if ( (B[values[i]] + B[values[r - i]] == r) && (sum < n / 10) &&  (values[i] != values[r - i]) ) {
                
                   return true;
                }
               
           }
       }
     
       delete values;
       return false;
   }

  

  
   int max(int num1, int num2) {
       if (num1 > num2)
           return num1;
       return num2;
   }


 /*
 template <class T>
   T maximizeProfit(T m, T n, T a[], T p[], T s){

{
           int** my2dArray = new int* [n + 1];
           for(int count = 0 ;count < n+1; count++)
               my2dArray[count] = new int[m + 1];

           for (int count = 0; count <= n; count++) {
               for (int InnerCount = 0; InnerCount <= m; InnerCount++) {
                   if (count == 0 || InnerCount == 0) {
                       my2dArray[count][InnerCount] = 0;
                   }
                   else if (a[count - 1] <= InnerCount) {
                       int first = my2dArray[count - 1][InnerCount];
                       int second = my2dArray[count - 1][InnerCount - a[count - 1]] + p[count - 1];

                       my2dArray[count][InnerCount] = max( first ,second);
                   }
                   else {
                       my2dArray[count][InnerCount] = my2dArray[count - 1][InnerCount];

                   }
               
               }
              
           }
       
          
           int TotalSaleMadeByTon = my2dArray[n][m];
           int BarrelsWhichAreNotSold = m;
           for (int i = n, j = m; i > 0 && j > 0; i--) {
               if (my2dArray[i][j] != my2dArray[i - 1][j]) {
                   BarrelsWhichAreNotSold -= a[i - 1];
                   j -= a[i - 1];
               }
           }

          
           
           int CostForStoringLeftOil = s * (BarrelsWhichAreNotSold);
           int ProfitMakeByTon = TotalSaleMadeByTon - CostForStoringLeftOil;

           return ProfitMakeByTon;
       }

      


   }
   */
   template <class T>
   T maximizeProfit(T m, T n, T a[], T p[], T s) {
       int** my2dArry = new int* [n + 1];
       for (int i = 0; i < n + 1; i++) {
           my2dArry[i] = new int[m + 1];
       }

       for (int i = 0; i < n + 1; i++) {
           for (int j = 0; j < m + 1; j++) {
               if(i == 0 || j == 0) {
                   my2dArry[i][j] = 0;
               }else if(my2dArry[i-1][j] <= j){
                   int first = my2dArry[i - 1][j - a[i - 1] + p[i - 1]];
                   int secod = my2dArry[i - 1][j];
                   my2dArry[i][j] = max(first, secod);
               }
               else {
                   my2dArry[i][j] = my2dArry[i - 1][j];
               }
           }
       }

       int totalsale = my2dArry[n][m];
       int barelnotSold = m;
       for (int i = n, j = m; j >= 0 && i >= 0; i++) {
           if (my2dArry[i][j] != my2dArry[i - 1][j]) {
               barelnotSold -= a[i - 1];
               j -= a[i - 1];
           }
       }
       int maxProft = totalsale - (s * barelnotSold);
       return maxProft;
   }

   template <class T>
   void mergeBookingSchedules(T R1[][2], int n1, T R2[][2], int n2, T mergedSchedule[][3], int& m) {
       T* startTimes = new T[n1 + n2];
       T* endTimes = new T[n1 + n2];

       int noofTimeStamps = (n1 + n2) * 2;
       T* TimeStamps = new T[noofTimeStamps];


       int index = 0;
       for (int i = 0; i < n1; i++) {
           TimeStamps[index++] = R1[i][0];
           TimeStamps[index++] = R1[i][1];
         
       } 
       for (int i = 0; i < n1; i++) {
           TimeStamps[index++] = R2[i][0];
           TimeStamps[index++] = R2[i][1];
         
       }

       int minTime = TimeStamps[0];
       int maxTime = TimeStamps[0];
       for (int i = 1; i < (n1 + n2)*2; i++) {
           if (minTime > TimeStamps[i]) {
               minTime = TimeStamps[i];

           }
           if (maxTime < TimeStamps[i]) {
               maxTime = TimeStamps[i];
           }
         
       }

       T* TimeStamp2 = new T[maxTime + 1];
    
       for (int i = 0;i < (maxTime + 1); i++) {
           TimeStamp2[i] = -1;
          
       }
       for (int i = 0; i < (n1+n2)*2; i++) {
           TimeStamp2[TimeStamps[i]] = TimeStamps[i];
       }
       
        index = 0;
       for (int i = 0; i < maxTime + 1; i++) {
           if (TimeStamp2[i] >= 0) {
               if(i == 0)
               TimeStamps[index++] = TimeStamp2[i];
               else if(TimeStamp2[i] > TimeStamp2[i-1])
                   TimeStamps[index++] = TimeStamp2[i];
            }
       }
       
       T** FinalScdule = new T * [index - 1];
       for (int i = 0; i < index - 1; i++) {
           FinalScdule[i] = new T[3];
       }
       int totalNoOfintervals = 0;
       for (int i = 0; i < index - 1; i++) {
           FinalScdule[i][1] = TimeStamps[i];
           FinalScdule[i][2] = TimeStamps[i+1];
           totalNoOfintervals++;
       }
       
     
      

       T* StartTimes = new T[n1+n2];
       T* EndTimes = new T[n1 + n2];
        int index2 = 0;
       for (int i = 0; i < n1 ; i++) {
           StartTimes[index2] = R1[i][0];
           EndTimes[index2] =    R1[i][1];
           index2++;

       } 
       for (int i = 0; i < n2 ; i++) {
           StartTimes[index2] = R2[i][0];
           EndTimes[index2] = R2[i][1];
           index2++;
       }
       int maxFromStart = StartTimes[0];
       int maxFromEnd = EndTimes[0];
       for (int i = 0; i < n1 + n2; i++) {
           if (maxFromStart < StartTimes[i]) {
               maxFromStart = StartTimes[i];
           }
           if (maxFromEnd < EndTimes[i]) {
               maxFromEnd = EndTimes[i];
           }
       }
       T* StartTimes2 = new T[maxFromStart+1];
       T* EndTimes2 = new T[maxFromEnd+1];
       int* NoOfOccurenceofStartTime = new int[maxFromStart + 1];
       int* NoOfOccurenceofEndTime = new int[maxFromEnd + 1];
       for (int i = 0; i <  maxFromStart + 1; i++) {
           StartTimes2[i] = -1;
           NoOfOccurenceofStartTime[i] = 0;
       }
       for (int i = 0;i< maxFromEnd + 1; i++) {
           EndTimes2[i] = -1;
           NoOfOccurenceofEndTime[i] = 0;
       }
       for (int i = 0; i < n1+n2; i++) {
           StartTimes2[StartTimes[i]] = StartTimes[i];
           NoOfOccurenceofStartTime[StartTimes[i]]++;
           EndTimes2[EndTimes[i]] = EndTimes[i];
           NoOfOccurenceofEndTime[EndTimes[i]]++;


       }
     

       int* RoomCounts = new int[totalNoOfintervals];
       int indexOfRoomCounts = 0;
       int currentNoOfRooms = 0;
       for (int i = 0; i < maxFromStart + 1; i++) {
           if (StartTimes2[i] == -1 && EndTimes2[i] == -1) {
               continue;
           }
           else if (StartTimes2[i] == -1 && EndTimes2[i] != -1) {
               if (currentNoOfRooms != 0)
                   currentNoOfRooms-= NoOfOccurenceofEndTime[i];
               RoomCounts[indexOfRoomCounts++] = currentNoOfRooms;

           }
           else if (StartTimes2[i] != -1 && EndTimes2[i] == -1) {
               currentNoOfRooms+= NoOfOccurenceofStartTime[i];
               RoomCounts[indexOfRoomCounts++] = currentNoOfRooms;
           }
           else if (StartTimes2[i] != -1 && EndTimes2[i] != -1) {
               RoomCounts[indexOfRoomCounts++] = currentNoOfRooms;
           }
           
           
          
       }

 
       m = 0;
       for (int i = 0; i < indexOfRoomCounts; i++) {
           FinalScdule[i][0] = RoomCounts[i];
           if (RoomCounts[i] != 0) {
               mergedSchedule[m][0] = FinalScdule[i][0];
               mergedSchedule[m][1] = FinalScdule[i][1];
               mergedSchedule[m][2] = FinalScdule[i][2];
               m++;
           }
        
       }
       m--;
       delete[]startTimes;
       delete[]EndTimes;
       delete[]StartTimes2;
       delete[]EndTimes2;
       for (int i = 0; i < index - 1; i++) {
           delete [] FinalScdule[i] ;
       }
       delete[]FinalScdule;
       delete[] NoOfOccurenceofStartTime;
       delete[] NoOfOccurenceofEndTime;


   }

   

  
   template <class T>
   void makeBookingSchedules(T R[][2], int n1, T Schedule[][3], int& m) {
       T* startTimes = new T[n1];
       T* endTimes = new T[n1];

       int noofTimeStamps = (n1) * 2;
       T* TimeStamps = new T[noofTimeStamps];


       int index = 0;
       for (int i = 0; i < n1; i++) {
           TimeStamps[index++] = R[i][0];
           TimeStamps[index++] = R[i][1];

       }
      
        int minTime = TimeStamps[0];
       int maxTime = TimeStamps[0];
       for (int i = 1; i < n1* 2; i++) {
           if (minTime > TimeStamps[i]) {
               minTime = TimeStamps[i];

           }
           if (maxTime < TimeStamps[i]) {
               maxTime = TimeStamps[i];
           }

       }

       T* TimeStamp2 = new T[maxTime + 1];
       for (int i = 0; i < (maxTime + 1); i++) {
           TimeStamp2[i] = -1;

       }
       for (int i = 0; i < (n1 ) * 2; i++) {
           TimeStamp2[TimeStamps[i]] = TimeStamps[i];
       }

       index = 0;
       for (int i = 0; i < maxTime + 1; i++) {
           if (TimeStamp2[i] >= 0) {
               if (i == 0)
                   TimeStamps[index++] = TimeStamp2[i];
               else if (TimeStamp2[i] > TimeStamp2[i - 1])
                   TimeStamps[index++] = TimeStamp2[i];
           }
       }

       T** FinalScdule = new T * [index - 1];
       for (int i = 0; i < index - 1; i++) {
           FinalScdule[i] = new T[3];
       }
       int totalNoOfintervals = 0;
       for (int i = 0; i < index - 1; i++) {
           FinalScdule[i][1] = TimeStamps[i];
           FinalScdule[i][2] = TimeStamps[i + 1];
           totalNoOfintervals++;
       }

       T* StartTimes = new T[n1 ];
       T* EndTimes = new T[n1];
       int index2 = 0;
       for (int i = 0; i < n1; i++) {
           StartTimes[index2] = R[i][0];
           EndTimes[index2] = R[i][1];
           index2++;

       }
     
       int maxFromStart = StartTimes[0];
       int maxFromEnd = EndTimes[0];
       for (int i = 0; i < n1 ; i++) {
           if (maxFromStart < StartTimes[i]) {
               maxFromStart = StartTimes[i];
           }
           if (maxFromEnd < EndTimes[i]) {
               maxFromEnd = EndTimes[i];
           }
       }
       T* StartTimes2 = new T[maxFromStart + 1];
       T* EndTimes2 = new T[maxFromEnd + 1];
       int* NoOfOccurenceofStartTime = new int[maxFromStart +1];
       int* NoOfOccurenceofEndTime = new int[maxFromEnd+1];
       for (int i = 0; i < maxFromStart + 1; i++) {
           StartTimes2[i] = -1;
           NoOfOccurenceofStartTime[i] = 0;
       }
       for (int i = 0; i < maxFromEnd + 1; i++) {
           EndTimes2[i] = -1;
           NoOfOccurenceofEndTime[i] = 0;
       }
       for (int i = 0; i < n1 ; i++) {
           
           StartTimes2[StartTimes[i]] = StartTimes[i];
           NoOfOccurenceofStartTime[StartTimes[i]]++;
           EndTimes2[EndTimes[i]] = EndTimes[i];
           NoOfOccurenceofEndTime[EndTimes[i]]++;

       }
     
       int* RoomCounts = new int[totalNoOfintervals];
       int indexOfRoomCounts = 0;
       int currentNoOfRooms = 0;
       for (int i = 0; i < maxFromStart + 1; i++) {
           if (StartTimes2[i] == -1 && EndTimes2[i] == -1) {
               continue;
           }
           else if (StartTimes2[i] == -1 && EndTimes2[i] != -1) {
               if (currentNoOfRooms != 0)
                   currentNoOfRooms-= NoOfOccurenceofEndTime[i];
               RoomCounts[indexOfRoomCounts++] = currentNoOfRooms;

           }
           else if (StartTimes2[i] != -1 && EndTimes2[i] == -1) {
              
               currentNoOfRooms += NoOfOccurenceofStartTime[i];
               RoomCounts[indexOfRoomCounts++] = currentNoOfRooms;
           }
           else if (StartTimes2[i] != -1 && EndTimes2[i] != -1) {
               RoomCounts[indexOfRoomCounts++] = currentNoOfRooms;
           }



       }

        m = 0;
       for (int i = 0; i < indexOfRoomCounts; i++) {
           FinalScdule[i][0] = RoomCounts[i];
           if (RoomCounts[i] != 0) {
               Schedule[m][0] = FinalScdule[i][0];
               Schedule[m][1] = FinalScdule[i][1];
               Schedule[m][2] = FinalScdule[i][2];
               m++;
           }

       }
       m--;
       delete[]startTimes;
       delete[]EndTimes;
       delete[]StartTimes2;
       delete[]EndTimes2;
       for (int i = 0; i < index - 1; i++) {
           delete[] FinalScdule[i];
       }
       delete[]FinalScdule;
       delete[] NoOfOccurenceofStartTime;
       delete[] NoOfOccurenceofEndTime;

   }

