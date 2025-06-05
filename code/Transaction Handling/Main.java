import java.sql.*;
import java.util.Scanner;

public class Main {

    // JDBC URL, username and password of MySQL server
    private static final String url = "jdbc:mysql://localhost:3306/test_db";
    private static final String username = "root";
    private static final String password = "<password>";

    public static void main(String[] args) {
        // Load MySQL JDBC driver
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            // Rethrow as unchecked exception if driver class is not found
            throw new RuntimeException("JDBC Driver not found", e);
        }

        // SQL queries to perform debit and credit operations
        String debit_query = "UPDATE accounts SET balance = balance - ? WHERE account_number = ?";
        String credit_query = "UPDATE accounts SET balance = balance + ? WHERE account_number = ?";

        // Try-with-resources ensures proper closing of resources
        try (
                Connection connection = DriverManager.getConnection(url, username, password);
                PreparedStatement debitPreparedStatement = connection.prepareStatement(debit_query);
                PreparedStatement creditPreparedStatement = connection.prepareStatement(credit_query);
                Scanner scanner = new Scanner(System.in);
        ) {
            // Disable auto-commit mode to manage transaction manually
            connection.setAutoCommit(false);

            // Input transaction details from user
            System.out.print("Enter Credit Account Number: ");
            int credit_account_number = scanner.nextInt();

            System.out.print("Enter Debit Account Number: ");
            int debit_account_number = scanner.nextInt();

            System.out.print("Enter Amount: ");
            double amount = scanner.nextDouble();

            // Set parameters for debit query
            debitPreparedStatement.setDouble(1, amount);
            debitPreparedStatement.setInt(2, debit_account_number);

            // Set parameters for credit query
            creditPreparedStatement.setDouble(1, amount);
            creditPreparedStatement.setInt(2, credit_account_number);

            // Execute debit and credit operations
            debitPreparedStatement.executeUpdate();
            creditPreparedStatement.executeUpdate();

            // Validate if debit account has sufficient balance after update
            if (isSufficient(connection, debit_account_number, amount)) {
                // Commit transaction if valid
                connection.commit();
                System.out.println("Transaction Successful");
            } else {
                // Rollback transaction if insufficient balance
                connection.rollback();
                System.out.println("Transaction Failed: Insufficient balance");
            }

        } catch (SQLException e) {
            // Handle any SQL exceptions during transaction
            throw new RuntimeException("Database error occurred", e);
        }
    }

    /**
     * Validates if the debit account has sufficient balance.
     *
     * @param connection Database connection
     * @param debit_account_number Account number to debit
     * @param amount Amount to be debited
     * @return true if sufficient balance exists; false otherwise
     */
    static boolean isSufficient(Connection connection, int debit_account_number, double amount) {
        String query = "SELECT balance FROM accounts WHERE account_number = ?";

        try (
                PreparedStatement preparedStatement = connection.prepareStatement(query)
        ) {
            // Set parameter for balance check
            preparedStatement.setInt(1, debit_account_number);

            ResultSet resultSet = preparedStatement.executeQuery();

            if (resultSet.next()) {
                double current_balance = resultSet.getDouble("balance");
                return current_balance >= amount;
            } else {
                // Account not found
                System.out.println("Debit account not found");
                return false;
            }
        } catch (SQLException e) {
            // Handle SQL exceptions in balance check
            throw new RuntimeException("Error checking account balance", e);
        }
    }
}