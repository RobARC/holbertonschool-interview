# 0x03. Minimum Operations

<p>In a text file, there is a single character H. Your text editor can execute only two operations in this file: Copy All and Paste. Given a number n, write a method that calculates the fewest number of operations needed to result in exactly n H characters in the file.</p>

<li>Prototype: def minOperations(n)</li>
<li>Returns an integer</li>
<li>If n is impossible to achieve, return 0</li>

<b>Example:</b>

##### n = 9

##### H => Copy All => Paste => HH => Paste =>HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH

##### Number of operations: 6