# Opencv-projects


# Title

My projects in master degree semester 1， including my learning and debugging processes. 


## Installation
- All the `code` required to get started

### Clone

- Clone this repo to your local machine using `https://github.com/LiuSirui99/Opencv-projects.git`

### Setup
- **For MacOS:**

     I am using MacOS Catalina version 10.15.6.
     
    -**Opencv-python**:
    
    For setting up the opencv-python running env I am using pycharm as the editor. 
        Just go to the terminal with the command: 
        `$ pip3 install opencv-python`
    
    For testing your settings, clone the Translation.py in testopencv folder, choose your image and press run. You should see an new window which displays the result of translation of your image.
        
   -**Opencv-c++**:
   
   1. Install Xcode
   
   2. Install Homebrew
   
   3. Install OpenCV
   
        `$ brew install opencv`
        in case you already have opencv installed, run
        `$ brew upgrade opencv`
        for ensure the latest version.
    4. Install pkg-config
    
        pkg-config is a helper tool used when compiling applications and libraries. It helps you insert the correct compiler options on the command line rather than hard-coding values. 
        `$ brew install pkg-config`
        
    5. View OpenCV linker flags
    ` $ pkg-config --cflags --libs /usr/local/Cellar/opencv/4.3.0_5/lib/pkgconfig/opencv4.pc`
    6. Test your env 
        Git clone one of my xcode projects and then modify the path of include hearder and library as it installed in your machine.
        
        - Run in xcode:
        1. Set the Header Search Path 
        `/usr/local/Cellar/opencv/<version_number>/include`
        2. Set the Library Search Path
        `/usr/local/Cellar/opencv/<version_number>/lib`
        3. Set the Other Linker Flags
        Set the other linker flags with all the flag values obtained after running pkg-config command above.
        4. Press Cmd+R to run your Xcode project.
        
        - Run from terminal :
        `g++ $(pkg-config --cflags --libs /usr/local/Cellar/opencv/4.3.0_5/lib/pkgconfig/opencv4.pc) -std=c++11  main.cpp -o myoutput`

- **For Ubuntu:**

    **Installation**.
    
    Install the opencv release from official website: <a href="https://opencv.org/releases/" target="_blank">`https://opencv.org/releases/`</a>.

    Extract the directory and apply
    ```
    $ cd ~/opencv
    $ mkdir build
    $ cd build
    ```

    **Configuring**. 
    
    Run cmake [<some optional parameters>] <path to the OpenCV source directory>

    For example
    ```
    $ cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
    ```

    build type: `CMAKE_BUILD_TYPE=Release\Debug`
    to build with modules from opencv_contrib set OPENCV_EXTRA_MODULES_PATH to <path to opencv_contrib/modules/>
    
    set BUILD_DOCS for building documents
    
    set BUILD_EXAMPLES to build all examples

    **Build**. 
    
    From build directory execute make, it is recommended to do this in several threads

    For example
    ```
    $ make -j7 # runs 7 jobs in parallel
    ```

    **Library**.
    
    To install libraries, execute the following command from build directory
    ```
    $ sudo make install
    ```
    
    **Install the dependencies**: 
    ```
    $ sudo apt-get install build-essential libgtk2.0-dev libvtk5-dev libjpeg-dev libtiff4-dev libjasper-dev libopenexr-dev libtbb-dev
    $ [compiler] sudo apt-get install build-essential
    $ [required] sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
    ```

    **Testing**.
    
    For testing your settings, clone the repo <a href="https://github.com/opencv/opencv_extra" target="_blank">`https://github.com/opencv/opencv_extra`</a>.

    set OPENCV_TEST_DATA_PATH environment variable to <path to opencv_extra/testdata>.
    
    execute tests from build directory.

    For example
    ```
    $ <cmake_build_dir>/bin/opencv_test_core
   ```


## Contributing

> To get started...

### Step 1

- **Option 1**
    - 🍴 Fork this repo!

- **Option 2**
    - 👯 Clone this repo to your local machine using `https://github.com/LiuSirui99/Opencv-projects.git`

### Step 2

- **HACK AWAY!** 🔨🔨🔨

### Step 3

- 🔃 Create a new pull request using <a href="https://github.com/LiuSirui99/Opencv-projects/compare/" target="_blank">`https://github.com/LiuSirui99/Opencv-projects/compare/`</a>.

---

## Usage

```
Follow the step by step opencv installation and codding process. 
Including basic core operations, image processing, 
camera calibrations, 3D reconstruction and object detections.
```


## License

Liu Sirui (liusirui1234@gmail.com)
