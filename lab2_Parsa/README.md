## Material
this week we implemented echo with the -e, -E and -n flags in python. We talked about grep and finally, we started implementing cat in python.  
The `echo.py` file contains a working python version of `echo`.  
The `cat.py` file contains a working version of `cat` but without actually applying any flags. I will leave implementing the `n`, `b`, and `s` flags to you as an exercise. I will show a way that you can implement them next week.

## Resources
while we talked about how to parse options, in practice(not in this class) you would want to use a command line option parsing library that most languages have. for example python has the `optparse` library which contains the `OptionParser` class. These provide facilities to define an option (short and long) with a description. More on that here:  
<https://docs.python.org/2/library/optparse.html>
