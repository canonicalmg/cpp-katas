/**
 * https://www.codewars.com/kata/555624b601231dc7a400017a/train/cpp
 * @param n amount of people in a circle
 * @param k every kth is being eliminated until one survives
 * @return the surviving person
 */
int josephusSurvivor(int n, int k) {
    int x = 1;

    for (int i = 1; i <= n; i++) {
        x += k - 1;
        x = x % i + 1;
    }

    return x;
}
