import sys

def cat(n, b, s, args):
    open_files = []
    if len(args) == 0:
        open_files.append(sys.stdin)
    else:
        for arg in args:
            open_files.append(open(arg, 'r')) # an error might happen here, see if you can figure it out

    for file in open_files:
        for line in file:
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
                    exit(1)
        else:
            break
        cntr += 1

    cat(nflag, bflag, sflag, sys.argv[cntr:])


if __name__ == '__main__':
    main()
