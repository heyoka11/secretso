#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


int main()
{
    pid_t child = fork();
    if (child == 0) {
        while (1) {
        puts("Toni");
        sleep(1);
}
} else {
    sleep(4);
    kill(child, SIGSTOP); // terminate
    sleep(3);
    kill(child, SIGCONT);
    sleep(2);
    kill(child, SIGTERM);
}
return 0;
}
