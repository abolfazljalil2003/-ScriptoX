

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple C++ Compiler Guide</title>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        code {
            background-color: #f4f4f4;
            padding: 2px 4px;
            border-radius: 4px;
        }
    </style>
</head>
<body>
# -ScriptoX
 ScriptoX – A lightweight and efficient interpreter for a simple scripting language. Supports mathematical operations, variables, labels, and conditional jumps.

    <h1>Simple C++ Compiler</h1>
    <p>This project is a simple compiler written in C++ that reads commands from a <code>testCase.txt</code> file and executes them.</p>
    
    <h2>Usage</h2>
    <ol>
        <li>Create a <code>testCase.txt</code> file with your desired commands.</li>
        <li>Compile the program:
            <pre><code>g++ -o compiler main.cpp</code></pre>
        </li>
        <li>Run the program:
            <pre><code>./compiler</code></pre>
        </li>
    </ol>
    
    <h2>Supported Commands</h2>
    <ul>
        <li><code>$var = value</code> - Assign a value to a variable</li>
        <li><code>var print</code> - Print the value of a variable or a number</li>
        <li><code>var increase</code> - Increment the value of a variable by one</li>
        <li><code>op1, op2 -> target operation</code> - Perform mathematical operations such as addition, multiplication, subtraction, division, power, and modulo</li>
        <li><code>@label</code> - Define a label for jumping</li>
        <li><code>@label jump</code> - Unconditional jump to a label</li>
        <li><code>@label op1, op2 jump_if_equal</code> - Conditional jump to a label if two values are equal</li>
        <li><code>@label op1, op2 jump_if_greater</code> - Conditional jump to a label if the first value is greater than the second</li>
        <li><code>@label op1, op2 jump_if_less</code> - Conditional jump to a label if the first value is less than the second</li>
    </ul>
    
    <h2>Example</h2>
    <pre><code>
$val1 = 5
$val2 = 3
val1, val2 -> $sum add
sum print
    </code></pre>
    
    <h2>Function Descriptions</h2>
    <ul>
        <li><code>addFunc(int x, int y)</code> - Add two numbers</li>
        <li><code>multiplyFunc(int x, int y)</code> - Multiply two numbers</li>
        <li><code>incrementVar(string var)</code> - Increment the value of a variable</li>
        <li><code>subtractFunc(int x, int y)</code> - Subtract two numbers</li>
        <li><code>divideFunc(int x, int y)</code> - Divide two numbers</li>
        <li><code>powerFunc(int x, int y)</code> - Calculate the power of a number</li>
        <li><code>modFunc(int x, int y)</code> - Calculate the modulo of two numbers</li>
        <li><code>isNumeric(const string& s)</code> - Check if a string is a numeric value</li>
        <li><code>gatherLabels(const vector<string>& lines)</code> - Gather labels from the lines of code</li>
        <li><code>processCommand(const vector<string>& lines, size_t currentLine)</code> - Process commands</li>
    </ul>
</body>
</html>