if __name__ == '__main__':
    cases=int(input())
    case_number=1
    for i in range(cases):
        print("Case #", end='')
        print(case_number,end=': ')
        print(" ".join(input().split(" ")[::-1]))
        case_number += 1
    