package com.tanay;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;

import java.util.Properties;

/**
 * Entry point of the application demonstrating basic CRUD operations using Hibernate ORM.
 *
 * This class sets up a Hibernate SessionFactory, opens a session, and contains examples for:
 * - Create (Insert)
 * - Read (Select)
 * - Update
 * - Delete
 *
 * Note: This is a demo setup using Hibernate's built-in connection pool (not for production).
 */
public class Main {
    public static void main(String[] args) {

        // Step 1: Configure Hibernate and build SessionFactory
        SessionFactory factory = new Configuration()
                .addAnnotatedClass(com.tanay.Student.class) // Register annotated entity class
                .configure() // Load configuration from hibernate.cfg.xml
                .buildSessionFactory();

        // Step 2: Open a new Hibernate session from the SessionFactory
        Session session = factory.openSession();

        /**
         * ------------------------------
         * CREATE Operation - Insert Data
         * ------------------------------
         * Uncomment to add a new Student record to the database.
         */
//        Student s1 = new Student();
//        s1.setSid(3); // Primary Key
//        s1.setName("Varun");
//        s1.setTech("JS"); // Technology
//
//        Transaction transaction = session.beginTransaction(); // Begin transaction
//        session.persist(s1); // Save entity
//        transaction.commit(); // Commit transaction

        /**
         * ---------------------------------------
         * READ Operation - Retrieve Data (SELECT)
         * ---------------------------------------
         * Eager vs Lazy loading demonstration.
         */
//        Student s1 = session.find(Student.class, 1);    // Eager loading: fetches data immediately
//        Student s2 = session.byId(Student.class).getReference(2); // Lazy loading: proxy, fetches data on use
//
//        System.out.println(s1); // Will print full details of student with ID 1
//        System.out.println(s2); // Will print proxy or trigger fetch if used

        /**
         * ------------------------------
         * UPDATE Operation - Update Data
         * ------------------------------
         * `merge()` performs update if entity exists, else inserts.
         */
//        Student s1 = new Student();
//        s1.setSid(3); // Must match existing record
//        s1.setName("Varun");
//        s1.setTech("Java"); // Changed from JS to Java
//
//        Transaction transaction = session.beginTransaction();
//        session.merge(s1); // Update or insert if not found
//        transaction.commit();

        /**
         * ------------------------------
         * DELETE Operation - Remove Data
         * ------------------------------
         * Deletes the student entity from the database.
         */
//        Student s1 = session.find(Student.class, 3); // Fetch entity by ID
//
//        Transaction transaction = session.beginTransaction();
//        session.remove(s1); // Mark entity for deletion
//        transaction.commit(); // Apply deletion

        // Step 3: Close session and factory to release resources
        session.close();
        factory.close();
    }
}