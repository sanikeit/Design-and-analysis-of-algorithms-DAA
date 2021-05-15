from functools import reduce


def partition(weights, values, start, end):
    x = values[end] / weights[end]
    i = start
    for j in range(start, end):
        if values[j] / weights[j] < x:
            values[i], values[j] = values[j], values[i]
            weights[i], weights[j] = weights[j], weights[i]
            i += 1

    values[i], values[end] = values[end], values[i]
    weights[i], weights[end] = weights[end], weights[i]

    return i


def _find_kth(weights, values, start, end, k):
    ind = partition(weights, values, start, end)
    if ind - start == k - 1:
        return ind
    if ind - start > k - 1:
        return _find_kth(weights, values, start, ind - 1, k)
    return _find_kth(weights, values, ind + 1, end, k - ind - 1)


def find_kth(weights, values, k):
    return _find_kth(weights, values, 0, len(weights) - 1, k)


def fractional_knapsack(weights, values, w):
    if w == 0 or len(weights) == 0:
        return 0

    if len(weights) == 1 and weights[0] > w:
        return w * (values[0] / weights[0])

    mid = find_kth(weights, values, len(weights) / 2)

    w1 = reduce(lambda x, y: x + y, weights[mid + 1:])
    v1 = reduce(lambda x, y: x + y, values[mid + 1:])

    if w1 > w:
        return fractional_knapsack(weights[mid + 1:], values[mid + 1:], w)

    return v1 + fractional_knapsack(weights[:mid + 1], values[:mid + 1], w - w1)


if __name__ == "__main__":
    print(fractional_knapsack([10., 1.], [1., 10.], 5.))
