# Prototype Design Pattern

## What is it? - Cloning the runtime state
- Prototype lets objects create copies of themselves. 
- This removes the need for client code to know or depend on their concrete type, and it avoids expensive re-initialization logic
- It’s especially useful when objects are complex or dynamically typed.

## Purpose
Create new objects by cloning existing ones — without depending on their concrete classes.


## Bad Approach: manual construction + copying
```java
obj2 = new Class();
obj2.field1 = obj1.field1;
...
obj2.fieldn = obj1.fieldn;
```
1. time consuming and tedious as object creation is expensive
2. dependant on the class implementation

## Good Approach
Let the object clone itself via a shared interface. Eg.
`clone()`
```java
obj2 = obj1.clone();
```
This shifts the responsibility of copying into the object itself.

## Why do real systems need this?

1. Object construction is expensive
    - Example: deeply nested configs, DB hydration, validation, caching
2. Class type is unknown at runtime
    - Example: polymorphic processing pipelines
3. Objects need to be duplicated safely
    - Example: undo/redo, snapshotting, config templating
4. You want pre-built templates
    - Example: prototype registry

## Key Insight
### “Prototype = copy object state, not rebuild behavior”

We’re cloning runtime state - which may differ from constructor-initialized state.

This matters because in production code:
1. constructors may validate
2. constructors may hit network or disk
3. constructors may load dependencies
4. constructors may randomize IDs

Cloning skips all that.

## Application
Store pre-built prototypes and clone instead of rebuilding state for

1. Undo/Redo
2. Versioning
3. Snapshotting
4. Copy-on-write
5. Draft mode
6. Config templates
7. Caching hydrated objects

## Cases
### 1. Cloning an immutable object
- state cannot change
- hence shallow copy 
- no need for cloning, copying is safe
```java
final class Money {
    private final int amount;
    private final String currency;

    public Money(int amount, String currency) {
        this.amount = amount;
        this.currency = currency;
    }

    public Money clone() {
        return new Money(this.amount, this.currency);
    }
}
```

### 2. Cloning aggregate objects
- Domain Object containing others
```txt
Order
 Customer
 Items
 ShippingDetails
 PaymentInfo
```
#### Define ownership and decide shallow/deep copy
- If Order owns Items → deep clone
- If Items are shared → shallow clone

```java
class Address {
    String city;
    String street;

    public Address(String city, String street) {
        this.city = city;
        this.street = street;
    }

    public Address clone() {
        return new Address(this.city, this.street);
    }
}

class User {
    String name;
    Address address;

    public User(String name, Address address) {
        this.name = name;
        this.address = address;
    }

    public User clone() {
        return new User(this.name, this.address.clone());
    }
}
```
We clone the address too — so modification to one user’s address doesn’t affect another.
```java
User u1 = new User("A", new Address("NY", "5th Ave"));
User u2 = u1.clone();

u2.address.city = "LA";
//u1 -> "NY"
//u2 -> "LA"
```


### 3. Handling Deep Clone reference graphs
There are
1. Circular references.
2. Shared dependencies.
3. Lazy-loaded data.

We must ans
1. do we preserve identity?
2. do we duplicate everything?
3. do we support graph-aware cloning?

Example:
- Order → Customer → Address
- Order → Items → Product
```java
class Product {
    String name;

    Product(String name) { this.name = name; }

    Product(Product source) {
        this.name = source.name;
    }

    Product clone() {
        return new Product(this);
    }
}

class OrderItem {
    Product product;
    int qty;

    OrderItem(Product p, int qty) {
        this.product = p;
        this.qty = qty;
    }

    OrderItem(OrderItem source) {
        this.product = source.product.clone();
        this.qty = source.qty;
    }

    OrderItem clone() {
        return new OrderItem(this);
    }
}
```
Every class controls how deep to go.

Think about
1. ownership
2. lifecycle
3. immutability


### 4. Registry
```java
interface Shape extends Cloenable{
    Shape clone();
}

class Circle implements Shape{
    int radius;
    String color;

    public Circle(int radius, String color){
        this.radius = radius;
        this.color = color;
    }

    public Circle(Circle source){
        this.radius = source.radius;
        this.color = source.color;
    }

    @override
    public Circle clone(){
        return new Circle(this);
    }
}

class PrototypeRegistry{
    private static final Map<String, Shape> registry = new HashMap<>();

    public static void register(String key, Shape prototype){
        registry.put(key, prototype);
    }

    public static Shape get(String key){
        return registry.get(key).clone();
    }
}
```

Usage:
```java
PrototypeRegistry.register("big-red-circle", new Circle(50, "red"));

Shape c1 = PrototypeRegistry.get("big-red-circle");
Shape c2 = PrototypeRegistry.get("big-red-circle");
```
## Optimization
### 1. Copy on Write
- Share state until someone modifies it. Only then, create a new copy.
- Flow:
1.	Two objects share data
2.	One modifies it
3.	System clones lazily
4.	Updates isolated copy