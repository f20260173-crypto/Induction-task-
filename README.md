# Induction-task-
SEDS avionics induction task 1

# Ship Depth Data Analysis

## Overview

This project focuses on analysing ship depth data using Python. The data was provided in a CSV file and was processed to identify unusual sensor readings, clean the data, smooth the measurements, and visualize the ship's depth over time.

The project was completed by breaking the problem into several steps.

## Question 1: Importing the Required Libraries

I first imported the Python libraries required for the analysis.

- Pandas was used to read and process the CSV data.
- NumPy was used to handle missing values.
- Matplotlib was used to create graphs.
- FuncAnimation was used to create the animated graph.
- HTML was used to display the animation in Google Colab/Jupyter.

## Question 2: Reading and Inspecting the Data

The `Depth Data.csv` file was read using Pandas and stored in a DataFrame.

I then created a copy of the original data so that the original dataset would not be changed during the cleaning process.

The column names were also printed to check that the data had been imported correctly.

## Question 3: Cleaning the Depth Data

The depth values were converted into numerical values using `pd.to_numeric()`.

If a value could not be converted into a number, `errors="coerce"` changed it into `NaN`.

I then calculated the difference between consecutive depth readings using `.diff()`.

## Question 4: Detecting Suspicious Readings

I calculated the absolute change between consecutive readings.

A threshold of 25 metres was selected. If the depth changed by more than 25 metres between two consecutive readings, the reading was considered suspicious.

These suspicious readings were replaced with `NaN` so that they would not affect the final analysis.

## Question 5: Estimating Missing Values

After removing suspicious readings, some values became missing.

I used interpolation to estimate these missing values based on the surrounding valid measurements.

This allowed the dataset to remain continuous.

## Question 6: Smoothing the Data

To reduce small fluctuations in the sensor readings, I used a 5-point rolling average.

This produced a new column called `Smoothed Depth (m)`.

The smoothed values were used for the final graphs because they provide a clearer representation of the overall depth trend.

## Question 7: Creating the Time Data

The dataset contained a `Point` column rather than an actual time column.

I assumed that each point represented one second of data and therefore created a `Time (s)` column using:

`Time = Point - 1`

This made the first point correspond to 0 seconds.

## Question 8: Creating the Depth vs Time Graph

I created a graph using Matplotlib.

- The X-axis represents time in seconds.
- The Y-axis represents depth in metres.
- The smoothed depth values were plotted to make the graph easier to interpret.

A title and grid were also added to improve readability.

## Question 9: Creating the Animated Graph

Finally, I created an animated version of the Depth vs Time graph using `FuncAnimation`.

Instead of displaying all the data at once, the animation gradually adds the data points to the graph.

This simulates how depth information could be displayed as if it were being received from a live sensor.

## Conclusion

The overall approach was to first understand and clean the raw sensor data, identify and correct suspicious readings, smooth the data, and then visualize the results.

This process helped demonstrate how Python can be used to analyse and visualize real-world sensor data.
