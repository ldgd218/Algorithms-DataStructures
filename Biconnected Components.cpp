//1
time = 0
function isBiconnected(vertex, adj[][], low[], disc[], parent[], visited[], V)
    disc[vertex]=low[vertex]=time+1
    time = time + 1
    visited[vertex]=true
    child = 0
    for i = 0 to V
        if adj[vertex][i] == true
            if visited[i] == false
                child = child + 1
                parent[i] = vertex
                result = isBiconnected(i, adj, low, disc, visited, V, time)
                if result == false
                    return false
                low[vertex] = minimum(low[vertex], low[i])
                if parent[vertex] == nil AND child > 1
                    return false
                if parent[vertex] != nil AND low[i] >= disc[vertex]
                    return false    
            else if parent[vertex] != i
                low[vertex] = minimum(disc[i], low[vertex])
    return true
//2:modification of 1
time = 0
function DFS(vertex, adj[][], low[], disc[], parent[], visited[], V, stack)
    disc[vertex]=low[vertex]=time+1
    time = time + 1
    visited[vertex]=true
    child = 0
    for i = 0 to V
        if adj[vertex][i] == true
            if visited[i] == false
                child = child + 1
                push edge(u,v) to stack
                parent[i] = vertex
                DFS(i, adj, low, disc, visited, V, time, stack)
                low[vertex] = minimum(low[vertex], low[i])
                if parent[vertex] == nil AND child > 1
                    while last element of stack != (u,v)
                        print last element of stack
                        pop from stack
                    print last element of stack
                    pop from stack
                if parent[vertex] != nil AND low[i] >= disc[vertex]
                    while last element of stack != (u,v)
                        print last element of stack
                        pop from stack
                    print last element of stack
                    pop from stack
            else if parent[vertex] != i AND disc[i] < low[vertex]
                low[vertex] = disc[i]
                push edge(u,v) to stack

fuction biconnected_components(adj[][], V)
    for i = 0 to V
        if visited[i] == false
            DFS(i, adj, low, disc, parent, visited, V, time, stack)
            while stack is not empty
                print last element of stack
                pop from stack