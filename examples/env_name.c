#include <stdlib.h>
#include <stdio.h>

// Function demonstrating how C can get environment variables.

int main(){
    char *uname = getenv("MYNAME");
    printf("%s\n", uname);
}
