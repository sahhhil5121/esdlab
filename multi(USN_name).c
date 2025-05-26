#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Global variables to hold user inputs
char student_name[100];
char usn[20];
char college_name[100];

// First thread: handles name
void* name_thread(void* arg) {
    printf("Thread 1: Name is %s\n", student_name);
    printf("Thread 1: Enter your name again to confirm: ");
    char temp[100];
    scanf("%s", temp);  // you can use fgets for spaces
    printf("Thread 1 ID: %lu\n", pthread_self());
    pthread_exit(NULL);
}

// Second thread: handles USN and college
void* usn_college_thread(void* arg) {
    printf("Thread 2: USN is %s\n", usn);
    printf("Thread 2: Enter your college name: ");
    scanf("%s", college_name);  // use fgets if name has spaces
    printf("College: %s\n", college_name);
    printf("Thread 2 ID: %lu\n", pthread_self());
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Main thread takes initial input
    printf("Main: Enter your Name: ");
    scanf("%s", student_name);

    printf("Main: Enter your USN: ");
    scanf("%s", usn);

    // Create threads
    pthread_create(&thread1, NULL, name_thread, NULL);
    pthread_create(&thread2, NULL, usn_college_thread, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Exit message
    printf("Name thread successful\n");
    printf("College thread successful\n");

    return 0;
}
