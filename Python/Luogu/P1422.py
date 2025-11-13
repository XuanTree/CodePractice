n = int(input())
if n <= 150:
    cost = n * 0.4463
    pass
elif n <= 400:
    cost = 150 * 0.4463 + (n - 150) * 0.4663
    pass
else:
    cost = 150 * 0.4463 + (400 - 150) * 0.4663 + (n - 400) * 0.5663
    pass
print(f"{cost:.1f}")