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
            Statement statement = connection.createStatement();
        ){
            String query = String.format("DELETE FROM students WHERE id = %d", 2);
            int rowsAffected = statement.executeUpdate(query);
            if(rowsAffected>0)  System.out.println("Data Deleted Successfully");
            else System.out.println("Data Not Deleted");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
