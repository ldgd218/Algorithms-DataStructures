//Articulation Points(using back edges prop.)
time = 0
function DFS(adj[][], disc[], low[], visited[], parent[], AP[], vertex, V)
        visited[vertex] = true
        disc[vertex] = low[vertex] = time+1
        child = 0
        for i = 0 to V
                if adj[vertex][i] == true
                        if visited[i] == false
                                child = child + 1
                                parent[i] = vertex
                                DFS(adj, disc, low, visited, parent, AP, i, n, time+1)
                                low[vertex] = minimum(low[vertex], low[i])
                                if parent[vertex] == nil and child > 1
                                        AP[vertex] = true
                                if parent[vertex] != nil and low[i] >= disc[vertex]
                                        AP[vertex] = true
                        else if parent[vertex] != i
                                low[vertex] = minimum(low[vertex], disc[i])
//Bridges(using back edges prop.)
time = 0
function DFS(adj[][], disc[], low[], visited[], parent[], AP[], vertex, n)
        visited[vertex] = true
        disc[vertex] = low[vertex] = time+1
        child = 0
        for i = 0 to n
                if adj[vertex][i] == true
                        if visited[i] == false
                                child = child + 1
                                parent[i] = vertex
                                DFS(adj, disc, low, visited, parent, AP, i, n, time+1)
                                low[vertex] = minimum(low[vertex], low[i])
                                if low[i] > disc[vertex]
                                        print vertex, i
                        else if parent[vertex] != i
                                low[vertex] = minimum(low[vertex], disc[i])