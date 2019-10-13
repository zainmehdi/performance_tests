# Performance_tests
Performs benchmarking tests on different configuration of python and C++ publisher/subscriber pair.
Test were performed on Ubuntu 18.04 ROS Melodic , Lenovo Legion Y540 Laptop with Intel® Core™ i7-9750H CPU @ 2.60GHz × 12 and 16GB RAM.

Launch files have been provided to start each pair.
There are two paramaters that control the testing phase:
- Loop Rate
- Epoch Interval (Interval after which we calculate frequency in subscriber node)
These two parameters can be adjusted in params.yaml file

### Cpp Publisher - Cpp Subscriber
There was no/minimal lag as such in terms of receiving messages at subscriber end. This node however is limited by the maximum 
loop rate it can achieve. 
- The maximum rate I could achieve was ~30000


### Cpp Publisher - Python Subscriber

- The maximum rate I could achieve was ~30000

### Python Publisher - Cpp Subscriber
Subscriber in this case was not as much limites as the the publisher.
- The maximum rate I could achieve was ~18000

### Python Publisher - Cpp Subscriber
- The maximum rate I could achieve was ~18500

## Launching the nodes

```
roslaunch performance_test cpp-to-cpp.launch
roslaunch performance_test cpp-to-pyt.launch
roslaunch performance_test pyt-to-cpp.launch
roslaunch performance_test pyt-to-pyt.launch
```





