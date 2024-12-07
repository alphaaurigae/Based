# Base (58 only for now) encode decode w hex support 

- Supported: Base 58


## Build

- Build OS: "Ubuntu 24.04"

... cmake ...

- ```./build_cmake.sh``` - build
- ```./clean_cmake.sh``` - tidy build


## Deps
```
libflint-dev - https://github.com/flintlib/flint
```


## Run
```
$ '/home/mmmm/Desktop/Based/test.sh' 

Test w.o arg
Usage:
  bin/based_encode-decode [options] <input>

Options:
  -h, --help      Show this help message and exit.
  -d              Decode Base58 input.
  --hex           Handle input as hex E.g 68656c6c6f == Cn8eVZg 

  E.g 
  $ bin/based_encode-decode 'Cn8eVZg'
  $ bin/based_encode-decode --hex '68656c6c6f'
  $ bin/based_encode-decode -d  'Cn8eVZg'
  Ensure your input for decoding is valid Base58-encoded data.



```

```
$ bin/based_encode-decode -d '68656c6c6f'
Input received: [68656c6c6f]
No quotes to remove. Modified Input: [68656c6c6f]
Decoded Output (hex) default: 87 2a 92 a3 09 1b cc 
Decoded Output (hex) compact: 872a92a3091bcc
Decoded Output (Unicode Symbols): �*��	
```
```
$ bin/based_encode-decode --hex '68656c6c6f'
Input received: [68656c6c6f]
No quotes to remove. Modified Input: [68656c6c6f]
Encoded Output (Base58): Cn8eVZg
```
```
$ bin/based_encode-decode --hex 'Cn8eVZg'
Input received: [Cn8eVZg]
No quotes to remove. Modified Input: [Cn8eVZg]
Error: Hex string has an odd number of characters

```
```
$ bin/based_encode-decode -d  'Cn8eVZg'
Input received: [Cn8eVZg]
No quotes to remove. Modified Input: [Cn8eVZg]
Decoded Output (hex) default: 68 65 6c 6c 6f 
Decoded Output (hex) compact: 68656c6c6f
Decoded Output (Unicode Symbols): hello
```
```
$ bin/based_encode-decode hello
Input received: [hello]
No quotes to remove. Modified Input: [hello]
Encoding Input: hello
Encoded Output: Cn8eVZg
```

## Todo

.... add more base options , beautify code, formatting and sec etc ...
