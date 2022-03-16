from cs50 import get_int


def main():
    height = get_int('Height: \n')
    while(height < 1 or height > 8):
        height = get_int('Height: \n')
    for i in range(height):
        gap = ' ' * (height - 1 - i)
        tower = '#' * (i+1)
        print(f'{gap}{tower}  {tower}')

main()

