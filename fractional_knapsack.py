# Define a class to represent an item in the knapsack
class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight
        # Calculate the value per unit weight for each item
        self.ratio = value / weight

def fractional_knapsack(items, capacity):
    # Sort items by value-to-weight ratio in descending order
    items.sort(key=lambda x: x.ratio, reverse=True)
    
    total_value = 0.0  # Maximum total value that can be carried
    for item in items:
        # If the item can fit completely, take it
        if capacity >= item.weight:
            capacity -= item.weight
            total_value += item.value
        else:
            # If the item can't fit completely, take the fraction that fits
            total_value += item.ratio * capacity
            break  # Knapsack is full

    return total_value

# Example usage
items = [Item(60, 10), Item(100, 20), Item(120, 30)]
capacity = 50

# Calculate the maximum value for the given capacity
max_value = fractional_knapsack(items, capacity)
print(f"Maximum value in knapsack: {max_value}")
