# Use Ubuntu
FROM ubuntu:22.04

# Install dependencies
RUN apt update && apt install -y \
    build-essential \
    cmake

# Set working directory
WORKDIR /app

# Copy project files
COPY . .

# Build project using CMake
RUN mkdir build && cd build && cmake .. && make

# Run the executable
CMD ["./build/MonHealth"]
