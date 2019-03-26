##Infix Operations and Postfix Operations

Infix operations look similar to everyday math, where the operators are scattered within the operations. 
> a + b

Postfix operations change the order of operators so that operands are first and it ends with the operator
> ab+

###Steps for Postfix Implementation
1. Read from left to right, one symbol at a time
2. If the symbol is an operand, write to post fix
3. If the symbol is an operator:
    * If stack is != 0, PUSH
    * If the top of the stack is of lesser priority: if top(stack) < symbol: Push to stack
    * else: POP off stack
4. Pop all contents, write to postfix

>Example: a + b * c
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
        <td>b</td>
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
        <td>null</td>
        <td>+</td>
        <td>abc*</td>
    </tr>
    <tr>
        <td>null</td>
        <td>null</td>
        <td>abc*+</td>
    </tr>
</table>



