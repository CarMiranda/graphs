package adjacencymatrix;

import java.util.List;
import java.util.Set;
import java.util.HashMap;

import common.EdgeValue;
import common.IEdge;
import common.IGraph;
import common.IVertex;
import common.VertexValue;

/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Feb 1, 2018
 */
public class AdjacencyMatrix<V, E> implements IGraph<V, E> {
	
	private int n;
	private HashMap<IVertex<V>, HashMap<IVertex<V>, EdgeValue<E>>> a;
	
	public AdjacencyMatrix(List<IVertex<V>> vertices) {
		this.n = vertices.size();
		a = new HashMap<IVertex<V>, HashMap<IVertex<V>, EdgeValue<E>>>();
		for (IVertex<V> vertex1 : vertices) {
			a.put(vertex1, new HashMap<IVertex<V>, EdgeValue<E>>());
			for (IVertex<V> vertex2 : vertices) {
				a.get(vertex1).put(vertex2, null);
			}
		}
	}

	public boolean adjacents(IVertex<V> v1, IVertex<V> v2) {
		return a.get(v1).get(v2) != null;
	}

	public Set<IVertex<V>> neighbors(IVertex<V> v) {
		// TODO Auto-generated method stub
		return null;
	}

	public void addVertex(IVertex<V> v) {
		for (IVertex<V> vertex : a.keySet()) {
			a.get(vertex).put(v, null);
		}
		a.put(v, new HashMap<IVertex<V>, EdgeValue<E>>());
		for (IVertex<V> vertex : a.keySet()) {
			a.get(v).put(vertex, null);
		}
	}

	public void removeVertex(IVertex<V> v) {
		for (IVertex<V> vertex : a.keySet()) {
			a.get(vertex).remove(v);
		}
		a.remove(v);
	}

	public void addEdge(IVertex<V> v1, IVertex<V> v2, EdgeValue<E> e) {
		a.get(v1).put(v2, e);
	}

	public void removeEdge(IVertex<V> v1, IVertex<V> v2) {
		a.get(v1).put(v2, null);		
	}

	public EdgeValue<E> getValue(IVertex<V> v1, IVertex<V> v2) {
		return a.get(v1).get(v2);
	}

	public void setValue(IVertex<V> v1, IVertex<V> v2, EdgeValue<E> val) {
		a.get(v1).put(v2, val);
	}
	
	public String toString() {
		StringBuffer sb = new StringBuffer();
		for (IVertex<V> vertex1 : a.keySet()) {
			for (IVertex<V> vertex2 : a.keySet()) {
				EdgeValue<E> e = a.get(vertex1).get(vertex2);
				sb.append(e == null ? "X" : e.getValue());
			}
			sb.append("\n");
		}
		return sb.toString();
	}
}
