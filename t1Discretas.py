# Por favor complete con su nombre y RUT.
# NOMBRE Y APELLIDO: FRANCO ZAUTZIK
# RUT: 19.688.413-0

# Run the file as "python SAT.py -v"

# Add further needed modules
import unittest

# To implement the functions below, you are allowed
# to define auxiliary functions, if convenient.


def SetLiteral(formula, lit):
    # Define your function here
    i = 0
    j = 0
    while i < len(formula):
        while j <= len(formula[i]):
            if formula == [[]]:
                return formula
            if formula[i] == []:
                i += 1
                j = 0
                break
            else:
                if formula[i][j] == lit:
                    formula.pop(i)
                    j = 0
                    break
                if formula[i][j] == (-lit):
                    formula[i].pop(j)
                    j = 0
                    break
                if j == len(formula[i]) - 1:
                    if i == len(formula) - 1:
                        return formula
                    else:
                        i += 1
                        j = 0
                        break
                else:
                    j += 1
    return formula

def IsSatisfiable(formula):
    # Define your function here
    for i in range(0, len(formula)):
        if formula[i] == []:
            return False
    if formula == []:
        return True
    else:
        return IsSatisfiable(SetLiteral(formula, formula[0][0]))

def LiteralSetting(formula, setting):
    # Define your function here
    f = formula[:]
    if not IsSatisfiable(f):
        return {}
    if formula == []:
        return setting
    else:
        if formula[0][0] > 0:
            setting[formula[0][0]] = True
        else:
            setting[-formula[0][0]] = False
        return LiteralSetting(SetLiteral(formula, formula[0][0]), setting)

def BuildModel(formula):
    # Define your function here
    f = formula[:]
    s = (IsSatisfiable(f))
    r = (s, LiteralSetting(formula, {}))
    return r

class Tests(unittest.TestCase):
    def setUp(self):
        pass

    def test_SetLiteral(self):
        self.assertEqual(SetLiteral([[1, 2, -3], [-1, -2, 4], [3, 4]], 1), [[-2, 4], [3, 4]])
        self.assertEqual(SetLiteral([[1, 2, -3], [-1, -2, 4], [3, 4]], -1), [[2, -3], [3, 4]])

    def test_IsSatisfiable(self):
        self.assertEqual(IsSatisfiable([[1, 2, -3], [-1, -2, 4], [3, 4]]), True)
        self.assertEqual(IsSatisfiable([[1, 2], [1, -2], [], [-1]]), False)
        self.assertEqual(IsSatisfiable([]), True)

    def test_BuildModel(self):
        self.assertEqual(BuildModel([[-2, 4], [1], [-4,-1]]), (True, {1: True, 2: False, 4: False}))
        self.assertEqual(BuildModel([[1,2], [-1,-2], [-1,2], [1,-2]]), (False, {}))

# Perform the tests when running the file
if __name__ == '__main__':
    unittest.main()
