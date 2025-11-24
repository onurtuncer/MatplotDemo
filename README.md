# MatplotDemo

A small C++ demo application showing how to use the [matplot++](https://github.com/alandefreitas/matplotplusplus) plotting library from a CMake-based project.

The demo application generates a simple plot using the gnuplot backend of matplot++.

---

## Features

- Minimal, readable example of integrating **matplot++** into a CMake project  
- Uses the gnuplot backend to render plots  
- Ready to build on Linux, macOS and Windows (with a few notes for gnuplot on Windows)

---

---

## Example Output

Below is the sample figure you should see, if you succesfully build and run the demo application:

<p align="center">
  <img src="assets/orbit.png" width="500" alt="Orbit Figure">
</p>

---

## Prerequisites

### Common

- C++ compiler with at least C++17 support  
  - Linux: GCC or Clang  
  - macOS: Apple Clang  
  - Windows: MSVC (Visual Studio)  
- [CMake](https://cmake.org/) ≥ 3.26 
- [gnuplot](http://www.gnuplot.info/) installed and available on your `PATH`  
- matplot++ library (this repository is configured to use it via FetchContent directive; 
please `CMakeLists.txt` for details)

### Important: gnuplot on Windows

On Windows:

- **You must use gnuplot 5.x.**  
  gnuplot **6.0 is not supported** with this demo and will not work correctly.
- The `gnuplot.exe` binary **must be on the `PATH`** so that matplot++ can invoke it.  
  - Example: if you installed gnuplot to  
    `C:\Program Files\gnuplot\bin`,  
    then add that directory to your system or user `PATH`.

You can verify this in a fresh terminal / Developer Command Prompt:

```powershell
gnuplot --version

## Windows Build Using Visual Studio

1. Open **Visual Studio**
2. Click **Open Folder…**
3. Select the **MatplotDemo** directory
4. Let Visual Studio configure CMake automatically
5. Choose a configuration (e.g., **x64-Debug** or **x64-Release**)
6. Build the **MatplotDemo** target
7. Run the executable

### If the plot window doesn’t appear

- Restart Visual Studio after modifying your `PATH`
- Ensure **gnuplot 5.x** is the active version on your system

