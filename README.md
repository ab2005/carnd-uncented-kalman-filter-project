
# Unscented Kalman Filter Project

Self-Driving Car Engineer Nanodegree Program
## Basic Build Instructions

- Clone this repo.
- Make a build directory: `mkdir build && cd build`
- Compile: `cmake .. && make`
    On windows, you may need to run: cmake .. -G "Unix Makefiles" && make
 - Run it: `./UnscentedKF path/to/input.txt path/to/output.txt`. You can find some sample inputs in `data/`.
    eg. ./UnscentedKF ../data/sample-laser-radar-measurement-data-1.txt output-1.txt


```bash
cd build && cmake .. && make
```
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /Users/ab/SDC/CarND-Unscented-Kalman-Filter-Project-master/build
    Scanning dependencies of target UnscentedKF
    [ 20%] Building CXX object CMakeFiles/UnscentedKF.dir/src/tools.cpp.o
    [ 40%] Linking CXX executable UnscentedKF
    [100%] Built target UnscentedKF


## Execution and Visualization


```python
import plotly.offline as py
from plotly.graph_objs import *
import pandas as pd
import math
py.init_notebook_mode()
my_cols=['p1est','p2est','vest','yawest','yawrateest','p1meas','p2meas','p1','p2','v1_gt','v2_gt', 'NIS']

def plot(table_ekf_output):
    #Ground Truth
    trace1 = Scatter(
        x=table_ekf_output['p1'],
        y=table_ekf_output['p2'],
        xaxis='x2',
        yaxis='y2',
        name = 'ground truth position',
        mode = 'markers'      
    )
    #estimations
    trace2 = Scatter(
        x=table_ekf_output['p1est'],
        y=table_ekf_output['p2est'],
        xaxis='x2',
        yaxis='y2',
        name='UKF position estimation',
        mode = 'markers'       
    )
    #Measurements
    trace3 = Scatter(
        x=table_ekf_output['p1meas'],
        y=table_ekf_output['p2meas'],
        xaxis='x2',
        yaxis='y2',
        name = 'position measurements',
        #mode = 'markers'
    )
    data = [trace1, trace2, trace3]
    layout = Layout(
        autosize=False,
        width=1000,
        height=1000,
        xaxis2=dict(
            anchor='x2',
            title='px in m'
        ),
        yaxis2=dict(
            anchor='y2',
            title='py in m'
        )
    )
    fig = Figure(data=data, layout=layout)
    py.iplot(fig, filename= 'EKF')
```

```bash
DIR=/Users/ab/SDC/CarND-Unscented-Kalman-Filter-Project-master/
$DIR/build/UnscentedKF $DIR/data/sample-laser-radar-measurement-data-1.txt $DIR/data/output-1.txt
```
`Accuracy - RMSE:
 0.076647
 0.0831234
 0.594126
 0.579288
`
![Image](./Unknown-1)
```python
plot(pd.read_table('data/output-1.txt', sep='\t', header=None, names=my_cols, lineterminator='\n'))
```

```bash
DIR=/Users/ab/SDC/CarND-Unscented-Kalman-Filter-Project-master/
$DIR/build/UnscentedKF $DIR/data/sample-laser-radar-measurement-data-2.txt $DIR/data/output-2.txt
```
`Accuracy - RMSE:
 0.196052
 0.189331
 0.436046
 0.523499
`
```python
plot(pd.read_table('data/output-2.txt', sep='\t', header=None, names=my_cols, lineterminator='\n'))
```
![Image](Unknown-2)
