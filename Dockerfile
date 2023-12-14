# Use an official GCC runtime as a parent image
FROM gcc:latest

# Set the working directory to /app
WORKDIR /app

# Copy the current directory contents into the container at /app
ADD . /app


# Install any needed packages specified in requirements.txt
RUN apt-get update && apt-get install -y \
    # Add any additional dependencies here \
    && rm -rf /var/lib/apt/lists/*

# Compile individual source files
RUN g++ -o main main.cpp
# RUN g++ -o filesystem filesystem.cpp
# RUN g++ -o cat cat.cpp
# RUN g++ -o cd cd.cpp
# RUN g++ -o cp cp.cpp
# RUN g++ -o echo echo.cpp
# RUN g++ -o grep grep.cpp
# RUN g++ -o ls ls.cpp
# RUN g++ -o mkdir mkdir.cpp
# RUN g++ -o mv mv.cpp
# RUN g++ -o rm rm.cpp
# RUN g++ -o touch touch.cpp



# Run main.cpp when the container launches
CMD ["./main"]
