
public class LinkedList<T> implements List<T>{
    private Node<T> first;

    public LinkedList() {
        this.first = null;
    }

   public void addFirst(T v) {
        this.first = new Node<T> (v, this.first);
    }

    public void addLast(T v) {
        if(this.first == null) {
            addFirst(v);
        } else {
            Node<T> temp = first;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = new Node<T>(v, null);
        }
    }
    
    public T get(int index) {
        Node<T> temp = first;
        for(int i = 0; i < index; i++) {
            temp = temp.next;
        }
        return temp.value;
    }
   
    public int getSize() {
        int size;
        if(first == null) {
            return 0;
        } else {
            size = 1;
        }
        Node<T> temp = first;
        while(temp.next != null) {
            temp = temp.next;
            size++;
        }
        
        return size;
    }
    
    public boolean contains(T v) {
        Node<T> temp = first;
        while(temp.next != null) {
            if(temp.value == v) {
                return true;
            } else {
               temp = temp.next;
            }
        }
        return false;
    }
    
    public T remove (int index) {
        T val = this.get(index);
        Node<T> temp = first;
        for(int i = 0; i < index -1; i++) {
            temp = temp.next;
        }
        temp.next = temp.next.next;
        return val;
    }
    
    public void dedupHead() {
        T firstValue = first.value;
        Node<T> temp = first.next;
        Node<T> prevTemp = first;
        while(temp != null) {
            if(temp.value.equals(firstValue)) {
                prevTemp.next = temp.next;
                temp = temp.next;
            } else {
                prevTemp = prevTemp.next;
                temp = temp.next;
            }
        }
    }
    
    public static void main(String[] args) {
        LinkedList<Integer> l = new LinkedList<Integer>();
        l.addLast(3);
        l.addLast(1);
        l.addLast(8);
        l.addLast(9);
        l.addLast(10);
        l.addLast(4);
        l.addLast(3);
        l.dedupHead();
        for(int i = 0; i < l.getSize(); i++) {
            System.out.print(l.get(i) + " ");
        }
        System.out.print("\n");
    }
}
