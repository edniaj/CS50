from cs50 import get_int, get_string

def main():
    cardNumber = -1
    while int(cardNumber) <0:
        try:
            cardNumber = get_string("Number: ")
            if not cardNumber.isnumeric():
                raise ValueError
        except:
            cardNumber =-1
            continue
    lengthCard = len(cardNumber)
    firstNumber = int(cardNumber[0])
    secondNumber = int(cardNumber[1])
    total = 0
    for i in range(lengthCard-2,-1,-2) :
        temp = 2 * int(cardNumber[i])
        if temp > 10:
            temp -=10
            total +=1
        total += temp
    for i in range(lengthCard-1,-1,-2) :
        total += int(cardNumber[i])

    if total % 10 !=0:
        print('INVALID\n')
        return

    if (len(cardNumber) in [13,16]) and cardNumber[0] == '4':
        print('VISA\n')
    if (len(cardNumber) == 15) and cardNumber[0] in ['34','37']:
        print('AMEX\n')
    if (len(cardNumber) == 16) and cardNumber[0] in ['51','52','53','54','55']:
        print('MASTERCARD\n')
    # VISA = {
        # start with 4
    #     length: [13,16],

    # }
    # AMEX = {
    #     length: [15, start with 34 or 37]
    # }
    # MASTERCARD = { length 16, start with 51, 52 , 53 , 54 , 55 }





main()