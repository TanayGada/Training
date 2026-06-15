## JDBC (Java Database Connectivity)

- Java API for connecting and interacting with Databases.
- JDBC drivers provides necessary functionalities to connect Java Applications to different types of Databases

## Types of JDBC Drivers

1. JDBC-ODBC Driver -> old, slow, not efficient
2. Native-API partly Java Driver -> provided by db vendors(postgresql, Oracle,..)
3. Network Protocol Pure Java Driver -> have middleware between client and db, better
4. Thin Driver (Direct to Database Pure Java Driver) -> directly converts native-API calls into db calls -> best

## JDBC Components

- DriverManager is the only class here, others are Interfaces

1. DriverManager Class

   - a. `getConnection()` -> helps connect to DB

2. Connection Interface

   - a. Object of this interface -> stores `getConnection()`

3. Statement and PreparedStatement Interface

   - a. Object of this interface -> helps run the SQL query

4. ResultSet Interface
   - a. Object of this interface -> holds output of SQL query

## Flow

1. Connect IDE with DB using connector
2. Load and Register Drivers
3. Establish a Connection
4. Create a Statement
5. Execute the Query
6. Process the Results
7. Close the connection and statement

## Connect IDE with DB using connector

### 1. Connect IDE with DB Using Connector

- A. Install MySQL JDBC Driver (Connector/J)

  - Download from: https://dev.mysql.com/downloads/connector/j/
  - Choose Platform Independent ZIP, extract it.
  - Get the .jar file (e.g., mysql-connector-j-8.4.0.jar)

- B. Add Connector to IntelliJ:
  - Open IntelliJ -> Project Structure -> Modules -> Dependencies -> + -> JARs or directories -> Select .jar file -> Apply

### 2. Load and Register Drivers

- Dynamically loads the MySQL JDBC driver into JVM.

```java
Class.forName("com.mysql.cj.jdbc.Driver"); // Optional in Java 6+, still good practice
```

### 3. Establish a Connection

- Connects to MySQL using DriverManager and returns a Connection object.

```java
String url = "jdbc:mysql://localhost:3306/test_db"; // DB name
String user = "testuser";  // Your MySQL username
String password = "password123"; // Your password

Connection conn = DriverManager.getConnection(url, user, password);
```

### 4. Create A Statement

- Types of Statements
  1. Statement -> static SQL
  2. PreparedStatement -> predefined SQL
  3. Callable Statment -> Procedural SQL (stored procedures)

```java
Statement stmt = conn.createStatement(); // Simple query
// OR
PreparedStatement pstmt = conn.prepareStatement("SELECT * FROM users WHERE id = ?");
pstmt.setInt(1, 1); // For parameterized query
```

### 5. Execute A Query

```java
ResultSet rs = stmt.executeQuery("SELECT * FROM users");
// OR
ResultSet rs = pstmt.executeQuery();
```

- Other execution methods:
  1. executeUpdate() → For INSERT, UPDATE, DELETE
  2. execute() → When query type is unknown (returns boolean)

### 6. Process the Result

```java
while (rs.next()) {
    int id = rs.getInt("id");
    String name = rs.getString("name");
    System.out.println(id + ": " + name);
}
```

- ResultSet represents the table returned by the query.
- Use rs.getString(), rs.getInt(), etc., to read values.

### 7. Close the connection and Statement

```java
rs.close();
stmt.close(); // or pstmt.close();
conn.close();
```

- Prevents memory leaks, DB resource locking.

### Complete starter template

```java
import java.sql.*;

public class Main {

    private static final String url = "jdbc:mysql://localhost:3306/mydb";
    private static final String username = "root";
    private static final String password = "<password>";

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }


        try(
            Connection connection = DriverManager.getConnection(url, username, password);
        )  {

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
```
