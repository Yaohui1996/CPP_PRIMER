ulimit -c unlimited
ulimit -a

if [ -d "build" ]
then
    echo "build will be cleaned..."
    rm -rf build
    echo "build has been cleaned!"
fi
echo "create build..."
mkdir build
echo "create build finished!"
cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=RelWithDebInfo
make -C build -j10