#ifndef DATA_H_
#define DATA_H_

typedef struct Data {
  int* dataX;
  int* dataY;
} data; 

//TODO Sort fonksiyonunuzu tanimlayin
void insertion_sort(int *array, int size);
void read_data(char* filename,data* dt);
void get_information(int* param_list);
void sort_values(data* dt);
void find_line(data* dt,double* m,double* b);  

#endif
