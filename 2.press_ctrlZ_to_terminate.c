#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int signal)
{
    printf("Press CTRL+Z to terminate\n");
}

int main()
{
    
    (void) signal(SIGINT, my_handler);

    
    while (1)
    {
        printf("Running... Press CTRL+C\n");
        sleep(1);
    }

    return 0;
}

