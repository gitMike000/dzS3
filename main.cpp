#include <iostream>
#include <vector>
#include <cmath>
#include <valarray>
#include "Timer.h"
#include <list>
//#include "owniterator.h"
//#include "owncontainer.h"
#include "owncontainer.cpp"


using namespace std;

void average(vector<double>& vt) {
    double ave=0;
    for (vector<double>::iterator it = vt.begin(); it != vt.end(); ++it) {
          ave+=*it;
    }
    vt.push_back((ave/vt.size()));
}

// Task 2
// ----------------------------- Определитель --------------------------
// Вычисляет определитель матрицы T размерностью N
double det(double **T, int N)
{
  double det__;
  int sub_j, s;
  double **subT;    // Субматрица как набор ссылок на исходную матрицу
  switch (N)
  {
  case 1:
    return T[0][0];
  case 2:
    return T[0][0] * T[1][1] - T[0][1] * T[1][0];
  default:
    if (N < 1) return 0;  // Некорректная матрица
    subT = new double*[N-1];  // Массив ссылок на столбцы субматрицы
    det__ = 0;
    s = 1;        // Знак минора
    for (int i = 0; i < N; i++)  // Разложение по первому столбцу
    {
      sub_j = 0;
      for (int j = 0; j < N; j++)// Заполнение субматрицы ссылками на исходные столбцы
        if (i != j)      // исключить i строку
          subT[sub_j++] = T[j] + 1;  // здесь + 1 исключает первый столбец

      det__ = det__ + s * T[i][0] * det(subT, N-1);
      s = -s;
    };
    delete[] subT;
    return det__;
  };
};

double determinant(double **matrica_a,int n) {
 int i,j,k,r;
 double c,M,max,det=1,**a;
 a=new double *[n];
 for (i=0;i<n;i++) a[i]=new double[n];
 for (i=0;i<n;i++)
     for (j=0;j<n;j++)
         a[i][j]=matrica_a[i][j];
 for (k=0;k<n;k++){
     max=fabs(a[k][k]); r=k;
     for (i=k+1;i<n;i++)
         if (fabs(a[i][k])>max){
             max=fabs(a[i][k]); r=i;
         }
     if (r!=k) det=-det;
     for (j=0;j<n;j++) {
         c=a[k][j]; a[k][j]=a[r][j]; a[r][j]=c;
     }
     for(i=k+1;i<n;i++)
         for(M=a[i][k]/a[k][k],j=k;j<n;j++)
             a[i][j]-=M*a[k][j];
 }
 for(i=0;i<n;i++)
     det*=a[i][i];
 for (i=0;i<n;i++) delete [] a[i];
 delete [] a;
 return det;
};

double** initArray(double** array,const int row, const int col) {
 array=(double**) calloc(sizeof(double*),row);
 for (int i=0;i<row;++i) {
  *(array+i)=(double*) calloc(sizeof(double), col);
 }
 return array;
}

void printArray(double **array,const int row, const int col) {
 for (int i=0;i<row;++i) {
     for (int j=0;j<col;++j) {
         cout<< *((*(array+i))+j)<<" ";
     }
     cout<<endl;
 }
}

template <class TT>
class Array1: public valarray<TT> {
  size_t row,col;
public:
  Array1(){}
  Array1(size_t nx) : valarray<TT>(nx){row=nx,col=1;}
  Array1(size_t nx, size_t ny) : valarray<TT>(nx*ny){row=nx,col=ny;}
//  virtual ~Array1(){}
  TT& operator()(size_t i,size_t j) { return (*this)[i*col+j];}
//  size_t Size(size_t n) const { return (n<2) ? col: row;}

  void set_array(TT** mas) {
   for (size_t i = 0; i < col; ++i)
   {
      for (size_t j = 0; j < row; ++j)
         (*this)[i*col+j]= mas[i][j];
   }
  }

  void print() {
   for (size_t i = 0; i < col; ++i) {
      for (size_t j = 0; j < row; ++j)
         cout << (*this)[i*col+j]<< " ";
      cout << endl;
   };
  }

  TT determinant() {
   if (col!=row) return 0;
   size_t i,j,k,r,n=col;
   TT c,M,max,det=1;

   valarray<TT> temp=*this;

   for (k=0;k<n;k++){
       max=fabs(temp[k*col+k]); r=k;

       for (i=k+1;i<n;i++)
           if (fabs(temp[i*col+k])>max){
               max=fabs(temp[i*col+k]); r=i;
           }

       if (r!=k) det=-det;

       for (j=0;j<n;j++) {
           c=temp[k*col+j]; temp[k*col+j]=temp[r*col+j]; temp[r*col+j]=c;
       }
       for(i=k+1;i<n;i++)
           for(M=temp[i*col+k]/temp[k*col+k],j=k;j<n;j++)
               temp[i*col+j]-=M*temp[k*col+j];
   }
   for(i=0;i<n;i++)
       det*=temp[i*col+i];
   return det;
  };

};

int main()
{
    // ---- Task 1
    // Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого
    // равно среднему арифметическому всех его элементов.
    cout << "Task 1"<<endl;
    vector<double> v{ 1.4, 2.6, 3.1, 4.6, 5.3 };
    average(v);
    cout<<"vector with average number"<<endl;
    for (vector<double>::iterator it = v.begin(); it != v.end(); ++it) {
          cout << *it << " "; }
    cout << endl<<endl;

    // ---- Task 2
    // Создать класс, представляющий матрицу. Реализовать в нем метод, вычисляющий определитель матрицы.
    cout << "Task 2"<<endl;
    const int nn=9;
    double mas [nn][nn] ={{1,4,3,6,8,2,3,2,4},
                          {5,2,8,9,9,4,5,8,6},
                          {6,9,3,2,3,7,6,0,4},
                          {4,7,8,4,1,5,4,5,4},
                          {2,6,3,8,5,9,7,1,8},
                          {3,8,6,7,3,4,7,6,5},
                          {1,3,5,6,9,7,9,2,6},
                          {8,9,4,8,9,4,5,4,0},
                          {2,8,3,3,7,1,4,3,5}};

    double** mu=initArray(mu,nn,nn);
    for (int i=0;i<nn*nn;i++) mu[i]=mas[i];
    printArray(mu,nn,nn);

    double de;

    cout <<"Metod 1"<<endl;
    Timer timer1("M1");
    de=det(mu,nn);
    timer1.print();
    cout <<"det=" << de << endl;
    cout<<endl;

    cout <<"Metod 2"<<endl;
    Timer timer2("M2");
    de=determinant(mu,nn);
    timer2.print();
    cout << "det=" << de << endl;
    cout<<endl;

    cout <<"Metod 3"<<endl;
    Array1<double> as(nn,nn);
    double *dataPtrs[nn];
    for(size_t n=0; n<nn; ++n) {
      dataPtrs[n] = mas[n];
    }
    as.set_array(dataPtrs);
//    as.print();
//    cout<<as(nn-1,nn-1)<<endl;

    Timer timer3("M3");
    de=as.determinant();
    timer3.print();
    cout <<"det="<<de<<endl;

    cout << endl<<endl;

    // ---- Task 3
    // Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться по диапазону
    // целых чисел в цикле for-range-based.
    cout << "Task 3"<<endl;
    OwnContainer container = { 10, 20, 30, 40, 50, 60 };
    for (auto& iter:container) cout<<iter<<" ";
     cout << endl<<endl;

 // аналог
  auto __begin = container.rbegin();// std::begin(container);
  auto __end = container.rend();//std::end(container);
  for (; __begin != __end; ++__begin) {
           auto x = *__begin;
           cout <<x<<" ";
  }

  cout << endl<<endl;

     for (OwnContainer::riterator it = container.rbegin(); it != container.rend(); ++it) {
           cout << *it << " ";
     }

      cout << endl<<endl;

    return 0;
}
