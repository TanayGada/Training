### 1. ping
- `ping www.google.com`

### 2. netstat
- shows active internet connections

### 3. ifconfig
- shows network interfaces
- eth0 shows the ip address of the machine
- ethernet is connected to NIC(network interface card)
- localhost is local loopback server (127.0.0.1)

### 4. traceroute / tracepath
- shows the routes used to reach the destination website

### 5. mtr (my traceroute)
- pings and shows the path

### 6. nslookup
- shows the ip of client and server

### 7. telnet
- similar to nslookup, we can use the port number too

### 8. hostname
- shows the hostname of the server

### 9. ip address show
- shows all internet connected service address of the machine

### 10. iwconfig
- shows all wireless attachments to the server

### 11. ss
- same as netstat

### 12. dig
- shows where a website is hosted

### 13. whois
- domain name registry, domain owner, and other detailed info

### 14. arp
- shows the mac address and ip address mapping

### 15. ifplugstatus
- shows interfaces


### 16. curl
- used to call the api endpoints
- `curl -X GET api_endpoint | jq`

### 17. wget
- downlaod from internet using link
- `wget link_address_of_file`

### 18. iptables --list-rules
- shows route tables

### 19. watch
- `watch mtr google.com`
- every 2 sec runs any command

### 20. nmap 
- network map
- `nmap -v google.com`