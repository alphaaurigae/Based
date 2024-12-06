# Base (58 only for now) encode decode w hex support 

- Supported: Base 58

## Todo
.... add more base options , beautify code, formatting and sec etc ...

## RUN

```
$ bin/b58_decode_encode   -d '68656c6c6f'
Input received: [68656c6c6f]
No quotes to remove. Modified Input: [68656c6c6f]
Decoded Output (hex) default: 87 2a 92 a3 09 1b cc 
Decoded Output (hex) compact: 872a92a3091bcc
Decoded Output (Unicode): �*��	
```
```
$ bin/b58_decode_encode   --hex '68656c6c6f'
Input received: [68656c6c6f]
No quotes to remove. Modified Input: [68656c6c6f]
Encoded Output (Base58): Cn8eVZg
```
```
$ bin/b58_decode_encode   --hex 'Cn8eVZg'
Input received: [Cn8eVZg]
No quotes to remove. Modified Input: [Cn8eVZg]
Error: Hex string has an odd number of characters
```
```
$ bin/b58_decode_encode   'Cn8eVZg'
Input received: [Cn8eVZg]
No quotes to remove. Modified Input: [Cn8eVZg]
Encoding Input: Cn8eVZg
Encoded Output: 3ZD5jHsk6i
```
```
$ bin/b58_decode_encode -d  'Cn8eVZg'
Input received: [Cn8eVZg]
No quotes to remove. Modified Input: [Cn8eVZg]
Decoded Output (hex) default: 68 65 6c 6c 6f 
Decoded Output (hex) compact: 68656c6c6f
Decoded Output (Unicode): hello
```
```
$ bin/b58_decode_encode 'hello'
Input received: [hello]
No quotes to remove. Modified Input: [hello]
Encoding Input: hello
Encoded Output: Cn8eVZg
```
```
$ bin/b58_decode_encode   '68656c6c6f'
Input received: [68656c6c6f]
No quotes to remove. Modified Input: [68656c6c6f]
Encoding Input: 68656c6c6f
Encoded Output: 43gGFuQUh3Kpxd
```


## BUILD

Dev OS Ubuntu 24.04

... cmake ...

`./clean_cmake.sh`
`./build_cmake.sh`