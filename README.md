# Real-time-lossless-data-compression-for-the-FASER-experiment

# Problem Statement from: Brian & Claire
“Write a standalone c++ executable that compresses an input using a standard library, 
such as zlib, and evaluates the compression task via informative printed metrics. 
Please upload to your GitHub space with instructions on how to use your executable.”

Code Written By	: Shounak Das, Jadavpur University, Kolkata, India
Date		: March 03-2023 

Note: 
1. How to install zlib in Linux

To install zlib on Ubuntu, you can follow these steps:

    Open the terminal by pressing Ctrl+Alt+T.
    Update the package list using the following command:
    
    	$ sudo apt update
    	$ sudo apt install zlib1g-dev
After installation, you can verify the installation by checking the version of zlib using the following command:

	    $ dpkg -s zlib1g-dev | grep Version
It should show something like "Version: 1:1.2.11.dfsg-2ubuntu9.2"
 
2. How to compile the code : compilation should be linked with zlib ("-lz").example :

	    $ g++ -o compress compress.cpp -lz

         
3. How to run the object/ executable file:

	    $ ./compress compress.cpp 
      
      This will compress the compress.cpp file itself.
      
      output :
      
      Input file size: 3432 bytes.
      
      Compressed file size: 1411 bytes.
      
      Compression ratio: 2.43232.


4. How to add some real time feel in it, (my own idea, not implemented in the code).
   We can create two buffers viz, data_buffer1 and data_buffer2. 
   Create a thread CharGenerator() that randomly generates characters and fills in data_buffer1. 
   Once data_buffer1 is filled, parent process should hook another process called DataCompress(data_buffer1). 
   At this point CharGenerator() should write data into data_buffer2. Once data_buffer2 is filled it calls DataCompress(data_buffer2) and so on...... 
   Thus we can compress continuously generated data.
