class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return '🍪' * self.size

    def deposit(self, n):
        if self.size + n > self.capacity:
            raise ValueError
        self._size += n

    def withdraw(self, n):
        if n > self.size:
            raise ValueError
        self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size

# def main():
#     jar = Jar(5)
#     jar.deposit(4)
#     jar.withdraw(5)
#     print(jar.capacity)
#     print(jar.size)

# if __name__ == "__main__":
#     main()