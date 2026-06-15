## 1. CREATE Database
- Create new database
### Syntax
```sql
CREATE DATABASE databasename;
```
## 2. List Database
- Lists all existing database
### Syntax
```sql
SHOW DATABASES;
```

## 3. DROP Database
- Drop an existing SQL database.
### Syntax
```sql
DROP DATABASE databasename;
```

## 4. Backup Database
- create a full back up of an existing SQL database.
### Syntax
```sql
BACKUP DATABASE databasename
TO DISK = 'filepath';
```

### DIFFERENTIAL STATEMENT
- A differential back up only backs up the parts of the database that have changed since the last full database backup.

```sql
BACKUP DATABASE databasename
TO DISK = 'filepath'
WITH DIFFERENTIAL;
```

## 5. CREATE Table
- create a new table in a database.

### Syntax
```sql
CREATE TABLE table_name (
    column1 datatype,
    column2 datatype,
    column3 datatype,
   ....
);
```

## 6. CREATE table using another table
- A copy of an existing table can also be created using CREATE TABLE.
- The new table gets the same column definitions. All columns or specific columns can be selected.

### Syntax
```sql
CREATE TABLE new_table_name AS
    SELECT column1, column2,...
    FROM existing_table_name
    WHERE ....;
```

## 7. DROP TABLE 
- Drop an existing table in a database.

### Syntax
```sql
DROP TABLE table_name;
```

## 8. TRUNCATE TABLE
- Delete the data inside a table, but not the table itself.

### Syntax
```sql
TRUNCATE TABLE table_name;
```

## 9. ALTER TABLE
- Used to add, delete, or modify columns in an existing table.
- Also used to add and drop various constraints on an existing table.

### a. ADD Column
To add a column in a table, use the following syntax:
```sql
ALTER TABLE table_name
ADD column_name datatype;
```

### b. DROP COLUMN
To delete a column in a table, use the following syntax (notice that some database systems don't allow deleting a column):
```sql
ALTER TABLE table_name
DROP COLUMN column_name;
```

### c. RENAME COLUMN
To rename a column in a table, use the following syntax:
```sql
ALTER TABLE table_name
RENAME COLUMN old_name to new_name;
```

### d. ALTER/MODIFY DATATYPE
To change the data type of a column in a table, use the following syntax:
```sql
ALTER TABLE table_name
ALTER COLUMN column_name datatype;
```

## 10. SQL Constraints
- SQL constraints are used to specify rules for data in a table.
- The following constraints are commonly used in SQL:

1. NOT NULL - Ensures that a column cannot have a NULL value
2. UNIQUE - Ensures that all values in a column are different
3. PRIMARY KEY - A combination of a NOT NULL and UNIQUE. Uniquely identifies each row in a table
4. FOREIGN KEY - Prevents actions that would destroy links between tables
5. CHECK - Ensures that the values in a column satisfies a specific condition
6. DEFAULT - Sets a default value for a column if no value is specified
7. CREATE INDEX - Used to create and retrieve data from the database very quickly

### Create Constraints
- Constraints can be specified when the table is created with the CREATE TABLE statement, or after the table is created with the ALTER TABLE statement.

```sql
CREATE TABLE table_name (
    column1 datatype constraint,
    column2 datatype constraint,
    column3 datatype constraint,
    ....
);
```

## 10.1 NOT NULL Constraint
- By default, a column can hold NULL values.
- The NOT NULL constraint enforces a column to NOT accept NULL values.

### NOT NULL on CREATE TABLE
The following SQL ensures that the "ID", "LastName", and "FirstName" columns will NOT accept NULL values when the "Persons" table is created:

```sql
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255) NOT NULL,
    Age int
);
```

### NOT NULL on ALTER TABLE
To create a NOT NULL constraint on the "Age" column when the "Persons" table is already created, use the following SQL:

```sql
ALTER TABLE Persons
ALTER COLUMN Age int NOT NULL;
```

## 10.2 UNIQUE Constraint
The UNIQUE constraint ensures that all values in a column are different.

### UNIQUE Constraint on CREATE TABLE
The following SQL creates a UNIQUE constraint on the "ID" column when the "Persons" table is created:

```sql
CREATE TABLE Persons (
    ID int NOT NULL UNIQUE,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int
);
```

### UNIQUE Constraint on ALTER TABLE
To create a UNIQUE constraint on the "ID" column when the table is already created, use the following SQL:

```sql
ALTER TABLE Persons
ADD UNIQUE (ID);
```

### DROP a UNIQUE Constraint
To drop a UNIQUE constraint, use the following SQL:

```sql
ALTER TABLE Persons
DROP CONSTRAINT UC_Person;
```

## 10.3 PRIMARY KEY
- The PRIMARY KEY constraint is used to uniquely identify each record in a table.
- Primary keys must contain unique values, and cannot contain NULL values.
- Each table can have only ONE primary key. The primary key can be a single column or a combination of columns.

### PRIMARY KEY on CREATE TABLE
The following SQL creates a PRIMARY KEY on the "ID" column when the "Persons" table is created:


```sql
CREATE TABLE Persons (
    ID int NOT NULL PRIMARY KEY,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int
);
```
### PRIMARY KEY constraint on multiple columns
```sql
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    CONSTRAINT PK_Person PRIMARY KEY (ID,LastName)
);
```

### PRIMARY KEY on ALTER TABLE
To create a PRIMARY KEY constraint on the "ID" column when the table is already created, use the following SQL:

```sql
ALTER TABLE Persons
ADD PRIMARY KEY (ID);
```

### PRIMARY KEY with multiple columns on ALTER TABLE
```sql
ALTER TABLE Persons
ADD CONSTRAINT PK_Person PRIMARY KEY (ID,LastName);
```

#### Note: If you use ALTER TABLE to add a primary key, the primary key column(s) must have been declared with NOT NULL, when the table was first created.

### DROP a PRIMARY KEY Constraint
To drop a PRIMARY KEY constraint, use the following SQL:

```sql
ALTER TABLE Persons
DROP PRIMARY KEY;
```

## 10.4 Foreign Key
- A FOREIGN KEY is a field (or collection of fields) in one table, that refers to the PRIMARY KEY in another table.

- The table with the foreign key is called the child table, and the table with the primary key is called the referenced or parent table.

### FOREIGN KEY on CREATE TABLE
The following SQL creates a FOREIGN KEY on the "PersonID"(PK of Persons Table) column when the "Orders" table is created:

```sql
CREATE TABLE Orders (
    OrderID int NOT NULL PRIMARY KEY,
    OrderNumber int NOT NULL,
    PersonID int FOREIGN KEY REFERENCES Persons(PersonID)
);
```
### FOREIGN KEY having multiple columns/ Allow naming on CREATE TABLE
```sql
CREATE TABLE Orders (
    OrderID int NOT NULL,
    OrderNumber int NOT NULL,
    PersonID int,
    PRIMARY KEY (OrderID),
    CONSTRAINT FK_PersonOrder FOREIGN KEY (PersonID)
    REFERENCES Persons(PersonID)
);
```

### FOREIGN KEY on ALTER TABLE
To create a FOREIGN KEY constraint on the "PersonID" column when the "Orders" table is already created, use the following SQL:
```sql
ALTER TABLE Orders
ADD FOREIGN KEY (PersonID) REFERENCES Persons(PersonID);
```

### FOREIGN KEY having multiple columns/ Allow naming on ALTER TABLE
```sql
ALTER TABLE Orders
ADD CONSTRAINT FK_PersonOrder
FOREIGN KEY (PersonID) REFERENCES Persons(PersonID);
```

### DROP a FOREIGN KEY Constraint
```sql
ALTER TABLE Orders
DROP FOREIGN KEY FK_PersonOrder;
```

## 10.5 CHECK Constraint
- The CHECK constraint is used to limit the value range that can be placed in a column.

- If you define a CHECK constraint on a column it will allow only certain values for this column.

- If you define a CHECK constraint on a table it can limit the values in certain columns based on values in other columns in the row.

### Create a CHECK constraint on the "Age" column when the "Persons" table is created. The CHECK constraint ensures that the age of a person must be 18, or older:
```sql
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    CHECK (Age>=18)
);
```

### Name a CHECK constraint & multiple conditions
```sql
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    City varchar(255),
    CONSTRAINT CHK_Person CHECK (Age>=18 AND City='Sandnes')
);
```

### CHECK on ALTER TABLE
- To create a CHECK constraint on the "Age" column when the table is already created
```sql
ALTER TABLE Persons
ADD CHECK (Age>=18);
```

### Name a CHECK constraint & multiple conditions
```sql
ALTER TABLE Persons
ADD CONSTRAINT CHK_PersonAge CHECK (Age>=18 AND City='Sandnes');
```

### DROP a CHECK Constraint
```sql
ALTER TABLE Persons
DROP CHECK CHK_PersonAge;
```

## 10.6 DEFAULT Constraint
- The DEFAULT constraint is used to set a default value for a column.
- The default value will be added to all new records, if no other value is specified.

### DEFAULT on CREATE TABLE
- Sets a DEFAULT value for the "City" column when the "Persons" table is created:
```sql
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    City varchar(255) DEFAULT 'Sandnes'
);
```

### The DEFAULT constraint can also be used to insert system values, by using functions like GETDATE():
```sql
CREATE TABLE Orders (
    ID int NOT NULL,
    OrderNumber int NOT NULL,
    OrderDate date DEFAULT GETDATE()
);
```

### DEFAULT on ALTER TABLE
To create a DEFAULT constraint on the "City" column when the table is already created

```sql
ALTER TABLE Persons
ALTER City SET DEFAULT 'Sandnes';
```

### DROP a DEFAULT Constraint
```sql
ALTER TABLE Persons
ALTER City DROP DEFAULT;
```

## 10.7 CREATE INDEX
- Used to create indexes in tables.

#### Note: Updating a table with indexes takes more time than updating a table without (because the indexes also need an update). So, only create indexes on columns that will be frequently searched against.

### CREATE INDEX Syntax
Creates an index on a table. Duplicate values are allowed:
```sql
CREATE INDEX index_name
ON table_name (column1, column2, ...);
```

### CREATE UNIQUE INDEX Syntax
Creates a unique index on a table. Duplicate values are not allowed:
```sql
CREATE UNIQUE INDEX index_name
ON table_name (column1, column2, ...);
```

### DROP INDEX Statement
The DROP INDEX statement is used to delete an index in a table.
```sql
ALTER TABLE table_name
DROP INDEX index_name;
```

## 11. AUTO INCREMENT Field
- Auto-increment allows a unique number to be generated automatically when a new record is inserted into a table.

- Often this is the primary key field that we would like to be created automatically every time a new record is inserted.

### "Personid" column is an auto-increment primary key field in the "Persons" table: 

```sql
CREATE TABLE Persons (
    Personid int NOT NULL AUTO_INCREMENT,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    PRIMARY KEY (Personid)
);
```

### By default, the starting value for `AUTO_INCREMENT` is 1, and it will increment by 1 for each new record.

- To let the `AUTO_INCREMENT` sequence start with another value, use the following SQL statement:
```sql
ALTER TABLE Persons AUTO_INCREMENT=100;
```