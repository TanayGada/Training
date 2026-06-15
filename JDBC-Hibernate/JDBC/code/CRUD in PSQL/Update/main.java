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

        String query = "UPDATE students SET marks = ? WHERE id = ?";
        try(
            Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query);
        ){
            preparedStatement.setDouble(1, 97);
            preparedStatement.setInt(2, 3);

            int rowsAffected = preparedStatement.executeUpdate();
            if(rowsAffected>0) System.out.println("Data Updated Successfully");
            else System.out.println("Data Not Updated");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}