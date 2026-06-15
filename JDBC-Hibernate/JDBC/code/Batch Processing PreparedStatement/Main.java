import java.sql.*;
import java.util.Scanner;

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

        String query = "INSERT INTO students(name, age, marks) VALUES(?,?,?)";
        try(
            Scanner scanner = new Scanner(System.in);
            Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query);
        ){
            while(true) {
                System.out.print("Enter Name: ");
                String name = scanner.next();
                System.out.print("Enter Age: ");
                int age = scanner.nextInt();
                System.out.print("Enter Marks: ");
                double marks = scanner.nextDouble();
                System.out.print("Enter More Data (Y/N): ");
                String choice = scanner.next();

                preparedStatement.setString(1, name);
                preparedStatement.setInt(2, age);
                preparedStatement.setDouble(3, marks);

                preparedStatement.addBatch();
                if (choice.toUpperCase().equals("N")) break;
            }

            int[] rowsAffected = preparedStatement.executeBatch(); //outputs an array having 1(true) and 0(false)
            for(int i=0; i<rowsAffected.length; i++){
                if(rowsAffected[i]==1) System.out.println("Query " + (i+1) + " executed Successfully");
                else System.out.println("Query " + i + " not executed ");
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}