//

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.file.Paths;
import java.nio.file.Path;

public class TestJNIDirectBuffer {
    public static boolean flag = false;
    public static final int bufSize = 1024;
    
    static {
	System.loadLibrary("myjni");
    }

    private native void write(ByteBuffer buffer);
    private native double size(ByteBuffer buffer);
    
    private void complete() {
	System.out.println("In complete() on the Java side");
	flag = true;
    }

    public static void main(String args[]) throws Exception 
    {
	ByteBuffer buf = ByteBuffer.allocateDirect(bufSize);

	TestJNIDirectBuffer dbWriter = new TestJNIDirectBuffer();

	System.out.println("Is a direct buffer: " + buf.isDirect());
	System.out.println("Buffer has a backing array: " + buf.hasArray());
	
	System.out.println("In Java, the direct buffer size is " + dbWriter.size(buf));

	dbWriter.write(buf);

	while ( flag == false )
	    {
		System.out.println("Complete flag is false on the Java side");
	    }

	for (int i=bufSize-1; i>0; i=i-64 )
	    {
		System.out.println("DB[" + i + "]= " + buf.get(i));
	    } 
    }
}
