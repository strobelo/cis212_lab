import sys

def cat(n, b, s, args):
    open_files = []
    if len(args) == 0:
        open_files.append(sys.stdin)
    else:
        for arg in args:
            open_files.append(open(arg, 'r'))

    for file in open_files:
        line_cnt = 0
        empty_lines = 0 # holds the number of consecutive empty lines, used for s flag
        for line in file:
            # regardless of the flags(s, n, and b), when the line is not empty (i.e. != '\n')
            # we have to print it
            if line != '\n':
                empty_lines = 0 # reset number of consecutive empty lines
                # if n or b is specified we have to show the line number
                if n or b:
                    line_cnt += 1
                    sys.stdout.write("%6d  %s"%(line_cnt, line))
                else:
                    #otherwise just the line
                    sys.stdout.write(line)
            else:
                #increment the number of consecutive empty lines
                empty_lines += 1
                # if s flag is specified, we can only print the empty line, if the number of consecutive
                # empty lines is 1, if s is not specified, then we can print the empty line.
                if not s or empty_lines == 1:
                    if n:
                        line_cnt += 1
                        sys.stdout.write('%6d\n'%(line_cnt))
                    else:
                        sys.stdout.write(line)

    if len(args) != 0:
        for file in open_files:
            file.close()

def main():
    nflag = bflag = sflag = False
    cntr = 1

    for i in range(1, len(sys.argv)):
        if sys.argv[i][0] == '-':
            for j in range(1, len(sys.argv[i])):
                if sys.argv[i][j] == 'n':
                    nflag = True
                elif sys.argv[i][j] == 'b':
                    bflag = True
                elif sys.argv[i][j] == 's':
                    sflag = True
                else:
                    sys.stderr.write("unknown option -- {}\n".format(sys.argv[i][j]))

        else:
            break
        cntr += 1

    cat(nflag, bflag, sflag, sys.argv[cntr:])


if __name__ == '__main__':
    main()
