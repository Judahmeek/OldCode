=begin
Given the following parameters:
coll: an arrays of arrays, each one representing the jobs a resource could be exclusively assigned to. Example: [2,3] means that this resource could be assigned to job 2 or job 3 but NOT both.
req: the number of open jobs

Return: True if all jobs can be assigned a resource. Otherwise, false.
=end

def jobs_filled?(req, coll) #Time complexity can be improved through memoization at the cost of space
	stack, last = [], 0
	while true
		bad = true
		for i in (last...coll.size)
			next if stack.include?(i)
			next unless coll[i].include?(stack.size)
			stack.push(i)
			return true if stack.size == req
			bad = false
			last = 0
			break
		end
		if bad
			return false if stack.size == 0
			last = stack.pop + 1
		end
	end
end

def fork (coll) #returns the maximum number of jobs that can be assigned resources
	stack, last, max = [], 0, 0
	while true
		bad = true
		for i in (last...coll.size)
			next if stack.include?(i)
			next unless coll[i].include?(stack.size)
			stack.push(i)
			bad = false
			last = 0
			break
		end
		if bad
			max = Math.max(max, stack.size)
			return max if stack.size == 0
			last = stack.pop + 1
		end
	end
end