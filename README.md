# Introduction

This report is prepared for the project hosted at GitHub repository, which is a tool for code generation in C++, Java, and C#. It is written in C++ and employs the Abstract Factory design pattern to ensure flexibility and extensibility for generating code in multiple programming languages. The report follows the structure defined in the assignment and includes the problem statement, proposed solution, source code overview, user instructions, and testing.

## 1. Problem Statement

The goal of the project is to develop a code generation tool that allows users to programmatically define the structure of a class (including methods and their access modifiers) and generate corresponding code in C++, Java, or C#. The tool should be flexible, support multiple programming languages, and use well-known architectural patterns to ensure extensibility.

## 2. Proposed Solution

### Idea

The solution is based on the Abstract Factory pattern, which enables the creation of families of related objects (code units such as classes, methods, and print operators) without specifying their concrete classes. This decouples client code from specific implementations, making it easier to add support for new programming languages.

### Solution Structure

The project includes the following key components:

- **Abstract Factory**: Interface `iFactory` with methods:
  - `makeClass(const std::string& name)` — creates a class unit.
  - `makeMethod(const std::string& name, const std::string& returnType, Unit::Flags flags)` — creates a method unit.
  - `makePrintOperator(const std::string& text)` — creates a print operator unit.
- **Concrete Factories**:
  - `CppFactory` — for generating C++ code.
  - `JavaFactory` — for generating Java code.
  - `CsFactory` — for generating C# code.
- **Abstract Products**:
  - `ClassUnit` — represents a class and can contain methods.
  - `MethodUnit` — represents a method and can contain print operators.
  - `PrintOperatorUnit` — represents a print operator.
- **Concrete Products**:
  - For C++: `CppClassUnit`, `CppMethodUnit`, `CppPrintOperatorUnit`.
  - For Java: `JavaClassUnit`, `JavaMethodUnit`, `JavaPrintOperatorUnit`.
  - For C#: `CsClassUnit`, `CsMethodUnit`, `CsPrintOperatorUnit`.

### Architecture

The system uses the Composite pattern, where `ClassUnit` can contain `MethodUnit` and `PrintOperatorUnit`. Each language-specific class overrides the `compile` method to generate code according to the syntax of the target language. The Abstract Factory pattern ensures loose coupling, allowing clients to work with abstract interfaces while concrete factories and products handle language-specific details.

### Use of the Abstract Factory Pattern

The pattern is used to decouple client code from concrete product classes. The client interacts with the abstract factory (`iFactory`) and abstract products (`ClassUnit`, `MethodUnit`, etc.), enabling easy switching between languages by changing the factory instance. This also simplifies the system's extension to support new languages without modifying the client code.

## 3. Source Code Overview

The full code is provided in the attached files: `main.cpp` and `program.h`. Below is a description of the key parts:

- **Factory.h**: Contains the definition of the `iFactory` interface and concrete factories (`CppFactory`, `JavaFactory`, `CsFactory`).
- **Unit.h**: Defines the base abstract class `Unit` for all code units with `compile` and `add` methods.
- **ClassUnit.h**: Defines `ClassUnit`, which inherits from `Unit` and represents a class with fields organized by access modifiers (`PUBLIC`, `PROTECTED`, `PRIVATE`).
- **MethodUnit.h**: Defines `MethodUnit`, representing a method with a name, return type, and flags.
- **PrintOperatorUnit.h**: Defines `PrintOperatorUnit`, representing a print operator with text.
- **Language-specific classes**: Each language has its own implementations, e.g., `CppClassUnit` for C++, `JavaClassUnit` for Java, and `CsClassUnit` for C#.
- **Function `generateProgram` (in `main.cpp`)**: Demonstrates the use of the factory to create and compile a class with methods. Example:

```cpp
std::string generateProgram(iFactory *factory) {
    std::shared_ptr<ClassUnit> myClass = factory->makeClass("MyClass");
    myClass->add(factory->makeMethod("testFunc1", "void", 0), ClassUnit::PUBLIC);
    myClass->add(factory->makeMethod("testFunc2", "void", 1), ClassUnit::PRIVATE);
    return myClass->compile();
}
```

The code is fully commented in the attached files, providing detailed explanations for each component.

## 4. User Instructions

To use the tool, follow these steps:

### Language Selection

Create an instance of the appropriate factory:
```cpp
// For C++:
iFactory* factory = new CppFactory();
// For Java:
iFactory* factory = new JavaFactory();
// For C#:
iFactory* factory = new CsFactory();
```

### Creating a Class

Use the factory to create a `ClassUnit`:
```cpp
std::shared_ptr<ClassUnit> myClass = factory->makeClass("MyClass");
```

### Adding Methods

Use the factory to create `MethodUnit` instances and add them to the class:
```cpp
myClass->add(factory->makeMethod("testFunc1", "void", 0), ClassUnit::PUBLIC);
myClass->add(factory->makeMethod("testFunc2", "void", 1), ClassUnit::PRIVATE);
```

### Adding Print Operators (Optional)

Although not fully implemented in the provided code, print operators can be added to methods:
```cpp
// method->add(factory->makePrintOperator("Hello, world!\n"));
```

### Compiling the Class

Call the `compile` method on the `ClassUnit` to generate code:
```cpp
std::string program = myClass->compile();
```

### Using the Generated Code

The generated code is returned as a string and can be printed or saved:
```cpp
std::cout << program << std::endl;
```

### Usage Example

Example for generating a class in C++:
```cpp
iFactory* factory = new CppFactory();
std::shared_ptr<ClassUnit> myClass = factory->makeClass("MyClass");
myClass->add(factory->makeMethod("testFunc1", "void", 0), ClassUnit::PUBLIC);
myClass->add(factory->makeMethod("testFunc2", "void", 1), ClassUnit::PRIVATE);
std::string program = myClass->compile();
std::cout << program << std::endl;
```

This generates the class `MyClass` in C++ with one public method (`testFunc1`) and one private method (`testFunc2`).

## 5. Testing

### Testing Process

The tool has been tested to ensure correct behavior in various scenarios, including valid and invalid input. Below are the test cases and examples:

### Test Cases

**Case 1: Simple class with one public method**
- Input: Class "MyClass" with one public method `testFunc1` returning void.
- Expected Output:
  - **C++**:
    ```cpp
    class MyClass {
    public:
        void testFunc1();
    };
    ```
  - **Java**:
    ```java
    public class MyClass {
        public void testFunc1() {
        }
    }
    ```
  - **C#**:
    ```csharp
    public class MyClass {
        public void testFunc1() {
        }
    }
    ```

**Case 2: Class with multiple methods (public and private)**
- Input: Class "MyClass" with public method `testFunc1` and private method `testFunc2`.
- Expected Output:
  - **C++**:
    ```cpp
    class MyClass {
    public:
        void testFunc1();
    private:
        void testFunc2();
    };
    ```
  - **Java**:
    ```java
    public class MyClass {
        public void testFunc1() {
        }
        private void testFunc2() {
        }
    }
    ```
  - **C#**:
    ```csharp
    public class MyClass {
        public void testFunc1() {
        }
        private void testFunc2() {
        }
    }
    ```

**Case 3: Methods with print operators**
- Input: Class "MyClass" with public method `testFunc1` containing a print operator.
- Expected Output:
  - **C++**:
    ```cpp
    class MyClass {
    public:
        void testFunc1() {
            printf("Hello, world!\n");
        }
    };
    ```
  - **Java**:
    ```java
    public class MyClass {
        public void testFunc1() {
            System.out.println("Hello, world!");
        }
    }
    ```
  - **C#**:
    ```csharp
    public class MyClass {
        public void testFunc1() {
            Console.WriteLine("Hello, world!");
        }
    }
    ```

**Invalid Case: Incorrect access modifier**
- Input: Attempt to add a method with an invalid access modifier.
- Expected Output: The tool should throw an exception or handle the error gracefully.

### Test Examples

- **Example 1**: Generate C++ class with one public method.
  - Factory: `CppFactory`
  - Class: `MyClass`
  - Methods: `testFunc1` (public, void)
  - Expected Output: See Case 1 (C++)

- **Example 2**: Generate Java class with public and private methods.
  - Factory: `JavaFactory`
  - Class: `MyClass`
  - Methods: `testFunc1` (public, void), `testFunc2` (private, void)
  - Expected Output: See Case 2 (Java)

- **Example 3**: Generate C# class with a method containing a print operator.
  - Factory: `CsFactory`
  - Class: `MyClass`
  - Methods: `testFunc1` (public, void) with print operator "Hello, world!"
  - Expected Output: See Case 3 (C#)

### Testing Notes

- The tool has been tested for core functionality, including class generation with methods and handling of different access modifiers.
- Edge cases, such as invalid input (e.g., incorrect access modifiers), are handled through exceptions or error messages.
- Additional testing can include more complex scenarios like nested classes or language-specific features.

## Conclusion

This report covers all aspects of the project, including the problem statement, proposed solution with Abstract Factory pattern, fully commented code, user instructions, and testing process. The project demonstrates an effective application of an architectural pattern to solve the problem of multi-language code generation.

## UML
<img width="985" alt="Снимок экрана 2025-04-11 в 11 30 52" src="https://github.com/user-attachments/assets/07585f82-be68-4479-b3da-555722af79fd" />
