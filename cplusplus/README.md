## Compiling

This program can be compiled (on OSX) using the following command:

```bash
clang++ -std=c++11 -stdlib=libc++ filename.cpp -o outputname
```

## Measuring code speed

```c++
  auto t1 = std::chrono::high_resolution_clock::now(); // create start time variable
  // run code 
  // ...
  auto t2 = std::chrono::high_resolution_clock::now(); // create end time variable
  auto delta_t = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count(); // calculate duration
```

Refer to [this thread](https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c) for more information.