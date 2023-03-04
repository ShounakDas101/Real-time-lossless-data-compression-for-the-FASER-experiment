/*
Problem Statement from: Brian & Claire
“Write a standalone c++ executable that compresses an input using a standard library, 
such as zlib, and evaluates the compression task via informative printed metrics. 
Please upload to your GitHub space with instructions on how to use your executable.”

Code Written By	: Shounak Das, Jadavpur University, Kolkata, India
Date		: Mar 3 2023 
/////////////////////////////////////////////////////////////////
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
 
2. How to compile the code : compilation should be linked with zlib ("-lz") 
			example :  g++ -o compress compress.cpp -lz
3. How to run the object/ executable file:
			./compress compress.cpp  // this will compress the compress.cpp file itself

4. How to add some real time feel in it, (my own idea, not implemented in the code).
   We can create two buffers viz, data_buffer1 and data_buffer2. 
   Create a thread CharGenerator() that randomly generates characters and fills in data_buffer1. 
   Once data_buffer1 is filled, parent process should hook another process called DataCompress(data_buffer1). 
   At this point CharGenerator() should write data into data_buffer2. Once data_buffer2 is filled it calls DataCompress(data_buffer2) and so on...... 
   Thus we can compress continuously generated data.


*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <zlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
    	std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string input_file_path = argv[1];
    std::ifstream input_file(input_file_path, std::ios::binary);
    if (!input_file) {
        std::cerr << "Error: failed to open input file " << input_file_path << std::endl;
        return 1;
    }

    // Get the size of the input file
    input_file.seekg(0, std::ios::end);
    std::streampos input_file_size = input_file.tellg();
    input_file.seekg(0, std::ios::beg);

    // Allocate buffer for input data
    char* input_buffer = new char[input_file_size];

    // Read input data into buffer
    input_file.read(input_buffer, input_file_size);

    // Compress input data using zlib
    const size_t compression_buffer_size = compressBound(input_file_size);
    char* compression_buffer = new char[compression_buffer_size];
    compress((Bytef*)compression_buffer, (uLongf*)&compression_buffer_size, (const Bytef*)input_buffer, input_file_size);

    // Calculate compression ratio
    double compression_ratio = static_cast<double>(input_file_size) / static_cast<double>(compression_buffer_size);

    // Print compression metrics
    std::cout << "Input file size: " << input_file_size << " bytes" << std::endl;
    std::cout << "Compressed file size: " << compression_buffer_size << " bytes" << std::endl;
    std::cout << "Compression ratio: " << compression_ratio << std::endl;

    // Free memory
    delete[] input_buffer;
    delete[] compression_buffer;

    return 0;
}

