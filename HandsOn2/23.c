#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>

int main() {
    // Get the maximum number of files that can be opened
    struct rlimit rlim;
    if (getrlimit(RLIMIT_NOFILE, &rlim) == 0) {
        printf("Maximum number of files that can be opened: %lld\n", (long long)rlim.rlim_cur);
    }
    
    else {
        perror("Error getting RLIMIT_NOFILE");
    }

    // Create a pipe and get the size of the pipe buffer
    int pipe_fd[2];
    if (pipe(pipe_fd) == 0) {
        long pipe_size = fpathconf(pipe_fd[0], _PC_PIPE_BUF);
        if (pipe_size == -1) {
            perror("Error getting pipe buffer size");
        } else {
            printf("Size of a pipe (circular buffer): %ld bytes\n", pipe_size);
        }
        close(pipe_fd[0]);
        close(pipe_fd[1]);
    }

    else {
        perror("Error creating pipe");
    }
    return 0;
}
