#include <stdlib.h>
#include <stdio.h>

int run = 1;

int main() {
    while(run) {
        char c = getc(stdin);
        if(c == 'q')
            run = 0;
    }
    return EXIT_SUCCESS;
}
