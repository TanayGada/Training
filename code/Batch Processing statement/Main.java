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

        try(
            Scanner scanner = new Scanner(System.in);
            Connection connection = DriverManager.getConnection(url, username, password);
            Statement statement = connection.createStatement();
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
                String query = String.format("INSERT INTO students(name, age, marks) VALUES('%s', %d, %f)", name, age, marks);

                statement.addBatch(query);
                if (choice.toUpperCase().equals("N")) break;
            }

            int[] rowsAffected = statement.executeBatch(); //outputs an array having 1(true) and 0(false)
            for(int i=0;i<rowsAffected.length; i++){
                if(rowsAffected[i]==1) System.out.println("Query " + i + " executed Successfully");
                else System.out.println("Query " + i + " not executed ");
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}