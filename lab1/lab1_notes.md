# CIS212 Lab 1
#### Derek Strobel

## About Me
* Masters student CIS University of Oregon
* BS Computer Science Colorado State University
* Previously: Software engineer in aerospace engineering industry
* Sorry about my cat

## This Week - Linux & bash Literacy

### A Foreword: Virtual Machines and Operating Systems
* Many of you have Windows, Mac OS, and even various Linux systems
* Programs may have different behavior on different operating systems
* For this class, we will all use the Arch Linux image provided by Dr. Sventek
* Virtual Machines (VM): Allows you to run a "guest" OS as a program on your system
    * We will use Oracle VirtualBox (very popular hypervisor virtualization platform)
    * If you haven't already set this up: do it ASAP!!

### Linux
* Open-source operating system
* Based on: UNIX (1969!!!)
* Today: almost every website on the internet is hosted from a Linux system
    * Why?
        * Modular, predictable, and well-defined
        * By programmers, for programmers
        * Free!
* Linux is your friend
* "Linux is only free if your time has no value" - Jamie Zawinski (old-school open-source programmer)
* Linux is old (and UNIX is older). If you want to do something, someone has almost CERTAINLY done it before and written about it online!

### The Command Line Interface (CLI) (Or, the "Bash-course")
* What does bash do?
    * It's a program for running other programs

* Most of your day-to-day Linux commands will be:
    * `cd` (`c`hange `d`irectory)
    * `ls` (`l`i`s`t files)
    * `mv` (`m`o`v`e a file)
    * `cp` (`c`o`p`y a file)

* What programs can I use through bash?
    * Any binaries / executables!
    * `/usr/bin`
    * Your own compiled code! (next week)

* How do I know what anything does?
    * Hours of practice and experience
    * `man`

* Flags
    * Optional arguments to ask a program to perform a different function
    * Example: `ls`
    ```
    $ cd ~                   # ~ is a shortcut to your home directory!
    $ ls                     
    $ ls -l                  

    $ ls -a

    $ ls -l -a
    $ ls -la                 # these are the same! 

    ```
    `-l`: "long" list; displays ownership, permission, date, size, and more information

    `-a`: list "all"; displays hidden files (starting with "`.`" - UNIX convention)

    Try `man ls`: there are LOTS of options

## How do bash commands work? Well... They're just programs!
* We already know Python... so let's implement `echo` (just echoes the command-line input)
* Hint: Python `sys` package can access command-line arguments with `sys.argv`

## A case study: Creating a bash cheat-sheet
### Goals: 
* Create a helpful cheat-sheet for bash we can refer to (and add to) throughout the term
* Work with bash to create and modify directories and files
* Use the Linux Redirect operator ( `>` )

### Creating files and directories
```
$ cd ~                                        # move to our home directory
$ pwd                                         # print the working directory (to check)
/home/me

$ echo My Cheat Sheet                         # demonstrate the echo command
My Cheat Sheet
$ echo My Cheat Sheet > cheatsheet.txt        # use the > operator to write the output of echo to our cheatsheet file

$ ls                                          # list the contents of ~ (our cheatsheet.. and a bunch of other stuff!)
... cheatsheet.txt ...

$ mkdir reference                             # create a new directory just for our reference materials
$ mv cheatsheet.txt reference                 # move our cheatsheet into our reference directory
$ ls                                          # list the home dir again... cheatsheet is gone!
...

$ cd reference                                # change working dir to our new reference directory
$ ls                                          # list the contents of the reference directory and... lo!
cheatsheet.txt

$ cat cheatsheet.txt                          # viewing the fruits of our labor with the cat command
My Cheat Sheet

```

Now you have a plain-text cheatsheet file you can keep your favorite (or least-favorite) bash snippets in. But how to edit it?

### Text Editing
* Sublime Text: Well-featured, popular graphical text editor. 
    * Advantages: Easy to use, familiar GUI for most students
    * Disadvantages: Can be somewhat cumbersome for quick edits

* VIM: Classic, beloved command-line text editor. 
    * Advantages: Nearly universal among UNIX systems. Quick to pop open a file right from the CLI
    * Disadvantages: CLI interface & keybinds will be pretty foreign to most students, and can take time to learn

Exercise: Add some things to your bash cheat-sheet!

Some suggestions:
* Ctrl + L : Clear output from the terminal

