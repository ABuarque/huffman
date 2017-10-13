rm(list=ls())

dadosNonHeap = read.table('priority_queue.csv')
dadosHeap= read.table('heap_priority_queue.csv')
plot (dadosNonHeap , main="Insertion on priority queue with lists" ,type="o"
      ,xlab="Insertion", ylab="Time taken", col="red")
plot (dadosHeap , main="Insertion on priority queue with heap" ,type="o"
      ,xlab="Insertion", ylab="Time taken", col="blue")
