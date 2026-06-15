## Stored Procedure
- A stored procedure is a prepared SQL code that you can save, so the code can be reused over and over again.
- We can also pass parameters to stored procedures

### Syntax
```sql
CREATE PROCEDURE procedure_name
AS
sql_statement
GO;
```
### Execute a Stored Procedure
```sql
EXEC procedure_name;
```

### Stored Procedure With One Parameter
- Stored procedure that selects Customers from a particular City from the "Customers" table:

```sql
CREATE PROCEDURE SelectAllCustomers @City nvarchar(30)
AS
SELECT * FROM Customers WHERE City = @City
GO;
```

```sql
EXEC SelectAllCustomers @City = 'London';
```

### Stored Procedure With Multiple Parameters
- Stored procedure that selects Customers from a particular City with a particular PostalCode from the "Customers" table:
```sql
CREATE PROCEDURE SelectAllCustomers @City nvarchar(30), @PostalCode nvarchar(10)
AS
SELECT * FROM Customers WHERE City = @City AND PostalCode = @PostalCode
GO;
```
```sql
EXEC SelectAllCustomers @City = 'London', @PostalCode = 'WA1 1DP';
```

## SQL Dates
- The most difficult part when working with dates is to be sure that the format of the date you are trying to insert, matches the format of the date column in the database.

- Easier to work if data have only date portion, However, if a time portion is involved, it gets more complicated.

### SQL Date Data Types
#### MySQL DataTypes
1. DATE - format YYYY-MM-DD
2. DATETIME - format: YYYY-MM-DD HH:MI:SS
3. TIMESTAMP - format: YYYY-MM-DD HH:MI:SS
4. YEAR - format YYYY or YY

#### SQL Server
1. DATE - format YYYY-MM-DD
2. DATETIME - format: YYYY-MM-DD HH:MI:SS
3. SMALLDATETIME - format: YYYY-MM-DD HH:MI:SS
4. TIMESTAMP - format: a unique number

### Note: Two dates can easily be compared if there is no time component involved!