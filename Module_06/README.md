# Module_06

## Implicit and Explicit Casts
- There are implicit and explicit casts.
- Example of implicit conversion: `int a = 42; double b = a;`
- Example of explicit conversion: `double b = (double)a;`
- There is a hierarchy among types, depending on precision.
- Implicit conversions can lead to a loss of precision if the new type has less precision (e.g., double casted to int).
- It is safer to use explicit conversion when the types are different.

## Upcast and Downcast
- Upcast from child to parent:
```
class Parent {};
class Child : public Parent {};
Child child;
Parent *parent = &child; // implicit upcast
```

- Downcast from parent to child:
```
Parent *parent = new Child();
Child *child = static_cast<Child*>(parent); // explicit downcast
```

- Implicit downcast is flagged by the compiler:
```
Parent parent;
Child *child = &parent; // compile-time error: cannot implicitly downcast
```
- Classes create new types that fall into a hierarchy thanks to inheritance.

## Type Reinterpretation
- `void *` is the most generic type.
- Implicit promotion is fine:
```
float f = 3.14f;
void *p = &f;
```

- But implicit demotion is dangerous:
```
void *p;
int *ip = p; // dangerous
```

- Explicit cast tells the compiler that demotion is intended:
```
void *p;
int *ip = (int *)p;
```

## Static Cast
- C++-style explicit cast: `static_cast<type>(foo)`
- Can be used with user-defined types too.
- It can detect if the cast doesn't belong to the same inheritance line and throws an error.

## Dynamic Casts
- Cast happens at runtime and not during compilation.
- Used for virtual classes.
- Returns null if the cast is not possible.
- Cast using pointer: `dynamic_cast<Child *>(foo)`.
- Cast using reference `dynamic_cast<Child &>(foo)`.
- When casting by reference, it can't return a null reference, so there's a specific type of exception: `std::bad_cast &bc`.
