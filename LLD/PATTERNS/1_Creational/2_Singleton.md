# Singleton Design Pattern
Singleton ensures:

### Only one instance of a class exists in the entire application — and it is globally accessible.

## Think of it as:
1. One database connection manager
2. One configuration loader
3. One telemetry collector
4. One cache manager

## It is about controlling:
1. lifecycle
2. global access
3. resource safety
4. concurrency correctness

## Use Singleton when:

1. Only one instance makes logical sense
2. Object is expensive or stateful
3. Multiple components must coordinate through it
4. Lifecycle must be controlled

Examples:
- Logger
- Metrics collector
- Thread pool
- Configuration manager
- Registry services
- Feature flag provider

## When NOT to use Singleton

Avoid it when:
- Object represents business data
- It creates hidden global state
- You will want to unit test / mock it
- You may scale across processes
- It turns into a God Object

## 6 Ways to Achieve this
1. Eager
2. Lazy
3. Synchronization Method
4. Double Locking
5. Holder Pattern
6. Enum based Singleton

### Common Implementation

1. Make the default constructor private, to prevent other objects from using the new operator with the Singleton class.
2. Create a static creation method that acts as a constructor. Under the hood, this method calls the private constructor to create an object and saves it in a static field. All following calls to this method return the cached object.


## 1. Eager Initialization
- Eagerly initilizing the object at application initialization
```java
public class DBConnection{
    // create a static object
    private static DBConnection connectionObj = new DBConnection();
    // private constructor, so other classes cannot create a new instance
    private DBConnection(){}
    // return the same object everytime
    public static DBConnection getInstance(){
        return connectionObj;
    }
}
```
### Problem:
1. Object initilization on application initilization
2. Even if object is not used, it is created

## 2. Lazy Initialization
- Lazily initializing the object when the object is first created
```java
public class DBConnection{
    // declaring the static object with null initiation
    private static DBConnection connectionObj;
    private DBConnection(){}
    public static DBConnection getInstance(){
        // initializing the object when the 1st object is created, then use the same for next time
        if(connectionObj==null){
            connectionObj = new DBConnection();
        }
        return connectionObj;
    }
}
```
### Problem:
1. Not thread safe
2. Under race condition, multiple object instance can be created
3. Not safe for production

## 3. Synchronized Method
```java
public class DBConnection{
    private static DBConnection connectionObj;
    private DBConnection(){}
    // synchronization, to use locks to prevent race conditions
    synchronized public static DBConnection getInstance(){
        if(connectionObj==null){
            connectionObj = new DBConnection();
        }
        return connectionObj;
    }
}
```
### Problem
1. Locking is used everytime the `getInstance()` is called, even when the connectionObj is not null
2. Locking is expensive 

## 4. Double Locking (used in industry)
- Locking only when `connectionObj` is null
```java
public class DBConnection{
    private static DBConnection connectionObj;
    private DBConnection(){}
    public static DBConnection getInstance(){
        if(connectionObj==null){
            synchronized (DBConnection.class){
                if(connectionObj==null){
                    connectionObj = new DBConnection();
                }
            }
        }
        return connectionObj;
    }
}
```

## 5. Holder Pattern (used in industry)
### Static Inner Class
- They are NOT loaded into memory until first used
- Their fields are initialized when the class loads
- Class loading is thread-safe

Here
- Holder is not loaded when DBConnection is loaded
- It loads only when Holder.INSTANCE is first accessed


```java
class DBConnection {
    private DBConnection(){}

    // static inner class
    private static class Holder{
        static final DBConnection INSTANCE = new DBConnection();
    }

    public static DBConnection getInstance(){
        return Holder.INSTANCE;
    }
}
```
### Advantages:
1. Lazy initialization happens automatically (no instance is created until needed)
2. Thread-safety is guaranteed (because JVM class loading is synchronized)

## 6. Enum Singleton
An enum in Java guarantees:
1. exactly one instance per enum constant
2. thread-safe initialization
3. serialization-safe
4. reflection-safe

```java
public enum DBConnection {
    INSTANCE;

    public void connect() {
        System.out.println("Connected to database");
    }
}
```
```java
public class Main {
    public static void main(String[] args) {

        DBConnection c1 = DBConnection.INSTANCE;
        DBConnection c2 = DBConnection.INSTANCE;

        c1.connect();

        System.out.println(c1 == c2);   // true
    }
}
```
### When NOT to use Enum Singleton

1. You need subclassing
2. Your Singleton must accept constructor parameters
3. You’re writing library code meant for frameworks like Spring (DI preferred)
4. You want multiple instances in tests


## 3 Problems while implementing Singleton
1. Thread Safety -> solved by synchronization and holder usage
2. Serialization/Deserialization -> solved using `readResolve()`
3. Reflection -> solved using

## Serialization/Deserialization
- Serialization is the process of converting an object's state into a byte stream. This stream can then be stored in a file, sent over a network, or stored in a database and later reconstructed back into a working object through a reverse process called deserialization. 


### Serialization
```java
Singleton s1 = Singleton.getInstance();

ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("obj.ser"));
out.writeObject(s1);
```
### Deserialization
```java
ObjectInputStream in = new ObjectInputStream(new FileInputStream("obj.ser"));
Singleton s2 = (Singleton) in.readObject();
```
- Deserialization creates a new object, bypassing `getInstance()`
- So now there are two Singleton objects in memory

### Solution
- Add this to singleton class
```java
protected Object readResolve() {
    return getInstance();
}
```
- After deserialization:
    - JVM calls readResolve()
    - instead of returning the new object
    - it replaces it with the one you return