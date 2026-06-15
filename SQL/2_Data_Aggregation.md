# SQL Aggregate Functions
An aggregate function is a function that performs a calculation on a set of values, and returns a single value.

Aggregate functions are often used with the GROUP BY clause of the SELECT statement. The GROUP BY clause splits the result-set into groups of values and the aggregate function can be used to return a single value for each group.

The most commonly used SQL aggregate functions are:

1. MIN() - returns the smallest value within the selected column
2. MAX() - returns the largest value within the selected column
3. COUNT() - returns the number of rows in a set
4. SUM() - returns the total sum of a numerical column
5. AVG() - returns the average value of a numerical column

#### NOTE: Aggregate functions ignore null values (except for COUNT(*)).


## 1. MIN() MAX() functions
returned column by MIN() or MAX() doesnot have a descriptive name. To give the column a descriptive name, use the AS keyword:

Syntax
1. Min 
```sql
SELECT MIN(column_name) AS alias
FROM table_name
WHERE condition;
```
2. Max
```sql
SELECT MAX(column_name) AS alias
FROM table_name
WHERE condition;
```
### Use MIN() with GROUP BY
MIN() function and the GROUP BY clause, to return the smallest price for each category in the Products table:
```sql
SELECT MIN(Price) AS SmallestPrice, CategoryID
FROM Products
GROUP BY CategoryID;
```

## 2. COUNT() Function
The COUNT() function returns the number of rows that matches a specified criterion.

Syntax
```sql
SELECT COUNT(column_name)
FROM table_name
WHERE condition;
```

### Use an Alias
Give the counted column a name by using the AS keyword.

Name the column "Number of records":
```sql
SELECT COUNT(*) AS [Number of records]
FROM Products;
```

## 3. SUM() Function
The SUM() function returns the total sum of a numeric column.

Syntax
```sql
SELECT SUM(column_name)
FROM table_name
WHERE condition;
```

### Use SUM() with GROUP BY
Return the Quantity for each OrderID in the OrderDetails table:

```sql
SELECT OrderID, SUM(Quantity) AS [Total Quantity]
FROM OrderDetails
GROUP BY OrderID;
```

### SUM() With an Expression
The parameter inside the SUM() function can also be an expression.
```sql
SELECT SUM(Quantity * 10)
FROM OrderDetails;
```

## 4. AVG() Function
The AVG() function returns the average value of a numeric column.

```sql
SELECT AVG(column_name)
FROM table_name
WHERE condition;
```
### Use an Alias
```sql
SELECT AVG(Price) AS [average price]
FROM Products;
```

### AVG() with GROUP BY
Return the average price for each category in the Products table:
```sql
SELECT AVG(Price) AS AveragePrice, CategoryID
FROM Products
GROUP BY CategoryID
```

## 5. GROUP BY Statement
The GROUP BY statement groups rows that have the same values into summary rows, like "find the number of customers in each country".

The GROUP BY statement is often used with aggregate functions (COUNT(), MAX(), MIN(), SUM(), AVG()) to group the result-set by one or more columns.

### Syntax
```sql
SELECT column_name(s)
FROM table_name
WHERE condition
GROUP BY column_name(s)
ORDER BY column_name(s);
```

### Example: lists the number of customers in each country, sorted high to low:
```sql
SELECT COUNT(CustomerID), Country
FROM Customers
GROUP BY Country
ORDER BY COUNT(CustomerID) DESC;
```

### GROUP BY With JOIN Example
The following SQL statement lists the number of orders sent by each shipper:

```sql
SELECT Shippers.ShipperName, COUNT(Orders.OrderID) AS NumberOfOrders FROM Orders
LEFT JOIN Shippers ON Orders.ShipperID = Shippers.ShipperID
GROUP BY ShipperName;
```

## 6. HAVING Clause
`WHERE` keyword cannot be used with aggregate functions
```sql
SELECT column_name(s)
FROM table_name
WHERE condition
GROUP BY column_name(s)
HAVING condition
ORDER BY column_name(s);
```

### Example: lists the number of customers in each country, sorted high to low (Only include countries with more than 5 customers):
```sql
SELECT COUNT(CustomerID), Country
FROM Customers
GROUP BY Country
HAVING COUNT(CustomerID) > 5
ORDER BY COUNT(CustomerID) DESC;
```

### Example: list the employees that have registered more than 10 orders:
```sql
SELECT Employees.LastName, COUNT(Orders.OrderID) AS NumberOfOrders
FROM (Orders
INNER JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID)
GROUP BY LastName
HAVING COUNT(Orders.OrderID) > 10;
```

### Example: list if the employees "Davolio" or "Fuller" have registered more than 25 orders:
```sql
SELECT Employees.LastName, COUNT(Orders.OrderID) AS NumberOfOrders
FROM Orders
INNER JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID
WHERE LastName = 'Davolio' OR LastName = 'Fuller'
GROUP BY LastName
HAVING COUNT(Orders.OrderID) > 25;
```