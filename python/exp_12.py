import pandas as pd

# Step 2: Create a Pandas Series
print("Pandas Series Example:")
data_series = pd.Series([10, 20, 30, 40, 50], index=['a', 'b', 'c', 'd', 'e'])
print("Series:\n", data_series)

# Accessing elements in the series
print("\nAccessing Element with Label 'c':", data_series['c'])
print("Accessing Element by Position 3:", data_series[3])

# Performing operations on the series
print("\nSeries multiplied by 2:\n", data_series * 2)
print("Sum of the series:", data_series.sum())

# Step 4: Create a Pandas DataFrame
print("\nPandas DataFrame Example:")
data = {'Name': ['John', 'Anna', 'Peter', 'Linda'],
        'Age': [28, 24, 35, 32],
        'Department': ['HR', 'Finance', 'Marketing', 'IT']}
data_frame = pd.DataFrame(data)
print("DataFrame:\n", data_frame)

# Accessing columns and rows
print("\nAccessing 'Name' column:\n", data_frame['Name'])
print("Accessing first row using .loc[]:\n", data_frame.loc[0])

# Basic DataFrame operations
print("\nSorting DataFrame by Age:\n", data_frame.sort_values(by='Age'))
print("Mean Age of employees:", data_frame['Age'].mean())

# Adding a new column
data_frame['Salary'] = [50000, 60000, 55000, 62000]
print("\nDataFrame with new 'Salary' column:\n", data_frame)

# Step 7: Display the Results
print("\nFinal DataFrame after modifications:\n", data_frame)
