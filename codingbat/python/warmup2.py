def string_times(str, n):
    return str*n
	
def front_times(str, n):
    if len(str) <= 3:
        return str*n
    return str[0:3]*n

def string_bits(str):
    return str[0::2]
	
def string_splosion(str):
    tmp = ""
    for i in range(0,len(str)+1):
        tmp += str[0:i]
    return tmp

def last2(str):
    if len(str) < 2:
        return 0
    substr = str[-2:]
    count = 0
    for i in range(0,len(str)-2):
        if str[i:i+2] == substr:
            count+=1
    return count	
	
def array_count9(nums):
    count = 0
    for i in nums:
        if i == 9:
            count+=1
    return count
	
def array_front9(nums):
    count = 0
    for i in nums:
        if count > 3:
            return False
        if i == 9:
            return True
        count+=1
    return False

def array123(nums):
    if len(nums) < 3:
        return False
    for i in range(0,len(nums)-2):
        if nums[i:i+3] == [1,2,3]:
            return True
    return False
 
def string_match(a, b):
    if len(a) <= 1 or len(b) <= 1:
        return 0
    max = min(len(a),len(b))
    count = 0
    for i in range(0,max-1):
        if a[i:i+2] == b[i:i+2]:
            count+=1
    return count