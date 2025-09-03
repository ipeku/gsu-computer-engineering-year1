#include "data.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
/* ONEMLI BILGI
 * Asagida kullanilan tum listelerin uzunluklari
 * yukaridaki SIZE'a esit olacaktir.
 * Fonksiyonlarinizda (read_data haric) gonlunuzce kullanin.
 */


/* Alistirma 1
 * Istediginiz bir sort algoritmasini yazin
 * Bu algoritmayi data.h dosyasinda tanimlamayi unutmayin!
 * Dogru calistigi surece onceki calismalardan kopyalabilirsiniz.
 * Tip: Kolay bir tane secin, asagida bunu tekrar yazacaksiniz
 *      (Performans cok onemli degil, 100 eleman olacak zaten)
 */
// TODO: SORT FONKSIYONU
void insertion_sort(int *array, int size) {

  for (int i = 1; i < size; i++) {
    int pivot = array[i];
    int j;

    for (j = i; j > 0; j--) {
      if (pivot < array[j - 1]) {
        array[j] = array[j - 1];
      } else break;
    }

    array[j] = pivot;    
  }
}



/* Alistirma 2
 * Dosyayi satir satir okuyup, dt degiskeninin
 *  dataX ve dataY arraylerine yazan fonksiyonu yazin.
 * Dosyadaki sayilar virgul (,) ile ayrilmistir. Virgulden
 *  onceki deger x, sonraki deger y degeridir.
 * Dosyayi okuyamazsa error versin ki bilelim :)
 * Tip 1: feof() komutu dosya okurken cok kullanislidir.
 * Tip 2: Isiniz bitince dosyayi kapatmayi unutmayin.
 */
void read_data(char* filename, data* dt){
      FILE *fp = fopen(filename, "r");

      if (fp == NULL)
      {
          printf("Error: could not read file %s", filename);
          return;
      }
      int i = 0;
      while (!feof(fp)) {
          fscanf(fp, "%d , %d", &dt->dataX[i], &dt->dataY[i]);
            i++;
      }

      fclose(fp);
      }


/* Alistirma 3
 * Aldigi param_list degiskeninde asagidaki bilgileri 
 *  sirasiyla bulup ekrana basan fonksiyon:
 * - Eleman sayisi
 * - Ortalama
 * - Minimum
 * - Maximum
 * Tip: Min ve max bulmadan once sort ederseniz 
 *      isiniz cok daha kolay olur.
 */
void get_information(int* param_list){
  float toplam=0;
  printf("eleman sayisi: %d\n", SIZE);
  for(int i=0; i<SIZE; i++){
    toplam= toplam+ param_list[i];
  }
  float ortalama= toplam/SIZE;
  printf("ortalama: %.2f\n", ortalama);

  insertion_sort(param_list, SIZE);
  
  printf("minimum: %d\n", param_list[0]);
  printf("maximum: %d\n", param_list[SIZE-1]);
}


/* Alistirma 4
 * Yukarida yazdiginiz sorting fonksiyonunu dt 
 *  degiskenine uygulayan sorting fonksiyonunu yazin.
 * Bu fonksiyonu yazarken onceki yazdiginiz sort
 *  fonksiyonunu kullanamazsiniz. Yani bu fonksiyon
 *  kendi basina calismali.
 */

void sort_values(data* dt){
  // TODO
  for (int i = 1; i < SIZE; i++) {
    int pivot = dt->dataX[i];
    int j;

    for (j = i; j > 0; j--) {
      if (pivot < dt->dataX[j - 1]) {
        dt->dataX[j] = dt->dataX[j - 1];
      } 
      else break;
    }

   dt->dataX[j] = pivot;    
  }
}
/* Alistirma 5
 * dt degiskenindeki X ve Y degerlerini kullanarak
 *  lineer regresyon hesabi yapan fonksiyonu yazin.
 * Yani, Y = a + bX seklindeki formulun a ve b 
 *  parametreleri bulunacak.
 * Fonksiyon sonucu ekrana basmamali ve deger 
 *  geri dondurmemeli, b ve a uzerinden sonuca erisilmeli.
 * Tip: Gerekli formullerin hepsi PDF'te verilmistir.
 */
void find_line(data* dt, double* a, double* b){
  
    double toplamX = 0.0;
    double toplamY = 0.0;
    double toplamXY = 0.0;
    double toplamXX = 0.0;
    int length = sizeof(dt) / sizeof(dt[0]);

    for (int i = 0; i < SIZE; i++) {
        toplamX += dt->dataX[i];
        toplamY += dt->dataY[i];
        toplamXY += dt->dataX[i] * dt->dataY[i];
        toplamXX += dt->dataX[i] *dt->dataX[i];
    }

    double A_pay = (toplamY * toplamXX) - (toplamX * toplamXY);
    double A_payda = (SIZE * toplamXX) - (toplamX * toplamX);
    double B_pay = (SIZE * toplamXY) - (toplamX * toplamY);
    double B_payda = (SIZE * toplamXX) - (toplamX * toplamX);

    *a = A_pay / A_payda;
    *b = B_pay / B_payda;
}



