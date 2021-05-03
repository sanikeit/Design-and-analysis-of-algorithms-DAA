# 0-1 knapsack algorithm using branch and bound

data_weight = [20, 40, 60, 100, 120, 10, 50]
data_value = [100, 80, 120, 150, 200, 40, 180]
capacity = 200

values = []

for i in range(len(data_value)):
    cost = data_value[i] // data_weight[i]
    values.append([cost, data_value[i], data_weight[i]])

values.sort(reverse=True)


data_cost = [i[0] for i in values]
data_weight = [i[2] for i in values]
data_value = [i[1] for i in values]


class State(object):
    def __init__(self, level, benefit, weight, token):

        self.level = level
        self.benefit = benefit
        self.weight = weight
        self.token = token
        self.available = self.token[:self.level] + [1] * (len(data_value) - level)
        self.ub = self.upperbound()

    def upperbound(self):
        upperbound = 0
        weight_accumulate = 0
        for i in range(len(data_weight)):
            if data_weight[i] * self.available[i] <= capacity - weight_accumulate:
                weight_accumulate += data_weight[i] * self.available[i]
                upperbound += data_value[i] * self.available[i]
            else:
                upperbound += data_value[i] * (capacity - weight_accumulate) / data_weight[i] * self.available[i]       # Anikeit Sethi
                break
        return upperbound

    def develop(self):
        level = self.level + 1
        if self.weight + data_weight[self.level] <= capacity:
            left_weight = self.weight + data_weight[self.level]
            left_benefit = self.benefit + data_value[self.level]
            left_token = self.token[:self.level] + [1] + self.token[self.level + 1:]
            left_child = State(level, left_benefit, left_weight, left_token)
        else:
            left_child = None

        right_child = State(level, self.benefit, self.weight, self.token)
        if left_child is not None:
            return [left_child, right_child]
        else:
            return [right_child]


Root = State(0, 0, 0, [0] * len(data_value))
waiting_States = []
current_state = Root
while current_state.level < len(data_value):
    waiting_States.extend(current_state.develop())
    waiting_States.sort(key=lambda x: x.ub)
    current_state = waiting_States.pop()
best_solution = current_state

print("Value :", data_value)
print("Weight :", data_weight)
print("Capacity :", capacity)

print("Total Max Value: ", best_solution.benefit)
