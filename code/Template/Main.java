package code.Template;
import java.sql.*;

public class Main {

    private static final String url = "jdbc:mysql://localhost:3306/<db_name>";
    private static final String username = "<user>";
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