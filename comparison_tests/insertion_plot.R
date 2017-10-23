library("ggplot2")

dadosList = read.csv('priority_queue.csv')
dadosHeap= read.csv('heap_priority_queue.csv')

plot1 <- ggplot(data = dadosList, aes(x = quantity,y = comparison)) +geom_point(color='red') +xlab("Quantity")+ ylab("Comparisons")+ggtitle("Gráfico Sem Heap") +stat_function(fun=function(x)x, geom="line", color="black")
plot2 <- ggplot(data = dadosHeap, aes(x = quantity,y = comparison)) +geom_point(color='red') +xlab("Quantity")+ ylab("Comparisons")+ggtitle("Gráfico Heap") +stat_function(fun=function(x)log2(x), geom="line", color="black")

multiplot <- function(..., plotlist=NULL, file, cols=1, layout=NULL) {
  library(grid)
  plots <- c(list(...), plotlist)
  numPlots = length(plots)
  if (is.null(layout)) {
    layout <- matrix(seq(1, cols * ceiling(numPlots/cols)),
                     ncol = cols, nrow = ceiling(numPlots/cols))
  }
  
  if (numPlots==1) {
    print(plots[[1]])
    
  } else {
    grid.newpage()
    pushViewport(viewport(layout = grid.layout(nrow(layout), ncol(layout))))
    for (i in 1:numPlots) {
      matchidx <- as.data.frame(which(layout == i, arr.ind = TRUE))
      print(plots[[i]], vp = viewport(layout.pos.row = matchidx$row,
                                      layout.pos.col = matchidx$col))
    }
  }
}

multiplot(plot1,plot2)
