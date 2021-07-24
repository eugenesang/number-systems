# https://github.com/eugenesang/number-systems
string="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
max_width=len(string)
def listify(number, form):
    array=[]
    if number==0:
        array.append(number)
    while number>0:
        array.append(number%form)
        number //= form
    array.reverse()
    return array


def to_our_system(num, our_digits):
    new_list=listify(num, len(our_digits))
    answer=""
    for digit in new_list:
        answer+=our_digits[digit]
    return answer

def to_decimal(alien_num, alien_string):
    our_array=[]
    for n in alien_num:
        our_array.append(alien_string.index(n))
    our_array.reverse()
    decimal=0
    for i in range(0, len(our_array)):
        decimal+= our_array[i]*len(alien_string)**i 
    return decimal

tester = to_our_system(7656098, string)
print(to_decimal(tester, string))
