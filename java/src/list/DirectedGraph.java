/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Nov 20, 2017
 */

package list;

import java.util.HashSet;
import java.util.Set;

import common.EdgeValue;
import common.IEdge;
import common.IGraph;
import common.IVertex;
import common.VertexValue;

public class DirectedGraph<V,E> implements IGraph<V,E> {
	
	private Set<IVertex<V>> vertices;

	public DirectedGraph() {
		vertices = new HashSet<IVertex<V>>();
	}

	public boolean adjacent(IVertex<V> v1, IVertex<V> v2) {
		return (vertices.contains(v1) && vertices.contains(v2)) && v1.reachable(v2);
	}

	public Set<IVertex<V>> neighbors(IVertex<V> v) {
		return null;
	}
	
	public int getIndegree() {
		return 0;
	}
	
	public int getOutdegree() {
		return 0;
	}

	public IVertex<V> addVertex(V v) {
		IVertex<V> _v = new Vertex<V>(new VertexValue<V>(v));
		vertices.add(_v);
		return _v;
	}

	public void removeVertex(IVertex<V> v) {
		
	}

	public VertexValue<V> getValue(IVertex<V> v) {
		// TODO Auto-generated method stub
		return null;
	}

	public void setValue(IVertex<V> v, VertexValue<V> val) {
		// TODO Auto-generated method stub
		
	}

	public void addEdge(IEdge<E> e) {
		// TODO Auto-generated method stub
		
	}

	public void removeEdge(IEdge<E> e) {
		// TODO Auto-generated method stub
		
	}

	public EdgeValue<E> getValue(IEdge<E> e) {
		// TODO Auto-generated method stub
		return null;
	}

	public void setValue(IEdge<E> e, EdgeValue<E> val) {
		// TODO Auto-generated method stub
		
	}

	public void addVertex(IVertex<V> v) {
		// TODO Auto-generated method stub
		
	}
	
}
