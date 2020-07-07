# FireTimer
[![GitHub version](https://badge.fury.io/gh/PowerBroker2%2FFireTimer.svg)](https://badge.fury.io/gh/PowerBroker2%2FFireTimer) [![arduino-library-badge](https://www.ardu-badge.com/badge/FireTimer.svg?)](https://www.ardu-badge.com/FireTimer)<br /><br />
Simple and non-blocking Arduino library used to "fire-off" processes at specific intervals

# Example
```C++
#include "FireTimer.h"

FireTimer msTimer;
FireTimer usTimer;

void setup()
{
  Serial.begin(115200);

  msTimer.begin(1000);
  usTimer.begin(1000000, MICRO_SECONDS);
}

void loop()
{
  if(msTimer.fire())
    Serial.println("ms");

  if(usTimer.fire())
    Serial.println("us");
}
```

# Example Explanation
Include the library to use:
```c++
#include "FireTimer.h"
```

Instantiate 2 instances of the FireTimer class - one for keeping time with millis() and another for keeping time with micros():
```c++
FireTimer msTimer;
FireTimer usTimer;
```

Initialize the timers to both fire off at 1 second intervals without blocking. The first argument of "begin()" is the timeout and the second (optional) argument of "begin()" is the units of the timeout argument (ms or us):
```c++
msTimer.begin(1000);
usTimer.begin(1000000, MICRO_SECONDS);
```

Determine if enough time has elapsed (timeout) based on the return value of "fire()". The "fire()" method returns a bool - true if timeout has occurred and false if not. If a timeout has occurred, it will automatically reset the timer (this "resetting" can be overridden, however). Here, once the timout has occurred, we print "ms" or "us" depending on the timer:
```c++
if(msTimer.fire())
  Serial.println("ms");

if(usTimer.fire())
  Serial.println("us");
 ```
 
# Other
To check for a timeout without resetting the timer:
```c++
msTimer.fire(false) // Passing "false" prevents the timer from automatically resetting
```

To force a timer reset:
```c++
msTimer.start();
```

To update the timer's timeout value:
```c++
msTimer.update(100); // Save 100ms as the new timeout value and reset the timer
```
