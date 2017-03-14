import java.util.*;
public class Searching{

    public static <T> boolean contains(ArrayList<T>  l, T  v){
        for(int i=0; i<l.size();i++){
            if(l.get(i).equals(v)){
                return true;
            }
        }
        return false;
    }
    public static String listToString(ArrayList <Integer> l){
        if(l.size() == 0){
            return "[]";
        } else {
            StringBuffer buf = new StringBuffer();
            buf.append("[");
            buf.append(l.get(0));
            for(int i = 1; i < l.size(); i++){
                buf.append(", ");
                buf.append(l.get(i));
            }
            buf.append("]");
            return buf.toString();
        }
    }

    public static <T extends Comparable <T>>void swap(ArrayList<T> l, int i, int j) {
        T temp = l.get(i);
        l.set(i, l.get(j));
        l.set(j, temp);
    }

    private static <T extends Comparable<T>> void merge(ArrayList<T> l, int lo, int mid, int hi) {
        ArrayList<T> temp = new ArrayList<>();
        int i = lo;
        int j = mid + 1;
        while(i <= mid && j <= hi) {
            if(l.get(i).compareTo(l.get(j)) < 0) {
                temp.add(l.get(i++));
            } else {
                temp.add(l.get(j++));
            }
        }
        while(i <= mid) {
            temp.add(l.get(i++));
        }
        while(j <= hi) {
            temp.add(l.get(j++));
        }

        int m = 0;
        for(int k = lo; k <= hi; k++) {
            l.set(k, temp.get(m++));
        }
    }
    
    private static <T extends Comparable<T>> void mergeSortHelper(ArrayList<T> list, int lo, int hi) {
        if(lo < hi) {
            int middle = (hi + lo) / 2;
            mergeSortHelper(list, lo, middle);
            mergeSortHelper(list, middle + 1, hi);
            merge(list, lo, middle, hi);
        }
    }
    
    private static <T extends Comparable<T>> void mergeSort(ArrayList<T> list) {
        mergeSortHelper(list, 0, list.size() - 1);
    }


    public static <T extends Comparable <T>> void selectionSort(ArrayList<Integer> l){
        for(int i = 0; i < l.size(); i++) {
            int pos = i;
            for(int j = i + 1; j < l.size(); j ++) {
                if(l.get(j) < l.get(pos)) {
                    pos = j;
                }
            }
            swap(l,i,pos);
        }
    }

    public static <T extends Comparable<T>> int partition(ArrayList<T> l, int low, int hi, int pivotIndex) {
        swap(l, low + pivotIndex, hi);
        int left = low;
        int right = hi - 1;
        while(left <= right) {
            while(l.get(left).compareTo(l.get(hi)) < 0) {
                left++;
                if(left > hi - 1) {
                    break;
                }
            }
            while(l.get(right).compareTo(l.get(hi)) > 0) {
                right--;
                if(right < low) {
                    break;
                }
            }      
            if(left <= right) {
                swap(l, left++, right--);
            }
        }
        swap(l, left, hi);
        return left;
    }

    public static <T extends Comparable<T>> void quickSortHelper(ArrayList<T> l, int low, int hi) {
        if(low >= hi) {
            return;
        }
        int k =  (int) (Math.random() * (hi - low));
        int m = partition(l, low, hi, k);
        quickSortHelper(l, low, m - 1);
        quickSortHelper(l, m + 1, hi);
    }

    public static <T extends Comparable<T>> void quickSort(ArrayList<T> l) {
        quickSortHelper(l, 0, l.size() - 1);
    }
    public static <T extends Comparable <T>> void insertionSort(ArrayList<Integer> l){
        for(int i = 0; i < l.size(); i++){
            for(int j = i ; j > 0 && l.get(j - 1) > l.get(j); j--){
                int temp = l.get(j -1);
                l.set(j - 1, l.get(j));
                l.set(j, temp);
            }
        }
    }

    public static <T extends Comparable <T>> void bubbleSort(ArrayList<Integer> l) {
        for(int i = 0; i < l.size(); i++ ) {
            for(int j = 1; j < l.size() - i; j++) {
                if (l.get(j - 1).compareTo(l.get(j)) > 0) {
                    swap(l, j, j - 1);            
                } 
            }
        } 
    }
    
    public static void convertArrayIntoArrayList(int[] arr, ArrayList<Integer> l){
        for(int i = 0; i < arr.length; i++) {
            l.add(arr[i]);
        }
    }

    public static void main(String[] args) {
        int arr1[] = {1, 8, 10, 5, 7, 123, 19, 20, 17, 25, 44, 3, 5, 4};
        int arr2[] = {1, 3, 10, 7, 88, 25, 16, 100};
        int arr3[] = {-1, 13, 1032, 27, -68, -68, 3, 500, 1111};
        ArrayList<Integer> l = new ArrayList<>();
        convertArrayIntoArrayList(arr3, l);
//        l.add(23);
//        l.add(56);
//        l.add(8);
//        l.add(42);
//        l.add(5);
//        l.add(6);
//        l.add(73);
//        l.add(51);
        //		selectionSort(l);
        //		insertionSort(l);
        		mergeSort(l);
//        quickSort(l);
//        bubbleSort(l);
        System.out.print(listToString(l));
        System.out.println();
    }

}
