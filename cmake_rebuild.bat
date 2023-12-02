@echo off

echo "Removing existing build directory..."
rmdir /s /q build

echo "Creating a new build directory..."
mkdir build

echo "Changing to the build directory..."
cd build

echo "Running CMake..."
cmake ..

echo "Building project..."
cmake --build .

echo "Script completed."
