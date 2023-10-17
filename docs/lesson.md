<h1 id="title" align="center">
    MINISHELL
</h1>

<h3 align="center">
    <a href="#readline">Readline()</a>
    <span> · </span>
    <a href="#rl_clear_history">Rl_clear_history()</a>
    <span> · </span>
    <a href="#rl_on_new_line">Rl_on_new_line()</a>
    <span> · </span>
    <a href="#rl_replace_line">Rl_replace_line()</a>
    <span> · </span>
    <a href="#rl_redisplay">Rl_redisplay()</a>
    <span> · </span>
    <a href="#add_history">Add_history()</a>
    <span> · </span>
    <a href="#signal">Signal()</a>
    <span> · </span>
    <a href="#sigaction">Sigaction()</a>
    <span> · </span>
    <a href="#sigemptyset">Sigemptyset()</a>
    <span> · </span>
    <a href="#sigaddset">Sigaddset()</a>
    <span> · </span>
    <a href="#kill">Kill()</a>
    <span> · </span>
    <a href="#getcwd">Getcwd()</a>
    <span> · </span>
    <a href="#chdir">Chdir()</a>
    <span> · </span>
    <a href="#stat">Stat()</a>
    <span> · </span>
    <a href="#lstat">Lstat()</a>
    <span> · </span>
    <a href="#fstat">Fstat()</a>
    <span> · </span>
    <a href="#opendir">Opendir()</a>
    <span> · </span>
    <a href="#readdir">Readdir()</a>
    <span> · </span>
    <a href="#closedir">Closedir()</a>
    <span> · </span>
    <a href="#isatty">Isatty()</a>
    <span> · </span>
    <a href="#ttyname">Ttyname()</a>
    <span> · </span>
    <a href="#ttyslot">Ttyslot()</a>
    <span> · </span>
    <a href="#ioctl">Ioctl()</a>
    <span> · </span>
    <a href="#getenv">Getenv()</a>
    <span> · </span>
    <a href="#tcsetattr">Tcsetattr()</a>
    <span> · </span>
    <a href="#tcgetattr">Tcgetattr()</a>
    <span> · </span>
    <a href="#tgetent">Tgetent()</a>
    <span> · </span>
    <a href="#tgetflag">Tgeflag()</a>
    <span> · </span>
    <a href="#tgetnum">Tgetnum()</a>
    <span> · </span>
    <a href="#tgetstr">Tgetstr()</a>
    <span> · </span>
    <a href="#tgoto">Tgoto()</a>
    <span> · </span>
    <a href="#tputs">Tputs()</a>
</h3>

<h1 id="title" align="center">
    PIPEX
</h1>

<h3 align="center">
    <a href="#malloc">Malloc()</a>
    <span> · </span>
    <a href="#free">Free()</a>
    <span> · </span>
    <a href="#write">Write()</a>
    <span> · </span>
    <a href="#read">Read()</a>
	<span> · </span>
    <a href="#open">Open()</a>
	<span> · </span>
    <a href="#close">Close()</a>
	<span> · </span>
    <a href="#access">Access()</a>
	<span> · </span>
    <a href="#dup">Dup()/Dup2()</a>
	<span> · </span>
    <a href="#exec">Execve()</a>
	<span> · </span>
    <a href="#exit">Exit()</a>
	<span> · </span>
    <a href="#fork">Fork()</a>
	<span> · </span>
    <a href="#wait">Wait() and Waitpid()</a>
	<span> · </span>
    <a href="#pipe">Pipe()</a>
	<span> · </span>
    <a href="#unlink">Unlink()</a>
	<span> · </span>
    <a href="#perror">Perror()</a>
	<span> · </span>
    <a href="#strerror">Strerror()</a>
</h3>

<div id="readline">

# Readline() function

The readline() function in the C language is used to read a line of text interactively from the standard input. It simplifies the process of reading user input by allowing users to type a line of text, and it returns that line as a dynamically allocated C string.

The signature of the readline() function is typically provided by libraries like GNU Readline:
```bash
#include <readline/readline.h>

char *readline(const char *prompt);
```
The parameters of the readline() function are:

- `prompt`: This is a pointer to a null-terminated string that serves as the prompt to be displayed to the user before accepting input. It's an optional parameter.
The readline() function reads a line of text from the standard input (usually the keyboard) and returns it as a dynamically allocated C string. Users can edit the line of text using arrow keys, delete characters, and more, making it a useful function for interactive command-line applications.

It's important to note that you should free the memory allocated by readline() using the free() function when you're done with the returned string to prevent memory leaks. The function itself returns a pointer to the read line or NULL in case of an error.

Here's an example of how readline() might be used to read user input with a custom prompt:
```bash
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *user_input;

    user_input = readline("Enter a command: ");

    if (user_input != NULL) {
        printf("You entered: %s\n", user_input);
        free(user_input); // Don't forget to free the allocated memory.
    }

    return 0;
}
```
In this example, readline() is used to read a line of text with a custom prompt, and the user's input is displayed. The dynamically allocated memory for the input is freed to prevent memory leaks.

<br>
<br>
<div id="rl_clear_history">

# Rl_clear_history() function

The rl_clear_history() function is used to clear the command history stored by GNU Readline. This history typically consists of previously entered commands or lines of text. When you call this function, it removes all entries from the history, effectively clearing it. There is no return value for this function.

<br>
<br>
<div id="rl_on_new_line">

# Rl_on_new_line() function

The rl_on_new_line() function is used to notify GNU Readline that the current input line is complete, and a new line is beginning. This is typically used when implementing a custom prompt or input handling. After calling this function, you can display a new prompt for user input. There is no return value for this function.

<br>
<br>
<div id="rl_replace_line">

# Rl_replace_line() function

The rl_replace_line() function is used to replace the current line of text in the input buffer with a new line of text. This is useful for implementing command-line editing features where you want to replace the entire input line. The function takes two arguments: the new line of text to be displayed and a non-zero value to indicate whether the line should be redisplayed immediately. It returns 0 on success and -1 on failure.

<br>
<br>
<div id="rl_redisplay">

# Rl_redisplay() function

The rl_redisplay() function is used to force GNU Readline to redisplay the current line. This can be useful when you have modified the input buffer directly and need to update the displayed line to reflect the changes. After calling this function, the modified line will be redisplayed. There is no return value for this function.

<br>
<br>
<div id="add_history">

# Add_history() function

The add_history() function in the GNU Readline library is used to append a line of text to the command history. This command history typically stores previously entered commands or lines of text, allowing users to recall and execute them.

The signature of the add_history() function is as follows:
```bash
#include <readline/history.h>

void add_history(const char *line);
```
The parameter of the add_history() function is:

- `line`: This is a pointer to a null-terminated string that represents the line of text to be added to the command history.
After calling add_history() with the desired line of text, that line becomes part of the command history. Users can later recall and execute it, which is particularly useful in interactive command-line applications.

There is no return value for the add_history() function. It serves as a straightforward way to manage the history of commands or input lines within applications that use the GNU Readline library.

Here's an example of how add_history() might be used in a C program:
```bash
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *user_input;

    user_input = readline("Enter a command: ");

    if (user_input != NULL) {
        add_history(user_input); // Add the entered command to the history.
        printf("You entered: %s\n", user_input);
        free(user_input); // Don't forget to free the allocated memory.
    }

    return 0;
}
```
In this example, add_history() is used to add the user's input to the command history for later retrieval.

<br>
<br>
<div id="signal">

# Signal() function

The signal() function in the C language is used to establish a signal handler function for a specific signal. Signals are software interrupts that can be sent to a process to notify it of various events or exceptional conditions.

The signature of the signal() function is as follows:
```bash
#include <signal.h>

void (*signal(int signum, void (*handler)(int)))(int);
```
The parameters of the signal() function are:

- `signum`: This is an integer representing the signal number for which you want to set the handler. Common signal numbers include SIGINT (interrupt signal, often generated by pressing Ctrl+C), SIGTERM (termination signal), and SIGUSR1 (user-defined signal).
- `handler`: This is a pointer to a function that will be called when the specified signal is received. The handler function takes an integer argument representing the signal number.
The signal() function allows you to define custom signal handling behavior by specifying a function as the handler. When the specified signal is received by the process, the handler function is invoked. This enables you to perform specific actions or cleanup procedures in response to signals.

The function returns a pointer to the previous signal handler function for the specified signal. It's essential to be cautious when using signal() because its behavior can vary between different operating systems and C libraries. For more consistent and portable signal handling, you may prefer to use the sigaction() function.

Here's an example of how signal() might be used to set a custom signal handler for the SIGINT signal:
```bash
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void customHandler(int signum) {
    printf("Received signal %d (SIGINT)\n", signum);
    // Add custom signal handling code here.
}

int main() {
    // Set customHandler as the handler for the SIGINT signal.
    signal(SIGINT, customHandler);

    while (1) {
        // Your application's main loop.
    }

    return 0;
}
```
In this example, when the process receives the SIGINT signal (e.g., by pressing Ctrl+C), the customHandler() function is called to handle the signal.

<br>
<br>
<div id="sigaction">

# Sigaction() function

The sigaction() function in the C language is used to set or modify the action to be taken when a specific signal is received by a process. Signals are software interrupts that can be sent to a process to notify it of various events or exceptional conditions.

The signature of the sigaction() function is as follows:
```bash
#include <signal.h>

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```
The parameters of the sigaction() function are:

- `signum`: This is an integer representing the signal number for which you want to set or modify the action. Common signal numbers include SIGINT (interrupt signal), SIGTERM (termination signal), and SIGUSR1 (user-defined signal).
- `act`: This is a pointer to a struct sigaction that specifies the new action to be taken when the signal is received. It includes information about the signal handler function and additional flags.
- `oldact`: This is an optional pointer to a struct sigaction where the previous action for the specified signal will be stored. This allows you to retrieve the previous signal handling information.
The sigaction() function provides a more flexible and reliable way to handle signals compared to the older signal() function. It allows you to specify signal handlers as well as additional flags that control signal behavior, such as whether the signal should be blocked during the execution of the handler.

The function returns 0 on success and -1 on failure. It's important to note that signal handling behavior can vary between different operating systems and C libraries, so using sigaction() can lead to more consistent and portable signal handling in your applications.

Here's an example of how sigaction() might be used to set a custom signal handler for the SIGINT signal:
```bash
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void customHandler(int signum) {
    printf("Received signal %d (SIGINT)\n", signum);
    // Add custom signal handling code here.
}

int main() {
    struct sigaction sa;
    sa.sa_handler = customHandler;
    sa.sa_flags = 0;

    // Set customHandler as the handler for the SIGINT signal using sigaction.
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    while (1) {
        // Your application's main loop.
    }

    return 0;
}
```
In this example, sigaction() is used to set the customHandler() function as the handler for the SIGINT signal with additional flags set to 0. The handler will be called when the process receives the SIGINT signal, such as when pressing Ctrl+C.

<br>
<br>
<div id="sigemptyset">

# Sigemptyset() function

The sigemptyset() function in the C language is used to initialize an empty signal set. Signal sets are used in signal handling to represent a group of signals that may be blocked or unblocked by a process. An empty signal set contains no signals, effectively clearing any previously set signals.

The signature of the sigemptyset() function is as follows:
```bash
#include <signal.h>

int sigemptyset(sigset_t *set);
```
The parameter of the sigemptyset() function is:

- `set`: This is a pointer to a sigset_t object that will be initialized as an empty signal set.
The sigemptyset() function is typically used in conjunction with other signal-related functions, such as sigaddset() and sigprocmask(), to manipulate sets of signals. It's essential to initialize a signal set before adding or removing signals from it.

The function returns 0 on success and -1 on failure

Here's an example of how sigemptyset() might be used to initialize an empty signal set:
```bash
#include <stdio.h>
#include <signal.h>

int main() {
    sigset_t set;

    if (sigemptyset(&set) == -1) {
        perror("sigemptyset");
        return 1;
    }

    // The 'set' variable now represents an empty signal set.

    return 0;
}
```
In this example, sigemptyset() is used to initialize an empty signal set represented by the set variable. You can then add specific signals to this set using sigaddset() or use it in other signal-related functions.

<br>
<br>
<div id="sigaddset">

# Sigaddset() function

The sigaddset() function in the C language is used to add a specific signal to a signal set. Signal sets are used in signal handling to represent a group of signals that may be blocked or unblocked by a process. This function allows you to modify a signal set by adding individual signals to it.

The signature of the sigaddset() function is as follows:
```bash
#include <signal.h>

int sigaddset(sigset_t *set, int signum);
```
The parameters of the sigaddset() function are:

- `set`: This is a pointer to a sigset_t object representing a signal set. You can add the specified signal (signum) to this set.
- `signum`: This is an integer representing the signal number of the signal you want to add to the signal set.
The sigaddset() function is typically used in conjunction with other signal-related functions to manipulate sets of signals. It's used to customize the behavior of signal handling for a process. For example, you can add specific signals to a signal set and then block those signals using sigprocmask() to prevent them from interrupting the execution of a critical section of code.

The function returns 0 on success and -1 on failure.

Here's an example of how sigaddset() might be used to add the SIGUSR1 signal to a signal set:
```bash
#include <stdio.h>
#include <signal.h>

int main() {
    sigset_t set;

    if (sigemptyset(&set) == -1) {
        perror("sigemptyset");
        return 1;
    }

    // Add the SIGUSR1 signal to the signal set.
    if (sigaddset(&set, SIGUSR1) == -1) {
        perror("sigaddset");
        return 1;
    }

    // The 'set' variable now represents a signal set containing SIGUSR1.

    return 0;
}
```
In this example, sigaddset() is used to add the SIGUSR1 signal to the set signal set. You can then use this signal set in other signal-related functions to control signal behavior.

<br>
<br>
<div id="kill">

# Kill() function

The kill() function in the C language is used to send a signal to a specific process or group of processes. Signals are software interrupts that can be sent to a process to notify it of various events or exceptional conditions, or to request specific actions.

The signature of the kill() function is as follows:
```bash
#include <signal.h>

int kill(pid_t pid, int sig);
```
The parameters of the kill() function are:

- `pid`: This is an integer representing the process ID (PID) of the target process. You can specify the PID of a specific process to send the signal to that process, or you can use special values such as 0 (to send the signal to all processes in the caller's process group) or -1 (to send the signal to all processes for which the caller has permission to send signals).
- `sig`: This is an integer representing the signal number of the signal to be sent. Common signal numbers include SIGTERM (termination signal), SIGINT (interrupt signal), and SIGKILL (kill signal).
The kill() function is a versatile tool for process management and communication in Unix-like operating systems. It can be used to send various signals to processes for different purposes, such as requesting graceful termination (SIGTERM), interrupting a process (SIGINT), or forcefully killing a process (SIGKILL).

The function returns 0 on success and -1 on failure. You can use it in a variety of scenarios, such as sending signals to specific processes or controlling process behavior.

Here's an example of how kill() might be used to send a SIGTERM signal to a specific process with a known PID:
```bash
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t target_pid = 12345; // Replace with the PID of the target process.

    // Send a SIGTERM signal to the target process.
    if (kill(target_pid, SIGTERM) == -1) {
        perror("kill");
        return 1;
    }

    return 0;
}
```
In this example, kill() is used to send a SIGTERM signal to the process with the PID 12345.

<br>
<br>
<div id="getcwd">

# Getcwd() function

The getcwd() function in the C language is used to retrieve the current working directory of a process. The current working directory is the directory in the file system where the process is currently located or "working" in. This function provides a way to obtain the absolute path of the current directory.

The signature of the getcwd() function is as follows:
```bash
#include <unistd.h>

char *getcwd(char *buf, size_t size);
```
The parameters of the getcwd() function are:

- `buf`: This is a pointer to a character array (buffer) where the current working directory path will be stored. It should be large enough to accommodate the path.
- `size`: This is the size (in bytes) of the buffer pointed to by buf.
The getcwd() function populates the provided buffer (buf) with the absolute path of the current working directory. The buffer should be large enough to hold the entire path, and the size parameter specifies its size.

The function returns a pointer to the same buffer buf if it succeeds or NULL on failure. It's important to check the return value to ensure the function executed successfully.

Here's an example of how getcwd() might be used to retrieve the current working directory:
```bash
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    char *current_directory;
    size_t size = 1024; // Adjust the buffer size as needed.
    current_directory = (char *)malloc(size);

    if (current_directory == NULL) {
        perror("malloc");
        return 1;
    }

    if (getcwd(current_directory, size) != NULL) {
        printf("Current working directory: %s\n", current_directory);
    } else {
        perror("getcwd");
        free(current_directory);
        return 1;
    }

    free(current_directory);
    return 0;
}
```
In this example, getcwd() is used to retrieve the current working directory and store it in the current_directory buffer. You should ensure that the buffer is large enough to accommodate the path, and don't forget to free the allocated memory when you're done with it.

<br>
<br>
<div id="chdir">

# Chdir() function

The chdir() function in the C language is used to change the current working directory of a process. The current working directory is the directory in the file system where the process is currently located or "working" in. This function allows you to navigate and switch between directories within your program.

The signature of the chdir() function is as follows:
```bash
#include <unistd.h>

int chdir(const char *path);
```
The parameter of the chdir() function is:

- `path`: This is a pointer to a null-terminated string that specifies the path of the directory to which the current working directory should be changed.
The chdir() function changes the current working directory of the calling process to the directory specified by the path argument. If the operation is successful, it returns 0. On failure, it returns -1, and you can check the error code using errno to determine the cause of the error.

Here's an example of how chdir() might be used to change the current working directory:
```bash
#include <stdio.h>
#include <unistd.h>

int main() {
    const char *new_directory = "/path/to/your/directory"; // Replace with the desired directory path.

    if (chdir(new_directory) == 0) {
        printf("Changed working directory to: %s\n", new_directory);
    } else {
        perror("chdir");
        return 1;
    }

    return 0;
}
```
In this example, chdir() is used to change the current working directory to the specified path (/path/to/your/directory). You should replace this path with the directory you want to navigate to. If the operation is successful, it prints the new working directory. If it fails, it reports the error using perror().

<br>
<br>
<div id="stat">

# Stat() function

The stat() function in the C language is used to retrieve information about a file specified by its pathname. It provides various details about the file, such as its size, permissions, and timestamps. This function operates on symbolic links by following them and providing information about the linked-to file.

The signature of the stat() function is as follows:
```bash
#include <sys/stat.h>

int stat(const char *pathname, struct stat *buf);
```
The parameters of the stat() function are:

- `pathname`: This is a pointer to a null-terminated string representing the path to the file you want to obtain information about.
- `buf`: This is a pointer to a struct stat where the file information will be stored upon a successful call to stat().
The stat() function fills the provided struct stat with information about the file specified by the pathname. You can access various attributes of the file from the struct stat, such as its size, permissions, timestamps, and more.

Here's an example of how stat() might be used to retrieve information about a file:
```bash
#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *file_path = "example.txt"; // Replace with the path to your file.
    struct stat file_info;

    if (stat(file_path, &file_info) == 0) {
        printf("File size: %lld bytes\n", (long long)file_info.st_size);
        printf("File permissions: %o\n", file_info.st_mode & 0777);
        // Access more file information from the 'file_info' struct as needed.
    } else {
        perror("stat");
        return 1;
    }

    return 0;
}
```
In this example, stat() is used to retrieve and print information about a file, such as its size and permissions.

<br>
<br>
<div id="lstat">

# Lstat() function

The lstat() function is similar to stat() but specifically designed to provide information about a symbolic link, rather than following the link and providing information about the linked-to file. It retrieves details about the symbolic link itself.

The signature of the lstat() function is the same as that of stat():
```bash
#include <sys/stat.h>

int lstat(const char *pathname, struct stat *buf);
```
The parameters are the same as well:

- `pathname`: This is a pointer to a null-terminated string representing the path to the symbolic link you want to obtain information about.
- `buf`: This is a pointer to a struct stat where the symbolic link information will be stored upon a successful call to lstat().

Here's an example of how lstat() might be used:
```bash
#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *symlink_path = "symbolic_link"; // Replace with the path to your symbolic link.
    struct stat symlink_info;

    if (lstat(symlink_path, &symlink_info) == 0) {
        printf("Symbolic link size: %lld bytes\n", (long long)symlink_info.st_size);
        printf("Symbolic link permissions: %o\n", symlink_info.st_mode & 0777);
        // Access more symbolic link information from the 'symlink_info' struct as needed.
    } else {
        perror("lstat");
        return 1;
    }

    return 0;
}
```
In this example, lstat() is used to retrieve and print information about a symbolic link identified by its pathname (symlink_path). The key difference is that lstat() provides information about the symbolic link itself and not the linked-to file.

<br>
<br>
<div id="fstat">

# Fstat() function

The fstat() function in the C language is used to retrieve information about an open file, identified by its file descriptor. It provides the same type of file information as stat(), but it operates on an already opened file, not a file identified by pathname.

The signature of the fstat() function is as follows:
```bash
#include <sys/stat.h>

int fstat(int fd, struct stat *buf);
```
The parameters of the fstat() function are:

- `fd`: This is an integer representing the file descriptor of the open file for which you want to obtain information.
- `buf`: This is a pointer to a struct stat where the file information will be stored upon a successful call to fstat().
The fstat() function retrieves and fills the provided struct stat with information about the open file identified by the fd.

Here's an example of how fstat() might be used to retrieve information about an open file:
```bash
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char *file_path = "example.txt"; // Replace with the path to your file.
    int fd = open(file_path, O_RDONLY);
    struct stat file_info;

    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (fstat(fd, &file_info) == 0) {
        printf("File size: %lld bytes\n", (long long)file_info.st_size);
        printf("File permissions: %o\n", file_info.st_mode & 0777);
        // Access more file information from the 'file_info' struct as needed.
    } else {
        perror("fstat");
        return 1;
    }

    close(fd);
    return 0;
}
```
In this example, fstat() is used to retrieve and print information about an open file identified by its file descriptor (fd).

<br>
<br>
<div id="opendir">

# Opendir() function

The opendir() function in the C language is used to open and create a directory stream for reading the contents of a directory. It allows you to access the files and subdirectories within a directory.

The signature of the opendir() function is as follows:
```bash
#include <dirent.h>

DIR *opendir(const char *dirname);
```
The parameter of the opendir() function is:

- `dirname`: This is a pointer to a null-terminated string representing the name of the directory you want to open.
The opendir() function opens the directory specified by dirname and returns a pointer to a DIR structure, which is an opaque data type representing the directory stream. You can use this pointer to read the contents of the directory using readdir().

It's important to check the return value of opendir() for errors. If the function fails, it returns NULL, and you can use errno to determine the cause of the error.

Here's an example of how opendir() might be used to open a directory:
```bash
#include <stdio.h>
#include <dirent.h>

int main() {
    const char *directory_path = "/path/to/your/directory"; // Replace with the desired directory path.
    DIR *directory;

    directory = opendir(directory_path);

    if (directory != NULL) {
        printf("Opened directory: %s\n", directory_path);
        // Perform operations with the opened directory.
        closedir(directory); // Don't forget to close the directory when done.
    } else {
        perror("opendir");
        return 1;
    }

    return 0;
}
```
In this example, opendir() is used to open the specified directory, and the opened directory stream is stored in the directory pointer.

<br>
<br>
<div id="readdir">

# Readdir() function

The readdir() function in the C language is used to read the contents of a directory opened with opendir(). It retrieves information about the next entry in the directory, such as the name and file type.

The signature of the readdir() function is as follows:
```bash
#include <dirent.h>

struct dirent *readdir(DIR *dirp);
```
The parameter of the readdir() function is:

- `dirp`: This is a pointer to a DIR structure, representing the directory stream obtained from opendir().
The readdir() function reads the next directory entry from the directory stream pointed to by dirp and returns a pointer to a struct dirent structure, which contains information about the entry. When there are no more entries or an error occurs, it returns NULL.

Here's an example of how readdir() might be used to read and print the contents of a directory:
```bash
#include <stdio.h>
#include <dirent.h>

int main() {
    const char *directory_path = "/path/to/your/directory"; // Replace with the desired directory path.
    DIR *directory;
    struct dirent *entry;

    directory = opendir(directory_path);

    if (directory != NULL) {
        printf("Contents of directory: %s\n", directory_path);
        while ((entry = readdir(directory)) != NULL) {
            printf("Entry name: %s\n", entry->d_name);
        }
        closedir(directory);
    } else {
        perror("opendir");
        return 1;
    }

    return 0;
}
```
In this example, readdir() is used in a loop to read and print the names of all directory entries within the specified directory.

<br>
<br>
<div id="closedir">

# Closedir() function

The closedir() function in the C language is used to close a directory stream previously opened with opendir(). It releases the resources associated with the directory stream.

The signature of the closedir() function is as follows:
```bash
#include <dirent.h>

int closedir(DIR *dirp);
```
The parameter of the closedir() function is:

-`dirp`: This is a pointer to a DIR structure representing the directory stream to be closed.
The closedir() function closes the directory stream pointed to by dirp. It's important to call closedir() to release resources and free memory associated with the directory stream when you're done working with it.

Here's an example of how closedir() might be used to close a directory stream:

#include <stdio.h>
#include <dirent.h>
```bash
int main() {
    const char *directory_path = "/path/to/your/directory"; // Replace with the desired directory path.
    DIR *directory;

    directory = opendir(directory_path);

    if (directory != NULL) {
        printf("Opened directory: %s\n", directory_path);
        // Perform operations with the opened directory.
        closedir(directory); // Close the directory when done.
    } else {
        perror("opendir");
        return 1;
    }

    return 0;
}
```
In this example, closedir() is used to close the directory stream when the program is finished working with it.

<br>
<br>
<div id="isatty">

# Isatty() function

The isatty() function in the C language is used to determine whether a file descriptor refers to a terminal or not. It checks whether the given file descriptor is associated with a terminal device, such as a terminal, console, or serial port.

The signature of the isatty() function is as follows:
```bash
#include <unistd.h>

int isatty(int fd);
```
The parameter of the isatty() function is:

-`fd`: This is an integer representing the file descriptor you want to check.
The isatty() function returns 1 if the file descriptor fd is associated with a terminal, and 0 otherwise. It's commonly used to perform terminal-specific operations or behavior in programs.

Here's an example of how isatty() might be used to check if a file descriptor is associated with a terminal:
```bash
#include <stdio.h>
#include <unistd.h>

int main() {
    int file_descriptor = STDOUT_FILENO; // Replace with the file descriptor you want to check.

    if (isatty(file_descriptor)) {
        printf("File descriptor %d is associated with a terminal.\n", file_descriptor);
    } else {
        printf("File descriptor %d is not associated with a terminal.\n", file_descriptor);
    }

    return 0;
}
```
In this example, isatty() is used to determine whether the file descriptor STDOUT_FILENO (standard output) is associated with a terminal.

<br>
<br>
<div id="ttyname">

# Ttyname() function

The ttyname() function in the C language is used to obtain the name of the terminal device associated with a given file descriptor. It returns a pointer to a null-terminated string containing the device name.

The signature of the ttyname() function is as follows:
```bash
#include <unistd.h>

char *ttyname(int fd);
```
The parameter of the ttyname() function is:

- `fd`: This is an integer representing the file descriptor for which you want to retrieve the associated terminal device name.
The ttyname() function returns a pointer to a string containing the name of the terminal device associated with the specified file descriptor. If the file descriptor is not associated with a terminal, it returns NULL.

Here's an example of how ttyname() might be used to obtain the terminal device name associated with a file descriptor:
```bash
#include <stdio.h>
#include <unistd.h>

int main() {
    int file_descriptor = STDOUT_FILENO; // Replace with the file descriptor you want to check.
    char *device_name;

    device_name = ttyname(file_descriptor);

    if (device_name != NULL) {
        printf("Terminal device name for file descriptor %d: %s\n", file_descriptor, device_name);
    } else {
        printf("File descriptor %d is not associated with a terminal.\n", file_descriptor);
    }

    return 0;
}
```
In this example, ttyname() is used to retrieve and print the terminal device name associated with the file descriptor STDOUT_FILENO (standard output).

<br>
<br>
<div id="ttyslot">

# Ttyslot() function

The ttyslot() function in the C language is used to obtain the slot number of the terminal associated with the controlling process's terminal. It's typically used in conjunction with other terminal-related functions to identify the terminal.

The signature of the ttyslot() function is as follows:
```bash
#include <unistd.h>

int ttyslot(void);
```
The ttyslot() function takes no arguments.

The ttyslot() function returns the slot number of the terminal associated with the controlling process. If no terminal is associated, it returns -1.

Here's an example of how ttyslot() might be used:
```bash
#include <stdio.h>
#include <unistd.h>

int main() {
    int slot_number = ttyslot();

    if (slot_number != -1) {
        printf("Terminal slot number: %d\n", slot_number);
    } else {
        printf("No terminal associated with the controlling process.\n");
    }

    return 0;
}
```
In this example, ttyslot() is used to obtain and print the slot number of the terminal associated with the controlling process.

<br>
<br>
<div id="ioctl">

# Ioctl() function

The ioctl() function in the C language is a versatile system call used for various input/output control operations on devices and file descriptors. It allows you to perform device-specific control operations and manipulate terminal attributes, among other things.

The signature of the ioctl() function is as follows:
```bash
#include <sys/ioctl.h>

int ioctl(int fd, unsigned long request, ...);
```
The parameters of the ioctl() function are:

- `fd`: This is an integer representing the file descriptor or device to which the operation applies.
request: This is an unsigned long integer representing the specific operation to be performed.
Additional arguments: Depending on the request, there may be additional arguments required to carry out the operation.
The ioctl() function is highly device-dependent, and the request value determines the exact operation to be performed. It's commonly used for tasks like

Here's an example of how ioctl() might be used to manipulate terminal attributes, specifically to retrieve the terminal size:
```bash
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

int main() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        perror("ioctl");
        return 1;
    }

    printf("Terminal size:\n");
    printf("  Rows: %d\n", w.ws_row);
    printf("  Columns: %d\n", w.ws_col);

    return 0;
}
```
In this example, ioctl() is used with the TIOCGWINSZ request to retrieve the terminal size. The terminal size information is stored in a struct winsize, and the resulting values for the number of rows and columns are printed to the console. This is a common use case of ioctl() to interact with terminal attributes.

<br>
<br>
<div id="getenv">

# Getenv() function

The getenv() function in the C language is used to retrieve the value of an environment variable. Environment variables are key-value pairs that can store configuration information or data accessible to a process.

The signature of the getenv() function is as follows:
```bash
#include <stdlib.h>

char *getenv(const char *name);
```
The parameter of the getenv() function is:

- `name`: This is a pointer to a null-terminated string representing the name of the environment variable you want to retrieve.
The getenv() function searches for the environment variable with the specified name and returns a pointer to the value associated with that variable. If the variable is not found, it returns NULL.

Here's an example of how getenv() might be used to retrieve the value of an environment variable:
```bash
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *variable_name = "HOME"; // Replace with the desired environment variable name.
    char *variable_value;

    variable_value = getenv(variable_name);

    if (variable_value != NULL) {
        printf("Value of %s: %s\n", variable_name, variable_value);
    } else {
        printf("Environment variable %s not found.\n", variable_name);
    }

    return 0;
}
```
In this example, getenv() is used to retrieve and print the value of the HOME environment variable.

<br>
<br>
<div id="tcsetattr">

# Tcsetattr() function

The tcsetattr() function in the C language is used to set the terminal attributes of a terminal device. It allows you to configure various aspects of terminal behavior, such as echo mode, line editing, and more.

The signature of the tcsetattr() function is as follows:
```bash
#include <termios.h>

int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
```
The parameters of the tcsetattr() function are:

- `fd`: This is an integer representing the file descriptor associated with the terminal device.
- `optional_actions`: This is an integer representing the optional actions to be taken when setting the terminal attributes.
- `termios_p`: This is a pointer to a struct termios that contains the new terminal attributes.
The tcsetattr() function sets the terminal attributes of the terminal device represented by fd to the values specified in the termios structure pointed to by termios_p. The optional_actions parameter specifies when the changes should take effect.

Here's an example of how tcsetattr() might be used to configure terminal attributes:
```bash
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios term_settings;

    // Get the current terminal attributes.
    if (tcgetattr(STDIN_FILENO, &term_settings) == -1) {
        perror("tcgetattr");
        return 1;
    }

    // Modify the terminal attributes as needed.
    term_settings.c_lflag &= ~ECHO; // Disable echo mode.

    // Set the modified terminal attributes.
    if (tcsetattr(STDIN_FILENO, TCSANOW, &term_settings) == -1) {
        perror("tcsetattr");
        return 1;
    }

    printf("Terminal attributes updated.\n");

    // Restore terminal attributes to their original state if necessary.

    return 0;
}
```
In this example, tcgetattr() is used to retrieve the current terminal attributes, and tcsetattr() is used to modify the terminal attributes to disable echo mode.

<br>
<br>
<div id="tcgetattr">

# Tcgetattr() function

The tcgetattr() function in the C language is used to retrieve the current terminal attributes of a terminal device. It allows you to query the current terminal settings, including characteristics like baud rate, line discipline, and more.

The signature of the tcgetattr() function is as follows:
```bash
#include <termios.h>

int tcgetattr(int fd, struct termios *termios_p);
```
The parameters of the tcgetattr() function are:

- `fd`: This is an integer representing the file descriptor associated with the terminal device.
- `termios_p`: This is a pointer to a struct termios where the current terminal attributes will be stored.
The tcgetattr() function retrieves the current terminal attributes of the terminal device represented by fd and stores them in the termios structure pointed to by termios_p.

Here's an example of how tcgetattr() might be used to retrieve and print the current terminal attributes:
```bash
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios term_settings;

    if (tcgetattr(STDIN_FILENO, &term_settings) == -1) {
        perror("tcgetattr");
        return 1;
    }

    // Print terminal attributes.
    printf("Baud rate: %d\n", cfgetospeed(&term_settings));
    printf("Character size: %d\n", term_settings.c_cflag & CSIZE);
    printf("Control flags: 0x%08x\n", term_settings.c_cflag);

    // Add more attributes as needed.

    return 0;
}
```
In this example, tcgetattr() is used to retrieve the current terminal attributes, and various attributes are printed to the console.

<br>
<br>
<div id="tgetent">

# Tgetent() function

The tgetent() function is part of the terminfo library and is used to initialize the terminal description database. It allows you to access terminal capabilities and information defined in the terminfo database.

The signature of the tgetent() function is as follows:
```bash
#include <curses.h>

int tgetent(char *bp, const char *name);
```
The parameters of the tgetent() function are:

- `bp`: This is a pointer to a buffer where the terminal description will be stored.
- `name`: This is a pointer to a null-terminated string representing the name of the terminal type you want to access.
The tgetent() function initializes the terminal description database for the specified terminal type. It loads the terminal capabilities and information into the bp buffer for later use with functions like tgetflag() and tgetnum().

Here's an example of how tgetent() might be used:
```bash
#include <stdio.h>
#include <curses.h>

int main() {
    char term_buffer[1024]; // Adjust the buffer size as needed.
    const char *terminal_type = "xterm"; // Replace with the desired terminal type.

    if (tgetent(term_buffer, terminal_type) != 1) {
        printf("Failed to initialize terminal database for %s.\n", terminal_type);
        return 1;
    }

    // Use terminal capabilities and information with other terminfo functions.

    return 0;
}
```
In this example, tgetent() is used to initialize the terminal description database for the specified terminal type, and the database is stored in the term_buffer.

<br>
<br>
<div id="tgetflag">

# Tgetflag() function

The tgetflag() function is part of the terminfo library and is used to retrieve boolean terminal capabilities from the terminal description database. It allows you to check whether specific terminal features are supported.

The signature of the tgetflag() function is as follows:
```bash
#include <curses.h>

int tgetflag(const char *id);
```
The parameter of the tgetflag() function is:

- `id`: This is a pointer to a null-terminated string representing the name of the terminal capability you want to retrieve.
The tgetflag() function retrieves the boolean value associated with the specified terminal capability id from the terminal description database. It returns 1 if the capability is present and 0 if it is not.

Here's an example of how tgetflag() might be used:
```bash
#include <stdio.h>
#include <curses.h>

int main() {
    const char *capability_name = "am"; // Replace with the desired terminal capability name.
    int flag_value;

    flag_value = tgetflag(capability_name);

    if (flag_value) {
        printf("Terminal capability %s is supported.\n", capability_name);
    } else {
        printf("Terminal capability %s is not supported.\n", capability_name);
    }

    return 0;
}
```
In this example, tgetflag() is used to check whether the specified terminal capability is supported.

<br>
<br>
<div id="tgetnum">

# Tgetnum() function

The tgetnum() function is part of the terminfo library and is used to retrieve numeric terminal capabilities from the terminal description database. It allows you to obtain numerical values associated with terminal features.

The signature of the tgetnum() function is as follows:
```bash
#include <curses.h>

int tgetnum(const char *id);
```
The parameter of the tgetnum() function is:

- `id`: This is a pointer to a null-terminated string representing the name of the terminal capability you want to retrieve.
The tgetnum() function retrieves the numeric value associated with the specified terminal capability id from the terminal description database. It returns -1 if the capability is not found.

Here's an example of how tgetnum() might be used:
```bash
#include <stdio.h>
#include <curses.h>

int main() {
    const char *capability_name = "cols"; // Replace with the desired terminal capability name.
    int numeric_value;

    numeric_value = tgetnum(capability_name);

    if (numeric_value != -1) {
        printf("Value of terminal capability %s: %d\n", capability_name, numeric_value);
    } else {
        printf("Terminal capability %s is not supported or has no numeric value.\n", capability_name);
    }

    return 0;
}
```
In this example, tgetnum() is used to retrieve and print the numeric value associated with the specified terminal capability.

<br>
<br>
<div id="tgetstr">

# Tgetstr() function

The tgetstr() function is part of the terminfo library and is used to retrieve string terminal capabilities from the terminal description database. It allows you to obtain control strings that can be used to perform terminal-specific operations, such as moving the cursor, changing text attributes, and more.

The signature of the tgetstr() function is as follows:
```bash
#include <curses.h>

char *tgetstr(const char *id, char **area);
```
The parameters of the tgetstr() function are:

- `id`: This is a pointer to a null-terminated string representing the name of the terminal capability you want to retrieve.
- `area`: This is a pointer to a pointer that is used to manage the storage of the retrieved string capability.
The tgetstr() function retrieves the string capability associated with the specified terminal capability id from the terminal description database. It returns a pointer to the control string or NULL if the capability is not found.

Here's an example of how tgetstr() might be used:
```bash
#include <stdio.h>
#include <curses.h>

int main() {
    const char *capability_name = "clear"; // Replace with the desired terminal capability name.
    char *capability_string;

    capability_string = tgetstr(capability_name, NULL);

    if (capability_string != NULL) {
        printf("Control string for terminal capability %s: %s\n", capability_name, capability_string);
    } else {
        printf("Terminal capability %s is not supported.\n", capability_name);
    }

    return 0;
}
```
In this example, tgetstr() is used to retrieve and print the control string associated with the specified terminal capability.

<br>
<br>
<div id="tgoto">

# Tgoto() function

The tgoto() function is part of the terminfo library and is used to construct a control string for cursor addressing. It allows you to build control strings that move the cursor to specific positions on the terminal screen.

The signature of the tgoto() function is as follows:
```bash
#include <curses.h>

char *tgoto(const char *cm, int col, int row);
```
The parameters of the tgoto() function are:

- `cm`: This is a pointer to a null-terminated string representing the cursor movement capability.
- `col`: This is an integer representing the target column (horizontal position) on the screen.
- `row`: This is an integer representing the target row (vertical position) on the screen.
The tgoto() function constructs a control string using the cursor movement capability cm to move the cursor to the specified col and row positions on the terminal screen. It returns a pointer to the constructed control string.

Here's an example of how tgoto() might be used:
```bash
#include <stdio.h>
#include <curses.h>

int main() {
    const char *cursor_move_capability = "\033[%d;%dH"; // Replace with the desired cursor movement capability.
    int target_col = 5;
    int target_row = 10;
    char *control_string;

    control_string = tgoto(cursor_move_capability, target_col, target_row);

    if (control_string != NULL) {
        printf("Control string for cursor move: %s\n", control_string);
    } else {
        printf("Failed to construct cursor move control string.\n");
    }

    return 0;
}
```
In this example, tgoto() is used to construct a control string that moves the cursor to the specified column and row positions on the terminal screen.

<br>
<br>
<div id="tputs">

# Tputs() function

The tputs() function is part of the terminfo library and is used to output a terminal control string to the terminal. It allows you to send control strings obtained from tgetstr() or tgoto() to the terminal to perform various operations.

The signature of the tputs() function is as follows:
```bash
#include <curses.h>

int tputs(const char *str, int affcnt, int (*putc)(int));
```
The parameters of the tputs() function are:

- `str`: This is a pointer to a null-terminated string representing the control string to be sent to the terminal.
- `affcnt`: This is an integer that is typically set to 1 and represents the number of affected lines.
- `putc`: This is a function pointer to a function that is used to output characters to the terminal. It is typically set to putchar or a similar function.
The tputs() function sends the control string specified by str to the terminal for execution. The putc function is responsible for actually sending characters to the terminal, and affcnt indicates the number of lines affected by the control string.

Here's an example of how tputs() might be used to clear the terminal screen:
```bash
#include <curses.h>

int main() {
    char *clear_screen = tgetstr("clear", NULL);

    if (clear_screen != NULL) {
        tputs(clear_screen, 1, putchar);
    } else {
        printf("Clear screen capability not supported.\n");
    }

    return 0;
}
```
In this example, tputs() is used to send the "clear" control string to the terminal, which clears the screen. The putchar function is used to output characters to the terminal.

<br>
<br>
<div id="malloc">

# Malloc() function

The malloc() function in the C language is used for dynamic memory allocation. It allows you to allocate a specified number of bytes from the heap memory at runtime. The term "malloc" stands for "memory allocation."

The signature of the malloc() function is as follows:
```bash
#include <stdlib.h>

void *malloc(size_t size);
```
- `size` : this represents the number of bytes to allocate. It specifies the amount of memory you want to request from the operating system. The malloc() function returns a void pointer (void *) that points to the beginning of the allocated memory block.

It is important to check the return value of malloc() to ensure that the memory allocation was successful. If malloc() returns a NULL pointer, it indicates that the requested memory allocation failed. In such cases, you should handle the error appropriately. Also, it is essential to deallocate the memory block using the free() function when you no longer need it to avoid memory leaks.

<br>
<br>
<div id="free">

# Free() Function

The free() function in the C language is used to deallocate memory that was previously allocated dynamically using functions like malloc(), calloc(), or realloc().

The signature of the free() function is as follows:
```bash
#include <stdlib.h>

void free(void *ptr);
```

- `*ptr` : this is a pointer to the memory block that needs to be freed. It should correspond to a memory block previously allocated using malloc(), calloc(), or realloc(). If ptr is a NULL pointer, the free() function does nothing.

When you call the free() function, it releases the specified memory block so that it can be reused later. Once the memory is freed, you should no longer access its content as it would result in undefined behavior.

<br>
<br>
<div id="write">

# Write() Function

The write() function in the C language is used to write data to a file or a file descriptor. It is typically used to write data to standard output (stdout) or to a file that has been opened for writing.

The signature of the write() function is as follows:

```bash
#include <unistd.h>

ssize_t write(int fd, const void *buffer, size_t count);
```

The parameters of the write() function are:

- `fd` : It represents the file descriptor or the file handle to which the data will be written. For example, 1 represents standard output (stdout), and values greater than 2 represent file descriptors obtained using functions like open().
- `buffer` : It is a pointer to the buffer containing the data that will be written.
- `count` : It specifies the number of bytes to write from the buffer.

The write() function returns the number of bytes successfully written to the file or file descriptor. If the return value is -1, it indicates an error occurred during the write operation.

<br>
<br>
<div id="read">

# Read() Function

The read() function in the C language is used to read data from a file descriptor. It is typically used with files or sockets, but it can also be used with other types of input data streams.

The signature of the read() function is as follows:
```bash
#include <unistd.h>

ssize_t read(int fd, void *buffer, size_t count);
```

The parameters of the read() function are:

- `fd` : This is the file descriptor from which the data should be read. A file descriptor is an integer that identifies an open file or another type of input data stream. For example, 0 represents standard input (stdin), 1 represents standard output (stdout), and 2 represents standard error (stderr). File descriptors are typically obtained using functions like open() or socket().
- `buffer` : This is a pointer to the buffer where the read data will be stored.
- `count` : It specifies the maximum number of bytes to read from the file descriptor.

The read() function returns the number of bytes read from the file descriptor. If the returned value is -1, it indicates a read error.

<br>
<br>
<div id="open">

# Open() Function

The open() function in the C language is used to open a file and obtain a file descriptor, which is a unique identifier for an open file. It allows you to perform various operations on the file, such as reading, writing, or modifying its attributes.

The signature of the open() function is as follows:
```bash
#include <fcntl.h>

int open(const char *pathname, int flags, mode_t mode);
```

The parameters of the open() function are:

- `pathname` : It is a string that represents the path to the file you want to open.
- `flags` : It specifies the flags that control the opening and behavior of the file. Flags can include O_RDONLY (open for reading), O_WRONLY (open for writing), O_RDWR (open for reading and writing), O_CREAT (create the file if it doesn't exist), O_TRUNC (truncate the file if it exists), and more. Multiple flags can be combined using the bitwise OR operator (|).
- `mode` : It specifies the permissions to set on the file if O_CREAT flag is used. The mode is typically specified using constants defined in the <sys/stat.h> header, such as S_IRUSR (read permission for the owner), S_IWUSR (write permission for the owner), S_IRGRP (read permission for the group), and so on.

The open() function returns a file descriptor on success, which is a non-negative integer. If an error occurs, it returns -1, indicating the failure to open the file.

<br>
<br>
<div id="close">

# Close() Function

The close() function in the C language is used to close a file descriptor. It terminates the connection between the file descriptor and the corresponding open file, releasing any resources associated with it. After closing a file, further operations on that file descriptor are not possible unless the file is opened again.

The signature of the close() function is as follows:
```bash
#include <unistd.h>

int close(int fileDescriptor);
```

The parameter of the close() function is:

- `fileDescriptor` : It is an integer representing the file descriptor of the file to be closed.

The close() function returns 0 on success. If an error occurs while closing the file, it returns -1.

It is important to note that closing a file descriptor does not necessarily imply flushing any buffered data. Therefore, it's recommended to use functions like fsync() or fclose() (for standard library file streams) if you want to ensure that any buffered data is written to the file before closing it.

<br>
<br>
<div id="access">

# Access() Function

The access() function in the C language is used to check the accessibility or permission of a file or directory. It allows you to determine whether a specific file or directory can be accessed in a specified mode.

The signature of the access() function is as follows:

```bash
#include <unistd.h>

int access(const char *pathname, int mode);
```

The parameters of the access() function are:

- `pathname` : It is a string representing the path to the file or directory you want to check.
- `mode` : It specifies the accessibility mode, which can be F_OK to check the existence of the file, R_OK to check read permission, W_OK to check write permission, and X_OK to check execute permission. Multiple modes can be combined using the bitwise OR operator (|).

The access() function returns 0 if the file or directory exists and has the specified permissions according to the mode provided. If the file or directory doesn't exist or doesn't have the specified permissions, or if an error occurs, it returns -1.

Note that the access() function is useful for checking permissions before attempting to perform operations on a file or directory. However, keep in mind that the accessibility status can change between the access() call and subsequent operations, so it's important to handle potential errors or exceptions appropriately.

<br>
<br>
<div id="dup">

# Dup() and Dup2() Functions

The dup() function in C is used to duplicate an existing file descriptor. It creates a new file descriptor that refers to the same file or socket as the original descriptor. The new file descriptor is guaranteed to be the lowest available descriptor.

The signature of the dup() function is as follows:
```bash
#include <unistd.h>

int dup(int oldfd);
```

The dup() function takes the file descriptor oldfd as an argument and returns a new file descriptor on success. If an error occurs, it returns -1.

The dup2() function in C is similar to dup(), but it allows you to specify the desired file descriptor number for the duplicated descriptor. If the specified file descriptor number is already in use, dup2() will close it before duplicating the descriptor.

The signature of the dup2() function is as follows:
```bash
#include <unistd.h>

int dup2(int oldfd, int newfd);
```

The dup2() function takes two arguments: oldfd, the file descriptor to duplicate, and newfd, the desired file descriptor number for the duplicated descriptor. It returns the new file descriptor on success and -1 on failure.

It's important to note that both dup() and dup2() functions are primarily used for redirection of file descriptors, enabling output to be redirected to files or other destinations.

<br>
<br>
<div id="exec">

# Execve() Function

The execve() function in the C language is used to execute a program in place of the currently running process. It is part of the exec family of functions and allows you to replace the current process image with a new program.

The signature of the execve() function is as follows:

```bash
#include <unistd.h>

int execve(const char *pathname, char *const argv[], char *const envp[]);
```

The parameters of the execve() function are:

- `pathname` : It is a string that represents the path to the executable file you want to execute.
- `argv[]` : It is an array of strings that represents the program arguments. The last element of the array must be a NULL pointer.
- `envp[]` : It is an array of strings that represents the environment variables. The last element of the array must be a NULL pointer. If envp is set to NULL, the current environment is used.

The execve() function returns -1 on error, and on success, it does not return at all because the current process image is replaced by the new program.

It's important to note that the execve() function is a powerful tool for process execution, as it allows you to run other programs from within your program. However, it's crucial to handle errors appropriately and ensure that the necessary permissions and file paths are correctly set for the program you want to execute.

<br>
<br>
<div id="exit">

# Exit() Function

The exit() function in the C language is used to terminate the program and return control to the operating system. It allows you to explicitly exit the program at any point during its execution.

The signature of the exit() function is as follows:
```bash
#include <stdlib.h>

void exit(int status);
```

The parameter of the exit() function is:

- `status` : It is an integer value that represents the exit status of the program. A value of 0 typically indicates a successful execution, while a non-zero value indicates an error or abnormal termination.

The exit() function does not return to the calling function. It performs the following actions before terminating the program:

- Calls functions registered with the atexit() function, if any. These functions are typically used for performing cleanup tasks or freeing resources before the program exits.
- Closes open file descriptors, including standard input, standard output, and standard error.
- Flushes buffered output.
- Terminates the program and returns control to the operating system, along with the specified exit status.

The exit() function is commonly used to gracefully terminate a program and communicate its execution status to the calling environment or script. By convention, a value of 0 often represents successful execution, while non-zero values indicate various error conditions or abnormal terminations.

<br>
<br>
<div id="fork">

# Fork() Function

The fork() function in the C language is used to create a new process by duplicating the existing process. It creates a child process that is an exact copy of the parent process, including its code, data, and stack. After the fork() call, two separate processes, the parent process and the child process, are running concurrently.

The signature of the fork() function is as follows:

```bash
#include <unistd.h>

pid_t fork(void);
```

The fork() function does not take any arguments. It returns different values for the parent and child processes:

In the parent process, fork() returns the process ID (PID) of the child process.
In the child process, fork() returns 0.
If an error occurs during the fork() call, it returns -1.

When the program is executed, it will create a child process that starts executing from the point of the fork() call. Both the parent and child processes will continue executing from that point independently, but with separate memory spaces.

The fork() function is commonly used for process creation and parallel execution in C programs. It allows you to perform tasks concurrently and is the basis for many other process-related operations.

<br>
<br>
<div id="wait">

# Wait() and Waitpid() Functions

The wait() and waitpid() functions in the C language are used to wait for the termination of child processes in a parent process.

The wait() function suspends the execution of the calling process until one of its child processes terminates. It allows the parent process to wait for the completion of any child process without specifying a particular child process.
The signature of the wait() function is as follows:

```bash
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *status);
```

The wait() function takes a pointer to an integer status as an argument, which is used to retrieve the termination status of the child process. If the status information is not needed, you can pass NULL.
The wait() function returns the process ID (PID) of the terminated child process, or -1 on error.

<br>

The waitpid() function is similar to wait(), but it allows more control over which child process to wait for. It allows the parent process to wait for the termination of a specific child process or a group of child processes.

The signature of the waitpid() function is as follows:

```bash
#include <sys/types.h>
#include <sys/wait.h>

pid_t waitpid(pid_t pid, int *status, int options);
```

The parameters of the waitpid() function are:

- `pid` : It specifies which child process to wait for. The value of pid can be:
	- -1 to wait for any child process.
	- 0 to wait for any child process in the same process group as the calling process.
	- A positive value representing the process ID of a specific child process to wait for.
- `status` : It is a pointer to an integer used to retrieve the termination status of the child process. If the status information is not needed, you can pass NULL.
- `options` : It specifies additional options for controlling the behavior of waitpid(). Common options include WNOHANG (returns immediately if no child has terminated) and WUNTRACED (returns if a child has stopped, but not terminated).

The waitpid() function returns the process ID (PID) of the terminated child process, 0 if using WNOHANG and no child has terminated, -1 on error, or a negative value to indicate a specific error condition.

<br>
<br>
<div id="pipe">

# Pipe() Function

The pipe() function in the C language is used to create an interprocess communication (IPC) channel between two related processes. It establishes a unidirectional pipe that allows one process to write data to the pipe, while the other process reads the data from it.

The signature of the pipe() function is as follows:

```bash
#include <unistd.h>

int pipe(int pipefd[2]);
```
The pipe() function takes an array pipefd as an argument, which will be populated with two file descriptors: pipefd[0] for reading from the pipe and pipefd[1] for writing to the pipe.

The pipe() function returns 0 on success and -1 on failure.

The pipe acts as a conduit for communication between the parent and child processes. The parent writes a message to the pipe, and the child reads the message from the pipe and prints it.

<br>
<br>
<div id="unlink">

# Unlink() Function

The unlink() function in the C language is used to delete or remove a file from the file system. It allows you to remove a file by specifying its filename or path.

The signature of the unlink() function is as follows:
```bash
#include <unistd.h>

int unlink(const char *pathname);
```

The unlink() function takes a pathname parameter, which is a string representing the path to the file that needs to be deleted.

The unlink() function returns 0 on success and -1 on failure.

It's important to note that the unlink() function permanently removes the file from the file system. Once a file is unlinked, it cannot be recovered, so <strong>caution</strong> should be exercised when using this function.

The unlink() function is commonly used in situations where you need to programmatically delete files in a C program, such as during file management or cleanup operations.

<br>
<br>
<div id="perror">

# Perror() Function

The perror() function in the C language is used to print a descriptive error message to the standard error stream (stderr). It takes a string argument that is typically a custom error message or a label associated with the error. The perror() function then appends a colon and space, followed by the corresponding error message based on the value of the global variable errno.

The signature of the perror() function is as follows:

```bash
#include <stdio.h>

void perror(const char *s);
```

The perror() function takes a const char* argument s, which is the custom error message or label to be printed. If s is not NULL, the error message will be preceded by s:.

The perror() function is a convenient way to display meaningful error messages along with system-specific error descriptions. It helps in diagnosing and debugging errors in C programs by providing more information about the cause of the error.

<br>
<br>
<div id="strerror">

# Strerror() Function

The strerror() function in the C language is used to obtain a human-readable error message corresponding to a given error number. It converts the value of the errno variable into a descriptive error string.

The signature of the strerror() function is as follows:

```bash
#include <string.h>

char *strerror(int errnum);
```

The strerror() function takes an integer argument errnum, which represents the error number for which the error message is to be obtained.

The strerror() function returns a pointer to a string containing the error message associated with the given error number. This string is typically a static string within the implementation, and it should not be modified.

The strerror() function is helpful in scenarios where you want to obtain a human-readable error message based on the error number. It allows you to provide more detailed error information to users or for diagnostic purposes.

<br>
<br>
<a href="#title">Return ↑</a>
<br>
<br>
