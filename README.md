# 📝 Get Next Line (GNL) - 42/1337 Project

![42 Logo](https://upload.wikimedia.org/wikipedia/commons/5/50/42_School_logo.png)

Welcome to **Get Next Line**, a project from **42/1337 coding school**!  
The purpose of this project is to write a function that reads a line from a file descriptor and returns it, **one line at a time**.

---

## 📌 Project Overview

`get_next_line` allows you to read files **line by line** without loading the entire file into memory.  
This is especially useful for handling **large files** efficiently.

- Reads from any file descriptor (stdin, files, etc.)
- Handles multiple file descriptors (bonus)
- Works with a configurable `BUFFER_SIZE`
- Returns `NULL` on end-of-file or error

---

## ⚙️ Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
