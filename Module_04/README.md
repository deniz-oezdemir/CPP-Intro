# Subtyping Polymorphism

Subtyping polymorphism allows a subclass to be treated as an instance of its parent class. The following behaviors apply:

- **Inheritance and Initialization**: When a class inherits from another, it's possible to initialize an instance of the child class using a pointer. This pointer can be either of the parent or the child class.
- **Pointer Initialization Restrictions**: It's important to note that the relationship between parent and child classes is not reversible when it comes to pointers. Specifically, you can use a parent class type pointer to hold a child class instance, but you cannot use a child class type pointer to hold a parent class instance.
- **Method Resolution with Parent Class Pointers**: If you initialize a child class instance as a pointer using the parent class as a type, method calls on this pointer will, by default, refer to the methods defined in the parent class.
- **Overriding with `virtual` Functions**: To ensure that the child class's methods are called instead of the parent's when using a parent class type pointer, you can mark the parent class's method as `virtual`. If the child class provides its own implementation, this version will be called, showcasing polymorphic behavior.
