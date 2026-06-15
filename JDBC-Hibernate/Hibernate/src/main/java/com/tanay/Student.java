package com.tanay;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

/**
 * Entity class representing a Student.
 *
 * This class is mapped to the "student_data" table in the database using JPA annotations.
 * It includes fields for student ID, name, and technology specialization.
 */
@Entity // Marks this class as a persistent entity in Hibernate (mapped to a table)
@Table(name = "student_data") // Specifies the table name in the database for this entity
public class Student {

    /**
     * Primary key for the student entity.
     * Mapped to the "student_id" column in the database.
     */
    @Id // Declares 'sid' as the primary key
    @Column(name = "student_id") // Maps this field to the "student_id" column in the table
    private int sid;

    /**
     * Student's full name.
     * Mapped to the "student_name" column in the database.
     */
    @Column(name = "student_name") // Maps this field to the "student_name" column in the table
    private String name;

    /**
     * Technology/domain the student specializes in.
     * Will be mapped automatically using the field name "tech" if not overridden.
     */
    private String tech;

    // Standard getter and setter methods for each property

    public int getSid() {
        return sid;
    }

    public void setSid(int sid) {
        this.sid = sid;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getTech() {
        return tech;
    }

    public void setTech(String tech) {
        this.tech = tech;
    }

    /**
     * Provides a human-readable string representation of the Student object.
     * Useful for logging and debugging.
     */
    @Override
    public String toString() {
        return "Student{" +
                "sid=" + sid +
                ", name='" + name + '\'' +
                ", tech='" + tech + '\'' +
                '}';
    }
}