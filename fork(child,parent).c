#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (void)
{
    pid_t pid;
    char *message;
    int no, NO1 = 1;
    int i, l;

    printf("calling fork \n");
    pid = fork();

    switch (pid)
    {
        case -1:
            printf ("fork failed \n");
            exit (1);

        case 0:
            message = "Child Process";
            i = 1;
            no = getpid ();
            NO1 = getppid ();
            break;

        default:
            message = "Parent Process";
            i = 1;
            no = getpid ();
            NO1 = getpid ();
            break;
    }

    if(pid != 0) {
        printf("HP: hello from parent\n");
        wait(NULL);
        printf("CT: child has terminated\n");
    }

    for (l = i; l > 0; l--)
    {
        puts (message);
        printf ("My ID is %d \n", no);
        printf ("My parent ID is %d \n", NO1);
    }

    return (0);
}
