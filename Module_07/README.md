# Module_06
## Function Templates

Function templates allow you to write functions that can operate on different data types without rewriting the same function for each type. Here's how you can use function templates:

### Defining a Function Template:

Use `template<typename T>` before the function declaration to indicate that the function is a template.
`T` is a placeholder for any data type (e.g., `int`, `float`, `std::string`, etc.).

```cpp
template<typename T>
T max(T x, T y) {
	return (x > y) ? x : y;
}
```

### Passing/Returning Template Types:

You can pass and return the template type by reference, which can be useful for efficiency, especially with large objects.

```cpp
template<typename T>
const T& max(const T& x, const T& y) {
	return (x > y) ? x : y;
}
```

### Instantiation of Function Templates:

Templates can be instantiated (or used) in two ways:

1. Implicit Instantiation: The compiler automatically deduces the type based on the arguments passed.

```cpp
int a = 10, b = 20;
int result = max(a, b); // Implicit instantiation: T is deduced as int
```

2. Explicit Instantiation: You specify the type explicitly.

```cpp
int a = 10, b = 20;
int result = max<int>(a, b); // Explicit instantiation
```

## Class Templates

Class templates work similarly to function templates, allowing classes to operate with generic types.

### Defining a Class Template:

Use `template<typename T>` before the class declaration.

```cpp
template<typename T>
class MyClass {
private:
	T data;
public:
	MyClass(T data) : data(data) {}
	T getData() const { return data; }
};
```

### Referencing the Template Type Inside the Class:

Within the class definition, reference the template type using `ClassName<T>`.

```cpp
template<typename T>
T MyClass<T>::getData() const {
	return data;
}
```
