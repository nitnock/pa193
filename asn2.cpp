#include <iostream>
#include <cstring>
#include <cstdlib>

int globalArray[5];

void bufferOverflow() {
    char buffer[10];
    strcpy(buffer, "This is definitely too long"); // Vulnerability: Buffer overflow
}

void formatString(char* userInput) {
    printf(userInput); // Vulnerability: Uncontrolled format string
}

void stackMemoryCorruption() {
    int array[5];
    array[10] = 42; // Vulnerability: Stack-based buffer overflow
}

void heapMemoryCorruption() {
    int* array = new int[5];
    array[10] = 42; // Vulnerability: Heap-based buffer overflow
    delete[] array;
}

void heapOverflow() {
    char* heapBuffer = (char*)malloc(10 * sizeof(char));
    strcpy(heapBuffer, "Excessive data for heap!"); // Vulnerability: Heap overflow
    free(heapBuffer);
}

void useAfterFree() {
    int* data = new int[5];
    delete[] data;
    data[0] = 42; // Vulnerability: Use after free
}

void doubleFree() {
    int* data = new int[5];
    delete[] data;
    delete[] data; // Vulnerability: Double free
}

void nullPointerDereference() {
    int* ptr = nullptr;
    *ptr = 42; // Vulnerability: Null pointer dereference
}

void integerOverflow() {
    int size = INT_MAX;
    size += 10; // Vulnerability: Integer overflow
}

void uninitializedVariable() {
    int value;
    std::cout << value; // Vulnerability: Uninitialized variable use
}

void outOfBoundsRead() {
    int array[5] = {1, 2, 3, 4, 5};
    std::cout << array[10]; // Vulnerability: Out of bounds read
}

void unsafeMalloc() {
    int* data = (int*)malloc(5 * sizeof(int));
    data[10] = 42; // Vulnerability: Unsafe memory access
    free(data);
}

void signedToUnsignedConversion() {
    int index = -1;
    int array[5] = {1, 2, 3, 4, 5};
    std::cout << array[(unsigned)index]; // Vulnerability: Signed to unsigned conversion
}

void commandInjection() {
    char command[256];
    std::cin >> command;
    system(command); // Vulnerability: Command injection
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        bufferOverflow();
        formatString(argv[1]);
        stackMemoryCorruption();
        heapMemoryCorruption();
        heapOverflow();
        useAfterFree();
        doubleFree();
        nullPointerDereference();
        integerOverflow();
        uninitializedVariable();
        outOfBoundsRead();
        unsafeMalloc();
        signedToUnsignedConversion();
        commandInjection();
    }
    return 0;
}
