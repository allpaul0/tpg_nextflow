import numpy as np
import matplotlib.pyplot as plt

# Generate sample data (X and Y coordinates)
np.random.seed(42)
n_points = 100

# Generate random points
X = np.random.uniform(0, 10, n_points)
Y = np.random.uniform(0, 10, n_points)

# Add some points that form a clear Pareto front
X = np.append(X, np.linspace(1, 9, 20))
Y = np.append(Y, 10 - np.linspace(1, 9, 20)**0.7)

def is_pareto_efficient(costs):
    """
    Find the Pareto-efficient points (minimizing both objectives)
    """
    is_efficient = np.ones(costs.shape[0], dtype=bool)
    for i, c in enumerate(costs):
        if is_efficient[i]:
            # Remove dominated points (those worse in both dimensions)
            is_efficient[is_efficient] = np.any(costs[is_efficient] < c, axis=1)
            is_efficient[i] = True
    return is_efficient

# Combine X and Y into a cost matrix
costs = np.column_stack((X, Y))

# Find Pareto-efficient points
pareto_mask = is_pareto_efficient(costs)
pareto_X = X[pareto_mask]
pareto_Y = Y[pareto_mask]

# Sort Pareto points for proper line plotting
sort_idx = np.argsort(pareto_X)
pareto_X_sorted = pareto_X[sort_idx]
pareto_Y_sorted = pareto_Y[sort_idx]

# Create the plot
plt.figure(figsize=(10, 7))

# Plot all points
plt.scatter(X[~pareto_mask], Y[~pareto_mask], c='lightblue', 
            alpha=0.6, s=50, label='Dominated solutions', zorder=1)

# Plot Pareto front points
plt.scatter(pareto_X, pareto_Y, c='red', s=100, 
            label='Pareto front', zorder=3, edgecolors='darkred', linewidth=1.5)

# Connect Pareto front points with a line
plt.plot(pareto_X_sorted, pareto_Y_sorted, 'r--', 
         linewidth=2, alpha=0.7, zorder=2)

# Styling
plt.xlabel('Objective 1 (X)', fontsize=12, fontweight='bold')
plt.ylabel('Objective 2 (Y)', fontsize=12, fontweight='bold')
plt.title('Pareto Front Visualization', fontsize=14, fontweight='bold')
plt.legend(fontsize=11, loc='upper right')
plt.grid(True, alpha=0.3, linestyle='--')
plt.tight_layout()

# Add arrow annotations to show the improvement direction
plt.annotate('', xy=(1, 1), xytext=(3, 3),
            arrowprops=dict(arrowstyle='->', lw=2, color='green', alpha=0.6))
plt.text(2.5, 2.5, 'Better', fontsize=10, color='green', 
         fontweight='bold', ha='center')

plt.show()

# Print statistics
print(f"Total points: {len(X)}")
print(f"Pareto-efficient points: {np.sum(pareto_mask)}")
print(f"Percentage on Pareto front: {100 * np.sum(pareto_mask) / len(X):.1f}%")