# Module_04: Details

## Subtyping Polymorphism

Subtyping polymorphism allows a subclass to be treated as an instance of its parent class. The following behaviors apply:

- **Inheritance and Initialization**: When a class inherits from another, it's possible to initialize an instance of the child class using a pointer. This pointer can be either of the parent or the child class.
- **Pointer Initialization Restrictions**: It's important to note that the relationship between parent and child classes is not reversible when it comes to pointers. Specifically, you can use a parent class type pointer to hold a child class instance, but you cannot use a child class type pointer to hold a parent class instance.
- **Method Resolution with Parent Class Pointers**: If you initialize a child class instance as a pointer using the parent class as a type, method calls on this pointer will, by default, refer to the methods defined in the parent class.
- **Overriding with `virtual` Functions**: To ensure that the child class's methods are called instead of the parent's when using a parent class type pointer, you can mark the parent class's method as `virtual`. If the child class provides its own implementation, this version will be called, showcasing polymorphic behavior.


## Importance of `virtual` Destructors (ex01)
Compiling without a `virtual` Destructor in the Animal Class results in an error. The error messages are due to the C++ compiler flags `-Wall -Werror -Wextra`.

The specific warning here is about deleting instances of a polymorphic class that has a non-virtual destructor. In C++, if a class is designed to be a base class of a polymorphism hierarchy (i.e., it has or is intended to have subclasses that may override its methods), it should have a virtual destructor. This ensures that when a derived class object is deleted through a pointer to the base class, the destructor of the derived class is called first, followed by the base class destructor, allowing for proper resource cleanup.

Without the `virtual` keyword, only the base class destructor will be executed. This can lead to resource leaks or other issues if the derived class allocates resources (like dynamic memory, file handles, etc. - here a `Brain` instance) that are released in its destructor.

Here's what happens step by step without the `virtual` destructor in the base class:

1. **Object Creation**: An object of a derived class is created dynamically using `new`. This object might allocate additional resources that need to be cleaned up when the object is destroyed.

2. **Deletion through Base Class Pointer**: The object is deleted through a pointer to the base class, intending to clean up the resources.

3. **Base Class Destructor Called**: Because the base class destructor is not `virtual`, C++ does not perform dynamic dispatch to call the derived class's destructor. Instead, only the base class destructor is called.

4. **Derived Class Destructor Skipped**: The destructor of the derived class is not called. As a result, any resources allocated by the derived class are not released, leading to resource leaks.

5. **Undefined Behavior and Resource Leaks**: The failure to call the derived class destructor can lead to undefined behavior, especially if the derived class is managing resources that need explicit cleanup. This can manifest as memory leaks, dangling pointers, or other erratic behavior.

Using a `virtual` destructor in the base class ensures that deleting an object through a base class pointer will correctly call the destructor chain: first the derived class's destructor, then the base class's destructor, allowing for proper cleanup of resources.
