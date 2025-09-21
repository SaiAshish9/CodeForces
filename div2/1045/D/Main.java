import java.util.*;
 
public class Main {
 
    static List<List<Integer>> adjacencyList;
    static int[] distanceFromSource;
    static int[] parentNode;
 
    static void dfs(int currentNode, int parent) {
        parentNode[currentNode] = parent;
        for (int neighbor : adjacencyList.get(currentNode)) {
            if (neighbor != parent) {
                distanceFromSource[neighbor] = distanceFromSource[currentNode] + 1;
                dfs(neighbor, currentNode);
            }
        }
    }
 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
 
        while (testCases-- > 0) {
            int numberOfNodes = scanner.nextInt();
            adjacencyList = new ArrayList<>();
            for (int i = 0; i < numberOfNodes; i++) {
                adjacencyList.add(new ArrayList<>());
            }
            for (int i = 0; i < numberOfNodes - 1; i++) {
                int u = scanner.nextInt() - 1;
                int v = scanner.nextInt() - 1;
                adjacencyList.get(u).add(v);
                adjacencyList.get(v).add(u);
            }
            distanceFromSource = new int[numberOfNodes];
            parentNode = new int[numberOfNodes];
            dfs(0, -1);
            int farthestFromRoot = 0;
            for (int i = 0; i < numberOfNodes; i++) {
                if (distanceFromSource[i] > distanceFromSource[farthestFromRoot]) { // fixed here
                    farthestFromRoot = i;
                }
            }
            Arrays.fill(distanceFromSource, 0);
            dfs(farthestFromRoot, -1);
            int farthestFromX = 0;
            for (int i = 0; i < numberOfNodes; i++) {
                if (distanceFromSource[i] > distanceFromSource[farthestFromX]) {
                    farthestFromX = i;
                }
            }
            if (distanceFromSource[farthestFromX] == numberOfNodes - 1) {
                System.out.println(-1);
            } else {
                int[] onDiameterPath = new int[numberOfNodes];
                int current = farthestFromX;
                while (current != -1) {
                    onDiameterPath[current] = 1;
                    current = parentNode[current];
                }
                int parentOfDiameterNode = -1;
                int diameterNode = -1;
                int outsideNode = -1;
                boolean found = false;
                for (int node = 0; node < numberOfNodes && !found; node++) {
                    for (int neighbor : adjacencyList.get(node)) {
                        if (onDiameterPath[node] == 1 && onDiameterPath[neighbor] == 0) {
                            parentOfDiameterNode = parentNode[node];
                            diameterNode = node;
                            outsideNode = neighbor;
                            found = true;
                            break;
                        }
                    }
                }
                System.out.println(
                        (parentOfDiameterNode + 1) + " " +
                        (diameterNode + 1) + " " +
                        (outsideNode + 1)
                );
            }
        }
    }
}