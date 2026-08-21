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

## Question 2: Reading the data

The `Depth Data.csv` file was read using Pandas and stored in a variable.and also changed the data type of depth tonumeric from string

## Question 3: Cleaning the Depth Data

I made a copy of the data to remove suspicious readings and clear the noise.and added a column of difference in depth values to the data

## Question 4: Detecting Suspicious Readings

I calculated the absolute change between consecutive readings.and set a threshold of 25 meters above which a reading is considered as suspicious reading.and then delegating depth data from these points.
## Question 5: Estimating Missing Values

After removing suspicious readings, some values became missing.
then I uses interpolation to fill the missing values using the data of surrounding points

## Question 6: Smoothing the Data

To reduce small fluctuations in the sensor readings, I used a 5-point rolling average.
This produced a new column called `Smoothed Depth (m)`.
then used these values to plot the graph
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


## Question 9: Creating the Animated Graph

Finally, I created an animated version of the Depth vs Time graph using `FuncAnimation`.

Instead of displaying all the data at once, the animation gradually adds the data points to the graph.

This simulates how depth information could be displayed as if it were being received from a live sensor.

## Conclusion

The overall approach was to first understand and clean the raw sensor data, identify and correct suspicious readings, smooth the data, and then visualize the results.

# SEDS Avionics – Task 2
## Keeping Watch Over Odysseus

## Overview

Task 2 involves building an onboard monitoring system for Odysseus using Arduino and multiple sensors and output devices.
The system monitors the surroundings of the ship and uses a state machine to represent different situations such as normal sailing, an anchor being dropped, a storm, Charybdis, and the ship being wrecked.

## Question 1 – Build the System

### Approach

I built the monitoring system in Tinkercad using:

- Arduino
- Ultrasonic distance sensor
- Light sensor
- LCD screen
- Push button
- LED
- Buzzer

I connected each component to the Arduino and used the appropriate pins for the sensors, LCD, button, LED, and buzzer.

The LCD is used to display the current state of the ship.that is if the ship is sailing in open sea or wrecked or in a storm,anchored ,near Charybdis 

A push button is used to control the anchor of the ship

---

## Question 2 – Program the System

### Approach


The system contains the following states:

- OPEN SEA
- ANCHORED
- STORM
- CHARYBDIS
- WRECKED

### LCD
Used the last two pins of the ardunio in analog pins which are used for standard analog communication.
The current state is displayed on the LCD.

### ANCHOR

I used the signal received from the push button to determine if the anchor is dropped or not.
used the input in the constrains of the blocks.
### OPEN SEA
This is the normal mode of the ship.
the constrains of this block contain the data of the anchor and the time in storm and Charybdis.
this runs only when time in storm and Charybdis is less than 5 sec and when the ship is not anchored


### STORM

The storm state is triggered when the light sensor reading falls below half of the maximum(which is 511 of max 1023)
I used the analog pin to take the sensor values.
even added I led to blink when the ship was in storm.
And also added a variable which counted the time in storm 
### CHARYBDIS

The CHARYBDIS state is triggered when the ultrasonic sensor detects an object closer than 100 cm.
Also connected a buzzer to make sound when the ship is near Charybdis.


### WRECKED

If the ship continuously remains in either STORM or CHARYBDIS for five seconds, it enters the WRECKED state.

Dropping the anchor before the five seconds are completed prevents the ship from becoming wrecked and resets the timer.

Once the ship enters WRECKED, it remains there until the simulation is restarted.

### Simultaneous Dangers

If STORM and CHARYBDIS are triggered at the same time, the state that is entered first remains active and its five-second timer continues.

---

## Sensor Thresholds

The system uses the thresholds specified in the task:

- Storm: light sensor reading below half 
- Charybdis: distance below 100cm
