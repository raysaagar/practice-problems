def sleep_in(weekday, vacation):
  if not weekday:
      return True
  elif vacation:
      return True
  else:
      return False

def monkey_trouble(a_smile, b_smile):
    if a_smile == b_smile:
        return True
    else:
        return False
		
def sum_double(a, b):
    if a == b:
       return (a+b)*2
    else:
       return a+b
	   
def diff21(n):
  if n > 21:
     return (n-21)*2
  else:
     return 21-n

def parrot_trouble(talking, hour):
   if (talking == True) and (hour < 7 or hour > 20):
       return True
   else:
       return False 

def makes10(a, b):
    if a == 10 or b == 10 or (a+b) == 10:
       return True
    return False
  
def near_hundred(n):
   if abs(n-100) <= 10 or abs(n-200) <= 10:
       return True
   return False
   
def pos_neg(a, b, negative):
    if negative:
        if a < 0 and b < 0:
            return True
        else:
            return False
    else:
        if a*b < 0:
            return True
        return False
		
def not_string(str):
    if str[0:3] != "not":
        return "not " + str
    return str
 
def missing_char(str, n):
    return str[0:n]+str[n+1:]

def front_back(str):
    if len(str) <= 1:
       return str
    return str[-1] + str[1:-1] + str[0]

def front3(str):
    if len(str) <= 3:
       return str*3
    return str[0:3]*3