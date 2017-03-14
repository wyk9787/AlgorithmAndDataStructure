import java.util.Arrays;

public class ArrayList<T> implements List<T>{
    private static final int GROWTH_FACTOR = 2;
    
    private Object[] data;
    private int count;
    
    public ArrayList() {
        data = new Object[16];
        count = 0;
    }
    
    public int getSize() {
        return count;
    }
    
    public void ensureCapacity(){
        if (count >= data.length) {
            data = Arrays.copyOf(data, data.length * GROWTH_FACTOR);
        }
    }
    
    public void addLast(T v) {
        ensureCapacity();
        data[count++] = v;
    }
    
    public void addFirst(T v) {
        ensureCapacity();
        for(int i = count -1; i > 0; i--) {
            data[i - 1] = data[i];
        }
        data[0] = v;
    }
    
    public T get(int index) {
        if (index >= count) {
            throw new IndexOutOfBoundsException();
        }
        return (T)data[index];
    }
    
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0; i < 30; i++) {
            arr.addLast(i);
        }
        for(int i = 0; i < 30; i++ ) {
            System.out.print(arr.get(i) + " ");
        }
    }
}
