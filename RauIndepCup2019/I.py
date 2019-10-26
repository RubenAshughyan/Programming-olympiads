n = int(input())

lines = [input() for i in range(n)]

class I:
    def __init__(self, lines):
        self.lines = lines
        self.line_num = 1
        self.vars = {i:0 for i in 'qwertyuiopasdfghjklzxcvbnm'}
        self.end = False
        
    def exec_command(self, line):
        if line.startswith('GOTO'):
            self.line_num = int(line[4:].strip()) - 1
            return
        if line.startswith('PRINT'):
            print(eval(line[5:].strip(), self.vars))
            return
        if line.startswith('END'):
            exit(0)
            return
        if line.startswith('IF'):
            ind = line.find('THEN')
            lind = ind - 1
            rind = ind + 5
            test = line[3:lind].strip()
            command = line[rind:].strip()
            test_val = self.eval_exp(test)
            if test_val:
                self.exec_command(command)
            return
        vname, expr = line.split('=')
        vname = vname.strip()
        expr = expr.strip()
        self.vars[vname] = self.eval_exp(expr)
            
    def eval_exp(self, expr):
        expr = expr.replace('/', '//')
        expr = expr.replace('=', '==')
        try:
            return eval(expr, self.vars)
        except Exception:
            return 0
        
            
        
    def get_cur_line(self):
        return self.lines[self.line_num - 1]

    def run(self):
        while not self.end:
            line = self.get_cur_line()
            self.exec_command(line)
            self.line_num += 1

I(lines).run()

"""
4
x = 1
IF x > 2 THEN END
x = x + 1
GOTO 2
"""


"""
3
x = 2 + 3 * 3
PRINT x
END
"""


"""
6
x = 2
x = x * x
y = 3
x = x / y
PRINT x
END
"""

"""
6
p = 96
x = 1
IF x * x > p THEN END
IF p / x * x = p THEN PRINT x
x = x + 1
GOTO 3
"""

"""
4
x = 3
IF x < 2 THEN y = 2
IF x < 5 THEN PRINT x + y
END
"""
