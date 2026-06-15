## 1. INSERT INTO Statement
The INSERT INTO statement is used to insert new records in a table.

### Syntax


1. Specify both the column names and the values to be inserted:
```sql
INSERT INTO table_name (column1, column2, column3, ...)
VALUES (value1, value2, value3, ...);
```

2. If adding values for all the columns of the table, no need to specify the column names in the SQL query. Make sure the order of the values is in the same order as the columns in the table.
```sql
INSERT INTO table_name
VALUES (value1, value2, value3, ...);
```

### Insert Multiple Rows

```sql
INSERT INTO Customers (CustomerName, ContactName, Address, City, PostalCode, Country)
VALUES
('Cardinal', 'Tom B. Erichsen', 'Skagen 21', 'Stavanger', '4006', 'Norway'),
('Greasy Burger', 'Per Olsen', 'Gateveien 15', 'Sandnes', '4306', 'Norway'),
('Tasty Tee', 'Finn Egan', 'Streetroad 19B', 'Liverpool', 'L1 0AA', 'UK');
```

#### Make sure each set of values is separated with a comma ,.

## 2. UPDATE Statement

### Syntax
```sql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
```
### Note: The WHERE clause specifies which record(s) that should be updated. If you omit the WHERE clause, all records in the table will be updated!

### Example:
```sql
UPDATE Customers
SET ContactName = 'Alfred Schmidt', City= 'Frankfurt'
WHERE CustomerID = 1;
```

## 2. DELETE Statement
The DELETE statement is used to delete existing records in a table.

### DELETE Syntax
```sql
DELETE FROM table_name WHERE condition;
```

### Note: The WHERE clause specifies which record(s) should be deleted. If you omit the WHERE clause, all records in the table will be deleted!

### Example: delete a single tuple
```sql
DELETE FROM Customers WHERE CustomerName='Alfreds Futterkiste';
```

### Example: Delete All Records
It is possible to delete all rows in a table without deleting the table. This means that the table structure, attributes, and indexes will be intact:
```sql
DELETE FROM table_name;
```

### Example: Delete a Table
To delete the table completely, use the DROP TABLE statement:

```sql
DROP TABLE Customers;
```
## 3. INSERT INTO SELECT Statement
The `INSERT INTO SELECT` statement copies data from one table and inserts it into another existing table.

The `INSERT INTO SELECT` statement requires that the data types in source and target tables match.

### Example: Copy all columns from one table to another table:
```sql
INSERT INTO table2
SELECT * FROM table1
WHERE condition;
```

### Copy only some columns from one table into another table:
```sql
INSERT INTO table2 (column1, column2, column3, ...)
SELECT column1, column2, column3, ...
FROM table1
WHERE condition;
```

### Example: Copy "Suppliers" into "Customers" (fill all columns):
```sql
INSERT INTO Customers (CustomerName, ContactName, Address, City, PostalCode, Country)
SELECT SupplierName, ContactName, Address, City, PostalCode, Country FROM Suppliers;
```

## 4. SELECT INTO Statement
The SELECT INTO statement copies data from one table into a new table.

### Syntax

1. Copy all columns into a new table:
```sql
SELECT *
INTO newtable [IN externaldb]
FROM oldtable
WHERE condition;
```
2. Copy only some columns into a new table:
```sql
SELECT column1, column2, column3, ...
INTO newtable [IN externaldb]
FROM oldtable
WHERE condition;
```
The new table will be created with the column-names and types as defined in the old table. You can create new column names using the AS clause.

3. Create a new, empty table using the schema of another.

Just add a WHERE clause that causes the query to return no data:
```sql
SELECT * INTO newtable
FROM oldtable
WHERE 1 = 0;
```

### Example: The following SQL statement copies only the German customers into a new table:
```sql
SELECT * INTO CustomersGermany
FROM Customers
WHERE Country = 'Germany';
```