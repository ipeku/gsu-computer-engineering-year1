#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


/*
 * Parametre olarak verilen yigit
 *   elemanini bellekten siler.
 * Yigit zaten bos ise herhangi bir 
 *   islem yapmaz.
 */
void stack_free(struct stackNode** top) {
    /* Alistirma 1.a1 */

    // 1. "top" pointer'imizi kaybetmemek icin, while 
    //    icinde donecek olan yeni bir pointer tanimliyoruz.
    //    Bu yeni pointer (cursor), top pointer'in gosterdigi
    //    adresteki degere isaret etmeli. (dereference)
    struct stackNode ** cursor = top;


    // 2. Her bir eleman NULL olmadigi 
    //   surece silme islemi yapan donguyu yazin
    //dongu (kosul) {
    while (*cursor != NULL){
    

        // 3. "cursor"i hareket ettirecegiz, orijinali kaybetmemek 
        //    adina, orphan adinda bir pointer tanimlayin.
        //    orphan, cursor ile ayni yere isaret etmeli.
        struct stackNode* orphan = *cursor;


        // 4. "cursor"i bir sonraki node'a kaydirin.
        *cursor = (*cursor)->next; 
        

        // 5. "orphan"in kullandigi bellegi serbest birakin.
        free(orphan);

    }

    // 6. "top" pointer'ini NULL yapin, bellegi tamamen
    //    serbest biraktik.
    *top = NULL;
}

/*
 * Parametre olarak verilen yigit yapisinin
 * bos olup olmadini kontrol eder.
 * yigit bos ise 1, degilse 0 dondurur.
 */
int is_empty(struct stackNode *top){
    int result = 0;
    /* Alistirma 1.a2 */
    if (top == NULL){ 
        result=1;
        return result;
        }
    else
        return result;
}

/*
 * Parametre olarak verilen yigit yapisinda
 * yeni veri data yapisini ekler.
 * (LIFO prensibi ile)
 */
void stack_push(struct stackNode **top, double data) {
	/* Alistirma  1.b */
	/* 1. Yeni dugum icin gosterici olusturun
     *      ve bellekte yer acin.
     * 2. Bellek icin kontrol yaptiktan sonra
     *      yeni veri atamasini yapin.
     * 3. Son olarak, yigittaki ilk degeri guncelleyin.
    */

    //1:
    struct stackNode* NewNode = (struct stackNode*) malloc(sizeof(struct stackNode));

    //2:
    NewNode->data = data;
    NewNode->next = *top;

    //3:
    *top = NewNode;
}

/*
 * Parametre olarak verilen yigit yapisindan
 *   ilk elemani siler.
 * Eger yigit bos ise -1 degerini dondurur.
 */
double stack_pop(struct stackNode **top) {
	double retval = -1;
	/* Alistirma 1.c */
    /* Yigiti kontrol et, bos ise -1 dondur.
     * Bos degilse ilk elemani al, sonraki 
     *   elemani ilk eleman olarak ata.
     * Ilk eleman icin ayrilan bellegi sil.
     * Ilk eleman verisini dondur.
     */
    if (*top == NULL){ 
        return retval;
        }
    
    struct process* temporary = *top;
    double data = (*top)->data;
    *top = (*top)->next;
    free(temporary);
    
    return data;
}

/*
* Alistirma 1.d 
* Parametre olarak verilen number degiskeninin 
*   degeri kadar elemani pop ile stackten cikaran
*   stack_multi_pop fonksiyonunu tanimlayiniz.
* Dikkat! 
* Bu fonksiyonu stack.h dosyasina eklemeyi unutmayin!
*/

void stack_multi_pop(struct stackNode **top, int number){
    for(int x=0; x<number; x++){
        stack_pop(top);
    }
}


/*
 * Parametre olarak verilen yigit yapisini
 * ekrana basar.
 * yigit bos ise "yigit bos" mesajini gosterir.
 */
void stack_print(struct stackNode *top) {
    /* Alistirma 1.e */
	/* 1. Yigit bos mu kontrol edip, bos ise 
     *      ekrana mesaj basip fonksiyondan cikmali
     * 2. Yigit bos degilse ilk elemandan 
     *      baslayarak son elemana kadar tum 
     *      degerler ekrana yazilsin.
     * Tip: Yigit yapisi bagli liste olarak tanimlandigindan, 
     *   ekrana basma islemi de bagli listeler ile 
     *   benzer olacaktır.
     */

    //1:
    if(top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    //2:
    while(top != NULL) {
        printf("%f ->", top->data);
        top = top->next;
    }
    printf("NULL\n");
}