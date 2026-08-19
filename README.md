# Lexical Analyzer & Token Counter

## 1. Title

**Lexical Analyzer & Token Counter using C**

## 2. Objective

The objective of this project is to develop a lexical analyzer that reads a source-code file and identifies and counts different types of tokens.

The lexical analyzer identifies:

* Keywords
* Identifiers
* Operators
* Constants/Literals
* Separators/Delimiters
* Special Symbols
* Comments

The program is implemented in **C**.

---

## 3. Problem Statement

Develop a program that reads a source-code file and performs lexical analysis by identifying and counting different types of tokens.

The program reads the source code character by character and classifies each valid token into its appropriate category.

The token categories considered in this project are:

| Token Type     | Description                                 |
| -------------- | ------------------------------------------- |
| Keyword        | Reserved words such as `int`, `float`, `if` |
| Identifier     | Names of variables and functions            |
| Operator       | Symbols such as `+`, `-`, `=`, `/`, `>`     |
| Constant       | Numeric values such as `50`, `2.0`          |
| String Literal | Text enclosed in double quotes              |
| Separator      | Symbols such as `(`, `)`, `;`, `,`          |
| Special Symbol | Other special characters                    |
| Comment        | Single-line or multi-line comments          |

---

## 4. Algorithm

1. Start the program.
2. Ask the user to enter the source-code file name.
3. Open the source file in read mode.
4. Read the source file character by character.
5. Ignore white spaces and newline characters.
6. If a character is a letter or underscore, read the complete word.
7. Check whether the word is a keyword.
8. If it is a keyword, classify it as a **Keyword**.
9. Otherwise, classify it as an **Identifier**.
10. If a character is a digit, read the complete numeric value and classify it as a **Constant**.
11. If a double quote is encountered, read until the closing double quote and classify it as a **String Literal**.
12. Check for operators such as `+`, `-`, `*`, `/`, `=`, `>`, `<`, etc.
13. Check for separators/delimiters such as `(`, `)`, `{`, `}`, `[`, `]`, `;`, and `,`.
14. Check for comments beginning with `//` or `/*`.
15. Classify other symbols as **Special Symbols**.
16. Maintain separate counters for each token category.
17. Display the tokens and their corresponding types.
18. Display the total token count for each category.
19. Close the source file.
20. Stop.

---

## 5. Source Code

The complete source code is available in:

```text
lexical_analyzer.c
```

The program:

* Reads a source-code file.
* Identifies different token types.
* Displays each token with its type.
* Counts each category of token.
* Handles keywords, identifiers, operators, constants, string literals, separators, special symbols, and comments.

### Compile

Using GCC:

```bash
gcc lexical_analyzer.c -o lexical_analyzer
```

### Run

```bash
./lexical_analyzer
```

On Windows:

```bash
lexical_analyzer.exe
```

When prompted, enter:

```text
sample.c
```

---

## 6. Sample Input

Create a file named `sample.c` with the following source code:

```c
int sum = a + b;
float average = sum / 2.0;
// Calculate average
if (average > 50)
    printf("Pass");
```

---

## 7. Sample Output

```text
Enter source file name: sample.c

TOKEN TYPE
------------------------------------------------
int                  Keyword
sum                  Identifier
=                    Operator
a                    Identifier
+                    Operator
b                    Identifier
;                    Separator
float                Keyword
average              Identifier
=                    Operator
sum                  Identifier
/                    Operator
2.0                  Constant
;                    Separator
//                   Comment
if                   Keyword
(                    Separator
average              Identifier
>                    Operator
50                   Constant
)                    Separator
printf               Identifier
(                    Separator
"Pass"               String Literal
)                    Separator
;                    Separator
------------------------------------------------

Token Count
Keywords       : 3
Identifiers    : 7
Operators      : 4
Constants      : 2
String Literals: 1
Separators     : 8
Comments       : 1
```

---

## 8. Token Classification

For the given sample input, the tokens are classified as follows:

| Token     | Type           |
| --------- | -------------- |
| `int`     | Keyword        |
| `sum`     | Identifier     |
| `=`       | Operator       |
| `a`       | Identifier     |
| `+`       | Operator       |
| `b`       | Identifier     |
| `;`       | Separator      |
| `float`   | Keyword        |
| `average` | Identifier     |
| `=`       | Operator       |
| `sum`     | Identifier     |
| `/`       | Operator       |
| `2.0`     | Constant       |
| `;`       | Separator      |
| `//`      | Comment        |
| `if`      | Keyword        |
| `(`       | Separator      |
| `average` | Identifier     |
| `>`       | Operator       |
| `50`      | Constant       |
| `)`       | Separator      |
| `printf`  | Identifier     |
| `(`       | Separator      |
| `"Pass"`  | String Literal |
| `)`       | Separator      |
| `;`       | Separator      |

### Token Count

```text
Keywords       : 3
Identifiers    : 7
Operators      : 4
Constants      : 2
String Literals: 1
Separators     : 8
Comments       : 1
```

---

## 9. Test Cases

### Test Case 1: Basic Arithmetic

**Input:**

```c
int a = 10;
int b = 20;
int sum = a + b;
```

**Expected token types:**

```text
int     -> Keyword
a       -> Identifier
=       -> Operator
10      -> Constant
;       -> Separator
int     -> Keyword
b       -> Identifier
=       -> Operator
20      -> Constant
;       -> Separator
int     -> Keyword
sum     -> Identifier
=       -> Operator
a       -> Identifier
+       -> Operator
b       -> Identifier
;       -> Separator
```

### Test Case 2: Conditional Statement

**Input:**

```c
if (a > 10)
    printf("Greater");
```

**Expected token types:**

```text
if          -> Keyword
(           -> Separator
a           -> Identifier
>           -> Operator
10          -> Constant
)           -> Separator
printf      -> Identifier
(           -> Separator
"Greater"   -> String Literal
)           -> Separator
;           -> Separator
```

### Test Case 3: Comments

**Input:**

```c
// This is a comment
int x = 50;
```

**Expected token types:**

```text
//          -> Comment
int         -> Keyword
x           -> Identifier
=           -> Operator
50          -> Constant
;           -> Separator
```

### Test Case 4: Floating-Point Constant

**Input:**

```c
float average = 25.5;
```

**Expected token types:**

```text
float       -> Keyword
average     -> Identifier
=           -> Operator
25.5        -> Constant
;           -> Separator
```

---

## 10. Conclusion

The Lexical Analyzer & Token Counter successfully reads a source-code file and identifies different types of tokens such as keywords, identifiers, operators, constants, string literals, separators, special symbols, and comments.

The program also maintains counters for each token category and displays the classification and total count. This project demonstrates the basic working principle of the lexical analysis phase of a compiler.
