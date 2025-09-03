#include"data.h"
#include <stdlib.h>
#include <stdio.h>
#define SIZE 100

/* Alistirma 6
 * Bir dosyadan veri okuyup, uzerinde lineer regresyon
 *  uygulayan programi yazin.
 * Adim 1: Veriyi read_data fonksiyonu ile okuyup mainData 
 *         degiskenine yazin. read_data fonksiyonuna vereceginiz
 *         dosya adini argv kullanarak komut satirindan almalisiniz.
 * Adim 2: Veriyle ilgili bilgileri get_information 
 *         fonksiyonunu kullanarak ekrana basin.
 * Adim 3: Veriyi sort_values fonksiyonunu kullanarak
 *         siralayin.
 * Adim 4: sorted_data.txt isimli bir dosya olusturup,
 *         icine siralanmis X ve Y degerlerini yazin.
 *         (data.txt ile ayni formatta yazilmali!)
 * Adim 5: find_line fonksiyonunu kullanarak veri uzerinde
 *         lineer regresyon uygulayin. Elde ettiginiz 
 *         sonuclari a ve b degiskenlerine yazin. Ardindan
 *         bu sonuclari ekrana basin.
 * 
 * Basarilar
 */
int main(int argc, char const *argv[]){
  data mainData;
  int tmpX[SIZE];
  int tmpY[SIZE];
  mainData.dataX=tmpX;
  mainData.dataY=tmpY;

  // Adim 1
  read_data(argv[1], &mainData);
  for (int i = 0; i < SIZE; i++) {
      tmpX[i] = mainData.dataX[i];
      tmpY[i] = mainData.dataY[i];
  }

  // Adim 2
  printf("\nIlk sutundaki veri bilgileri: \n");
  get_information(tmpX);
  printf("\nIkinci sutundaki veri bilgileri: \n");
  get_information(tmpY);

  // Adim 3
  sort_values(&mainData);

  // Adim 4
  FILE* sortedFile = fopen("sorted_data.txt", "w");
    if (sortedFile == NULL) {
        printf("Error: could not create sorted_data.txt file\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        fprintf(sortedFile, "%d,%d\n", mainData.dataX[i], mainData.dataY[i]);
    }

    fclose(sortedFile);

  // Adim 5
  double a; 
  double b;
  find_line(&mainData, &a, &b);

    printf("\na= %.2f , b=%.2f\n", a, b);
    printf("\nLine of linear regression:\n");
    printf("Y = %.2f + %.2fX\n", a, b);

    
  return 0;
}
