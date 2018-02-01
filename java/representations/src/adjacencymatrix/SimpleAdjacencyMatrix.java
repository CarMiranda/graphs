package adjacencymatrix;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Feb 1, 2018
 */
public class SimpleAdjacencyMatrix {
	
	private int n;
	private boolean[][] a;
	
	public SimpleAdjacencyMatrix(int n) {
		this.n = n;
		a = new boolean[n][n];
	}
	
	public void addRelation(int v1, int v2) {
		a[v1][v2] = true;
	}
	
	public void removeRelation(int v1, int v2) {
		a[v1][v2] = false;
	}
	
	public boolean areAdjacent(int v1, int v2) {
		return a[v1][v2];
	}
	
	public List<Integer> outEdges(int v) {
		int i;
		List<Integer> edges = new ArrayList<Integer>();
		for (i = 0; i < n; ++i) {
			if (a[v][i]) edges.add(i);
		}
		return edges;
	}
	
	public List<Integer> inEdges(int v) {
		int i;
		List<Integer> edges = new ArrayList<Integer>();
		for (i = 0; i < n; ++i) {
			if (a[i][v]) edges.add(i);
		}
		return edges;
	}
	
	public String toString() {
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				sb.append(a[i][j] ? 1 : 0);
			}
			sb.append("\n");
		}
		return sb.toString();
	}
}
