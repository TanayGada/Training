### 1. awk
- AWK allow us to use programming language like features on log files directly in terminal
- AWK need structured/formatted data (csv, tsv, ..), else we use SED
- $x is used to get the output of column x
```
awk '{print $1, $2, $3, $5}' app.log
```
- add filter using //
```
awk '/INFO/ {print $1, $2, $3, $5}' app.log
```
- we want the output in different file
```
awk '/INFO/ {print $1, $2, $3, $5}' app.log > only_info.log
```
- view count of entries having "INFO"
```
awk '/INFO/ {count++} END {print count}' app.log
```
- add condition on logs based on column value
```
awk '$2 > "08:53:00" && $2 < "08:53:59" {print $2, $3, $4}' app.log
```


### 2. SED
- SED works line by line, even if it is not formatted
- print logs only with INFO
```
sed -n '/INFO/p' app.log
```
- replace INFO substring by LOG globally
```
sed 's/INFO/LOG/g' app.log
```

### 3. GREP (Global Regular Expression Print)
- match and find some RE from the global system
```
grep INFO app.log
```
- case insensitive
```
grep -i INFO app.log
```
- we need count
```
grep -i -c INFO app.log
```