class Beeramid {
private:
    int amount;

    [[nodiscard]] int findLevel(int sum, int level) const;

public:
    explicit Beeramid(int amount) : amount(amount) {}

    [[nodiscard]] int level() const {
        return findLevel(0, 0);
    }
};

/**
 * https://www.codewars.com/kata/51e04f6b544cf3f6550000c1/train/cpp
 * Changelog:
 *   - make methods const
 * @return number of complete beeramid levels
 */
int beeramid(int bonus, double price) {
    int amount = (int) (bonus / price);
    return Beeramid(amount).level();
}

int Beeramid::findLevel(int sum, int level) const {
    int nextLevel = level + 1;
    int nextSum = sum + nextLevel * nextLevel;

    if (nextSum > amount) {
        return level;
    }

    return findLevel(nextSum, nextLevel);
}
