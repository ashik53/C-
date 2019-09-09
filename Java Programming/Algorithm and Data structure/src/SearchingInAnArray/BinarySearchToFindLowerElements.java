package SearchingInAnArray;

public class BinarySearchToFindLowerElements {

}

public static int binarySearch(int element, int index, int size) {
	int began = 0;
	int end = size - 1;

	while (began <= end) {
		int mid = (began + end) / 2;
		if (elementList[index].get(mid) >= element) {
			end = mid - 1;
		} else {
			began = mid + 1;
		}
	} // search algo
	if (end < 0)
		return -1;
	return elementList[index].get(end);
}