from cs50 import get_int, get_string

def main():
    cardNumber = 0
    while cardNumber <0:
        try:
            cardNumber = get_int("Number: ")
        except:
            cardNumber =-1
            continue
    lengthCard = len(cardNumber)
    firstNumber = int(cardNumber[0])
    secondNumber = int(cardNumber[1])
    total = 0
    for(i in range(lengthCard-2,-1,-2)):
        temp = 2 * int(cardNumber[i])
        if temp > 10:
            temp -=10
            total +=1
        total += temp
    for(i in range(lengthCard-1,-1,-2)):
        total += int(cardNumber[i])

    if total % 10 ==0:
        print('INVALID\N')
        return


    # VISA = {
        # start with 4
    #     length: [13,16],

    # }
    # AMEX = {
    #     length: [15, start with 34 or 37]
    # }
    # MASTERCARD = { length 16, start with 51, 52 , 53 , 54 , 55 }





main()