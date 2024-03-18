# Usage

First, compile the code using the following command:

```bash
g++ -o urlcoder urlcoder.cpp
```

Then, run the program using the following command:

```bash
./urlcoder <string> <mode>
```

Where `<string>` is the string to encode or decode and `<mode>` is the mode to use. If mode is empty, the program will encode the string. If mode is `d`, the program will decode the string.

# Example

```bash
./urlcoder "Hello, World!" 
result: Hello%2C%20World%21
```

You can also pipe it

```bash
echo "Hello, World!" | ./urlcoder
result: Hello%2C%20World%21
```

The same can be done with decoding

```bash
./urlcoder "Hello%2C%20World%21" -d
```

Or piping

```bash
echo "Hello%2C%20World%21" | ./urlcoder -d
```
