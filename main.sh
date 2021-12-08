cc -fPIC -shared -o libMyMain.so -mavx512f -O3 MyMain.c
jextract -t org.jexract -lMyMain MyMain.h
cp libMyMain.so /home/ziyi/local/lib
java --enable-native-access=ALL-UNNAMED --add-modules jdk.incubator.foreign MyMain.java