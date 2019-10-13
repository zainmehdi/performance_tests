## performance_tests
Performs benchmarking tests on different configuration of python and C++ publisher/subscriber pair.
Test were performed on Ubuntu 18.04 ROS Melodic , Lenovo Legion Y540 Laptop with Intel® Core™ i7-9750H CPU @ 2.60GHz × 12 and 16GB RAM.

Launch files have been provided to start each pair.
There are two paramaters that control the testing phase:
- Loop Rate
- Epoch Interval (Interval after which we calculate frequency in subscriber node)
These two parameters can be adjusted in param.yaml file

# Cpp Publisher - Cpp Subscriber
There was no/minimal lag as such in terms of receiving messages at subscriber end. This node however is limited by the maximum 
loop rate it can achieve. 
- The maximum rate I could achieve was ~30000

[ INFO] [1570964818.429091960]: Measured Loop rate = 29847
[ INFO] [1570964819.429338610]: Measured Loop rate = 29930
[ INFO] [1570964820.428641837]: Measured Loop rate = 29712
[ INFO] [1570964821.428855677]: Measured Loop rate = 29896
[ INFO] [1570964822.429023938]: Measured Loop rate = 29950
[ INFO] [1570964823.429304461]: Measured Loop rate = 29563
[ INFO] [1570964824.428520047]: Measured Loop rate = 29745




