rm(list=ls())

dadosList = read.csv('priority_queue.csv')
dadosHeap= read.csv('heap_priority_queue.csv')
plot (dadosList , main="Insertion on priority queue with lists" ,type="p"
      ,xlab="Time taken", ylab="Comparisons", col="blue")
plot (dadosHeap , main="Insertion on priority queue with heap" ,type="p"
      ,xlab="Time taken", ylab="Comparisons", col="red")
