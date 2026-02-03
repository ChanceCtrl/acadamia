#
## Confidence interval
mean <- 2.3
std <- .2
sample <- 65
confidence <- 0.9

MOE <- qnorm((1+confidence)/2) * (std/sqrt(sample))

mean - MOE
mean + MOE

#
## Another confidence interval
pop <- 300
n <- 16
confidence <- 0.99

p_hat <- n / pop
z <- qnorm((1 + confidence) / 2)

MOE <- z * sqrt((p_hat * (1 - p_hat)) / pop)

p_hat - MOE
p_hat + MOE

#
## Sample size
confidence = .9
MOE = 1.5
p = .38 # This is .5 if unknown

z = qnorm((1 + confidence) / 2)
(z^2 * p * (1 - p))/MOE^2

#
## Other sample size
sample = 40
std = .075
confidence = .98
MOE = 1.5

z = qnorm(1 - (1 - confidence) / 2)
(z * std / MOE)^2

#
## Null hypothesis P-values
z = -1.79
2 * (1 - pnorm(abs(z)))

#
## Test value or something
sample = 300
sample_mean = 208
pop_mean = 210
std = 3.6

std_error <- std / sqrt(sample)

z <- (sample_mean - pop_mean) / std_error
z


#p <- pt(z, sample - 1, lower.tail = FALSE) # Right tailed
#p <- pt(z, sample -1 ) # Left tailed
p <- 2 * pnorm(-abs(z)) # Two tailed
p

#
## Hypothesis test for proportions(?)
pop_mean = .01
sample_true = 11
sample = 300
phat = sample_true / sample
z = (phat - pop_mean)/sqrt((pop_mean*(1-pop_mean)/sample))

z=-1.466
pnorm(z, 0, 1, lower.tail =TRUE) # compare p-value to alpha
p <- pt(z, sample -1 ) # Left tailed

#
## Hypothesis test for something else ig
sample = 300
sample_true = 11
p_null = 0.01

p_sample = sample_true / sample
z = (p_sample - p_null) / sqrt((p_null * (1 - p_null)) / sample)

# get the P
1 - pnorm(z)



# Given data
sample_mean <- 29.4
population_mean <- 28
standard_deviation <- 4.1
sample_size <- 40
alpha <- 0.05

# Compute the t-test statistic
t_value <- (sample_mean - population_mean) / (standard_deviation / sqrt(sample_size))

# Calculate degrees of freedom
df <- sample_size - 1

# Calculate p-value
p_value <- pt(t_value, df)

# Print the results
cat("t-value:", t_value, "\n")
cat("Degrees of Freedom:", df, "\n")
cat("p-value:", p_value, "\n")

# Make a decision
if (p_value < alpha) {
  cat("Reject the null hypothesis. There is convincing evidence that the mean commute time is less than 30 minutes.")
} else {
  cat("Fail to reject the null hypothesis. There is not enough evidence to conclude that the mean commute time is less than 30 minutes.")
}
