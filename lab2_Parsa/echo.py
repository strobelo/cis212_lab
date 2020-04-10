import sys

def echo(e, n, args):
    for arg in args:
        if e:
            sys.stdout.write(arg.encode().decode('unicode_escape') + ' ')
        else:
            sys.stdout.write(arg + ' ')
    
    if not n:
        sys.stdout.write('\n')

def main():
    eflag = nflag = False
    cntr = 1
    #echo -n -e something
    #echo -ne somthing

    for i in range(1, len(sys.argv)):
        if sys.argv[i][0] == '-':
            #parsing flags/options
            for j in range(1, len(sys.argv[i])):
                if sys.argv[i][j] == 'n':
                    nflag = True
                elif sys.argv[i][j] == 'e':
                    eflag = True
                elif sys.argv[i][j] == 'E':
                    eflag = False
                else:
                    sys.stderr.write("unknown option -- {}\n".format(sys.argv[i][j]))
                    exit(1)

        else:
            break

        cntr += 1

    
    echo(eflag, nflag, sys.argv[cntr:])


if __name__ == '__main__':
    main()
