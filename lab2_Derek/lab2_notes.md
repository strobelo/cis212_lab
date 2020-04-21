# CIS212 Lab 2: Searching with `grep`
Derek Strobel


#### `g`lobally search a `r`egular `e`x`p`ression

## Regular Expressions Review
Syntax for a search pattern

* What does it mean to "match" a regex?
    * regex string specifies a set of rules
    * if a string follows those rules, it's a match

Example:
```
regex:                 "[A-Z]{3}"
this string matches:   "ABC"
this string doesn't:   "abc"
```

* How do we build up a regex?
    * Tokens: Things to match
        * eg: `"a"`, `"[A-Z]"`, `"(x|y)"`

    * Quantifiers: How to match them
        * eg: `"?"`, `"*"`, `"{3}"`

    * Each quantifier applies to the preceding token
        * eg: in `"[a-z]*[0-9]"`, the `*` applies to the `[a-z]` token
            * -> any number of lowercase letters are matched before a single digit
            * eg: `"abcdefg1"` is a match, but `"abCdefg1"` and `"abcd3f"` are not
## Back to `grep`
* "globally" search means search the entire input
* if a line contains a match, the whole line is included in `grep`'s output

### Man.. the man is nonstop
Let's use `grep` a bit... but we need something to search!
* `grep` originally used to analyze the Federalist Papers
* full text: http://www.gutenberg.org/cache/epub/18/pg18.txt (~1MB)

to download:
```
curl http://www.gutenberg.org/ebooks/18.txt.utf-8 -o feds.txt
```


The Gutenberg edition lists the (accepted) author of each paper in caps...

(eg.`"HAMILTON"`, `"HAMILTON OR MADISON"`, `"HAMILTON AND MADISON"`)

Hint: use `wc`

Use only ONE grep invocation to find the following:

#### Authorship
1. How many papers COULD Hamilton have contributed to total?
1. How many papers COULD Madison have contributed to total?
1. How many papers written by just Hamilton?
1. How many papers MIGHT both Hamilton and Madison have contributed to?
1. How many papers are still disputed?

#### Name Drops
1. How many times is Rome mentioned? (Rome, Roman, and Romans)
1. How many times is Germany mentioned? (Germany, German, Germans, etc)

#### Needle in the Haystack
1. On which line does the word "civilian" appear?
1. On which line do words containing "civil" appear?

#### The World Turned Upside Down
1. How many lines contain the word "world"? How many **don't**?
