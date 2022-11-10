// driver untuk ADT Mesin Karakter

#include "mesinkarakter.h"
#include "stdio.h"

int main() {
    char y;

    printf("===== tes START dan ADV input user =====\n");
    printf("Masukkan beberapa karakter ke dalam pita : ");
    START(); // proses print akan berakhir jika charnya diakhiri .
    while(!IsEOP()) {
        y = GetCC();
        printf("%c\n", y);
        advTerminal();
    }
    
    // startFromFile dan advFile akan dicoba pada driver mesin kata
    return(0);
}