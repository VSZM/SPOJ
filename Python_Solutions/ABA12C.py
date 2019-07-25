from typing import List

"""

module_name, package_name, ClassName, method_name, ExceptionName, function_name, GLOBAL_CONSTANT_NAME, global_var_name, instance_var_name, function_parameter_name, local_var_name

"""


MAX_PRICE = 1000

def calculate_min_price(N_friends: int, K_kilograms: int, prices: List[int], depth: int = 0) -> int:
    if K_kilograms == 0:
        return 0

    if depth == N_friends:
        return MAX_PRICE + 1

    until = min(len(prices), K_kilograms) + 1
    mins = [MAX_PRICE + 1]

    for i in [i for i in range(until) if prices[i] >= 0]:
        mins.append(prices[i] + calculate_min_price(N_friends, K_kilograms - i, prices, depth + 1))

    return min(mins)



if __name__ == "__main__":
    case_count = int(input())

    for _ in range(case_count):
        nk = input().split()
        n = int(nk[0])
        k = int(nk[1])
        prices = [int(number) for number in input().split()]
        prices.insert(0, -1)

        result = calculate_min_price(n, k, prices)
        if result > MAX_PRICE:
            print(-1)
        else:
            print(result)

