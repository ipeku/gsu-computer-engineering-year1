#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "stack.h"
#include "rpn.h"

#define LINE_MAX 20

int main(int argc, char *argv[]) {
	// Alistirma 1.f
	// stack.c dosyasina yazdiginiz fonksiyonlari test edin.
	struct stackNode *test = NULL;

	// Stack bos mu testi
	is_empty(test);

	// Stack push testi
	stack_push(&test, 16);

	// Stack print testi
	printf("\n");
	stack_print(test);
	printf("\n");
	
	// Stack pop ve multi-pop testi
	stack_pop(&test);
	stack_multi_pop(&test, 3);

	// Stack free testi
	stack_free(&test);


    // Alistirma 2.b yi tamamladiktan sonra alttaki 
	//   satiri yorumdan cikarip test yapabilirsiniz.
	// Bu fonksiyon herhangi bir ek isleme gerek duymaz,
	//   oldugu gibi calisir.
	rpn_test_evaluate_RPN();


	/* Alistirma 3
	 * Komut satiri arayuzunden (CLI), kullanicinin
	 *   girdigi islemi alip, hesaplayan donguyu yazin.
	 * Kullanici sistemden cikis yapmak icin 
	 *   exit yazip Enter'a basmalidir.
	 * Programdan cikmadan once bellekte stack icin 
	 *   kullandiginiz yeri serbest birakmayi unutmayin!
	 * Kullanicinin komutunu asagida tanimlanan 
	 *   <line> degiskeni icine okuyabilirsiniz.
	 * Stack baslangici icin asagida tanimlanmis <stack>
	 *   degiskenini kullanabilirsiniz.
	 */
	char line[LINE_MAX];
	struct stackNode *stack = NULL;

	printf("\n\nWelcome to RPN Calculator!\n");
	printf("To exit, write exit and press ENTER\n");
	//Komut satiri arayuzunden (CLI), kullanicinin girdigi islemi alip hesaplayan, exit yazinca cikan dongu
	while (1) {
        printf("\nEnter the equation:  ");
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "exit") == 0) {
			printf("The program has been terminated. See you later!\n");
            break;
        }
		double result= evaluate_RPN(line, stack);
        printf("The result of this equation: %.2f\n\n", result);
    }

	//Programdan cikmadan once bellekte stack icin kullandiginiz yeri serbest birakmayi unutmayin!
	while (stack != NULL) {
    	struct stackNode* temporary = stack;
        stack = stack->next;
        free(temporary);
    }

	return 0;
}
