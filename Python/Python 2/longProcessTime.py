'''
Given the following parameters:
jobs: an array of integers where each integer represents the time required to complete a job
servers: an integer representing the number of available servers

Return: A list of lists where each list represents the jobs assigned to a specifc server
where: jobs are assigned according to the Longest Processing Time rule
'''
import operator

def serverPool(jobs, servers):
    jobs = sorted([(time, index) for index, time in enumerate(jobs)], key=lambda x: x[0], reverse=True)
    result = [[] for i in range(servers)]
    times = [0 for i in range(servers)]
    
    for i in range(len(jobs)):
        available = min(enumerate(times), key=operator.itemgetter(1))[0]
        times[available] = times[available] + jobs[i][0]
        result[available].append(jobs[i][1])
    return result