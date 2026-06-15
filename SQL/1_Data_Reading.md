## 1. SELECT DISTINCT
Select all the different countries from the "Customers" table
```sql
SELECT DISTINCT Country FROM Customers;
```
## 2. COUNT DISTINCT
Return the number of different countries
```sql
SELECT COUNT(DISTINCT Country) FROM Customers;
```

## 3. WHERE Clause (filtering)
Used to filter records. Select all customers from Mexico:
```sql
SELECT * FROM Customers
WHERE Country='Mexico';
```

Syntax
```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition;
```
**NOTE: WHERE clause is not only used in SELECT statements, it is also used in UPDATE, DELETE, etc..**

### Text Fields vs Numeric Fields
- Text should be enclosed by single or double quotes
- Numbers need not be enclosed by quotes
```sql
SELECT * FROM Customers
WHERE CustomerID=1;
```

### Logical Operators
- Used for conditional filtering using WHERE Clause
- Select all customers with a CustomerID greater than 80:
```sql
SELECT * FROM Customers
WHERE CustomerID > 80;
```
![](./images/1.png)


## 4. ORDER BY (sorting)
Used to sort the result-set in ascending or descending order based on numeric or alphabetic data
- Eg: Sort the products by price:
```sql
SELECT * FROM Products
ORDER BY Price ASC;
```
Syntax
```sql
SELECT column1, column2, ...
FROM table_name
ORDER BY column1, column2, ... ASC|DESC;
```

### ORDER BY several column
- Sorted by the "Country" and the "CustomerName" column. This means that it orders by Country, but if some rows have the same Country, it orders them by CustomerName:
```sql
SELECT * FROM Customers
ORDER BY Country, CustomerName;
```
- Using Both ASC and DSC
```sql
SELECT * FROM Customers
ORDER BY Country ASC, CustomerName DESC;
```


## 5. AND Operator
- The AND operator is used to filter records based on more than one condition.
- Eg. Select all customers from Spain that starts with the letter 'G':
```sql
SELECT *
FROM Customers
WHERE Country = 'Spain' AND CustomerName LIKE 'G%';
```
Syntax
```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition1 AND condition2 AND condition3 ...;
```

## 6. OR Operator
- The OR operator displays a record if any of the conditions are TRUE.
- Select all customers from Germany or Spain:
```sql
SELECT *
FROM Customers
WHERE Country = 'Germany' OR Country = 'Spain';
```
#### Combining AND and OR
Select all Spanish customers that starts with either "G" or "R":
```sql
SELECT * FROM Customers
WHERE Country = 'Spain' AND (CustomerName LIKE 'G%' OR CustomerName LIKE 'R%');
```
Without parenthesis, the select statement will return all customers from Spain that starts with a "G", plus all customers that starts with an "R", regardless of the country value:

## 7. NOT Operator
- Used in combination with other operators to give the opposite result
- Eg: Select only the customers that are NOT from Spain:
```sql
SELECT * FROM Customers
WHERE NOT Country = 'Spain';
```
Syntax
```sql
SELECT column1, column2, ...
FROM table_name
WHERE NOT condition;
```
### NOT LIKE
Ex: Select customers that does not start with the letter 'A':
```sql
SELECT * FROM Customers
WHERE CustomerName NOT LIKE 'A%';
```

### NOT BETWEEN
Ex: Select customers with a customerID not between 10 and 60:
```sql
SELECT * FROM Customers
WHERE CustomerID NOT BETWEEN 10 AND 60;
```

### NOT IN
Eg: Select customers that are not from Paris or London:
```sql
SELECT * FROM Customers
WHERE City NOT IN ('Paris', 'London');
```

### NOT Greater Than
Ex: Select customers with a CustomerId not greater than 50:
```sql
SELECT * FROM Customers
WHERE NOT CustomerID > 50;
```

## 8. NULL Values
A field with a NULL value is a field with no value
#### Note: A NULL value is different from a zero value or a field that contains spaces. A field with a NULL value is one that has been left blank during record creation!

### IS NULL Syntax
```sql
SELECT column_names
FROM table_name
WHERE column_name IS NULL;
```
### IS NOT NULL Syntax
```sql
SELECT column_names
FROM table_name
WHERE column_name IS NOT NULL;
```


## 9. Aliases
SQL aliases are used to give a table, or a column in a table, a temporary name.

An alias only exists for the duration of that query.

An alias is created with the AS keyword.

#### When alias is used on column:
```sql
SELECT column_name AS alias_name
FROM table_name;
```

#### When alias is used on table:
```sql
SELECT column_name(s)
FROM table_name AS alias_name;
```

### Using Aliases With a Space Character
If you want your alias to contain one or more spaces, like "My Great Products", surround your alias with square brackets or double quotes.
`[My Great Products]` or `"My Great Products"`

### Concatenate Columns
Alias named "Address" that combine four columns (Address, PostalCode, City and Country):

```sql
SELECT CustomerName, Address + ', ' + PostalCode + ' ' + City + ', ' + Country AS Address
FROM Customers;
```
```sql
SELECT CustomerName, CONCAT(Address,', ',PostalCode,', ',City,', ',Country) AS Address
FROM Customers;
```

### Alias for Tables
It might seem useless to use aliases on tables, but when you are using more than one table in your queries, it can make the SQL statements shorter.
```sql
SELECT o.OrderID, o.OrderDate, c.CustomerName
FROM Customers AS c, Orders AS o
WHERE c.CustomerName='Around the Horn' AND c.CustomerID=o.CustomerID;
```

### Aliases can be useful when:

There are more than one table involved in a query
Functions are used in the query
Column names are big or not very readable
Two or more columns are combined together


## 10. SELECT TOP
Specify the number of records to return.

Useful on large tables with thousands of records. Returning a large number of records can impact performance.

#### Note: Not all database systems support the SELECT TOP clause. MySQL supports the LIMIT clause to select a limited number of records, while Oracle uses FETCH FIRST n ROWS ONLY and ROWNUM

#### SQL Server / MS Access Syntax:
```sql
SELECT TOP number|percent column_name(s)
FROM table_name
WHERE condition;
```

#### MySQL Syntax:
```sql
SELECT column_name(s)
FROM table_name
WHERE condition
LIMIT number;
```

Can use `WHERE` and `ORDER BY` clause with `SELECT TOP`

## 11. IN
The IN operator allows to specify multiple values in a WHERE clause.

The IN operator is a shorthand for multiple OR conditions.

#### Syntax
```sql
SELECT column_name(s)
FROM table_name
WHERE column_name IN (value1, value2, ...);
```

### IN (SELECT)
We can also use IN with a subquery in the WHERE clause.

Example
Return all customers that have an order in the Orders table:
```sql
SELECT * FROM Customers
WHERE CustomerID IN (SELECT CustomerID FROM Orders);
```
## 12. NOT IN
By using the NOT keyword in front of the IN operator, you return all records that are NOT any of the values in the list.

Example
Return all customers that are NOT from 'Germany', 'France', or 'UK':
```sql
SELECT * FROM Customers
WHERE Country NOT IN ('Germany', 'France', 'UK');
```

### NOT IN (SELECT)
Example
Return all customers that have NOT placed any orders in the Orders table:
```sql
SELECT * FROM Customers
WHERE CustomerID NOT IN (SELECT CustomerID FROM Orders);
```

## 13. BETWEEN Operator
Select values within a given range. The values can be numbers, text, or dates.

Syntax
```sql
SELECT column_name(s)
FROM table_name
WHERE column_name BETWEEN value1 AND value2;
```
Selects all products with a price between 10 and 20:
```sql
SELECT * FROM Products
WHERE Price BETWEEN 10 AND 20;
```

### NOT BETWEEN
```sql
SELECT * FROM Products
WHERE Price NOT BETWEEN 10 AND 20;
```

### BETWEEN with IN
Select all products with a price between 10 and 20. In addition, the CategoryID must be either 1,2, or 3:
```sql
SELECT * FROM Products
WHERE Price BETWEEN 10 AND 20
AND CategoryID IN (1,2,3);
```

### BETWEEN Text Values
The following SQL statement selects all products with a ProductName alphabetically between Carnarvon Tigers and Mozzarella di Giovanni:

```sql
SELECT * FROM Products
WHERE ProductName BETWEEN 'Carnarvon Tigers' AND 'Mozzarella di Giovanni'
ORDER BY ProductName;
```

### BETWEEN Dates
The following SQL statement selects all orders with an OrderDate between '01-July-1996' and '31-July-1996':

```sql
SELECT * FROM Orders
WHERE OrderDate BETWEEN '07/01/1996' AND '07/31/1996';
```

## 14. LIKE Operator
Used in a WHERE clause to search for a specified pattern in a column.

There are two wildcards often used in conjunction with the LIKE operator:

1. The percent sign % represents zero, one, or multiple characters
2. The underscore sign _ represents one, single character

#### Syntax
```sql
SELECT column1, column2, ...
FROM table_name
WHERE columnN LIKE pattern;
```
Select all customers that starts with the letter "a":
```sql
SELECT * FROM Customers
WHERE CustomerName LIKE 'a%';
```

## 15. WILDCARDS
A wildcard character is used to substitute one or more characters in a string.

There are two wildcards often used in conjunction with the LIKE operator:
1. The percent sign % represents zero, one, or multiple characters
2. The underscore sign _ represents one, single character

### Starts With
Return all customers that starts with 'La':
```sql
SELECT * FROM Customers
WHERE CustomerName LIKE 'La%';
```

### Ends With
Return all customers that ends with 'a':
```sql
SELECT * FROM Customers
WHERE CustomerName LIKE '%a';
```

### Starts with and Ends with combination
Return all customers that starts with "b" and ends with "s":
```sql
SELECT * FROM Customers
WHERE CustomerName LIKE 'b%s';
```

### Contains
Return all customers that contains the phrase 'or'
```sql
SELECT * FROM Customers
WHERE CustomerName LIKE '%or%';
```

### Combine Wildcards
Any wildcard, like % and _ , can be used in combination with other wildcards.

Return all customers that starts with "a" and are at least 3 characters in length:
```sql
SELECT * FROM Customers
WHERE CustomerName LIKE 'a__%';
```