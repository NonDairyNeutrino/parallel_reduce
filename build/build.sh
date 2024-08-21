# all in one line so that main compilation doesn't run if the tests don't compile
rm -f bin/*
gcc test/test.c -o bin/test && gcc -pthread src/main.c -o bin/main
