rm(list=ls())

dadosNonHeap = read.table('teste.txt')
dadosHeap= read.table('testeheap.txt')
plot (dadosNonHeap , main="Insertion on priority queue with lists" ,type="o"
      ,xlab="Insertion", ylab="Time taken", col="red")
plot (dadosHeap , main="Insertion on priority queue with heap" ,type="o"
      ,xlab="Insertion", ylab="Time taken", col="blue")
