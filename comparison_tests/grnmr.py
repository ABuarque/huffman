from random import randint

def main():
	rng = 10000
	for i in range(1,rng):
		print(str(randint(1,rng))+' '+str(randint(1,rng)))


if __name__ == "__main__":
	main()
