def selection_sort(numbers):
    a = numbers.copy()
    for i in range(len(a)):
        smallest = i
        for j in range(i + 1, len(a)):
            if a[j] < a[smallest]:
                smallest = j
        a[i], a[smallest] = a[smallest], a[i]
    return a
 
def bubble_sort(numbers):
    a = numbers.copy()
    for i in range(len(a)):
        for j in range(0, len(a) - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
    return a
 
def insertion_sort(numbers):
    a = numbers.copy()
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key
    return a
 
n = int(input("Enter number of students: "))
percentages = []
 
for i in range(n):
    marks = float(input("Enter percentage: "))
    percentages.append(marks)
 
print("Selection sort:", selection_sort(percentages))
print("Bubble sort:", bubble_sort(percentages))
print("Insertion sort:", insertion_sort(percentages))
print("Top five percentages:", sorted(percentages, reverse=True)[:5])
