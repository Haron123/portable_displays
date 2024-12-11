### Purpose of This Repository

This repository was created to address the lack of portable display implementations for various microcontrollers.
Many existing libraries are either made specifically for the Arduino IDE or designed using primitives of a single microcontroller. 
While porting these libraries is not overly complex, I believe this is a more elegant approach even though it requires the use of C++.

The approach taken here is to provide well-defined interfaces that must be implemented and passed to a display. If the implementation is correct, it should work instantly.

Currently, there is an example implementation for the ST7735 display using the ATmega328P microcontroller:
- The SPI implementation is taken from [this repository](https://github.com/goessl/ATmega328P/tree/master).
- The ST7735 implementation is heavily inspired by [this repository](https://github.com/Matiasus/ST7735/tree/master).
- The system time implementation is self-made.

The Beauty here is the flexibility it offers. You can easily add your own implementation of the delay function or any other function by following the provided comments in the interface definitions.

### TODO List
- [x] Create README
- [ ] Develop a usage guide
- [ ] Review Doxygen comments for clarity
- [ ] Upload diagrams to explain the architecture
- [ ] Add more display implementations
