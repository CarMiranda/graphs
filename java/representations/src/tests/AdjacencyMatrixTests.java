/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Nov 20, 2017
 */

package tests;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import adjacencymatrix.SimpleAdjacencyMatrix;
import adjacencymatrix.AdjacencyMatrix;

import org.junit.Test;

import common.EdgeValue;
import common.IEdge;
import common.ILabel;
import common.IVertex;
import common.VertexValue;

class Vertex<V> implements IVertex<V> {
	
	private VertexValue<V> vv;
	private List<ILabel<?>> ll;
	private Set<IEdge<?>> se;
	private boolean marked;
	
	public Vertex(VertexValue<V> vv) {
		this.vv = vv;
		this.ll = new ArrayList<ILabel<?>>();
		this.se = new HashSet<IEdge<?>>();
		marked = false;
	}

	public boolean reachable(IVertex<V> v) {
		// TODO Auto-generated method stub
		return false;
	}

	public void addLabel(ILabel<?> l) {
		ll.add(l);
	}

	public void removeLabel(ILabel<?> l) {
		ll.remove(l);
	}

	public List<ILabel<?>> getLabels() {
		return ll;
	}

	public void addEdge(IEdge<?> e) {
		se.add(e);
	}

	public void removeEdge(IEdge<?> e) {
		se.remove(e);
	}

	public Set<IEdge<?>> getEdges() {
		return se;
	}

	public void setValue(VertexValue<V> v) {
		this.vv = v;
	}

	public VertexValue<V> getValue() {
		return vv;
	}

	public boolean isMarked() {
		return marked;
	}

	public void mark() {
		marked = true;
	}
	
}

public class AdjacencyMatrixTests {

	@Test
	public void test() {
		SimpleAdjacencyMatrix sam = new SimpleAdjacencyMatrix(5);
		sam.addRelation(2, 4);
		sam.addRelation(2, 3);
		sam.addRelation(0, 3);
		//System.out.println(sam);
	}
	
	@Test
	public void test2() {
		List<IVertex<Integer>> lvi = new ArrayList<>();
		for (int i = 1; i < 6; ++i) {
			lvi.add(new Vertex<Integer>(new VertexValue<Integer>(i)));
		}
		AdjacencyMatrix<Integer, String> am = new AdjacencyMatrix<>(lvi);
		am.addEdge(lvi.get(1), lvi.get(2), new EdgeValue<String>("b"));
		System.out.println(am);
	}

}
