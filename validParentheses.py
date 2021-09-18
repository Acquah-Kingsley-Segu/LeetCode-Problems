#List to act as stack to hold the opening brackets
stack = []

#string holding the set of parentheses
string = '()[]{}'
#validity check
validState = False

for char in string:
    if char in '[({':
        stack.append(char)
    elif char in '])}':
        if len(stack) == 0:
            validState = False
            break
        else:
            parentheses = stack.pop()
                    
            if (char == ']' and parentheses == '[') or (char == ')' and parentheses == '(') or (char == '}' and parentheses == '{'):
                validState = True
            elif validState:
                validState = False
                break
            else:
                break



if len(stack) != 0 and validState:
    validState = False

print(validState)
            
        

