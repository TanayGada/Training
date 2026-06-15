## ORM (Object Relational Mapping)
- Relation between OOP and Relational Databases.
- We need ORM tools to store objects directly into the databases
- class is the table
- object is the row in the table


## How do we store objects into Databases
1. sessionFactory -> session object
2. session object -> save(obj)

## CRUD Operations
### 1. Project Setup with Maven
- Create a pom.xml with the required dependencies:
    - hibernate-core
    - postgresql JDBC driver

### 2. Entity Class: Student.java
- @Entity: Declares this class as a Hibernate entity.
- @Table(name=...): Maps to custom table name in DB.
- @Id: Primary key.
- @Column(name=...): Maps to custom column names.

### 3. Hibernate Configuration File: hibernate.cfg.xml
- Located in src/main/resources:
- Contains
    -  JDBC connection details
    -  Hibernate dialect and DDL strategy
    -  Entity class mapping
- hbm2ddl.auto:
    - create → drops and recreates tables
    - update → updates schema without data loss
    - validate → checks schema, no changes
    - show_sql: Enables SQL logging

### 4. Main Class to Perform CRUD
- Bootstrap Hibernate via SessionFactory
- Demonstrates basic CRUD operations:
    - Create: session.persist(entity)
    - Read: session.find() / session.byId().getReference()
    - Update: session.merge(entity)
    - Delete: session.remove(entity)
- CUD operations wrapped inside transactions

## Common Errors:
1. Main Class to Perform CRUD
- Missing hbm2ddl.auto, or mapping not added

2. Cannot connect to DB
- Check username/password/port

3. ClassNotFoundException
- Missing driver dependency in pom.xml

4. SQL not printed
- show_sql is false(default)
