# Module_05

## Exceptions (ex00)

Exception handling in C++ is a mechanism to handle runtime errors. Key components:

- **`std::exception`**
	- This is the base class for all standard exceptions in C++.
	- Custom exceptions can be created by inheriting from this class.

- **`try`**
	- A block of code that might throw an exception is placed inside a `try` block.
	- If an exception occurs, the control is transferred to the corresponding `catch` block.

- **`throw`**
	- Used to signal the occurrence of an exception.
	- When an error condition is met, `throw` is used to create an exception object and transfer control to the nearest `catch` block.

- **`catch`**
	- A block of code that handles the exception thrown by the `try` block.
	- It specifies the type of exception it can handle.

## Nested Classes (ex00) - tbd
