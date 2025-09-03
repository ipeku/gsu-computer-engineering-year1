#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include"rpn.h"
#include"stack.h"

/*
 * Verilen iki sayi uzerinde, verilen islemi uygular.
 * Ex: op1 = 1 op2 = 3 operation= +
 *        sonuc: 1+3 = 4
 * Ex: op1 = 8 op2 = -3 operation = *
 *        sonuc: 8 * -3 = -24
 * Verilen operation eger istenen 4 islem(*,+,/,-) karakterinde degilse
 *   hata mesaji gosterip fonksiyondan cikar.
 */
double compute_operation(double op1, double op2, char operation) {
    /* Alistirma 2.a: op1 ve op2'yi operation ile verilen '+', '-', '*', '/'
     *   islemlerini uygulayip geri donduren fonksiyonu yazin. 
     */
    double result = 0;
    /*
     * Tip: switch-case kullanabilirsiniz.
     */
    
    switch(operation) {
        case '-':
            result = op1 - op2;
            break;

        case '+':
            result = op1 + op2;
            break;

        case '/':
            result = op1 / op2;
            break;

        case '*':
            result = op1 * op2;
            break;

        default:
            printf("Wrong operator selection!!!");
            break;
    }
    return result;
}

/*
 * Verilen expr parametresindeki sayilari, yine
 *   expr icindeki islemler ile hesaplayip,
 *   yigit icerisine kaydedecek.
 */
double evaluate_RPN(char *expr, struct stackNode **top) {
    double retval = 0.0;
    // Alistirma 2.b
    /* Ifadenin sonuna kadar elemanlari gezecek bir dongu kurunuz.
     * Ifadenin sonuna gelip gelmedigini ('\0') ile kontrol edebilirsiniz.
     * Tip: Kontrol icin her dongu sirasinda yigit icerigini ekrana basabilirsiniz
     *   boylece yigitdaki degisimleri gorebilirsiniz.
     * 
     * Eger eleman islenen (operand) ise yigita ekleyiniz (push).
     * Eger eleman bir islem ise yigittan iki deger cekiniz (pop).
     * Tip: isdigit fonksiyonunu kontrol icin kullanabilirsiniz . 
     * 
     * Bu iki deger ile istenen islemi compute_operation()
     *   fonksiyonuna verip donus degeri yigita ekleyin (push).
     */

    // Kullanilacak degisken atamalarini yapin
    int j = 0; 

    // Donguyu kurun
    while (expr[j] != '\0') {

        // Eleman islenen (operand) ise yigita ekleyiniz (push)
        if (isdigit(expr[j])==1) {
            double operand =expr[j]-'0'; 
            stack_push(&top, operand);
        }
 
        // Eleman bir islem ise yigittan iki deger cekin (pop)
        if (expr[j]== '-'||expr[j]== '+'||expr[j]== '/'||expr[j]== '*') {
            
            if (*top == NULL) {
                printf("ERROR! Operation is not possible because the stack is empty.\n");
                return retval;
            }

            double op1 = stack_pop(&top);
            double op2 = stack_pop(&top);            

            // Istenen islemi compute_operation() fonksiyonuna verip donus degerini yigita ekleyin (push)
            double outcome = compute_operation(op2, op1, expr[j]);
            stack_push(&top, outcome);
        }
        j++; 
        printf("Here is your list:   ");

        // Yigita koyulan elemanlari her adimda ekrana basiyoruz
        stack_print(top);
    }

    // Yigitta kalan eleman sonuc degeridir.
    // retval degiskenini sonuc degerini pop ile alarak guncelleyin.
    retval = stack_pop(&top);
   

    // Yigit bos degilse kontrol edin, bu durumda compute_operation fonksiyonu hatali olabilir.
    // Bununla ilgili mesaj ekrana yazdirin.
    if (top != NULL) {
        printf("ERROR! The stack is not empty, but the process is complete. Compute_operation function may contain errors");
    } 
    return retval;
}

void rpn_test_evaluate_RPN(){
	/* Test */
    struct stackNode *stack = NULL;
    printf("Testing equation 13+2-\n");
    //printf("\n%f\n",evaluate_RPN("13+2-", stack));
	assert(evaluate_RPN("13+2-", stack) == 2.0);
    printf("\nTesting equation 62+5*84/-\n");
	assert(evaluate_RPN("62+5*84/-", stack) == 38.0);
    stack_free(&stack);
	printf("\nThe tests are successful.\n");
}
