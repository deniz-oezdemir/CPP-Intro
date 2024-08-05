# Module_04

## Subtype Polymorphism (ex00)

Subtyping polymorphism allows a subclass to be treated as an instance of its parent class. The following behaviors apply:

- **Inheritance and Initialization**: When a class inherits from another, it's possible to initialize an instance of the child class using a pointer. This pointer can be either of the parent or the child class.
- **Pointer Initialization Restrictions**: It's important to note that the relationship between parent and child classes is not reversible when it comes to pointers. Specifically, you can use a parent class type pointer to hold a child class instance, but you cannot use a child class type pointer to hold a parent class instance.
- **Method Resolution with Parent Class Pointers**: If you initialize a child class instance as a pointer using the parent class as a type, method calls on this pointer will, by default, refer to the methods defined in the parent class.
- **Overriding with `virtual` Functions**: To ensure that the child class's methods are called instead of the parent's when using a parent class type pointer, you can mark the parent class's method as `virtual`. If the child class provides its own implementation, this version will be called, showcasing polymorphic behavior.


## `virtual` Destructors (ex01)

Compiling without a `virtual` Destructor in the Animal Class results in an error. The error messages are due to the C++ compiler flags `-Wall -Werror -Wextra`.

The specific warning here is about deleting instances of a polymorphic class that has a non-virtual destructor. In C++, if a class is designed to be a base class of a polymorphism hierarchy (i.e., it has or is intended to have subclasses that may override its methods), it should have a virtual destructor. This ensures that when a derived class object is deleted through a pointer to the base class, the destructor of the derived class is called first, followed by the base class destructor, allowing for proper resource cleanup.

Without the `virtual` keyword, only the base class destructor will be executed. This can lead to resource leaks or other issues if the derived class allocates resources (like dynamic memory, file handles, etc. - here a `Brain` instance) that are released in its destructor.

Here's what happens step by step **_without_** the `virtual` destructor in the base class:

1. **Object Creation**: An object of a derived class is created dynamically using `new`. This object might allocate additional resources that need to be cleaned up when the object is destroyed.

2. **Deletion through Base Class Pointer**: The object is deleted through a pointer to the base class, intending to clean up the resources.

3. **Base Class Destructor Called**: Because the base class destructor is not `virtual`, C++ does not perform dynamic dispatch to call the derived class's destructor. Instead, only the base class destructor is called.

4. **Derived Class Destructor Skipped**: The destructor of the derived class is not called. As a result, any resources allocated by the derived class are not released, leading to resource leaks.

5. **Undefined Behavior and Resource Leaks**: The failure to call the derived class destructor can lead to undefined behavior, especially if the derived class is managing resources that need explicit cleanup. This can manifest as memory leaks, dangling pointers, or other erratic behavior.

Using a `virtual` destructor in the base class ensures that deleting an object through a base class pointer will correctly call the destructor chain: first the derived class's destructor, then the base class's destructor, allowing for proper cleanup of resources.


## Abstract Classes (ex02)

Abstract classes serve as foundational templates for other classes. They are characterized by the following:
- They contain at least one pure virtual method, which is declared with `virtual` and assigned `= 0`. This indicates that the method must be implemented by any derived class.
- By convention, abstract classes are named with a prefix `A` to denote their abstract nature. This helps in quickly identifying abstract classes in a codebase.
- Abstract classes are utilized to outline common behaviors that derived classes should implement, providing a clear structure for inheritance.


## Interfaces (ex03)

Interfaces act as contracts for class behavior, ensuring consistency across different implementations:
- An interface, typically prefixed with `I`, defines a set of methods without implementing them. It mandates that any class inheriting the interface must implement these methods.
- Interfaces facilitate a form of multiple inheritances by allowing a class to inherit behavior from multiple sources, ensuring that a class adheres to a particular protocol or set of behaviors.

Both abstract classes and interfaces are instrumental in creating a well-structured, modular, and maintainable codebase. They encourage the design of components that are both extensible and interoperable.
