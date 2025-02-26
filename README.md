<!DOCTYPE html>
<html lang="fa">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>راهنمای پروژه</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            direction: rtl;
            text-align: right;
            margin: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 800px;
            background: white;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        code {
            background: #ddd;
            padding: 2px 5px;
            border-radius: 5px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>مفسر زبان اسکریپتی ساده</h1>
        <p>این پروژه یک مفسر ساده برای یک زبان اسکریپتی است که از عملیات ریاضی، پرش‌ها و متغیرها پشتیبانی می‌کند.</p>
        
        <h2>نحوه اجرا</h2>
        <p>برای اجرای برنامه، ابتدا کد را کامپایل کرده و سپس فایل ورودی را اجرا کنید:</p>
        <pre><code>g++ -o interpreter main.cpp
./interpreter</code></pre>
        
        <h2>ساختار دستورات</h2>
        <p>دستورات این زبان به‌صورت زیر هستند:</p>
        <ul>
            <li><code>$var = مقدار</code> → مقداردهی به متغیر</li>
            <li><code>@label</code> → تعریف برچسب</li>
            <li><code>label jump</code> → پرش به برچسب</li>
            <li><code>var print</code> → نمایش مقدار متغیر</li>
            <li><code>var increase</code> → افزایش مقدار متغیر</li>
        </ul>
        
        <h2>نمونه کد ورودی</h2>
        <pre><code>
$X = 5
$Y = 10
$X $Y add $Z
$Z print
        </code></pre>
    </div>
</body>
</html>
