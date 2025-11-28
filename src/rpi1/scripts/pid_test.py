import pandas as pd
import matplotlib.pyplot as plt
import os

# Path to your CSV file relative to the script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
csv_file = os.path.join(SCRIPT_DIR, "pid_test.csv")

# Load CSV
try:
    df = pd.read_csv(csv_file)
except FileNotFoundError:
    print(f"CSV file '{csv_file}' not found!")
    exit(1)

# Check the first few rows
print(df.head())

# Plot motor position over time
plt.figure(figsize=(10, 6))
plt.plot(df['time'], df['pos'], label='Position', color='blue')
plt.plot(df['time'], df['ctrl'], label='Control Output', color='green')
plt.plot(df['time'], df['pwm'], label='PWM', color='red')
plt.xlabel('Time [s]')
plt.ylabel('Value')
plt.title('PID Test Results')
plt.legend()
plt.grid(True)
plt.tight_layout()

# Save the plot as PNG
output_path = os.path.join(SCRIPT_DIR, "pid_plot.png")
plt.savefig(output_path, dpi=300)
print(f"Saved plot to: {output_path}")

# Optional: comment out if no display is available
# plt.show()
