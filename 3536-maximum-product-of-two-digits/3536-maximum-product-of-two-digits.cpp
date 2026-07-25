class Solution {
public:
    int maxProduct(int n) {
        int largest = 0;
        int secondLargest = 0;

        while (n > 0) {
            int lastDigit = n % 10;

            if (lastDigit >= largest) {
                secondLargest = largest;
                largest = lastDigit;
            }
            else if (lastDigit > secondLargest) {
                secondLargest = lastDigit;
            }

            n /= 10;
        }

        return largest * secondLargest;
    }
};