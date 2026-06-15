# Linux Shell Commands
## Basic Commands
### 1. ls
- list files and directories
- `-l` & `-ltr` detailed output

### 2. cd
- change directory

### 3. mkdir
- make new directory

### 4. pwd
- present working directory

### 5. touch
- make new file

### 6. rm
- remove file
- `-r` remove everything inside a directory

### 7. rmdir
- remove directory

### 8. cat
- view file content

### 9. echo
- output a text
- `echo "hello" > test.txt"

### 10. zcat
- 

### 11. head
- print top 10 lines
- `head -n 5 file_name`

### 12. tail
- print bottom 10 lines
- `-f` prints new incoming text

### 13. less, more
- output file content in a paginated manner

## Useful commands

### 1. cp
- copy file at `source` to `destination`
- eg. `cp source destination`
- eg. `cp TANAY/marksheet.png FYP/`
- eg. `cp -r TANAY/ FYP/`

### 2. mv
- Move file from source to destination
- eg. `mv source destination`
- eg. `mv TANAY/marksheet.png FYP/`
- rename: `mv TANAY/ USER`

### 3. wc
- no of lines, no of words, and no of bytes

### 4. ln
- hardlink: `ln hardlink-file path_to_file`
- softlink: `ln -s path_to_file`

### 5. cut
- outputs a certain portion from a file
- eg. `cut -b 1 test.txt` -> outputs 1 byte from test.txt
- eg. `cut -b 1-4 test.txt` -> outputs 1 to 4 bytes from test.txt

### 6. sort
- sort text in file

### 7. diff
- see difference between 2 files

## Advanced Commands
### 1. ssh
- connects to port 22 on server
- ssh key gen -> generated public and private key of the machine
- putty is used to connect to Windows

### 2. df
- disk usage
- `-h` shows in high level

### 3. top
- shows all running processes

### 4. ps
- processId of particular process

### 5. kill
- `kill -9 processId` kill process

### 6. free
- shows details about ram
- `free -h` -> detailed view

### 7. nhop
- used to store output of a command to a file
- `nhop free -h`

### 8. vmstat
- shows detail about virtual memory
- `vmstat -a` active and inactive