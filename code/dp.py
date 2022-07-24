# dynamic programming

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

    r = n - 1
    if s[r] > sum:
        return is_subset_sum(s, n - 1, sum)

    return is_subset_sum(s, n - 1, sum) or \
           is_subset_sum(s, n - 1, sum - s[r])

if __name__ == '__main__':
    print("test is subset sum")
    s = [1, 2, 3, 4, 5]
    sum = 5
    for sum in [5, 9, 30]:
        if is_subset_sum(s, len(s), sum):
            print(s, "has a subset exists with given sum", sum)
        else:
            print(s, "has No subset exists with given sum", sum)
