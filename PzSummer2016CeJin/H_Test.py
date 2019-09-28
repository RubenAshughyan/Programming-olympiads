from random import randint, seed

seed(0)

with open("/home/ruben/CLionProjects/abgar/cmake-build-debug/in.txt", "w") as f:
    n = 100*1000
    q = 100 * 1000

    f.write("%d %d\n" % (n, q))

    for i in range(n):
        f.write(str(randint(1, n)) + " ")
    f.write("\n")

    for i in range(q//2):
        f.write("%d %d %d %d\n" % (1, 1, n, int(100000)))

    for i in range(q//2):
        f.write("%d %d %d\n" % (2, 1, n))

    exit(0)
    for i in range(q):
        op = randint(2,2)
        l = randint(1, n)
        r = randint(1, n)
        if l > r:
            l, r = r, l
        if op == 1:
            x = randint(0, 2 * n)
            f.write("%d %d %d %d\n" % (op, l, r, x))
        else:
            f.write("%d %d %d\n" % (op, l, r))

