/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Nov 20, 2017
 */

package list;

import common.IEdge;
import common.ILabel;
import common.IVertex;
import common.VertexValue;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Vertex<V> implements IVertex<V> {


	private VertexValue<V> value;
	private Set<IEdge<?>> edges; // List of edges
	private List<ILabel<?>> labels;
	private boolean marked; // Marked as visited
	
	/**
	 * Creates a vertex from a value
	 * @param value
	 */
	public Vertex(VertexValue<V> value) {
		this.value = value;
		edges = new HashSet<IEdge<?>>();
		labels = new ArrayList<ILabel<?>>();
		marked = false;
	}
	
	/**
	 * Creates a vertex from a value and a set of edges
	 * @param value
	 * @param edges
	 */
	public Vertex(VertexValue<V> value, Set<IEdge<?>> edges) {
		this.value = value;
		this.edges = new HashSet<IEdge<?>>();
		this.edges.addAll(edges);
		this.labels = new ArrayList<ILabel<?>>();
		marked = false;
	}
	
	/**
	 * Creates a vertex from a value and a list of labels
	 * @param value
	 * @param labels
	 */
	public Vertex(VertexValue<V> value, List<ILabel<?>> labels) {
		this.value = value;
		edges = new HashSet<IEdge<?>>();
		this.labels = new ArrayList<ILabel<?>>();
		this.labels.addAll(labels);
		marked = false;
	}
	
	/**
	 * Creates a vertex from a value, a set of edges and a list of labels
	 * @param value
	 * @param edges
	 * @param labels
	 */
	public Vertex(VertexValue<V> value, Collection<IEdge<?>> edges, Collection<ILabel<?>> labels) {
		this.value = value;
		this.edges = new HashSet<IEdge<?>>();
		this.edges.addAll(edges);
		this.labels = new ArrayList<ILabel<?>>();
		this.labels.addAll(labels);
		marked = false;
	}
	
	/**
	 * Returns whether this vertex is reachable from a vertex v
	 * @return boolean
	 */
	public boolean reachable(IVertex<V> v) {
		return false;
	}

	// Setters and getters
	public void addLabel(ILabel<?> l) { labels.add(l); }
	public void removeLabel(ILabel<?> l) { labels.remove(l); }
	public List<ILabel<?>> getLabels() { return labels; }

	public void addEdge(IEdge<?> e) { edges.add(e); }
	public void removeEdge(IEdge<?> e) { edges.remove(e); }
	public Set<IEdge<?>> getEdges() { return edges; }

	public void setValue(VertexValue<V> v) { value = v; }
	public VertexValue<V> getValue() { return value; }

	public boolean isMarked() { return marked; }
	public void mark() { marked = true; }
}