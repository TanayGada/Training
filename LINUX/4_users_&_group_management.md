## System level commands
### 1. uname
- names the platform which we are using

### 2. uptime
- shows machine is runnig since when

### 3. who
- shows details of all users

### 4. whoami
- shows details of current logged in user

### 5. which
- location of a package
- `which bash`, or `which python`

### 6. id
- shows details of userId(uid), groupId(gid), and all groups presents

### 7. shutdown
- turn off the machine

### 8. reboot
- restart the machine

### 9. apt
- application package manager

### 10. useradd
- add a new user in current group
- `sudo useradd -m new_user`

### 11. passwd
- set password for a user
- `sudo passwd new_user`

### 12. su
- switch user
- `su new_user`

### 13. userdel
- delete user
- `sudo userdel new_user`

### 14. groupadd
- create a group
- `sudo useradd tester1`
- `sudo useradd tester2`
- `sudo useradd tester3`
- `sudo useradd tester4`
- `sudo groupadd testers`

### 15. gpasswd
- add users to a group
- `sudo gpasswd -a tester1 testers`
- add multiple users to a group
- `sudo gpasswd -M tester2, tester3, tester4 testers`

### 16. cat etc/group
- shows info about groups and its members

### 17. groupdel
- delete group