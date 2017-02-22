
public class LinkedList {
    private static Node first;

    public LinkedList() {
        this.first = null;
    }

    public void addFirst(int v) {
        //this.first.value = v;
        //this.first.next = null;
        this.first = new Node (v, this.first);
    }

    public void addLast(int v) {
        if(this.first == null) {
            addFirst(v);
        } else {
//            Node temp = new Node(this.first.value, this.first.next);
            Node temp = first;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = new Node(v, null);
        }
    }
    
    public int get(int index) {
        Node temp = first;
        for(int i = 0; i < index; i++) {
            temp = temp.next;
        }
        return temp.value;
    }
   
    public int size() {
        int size;
        if(first == null) {
            return 0;
        } else {
            size = 1;
        }
        Node temp = first;
        while(temp.next != null) {
            temp = temp.next;
            size++;
        }
        
        return size;
    }
    
    public boolean contains(int v) {
        Node temp = first;
        while(temp.next != null) {
            if(temp.value == v) {
                return true;
            } else {
               temp = temp.next;
            }
        }
        return false;
    }
    
    public int remove (int index) {
        int val = this.get(index);
        Node temp = first;
        for(int i = 0; i < index -1; i++) {
            temp = temp.next;
        }
        temp.next = temp.next.next;
        return val;
    }
}
