x = 0;
y = 0;

def gcd (a, b):
    global x
    global y

    if a == 0:
        x = 0
        y = 1
        return b

    x1 = 0
    y1 = 0
    d = gcd(b % a, a)
    x = y1 - (b / a) * x1
    y = x1
    return d



x0 = 1
y0 = 1
g = 1
def find_any_solution(a, b,  c):
    global x0
    global y0
    global g

    g = gcd(abs(a), abs(b))

    if c % g != 0:
        return False

    x0 *= c / g
    y0 *= c / g
    if (a < 0):
        x0 *= -1;
    if (b < 0):
        y0 *= -1;
    return True;



X = 0
Y = 0
def shift_solution(a,  b, cnt):
    global X;
    global Y;
    X += cnt * b;
    Y -= cnt * a;


def find_all_solutions( a,  b,  c,  minx,  maxx,  miny,  maxy):

    if find_any_solution(a, b, c, x, y, g) == False:
        return 0

    a /= g;
    b /= g;

    sign_a = +1
    sign_b = +1

    shift_solution(x, y, a, b, (minx - x) // b);
    if (x < minx):
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx):
        return 0;

    lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) // b);
    if (x > maxx):
        shift_solution(x, y, a, b, -sign_b);
    rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) // a);
    if (y < miny):
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy):
        return 0;
    lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) // a);
    if (y > maxy):
        shift_solution(x, y, a, b, sign_a);
    rx2 = x;

    if (lx2 > rx2):
        lx2, rx2 = rx2, lx2

    lx = max(lx1, lx2)
    rx = min(rx1, rx2)


    return (rx - lx) // abs(b) + 1;


def solve(d, b):

    LIM = 1e17;
    ans = find_all_solutions(b, d, b * b, 1, LIM, 1, LIM );
    return ans;






t = int(input())
for i in range(t):
    b,d = map(int, input().split(' '))

    print(solve(d,b))

