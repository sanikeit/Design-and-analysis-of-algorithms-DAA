""" 1) Firstly, define class item. """


class Item:
    def __init__(self, wt, val, ind):
        self.wt = wt
        self.val = val
        self.ind = ind
        self.cost = val // wt

    def __lt__(self, other):
        return self.cost < other.cost


""" Initialize weight and value """


def kanpsack(weight, value, capacity):
    items = []
    for i in range(len(weight)):
        items.append(Item(weight[i], value[i], i))

    """Sort by cost with descending order."""

    items.sort(reverse=True)

    ans = 0
    for i in items:
        w = int(i.wt)
        v = int(i.val)
        if capacity >= w:
            capacity -= w
            ans += v
        else:
            cost = int(i.cost)
            ans += cost * capacity
            capacity = 0
            break

    return ans


"""Python3 code to run the above program"""

if __name__ == "__main__":
    capacity = int(input())
    weight = list(map(int, input().split()))
    value = list(map(int, input().split()))

    print(kanpsack(weight, value, capacity))
