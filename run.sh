echo "Compiling ..."
clang++ -std=c++20 main.cpp -o app -arch arm64

echo "Running ..."
./app
