
import jdk.incubator.foreign.SegmentAllocator;
import jdk.incubator.foreign.ResourceScope;

import static org.jexract.dotp_h.*;


public class myMain{
    public static void main(String[] args) {
        try (var scope = ResourceScope.newConfinedScope()) {
            var allocator = SegmentAllocator.newNativeArena(scope);
            var a = allocator.allocateArray(C_DOUBLE, new double[] {
                    1.0, 2.0, 3.0, 4.0,
                    1.0, 1.0, 1.0, 1.0,
                    3.0, 4.0, 5.0, 6.0,
                    5.0, 6.0, 7.0, 8.0
            });
            int k  = 1;
            myMain(a);
        }

    }
}