
// bfs from each building to all empty cells, add distance to each empty cell, and increase cnt, denoting number of buildings reachable
// at the end, get the minimum distance among empty cells which have cnt equal to building cnt

// tc -> (n*m)2
// sc -> n*m

int shortestDistance(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return -1;
    }

    int rows = grid.size();
    int cols = grid[0].size();
    int totalBuildings = 0;

    // Count the number of buildings
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                totalBuildings++;
            }
        }
    }

    vector<vector<int>> totalDistances(rows, vector<int>(cols, 0));
    vector<vector<int>> reachableBuildingsCount(rows, vector<int>(cols, 0));

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Breadth-first search from each building
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                
                queue<pair<int, int>> buildingQueue;
                buildingQueue.push({i, j});
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                visited[i][j] = true;
                int distance = 0;

                // BFS to calculate distances from current building
                while (!buildingQueue.empty()) {
                    int queueSize = buildingQueue.size();
                    distance++;

                    for (int k = 0; k < queueSize; ++k) {
                        int currentRow = buildingQueue.front().first;
                        int currentCol = buildingQueue.front().second;
                        buildingQueue.pop();

                        for (const auto& direction : directions) {
                            int newRow = currentRow + direction.first;
                            int newCol = currentCol + direction.second;

                            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                                grid[newRow][newCol] == 0 && !visited[newRow][newCol]) {
                                visited[newRow][newCol] = true;
                                totalDistances[newRow][newCol] += distance;
                                reachableBuildingsCount[newRow][newCol]++;
                                buildingQueue.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }
    }

    int shortestDistanceValue = numeric_limits<int>::max();

    // Find the minimum distance reachable by all buildings
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Need to ensure that all buildings can reach this location
            if (grid[i][j] == 0 && reachableBuildingsCount[i][j] == totalBuildings) {
                shortestDistanceValue = min(shortestDistanceValue, totalDistances[i][j]);
            }
        }
    }

    if (shortestDistanceValue == numeric_limits<int>::max()) {
        return -1;
    } else {
        return shortestDistanceValue;
    }