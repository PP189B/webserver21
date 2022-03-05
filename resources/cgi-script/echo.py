#!/usr/bin/python3
import os
import sys
from urllib import response

# echo
if (os.environ['REQUEST_METHOD'] == 'POST'):    
    data = sys.stdin.read()
else:
    data = "You didn't used POST method, so there is nothing to ECHO... :c"


response_body = """<html>
    <title> ECHO </title>

    <body>
        <h1>{}</h1>
    </body>
</html>""".format(data)

print("Content-type: text/html")
print("Content-Lenght: {}".format(len(response_body) - 1))
print()
print(response_body, end='')

