/*
https://leetcode.com/problems/flood-fill/


color the connected component starting at sr, sc

Why BFS => we need to get the adjacent/contiguous grids i.e grids at same level
Why DFS => we have a boundary i.e. need to visit only grids having color same as the initial one and that too they must be consecutive

We can avoid visitedArray by using newImage[i][j]!=image[i][j] to check if it has been visited previously or not

We are calling dfs for n*m elements and each one is calling 4 other elements
tc => O(n*m) + O(n*m*4) => O(n*m)
sc => O(n*m) + O(n*m) => O(n*m)
        ans      stack

*/

class Solution {
public:

    void fillFlood(vector<vector<int>>& newImage, int sr, int sc, int color, int initialColor, vector<vector<int>> image){
        int n = newImage.size();
        int m = newImage[0].size();
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        for(int i=0;i<4;i++){
            int newX = sr + delRow[i];
            int newY = sc + delCol[i];
            if(newX>=0 && newX<n && newY>=0 && newY<m && newImage[newX][newY]==initialColor && image[newX][newY]==newImage[newX][newY]){
                visited[newX][newY] = true;
                newImage[newX][newY] = color;
                fillFlood(newImage, newX, newY, color, initialColor, visited);
            }
            
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];
        vector<vector<int>> newImage = image;
        visited[sr][sc] = true;
        newImage[sr][sc] = color;
        fillFlood(newImage, sr, sc, color, initialColor, image);
        return newImage;
    }
};














/*
Geographic Information Systems (GIS) use flood fill algorithms to analyze and manipulate spatial data. Here’s a detailed explanation of how flood fill algorithms are used in GIS with practical examples:

### 1. **Land Coverage Analysis**

**Scenario:**
You have a satellite image of a region with different land cover types, such as forests, water bodies, urban areas, and agricultural land. The image is represented as a grid where each cell corresponds to a different land cover type.

**Objective:**
Identify and analyze contiguous regions of the same land cover type to understand the distribution of different types of land cover across the area.

**Application of Flood Fill:**
- **Identification**: Use flood fill to identify contiguous regions of a specific land cover type. For example, you might use flood fill to identify all contiguous cells marked as "forest" in the grid.
- **Analysis**: Once the regions are identified, you can analyze their size, shape, and distribution. This information is useful for environmental monitoring, urban planning, and resource management.

**Process:**
1. **Initialization**: Start at a cell with the desired land cover type (e.g., forest).
2. **Flood Fill**: Apply the flood fill algorithm to expand from this cell to all contiguous cells with the same land cover type. This creates a polygon representing the entire contiguous forest region.
3. **Analysis**: Calculate metrics such as the total area covered by forests and visualize this information on a map.

### 2. **Flood Risk Assessment**

**Scenario:**
You are assessing flood risk in a city. You have a grid map showing different elevations, and you need to simulate how a flood might spread across the city based on elevation and terrain.

**Objective:**
Model the spread of floodwaters across contiguous areas of the city to identify flood-prone zones.

**Application of Flood Fill:**
- **Simulation**: Use flood fill to simulate the spread of floodwaters starting from a source point (e.g., a river or dam breach). The algorithm will fill in all contiguous cells that are below a certain elevation threshold, representing the spread of the flood.
- **Risk Assessment**: Identify which areas are affected by the flood and assess potential risks to infrastructure and communities.

**Process:**
1. **Initialization**: Start at the cell(s) representing the source of the flood (e.g., a breached dam).
2. **Flood Fill**: Apply the flood fill algorithm to expand from this cell to all contiguous cells that meet the flood criteria (e.g., below a certain elevation).
3. **Assessment**: Map the affected areas and analyze the potential impact on infrastructure, homes, and businesses.

### 3. **Urban Planning**

**Scenario:**
You are planning the expansion of a city and need to identify available land for development. The city’s land use map shows different zones like residential, commercial, and industrial areas.

**Objective:**
Identify contiguous areas available for development that meet specific criteria (e.g., undeveloped land).

**Application of Flood Fill:**
- **Identification**: Use flood fill to find contiguous regions of undeveloped land within the city map. This helps in identifying large plots of land that can be allocated for new projects.
- **Planning**: Utilize the identified regions to plan for infrastructure, transportation, and other development activities.

**Process:**
1. **Initialization**: Start at a cell representing undeveloped land.
2. **Flood Fill**: Apply the flood fill algorithm to find all contiguous cells of undeveloped land.
3. **Planning**: Determine the size and location of available plots and integrate this information into city planning efforts.

### Summary

In GIS, flood fill algorithms help manage and analyze spatial data by identifying and analyzing contiguous regions with similar attributes. Whether it’s for land cover analysis, flood risk assessment, or urban planning, flood fill algorithms provide valuable insights and facilitate decision-making in managing geographic and environmental information.
*/