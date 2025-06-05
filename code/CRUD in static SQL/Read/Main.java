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

        String query = "SELECT * FROM students";
        try(
            Connection connection = DriverManager.getConnection(url, username, password);
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(query)
        )  {
            while(resultSet.next()){
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                int age = resultSet.getInt("age");
                double marks = resultSet.getDouble("marks");
                System.out.println("id: " + id);
                System.out.println("name: " + name);
                System.out.println("age: " + age);
                System.out.println("marks: " + marks);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}