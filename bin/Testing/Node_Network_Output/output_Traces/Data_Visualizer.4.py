import os
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.colors import LinearSegmentedColormap

# Function to read .ssv files and return a list of lists
def read_ssv_files(directory):
    data = []
    for filename in os.listdir(directory):
        if filename.endswith('.ssv'):
            with open(os.path.join(directory, filename), 'r') as file:
                for line in file:
                    row = list(map(float, line.strip().split()))
                    data.append(row)
    return data

# Read data from .ssv files
directory = '.'  # current directory
data = read_ssv_files(directory)

# Step 1: Preprocess the Data
# Find the maximum row length (excluding the first index)
max_length = max(len(row) - 1 for row in data)

# Initialize a list for padded rows
padded_data = []

# Pad the rows with NaNs
for row in data:
    # Exclude the first index, which is the row number
    values = row[1:]
    # Pad the row with NaNs to make all rows the same length
    padded_row = values + [np.nan] * (max_length - len(values))
    padded_data.append(padded_row)

# Convert the list of lists to a NumPy array
padded_data = np.array(padded_data, dtype=float)

# Define a custom colormap
colors = [(0, "black"), (0.25, "cyan"), (0.5, "purple"), (0.75, "magenta"), (1.0, "lime")]  # Replace with your custom colors
custom_colormap = LinearSegmentedColormap.from_list("custom_colormap", colors)

# Step 2: Generate the 2D Heatmap
fig, ax = plt.subplots()

# Mask NaN values
masked_data = np.ma.masked_invalid(padded_data)

# Create the heatmap with the custom colormap
cax = ax.imshow(masked_data, cmap=custom_colormap, aspect='auto')

# Add color bar to indicate the scale
cbar = fig.colorbar(cax, ax=ax, shrink=0.5, aspect=5)

# Set labels
ax.set_xlabel('Column Index')
ax.set_ylabel('Row Index')

plt.show()
