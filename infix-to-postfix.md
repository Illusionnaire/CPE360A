## Infix Operations and Postfix Operations

Infix operations look similar to everyday math, where the operators are scattered within the operations. 
> a + b

Postfix operations change the order of operators so that operands are first and it ends with the operator
> ab+

With postfix, a program can go in order from left to right and look for the operators only to do the correct calculations. Because of this, the operators need to be put in the correct order.

## Steps for Postfix Implementation
1. Read from left to right, one symbol at a time
2. If the symbol is an operand, write to post fix
3. If the symbol is an operator:
    * If stack is != 0, PUSH
    * If the top of the stack is of lesser priority: if top(stack) < symbol: Push to stack
    * else: POP off stack until top of the stack is ~ equal priority
4. Pop all contents, write to postfix

### Priority order:
1. Open parenthesis should always be pushed (highest priority)
2. Closed parenthesis should be popped until open parenthesis and then do not write the parenthesis in postfix
3. Exponents are 2nd highest priority
4. Multiplication/Division are 3rd priority
5. Addition/Subtraction are 4th priority
<hr>
Example: a + b * c
<table>
    <tr>
        <th>Symbol</th>
        <th>Stack</th>
        <th>Postfix</th>
    </tr>
    <tr>
        <td>-</td>
        <td>null</td>
        <td>-</td>
    </tr>
    <tr>
        <td>a</td>
        <td>null</td>
        <td>a</td>
    </tr>
    <tr>
        <td>+</td>
        <td>+</td>
        <td>a</td>
    </tr>
    <tr>
        <td>b</td>
        <td>+</td>
        <td>ab</td>
    </tr>
    <tr>
        <td>*</td>
        <td>*|+</td>
        <td>ab</td>
    </tr>
    <tr>
        <td>c</td>
        <td>*|+</td>
        <td>abc</td>
    </tr>
    <tr>
        <td>-</td>
        <td>+</td>
        <td>abc*</td>
    </tr>
    <tr>
        <td>null</td>
        <td>null</td>
        <td>abc*+</td>
    </tr>
</table>
<hr>
Example: a + b * c - d / e
<table>
    <tr>
        <th>Symbol</th>
        <th>Stack</th>
        <th>Postfix</th>
    </tr>
    <tr>
        <td>null</td>
        <td>null</td>
        <td>null</td>
    </tr>
    <tr>
        <td>a</td>
        <td>null</td>
        <td>a</td>
    </tr>
    <tr>
        <td>+</td>
        <td>+</td>
        <td>a</td>
    </tr>
    <tr>
        <td>b</td>
        <td>+</td>
        <td>ab</td>
    </tr>
    <tr>
        <td>*</td>
        <td>*|+</td>
        <td>ab</td>
    </tr>
    <tr>
        <td>c</td>
        <td>*|+</td>
        <td>abc</td>
    </tr>
    <tr>
        <td>-</td>
        <td>-|+</td>
        <td>abc*</td>
    </tr>
    <tr>
        <td>d</td>
        <td>-|+</td>
        <td>abc*d</td>
    </tr>
    <tr>
        <td>/</td>
        <td>/|-|+</td>
        <td>abc*d</td>
    </tr>
    <tr>
        <td>e</td>
        <td>/|-|+</td>
        <td>abc*de</td>
    </tr>
    <tr>
        <td>null</td>
        <td>/|-|+</td>
        <td>abc*de/-+</td>
    </tr>
</table>
<hr>
Example: a * b - c / d + e ^ f
<table>
    <tr>
        <th>Symbol</th>
        <th>Stack</th>
        <th>Postfix</th>
    </tr>
    <tr>
        <td>null</td>
        <td>null</td>
        <td>null</td>
    </tr>
    <tr>
        <td>a</td>
        <td>null</td>
        <td>a</td>
    </tr>
    <tr>
        <td>*</td>
        <td>*</td>
        <td>a</td>
    </tr>
    <tr>
        <td>b</td>
        <td>*</td>
        <td>ab</td>
    </tr>
    <tr>
        <td>-</td>
        <td>-</td>
        <td>ab*</td>
    </tr>
    <tr>
        <td>c</td>
        <td>-</td>
        <td>ab*c</td>
    </tr>
    <tr>
        <td>/</td>
        <td>/|-</td>
        <td>ab*c</td>
    </tr>
    <tr>
        <td>d</td>
        <td>/|-</td>
        <td>ab*cd</td>
    </tr>
    <tr>
        <td>+</td>
        <td>+|-</td>
        <td>ab*cd/</td>
    </tr>
    <tr>
        <td>e</td>
        <td>+|-</td>
        <td>ab*cd/e</td>
    </tr>
    <tr>
        <td>^</td>
        <td>^|+|-</td>
        <td>ab*cd/e</td>
    </tr>
    <tr>
        <td>f</td>
        <td>^|+|-</td>
        <td>ab*cd/ef</td>
    </tr>
    <tr>
        <td>null</td>
        <td></td>
        <td>ab*cd/ef^+-</td>
    </tr>
</table>
<hr>
Example: (a + b) * c
<table>
    <tr>
        <th>Symbol</th>
        <th>Stack</th>
        <th>Postfix</th>
    </tr>
    <tr>
        <td>null</td>
        <td>null</td>
        <td>null</td>
    </tr>
    <tr>
        <td>(</td>
        <td>(</td>
        <td>null</td>
    </tr>
    <tr>
        <td>a</td>
        <td>(</td>
        <td>a</td>
    </tr>
    <tr>
        <td>+</td>
        <td>+|(</td>
        <td>a</td>
    </tr>
    <tr>
        <td>b</td>
        <td>+|(</td>
        <td>ab</td>
    </tr>
    <tr>
        <td>)</td>
        <td>*</td>
        <td>ab+</td>
    </tr>
    <tr>
        <td>c</td>
        <td>*</td>
        <td>ab+c</td>
    </tr>
    <tr>
        <td>null</td>
        <td></td>
        <td>ab+c*</td>
    </tr>
</table>

>I didn't want to table (a^b + c) * (d - e^f)
>Thanks for the long problem Regan
>> Answer: ab^c+def^-*