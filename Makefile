
CPPFLAGS = -I $(JAVA_HOME)/include -I $(JAVA_HOME)/include/darwin

all: libmyjni.jnilib

clean:
	rm *.class TestJNIDirectBuffer.h libmyjni.jnilib

TestJNIDirectBuffer.h: TestJNIDirectBuffer.java
	javac -h . TestJNIDirectBuffer.java

libmyjni.jnilib: TestJNIDirectBuffer.h TestJNIDirectBuffer.c
	gcc $(CPPFLAGS) -shared -o libmyjni.jnilib TestJNIDirectBuffer.c
