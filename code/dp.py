# dynamic programming

# subset sum
# Given a set of non-negative integers, and a value sum, determine if there is
# a subset of the given set with sum equal to the given sum.
#
# Recursion:
# divide into two sub-problems and combine, 
# one subset that still contains the last element and another subset that 
# doesn't contain the last element.
# isSubsetSum(set, n, sum) = isSubSetSum(set, n-1, sum) ||
#                            isSubsetSum(set, n-1, sum-set[n-1])
#
def is_subset_sum(s, n, sum):
    if sum == 0:
        return True
    if n == 0:
        return False

    '''
    if s[n - 1] > sum:
        return is_subset_sum(s, n - 1, sum)
    '''

    # check two possible cases
    # one including the last element
    # one excluding the last element
    return is_subset_sum(s, n - 1, sum) or \
           is_subset_sum(s, n - 1, sum - s[n - 1])

def is_subset_sum_self(s, n, sum):
    if sum == 0:
        return True
    if n == 0:
        return False
    if is_subset_sum_self(s, n - 1, sum):
        return True;
    elif is_subset_sum_self(s, n - 1, sum - s[n - 1]):
        return True;
    else:
        return False


# 0-1 Knapsack problem
# Given the values and weights of n items, put these items in a knapsack of 
# weight capacity W to get the maximum value in the knapsack
# KValue(W, w, v, n) = max(KValue(W, w, v, w, n-1), KValue(W-w[n], w, v, n-1) + v[n])
#
def knapsack_weight_max_value(W, w, v, n):
    if W <= 0 or n == 0:
        return 0

    if w[n - 1] > W:
        # if the last item weight is more than given weight W,
        # then it can not be included in the optimal solution
        return knapsack_weight_max_value(W, w, v, n - 1)

    return max(knapsack_weight_max_value(W, w, v, n - 1), \
               knapsack_weight_max_value(W - w[n - 1], w, v, n - 1) + \
               v[n - 1])

# 0-1 Knapback problem through dynamic programming bottom up with array
# the computed max value of subproblems are saved in array K for later lookup.
#
def knapsack_weight_max_value_dp(W, w, v, n):
    # create an array K with
    # row index: number of items
    # column index: weight capacity
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]

    # build table K in bottom up manner to record max value of needed subproblems
    for i in range(n + 1):
        for j in range(W + 1):
            if i == 0 or j == 0:
                K[i][j] = 0
            elif w[i - 1] <= j:
                K[i][j] = max(v[i-1] + K[i-1][j-w[i-1]], K[i-1][j])
            else:
                K[i][j] = K[i - 1][j]
    return K[n][W]


if __name__ == '__main__':
    print("test is_subset_sum ...")
    s = [1, 2, 3, 4, 5]
    sum = 5
    for sum in [5, 9, 30]:
        if is_subset_sum(s, len(s), sum):
            print(s, "has a subset exists with given sum", sum)
        else:
            print(s, "has No subset exists with given sum", sum)
    print("test is_subset_sum_self")
    for sum in [5, 9, 30]:
        if is_subset_sum_self(s, len(s), sum):
            print(s, "has a subset exists with given sum", sum)
        else:
            print(s, "has No subset exists with given sum", sum)

    print("")
    print("test 0-1 knapsack_weight_max_value ...")
    v = [100, 200, 300, 400, 500]
    w = [10, 20, 30, 40, 50]
    W = 80
    print("weights:", w)
    print("values:", v)
    mv = knapsack_weight_max_value(W, w, v, len(v))
    print("max value is", mv, "for weight", W, "through recursion")
    mv = knapsack_weight_max_value_dp(W, w, v, len(v))
    print("max value is", mv, "for weight", W, "through dp bottom up")
