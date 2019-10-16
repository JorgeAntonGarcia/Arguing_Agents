setwd("D:/HMC/Arguing Agents/RData")
AgentDat <- read.csv("Data.csv", header = TRUE)

install.packages("rbin")
library(rbin)

xlim=c(0, 100)
breaks = c(0, 10, 20, 30, 40, 50, 60, 70, 80, 90)
hist(AgentDat$verdict,xlim = xlim, breaks = breaks)
