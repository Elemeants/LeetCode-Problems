mkdir $1
cp ../Template/* ./$1
cd $1
mkdir build
cd build
cmake ..